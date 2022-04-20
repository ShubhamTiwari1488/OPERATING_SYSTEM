/*------In a civilized society, a gentle man lives with his spouse and his elderly parents.
Due to old age, his parents cannot be left alone in the house. So, at least any one of the spouse must be available in the house. Write a synchronize solution using semaphore for this problem.----------*/


#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<pthread.h>
#include<time.h>
#include<semaphore.h>

#define SPOUSE 2	 //Either wife or husband


enum {out,in};	//enum for out and in status;


int spouse_state[2] = {out};	//An array of size 2 for the current status(out,in) of spouse


//Mutex
pthread_mutex_t mutex;

//Semaphore
sem_t spouse[SPOUSE];


//USER DEFINED FUNCTIONS
void *spouse_work(void *args);
void enter_house(int );
void check_spouse_status(int );
void takecare_parent(int );
void leave_house(int ); 


//Main
int main()
{
  int i;
  int *a;
  
  pthread_t spouse_thread[SPOUSE];
  
  //Initializing mutex
  pthread_mutex_init(&mutex,NULL);
  
  
  //Initializing semaphore spouse
  for(i=0;i<SPOUSE;i++)
  	sem_init(&spouse[i],0,0);
  	
  
  //Thread Creation
  for(i=0;i<SPOUSE;i++)
  {
    a=(int *)malloc(sizeof(int));
    
    *a = i;
    
    //Creating thread
    if(i>0)
    {
     if(pthread_create(&spouse_thread[i] ,NULL,&spouse_work ,a) !=0)
     {
       perror("Failed to create thread\n");
     }
     
    }
     
    else
    {
      if(pthread_create(&spouse_thread[i],NULL,&spouse_work, a) !=0)
      {
        perror("Failed to create thread\n");
      }
    }
      
  }      
  
  
  //Joining the threads
  for(i=0;i<SPOUSE;i++)
  {
    if(pthread_join(spouse_thread[i],NULL) != 0)
    {
      perror("Failed to join thread");
    }
    
  }
  
  //Destroying the semaphore
  sem_destroy(spouse);
  
  //Destroying the mutex
  pthread_mutex_destroy(&mutex);
  
  
  free(a);	//Free the space
  
  return 0;
}  



//Spouse_Work Function
void *spouse_work(void *args)
{
  while(1)	//Infinite Loop
  {
   	enter_house(*(int *)args);
   	takecare_parent(*(int *)args);
   	leave_house(*(int *)args);
   	
  }
  
}


//Enter_house Function
void enter_house(int i)
{
  pthread_mutex_lock(&mutex);	  //P(mutex)
  	
  	spouse_state[i]=in;	//Spouse 'i' returned back to home
  	
 	if(i==0)
  		printf("\nHusband says - 'Wife , I have returned home'\n");
  	  
  	else
  		printf("\nWife says - 'Husband , I have returned home'\n");
  	  
  
  	sleep(1);
  
  	check_spouse_status((i+1)%2);
  
  pthread_mutex_unlock(&mutex);  //V(mutex)

}


//check_spouse_status Function
void check_spouse_status(int i)
{
  if(spouse_state[(i+1)%2]==in)
  {
   	spouse_state[i]=out;	//Spouse 'i' went out
   	
   	if(i==0)
   	  printf("\nHusband says - 'Wife , I am going out!!'\n");
   	  
   	else
   	  printf("\nWife says - 'Husband , I am going out!!'\n");
   	  
   	  
   	sem_post(&spouse[i]);	 //V(spouse[i])
   	
  }
  
  sleep(1);

}


//leave_house Function
void leave_house(int i)
{
  
  pthread_mutex_lock(&mutex);	 //P(mutex)
  
       check_spouse_status(i);  
  
  pthread_mutex_unlock(&mutex); //V(mutex)  
  
  sem_wait(&spouse[i]);	  //P(spouse[i])
  
}

//takecare_parent Function
void takecare_parent(int i)
{
  if(i==0)
  	printf("\nHusband says - ' I will take care of our parents '\n");
  	
  else
  	printf("\nWife says - 'I will take care of our parents '\n");

} 


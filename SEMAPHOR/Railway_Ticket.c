/*------In a railway ticket booking office, maximum 10 persons, either male, female, or both are allowed to go inside. There are three ticket counters in the booking office. Among these 10 persons, a maximum of 3 persons are allowed to book the ticket at a time with a restriction that all these 3 persons can neither be male nor be female. It means that maximum of 2 males with 1 female or maximum of 2 females with 1 male is allowed to book the ticket. Write a solution using semaphore to synchronize among the males and females to book their ticket.---------*/


#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<time.h>
#include<pthread.h>
#include<semaphore.h>


//Semaphore
sem_t person_cnt , female_cnt , male_cnt , counter;


//Global Variable
int count = 0;


//USER-DEFINED FUNCTIONS
void *Book_Ticket(void *args);
void Male(void);
void Female(void);
void Male_book_ticket(void);
void Female_book_ticket(void);


//Main
int main()
{
 int i;
 
 pthread_t Thread[2];
 
 //Initializing semaphore
 sem_init(&person_cnt,0,10);
 sem_init(&female_cnt,0,2);
 sem_init(&male_cnt,0,2);
 sem_init(&counter,0,3);
 
 
 //Creating Threads
 for(i=0;i<2;i++)
 {
  if(i==0)
  {
   if(pthread_create(&Thread[i],NULL,&Book_Ticket,NULL)!=0)
   {
     perror("Failed to create thread\n");
   }
   
  }
  else
  {
   
   if(pthread_create(&Thread[i],NULL,&Book_Ticket,NULL)!=0)
   {
     perror("Failed to create thread\n");
   }
    
  }
   
 }
 
 //Joining the threads
 for(i=0;i<2;i++)
 {
  if(pthread_join(Thread[i],NULL)!=0)
  {
    perror("Failed to join the threads\n");
  }
  
 }
 
 
 //Destroying the semaphore
 sem_destroy(&person_cnt);
 sem_destroy(&female_cnt);
 sem_destroy(&male_cnt);
 sem_destroy(&counter);
 
 
 return 0;
}


void *Book_Ticket(void *args)
{
 
 //20 number of people are arriving to book ticket but 10 persons are allowed at a time
  for(;count<20;count++)
 {
   Male();	//Male Ticket Book Function
   
   Female(); //Female Ticket Book Function
 }

}

//Male Ticket Book Function
void Male(void)
{
 sem_wait(&person_cnt);	  //p(person_cnt)
   
    sem_wait(&male_cnt);	//p(male_cnt)
        
         sem_wait(&counter);	 //p(counter)
              
              Male_book_ticket();
              
         sem_post(&person_cnt);	//v(person_cnt)
         
     sem_post(&male_cnt);	//v(male_cnt)
     
 sem_post(&counter);	//v(counter)
  
}  

//Female Ticket Book Function
void Female(void)
{
 sem_wait(&person_cnt);		//p(person_cnt)
    
    sem_wait(&female_cnt);	//p(female_cnt)
    
       sem_wait(&counter);	//p(counter)
          
          Female_book_ticket();
          
       sem_post(&person_cnt);	 //v(person_cnt)
       
    sem_post(&female_cnt);	//v(female_cnt)
    
 sem_post(&counter);	//v(counter)
 
}

//Male_book_ticket Function
void Male_book_ticket()
{
 printf("\nMale Booked Ticket\n");
}

//Female_book_ticket Function
void Female_book_ticket()
{ 
 printf("\nFemale Booked Ticket\n");
}
 
 

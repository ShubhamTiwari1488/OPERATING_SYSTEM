/*----In a railway station, there are 3 rest rooms. In each rest room, only one passenger is allowed to take rest at a time. Write a solution using semaphore to synchronize among the passenger to avoid the race condition for accessing the rooms.----*/


#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<time.h>
#include<pthread.h>
#include<semaphore.h>


enum {empty,pack};


//Semaphore
sem_t passenger[10];


//Mutex
pthread_mutex_t mutex;


//Global Variable
int room_state[3] = {empty};

int room_occupied[10] = {-1,-1,-1,-1,-1,-1,-1,-1,-1,-1};

int num = 0;


//USER DEFINED FUNCTIONS
void *passenger_work(void *args);
void occupy_room(int );
void check_room_status(int );
void vacant_room(int );
void take_rest(int );

//Main
int main()
{
 int i;
 int *a;
 
 pthread_t Thread[10];
 
 
 //Initializing mutex
 pthread_mutex_init(&mutex,NULL);
 
 
 //Initializing semaphore passenger
 for(i=0;i<10;i++)
 	sem_init(&passenger[i],0,0);
 	
 
 //Thread Creation
 for(i=0;i<10;i++)
 {
  a=(int *)malloc(sizeof(int ));
  *a = i;
  
  if(pthread_create(&Thread[i],NULL,&passenger_work,a)!=0)
  {
   perror("Failed to create thread\n");
  }
  
 }
 
 
 //Joining the threads
 for(i=0;i<10;i++)
 {
   if(pthread_join(Thread[i],NULL)!= 0)
   {
    perror("Failed to join thread\n");
   }
   
 }
 
 
 //Destroying the semaphore
 sem_destroy(passenger);
 
 //Destroying the mutex
 pthread_mutex_destroy(&mutex);
 
 free(a);	//Free the space
 
 return 0;
}


//Passenger_Work Function
void *passenger_work(void *args)
{
 while(1)
 {
  occupy_room(*(int *)args);
  
  take_rest(*(int *)args);     
  
  vacant_room(*(int *)args);
 }
}


//Occupy_room Function
void occupy_room(int i)
{
 pthread_mutex_lock(&mutex);	//P(mutex)
   check_room_status(i);
 pthread_mutex_unlock(&mutex); //V(mutex)
 
 sem_wait(&passenger[i]);	// p(passenger[i])
 
}


//Check_Room_Status Function
void check_room_status(int i)   
{
 int rm_no = -1;	// -1 because no room is occupied
 
 if(room_state[0] == empty)
 { 
   rm_no = 0;	// Room '0' is occupied
 }
 
 else if(room_state[1] == empty)
 {
   rm_no = 1;	//Room '1' is occupied
 }
 
 else if(room_state[2] == empty)
 {
   rm_no = 2;	//Room '2' is occupied
 }
 
 if(rm_no != -1)
 {
  room_occupied[i] = rm_no;	//It assigns the room , the passenger is occupying.
  
  room_state[rm_no] = pack;	//Room state is changed to pack
  
  
  sem_post(&passenger[i]);	// v(passenger[i])
 }
 
}


//Vacant_Room Function
void vacant_room(int i)
{ 
  int count;
  
  pthread_mutex_lock(&mutex);		//p(mutex)
  
     room_state[room_occupied[i]] = empty;	//Passenger vacated the room
     
     room_occupied[i] = -1;		//Since the passenger vacated the room
     
     
     //Looking for the passengers who are waiting....
     for(count=0;count<10;num=(num+1)%10,count++)
     {
     
      if(room_occupied[num]==-1 && num!=i)
      {
     		check_room_status(num);
     		
     		num=(num+1)%10;		//Similar to what we do in queue traversal
     	
     	}
     
     }

     
  pthread_mutex_unlock(&mutex);	//v(mutex)
  
}


//Take_Rest Function
void take_rest(int i)
{

  printf("\nPassenger %d is in the rest room\n",(i+1));
  
  sleep(1);
  
} 

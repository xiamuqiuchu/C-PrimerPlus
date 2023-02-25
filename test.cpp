#include <iostream>
#include <cstdlib>
#include <pthread.h>
 
using namespace std;
 
#define NUM_THREADS     5
 
struct thread_data{
   int thread_id;
   char *message;
};

void *PrintHello(void * threadarg)
{
   struct thread_data *my_data;

   my_data = (struct thread_data *)threadarg;
   cout << "thread id : " << my_data->thread_id;
   cout << " message: " << my_data->message << endl;
   pthread_exit(NULL);
}

int main()
{
   pthread_t threads[NUM_THREADS];
   struct thread_data td[NUM_THREADS];
   int rc;
   int i;

   for(i = 0;i< NUM_THREADS;i++)
   {
      cout << "main(): createing thread, " << i << endl;
      td[i].thread_id= i;
      td[i].message = (char*)"this is message";
      rc = pthread_create(&threads[i],NULL,PrintHello,(void*)&td[i]);
      if (rc){
         cout << "error: "<< rc << endl;
         exit(-1);
      }

   }
   pthread_exit(NULL);
}
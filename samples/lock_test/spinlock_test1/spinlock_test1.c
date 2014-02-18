#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>

pthread_spinlock_t var_spinlock;
int var;
//static struct var_m pvar_m[1] = {{.var_mutex = PTHREAD_MUTEX_INITIALIZER}};

void var_inc(void* i);

int main()
{
   pthread_t ptchild[2];
   int num[2];
   num[0] = 0;
   num[1] = 1;
   int timer = 0;
   
   pthread_spin_init(&var_spinlock, PTHREAD_PROCESS_SHARED);
   printf("timer: %d\n", timer);
   timer++;
   pthread_create(&(ptchild[0]), NULL, (void*) &var_inc, (void*) &(num[0]));
   sleep(1);
   printf("here1!!\n"); //test1
   pthread_create(&(ptchild[1]), NULL, (void*) &var_inc, (void*) &(num[1]));

   //pthread_join(ptchild[0], NULL);
   //pthread_join(ptchild[1], NULL);
   
   while(1)
   {
      printf("timer: %d\n", timer);
      timer++;
      sleep(1);
   }

   return 0;
}

void var_inc(void* i)
{
   int num = *((int*)i);
   
   while(1)
   {
      //printf("here2!! num:%d\n", num); //test1

      printf("\nnum:%d waiting!!\n\n", num);
      pthread_spin_lock(&var_spinlock);

      var++;
      printf("\nnum:%d var:%d\n", num, var);
      printf("num:%d sleep 8 secs!!\n\n", num);
      sleep(8);

      pthread_spin_unlock(&var_spinlock);

      sleep(2);
   }
}

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>

pthread_rwlock_t var_rwlock;
int var;
//static struct var_m pvar_m[1] = {{.var_mutex = PTHREAD_MUTEX_INITIALIZER}};

void var_read(void* i);
void var_inc(void* i);

int main()
{
   pthread_t ptchild[5];
   int num[5];
   num[0] = 0;
   num[1] = 1;
   num[2] = 2;
   num[3] = 3;
   num[4] = 4;
   int timer = 0;
   
   pthread_rwlock_init(&var_rwlock, NULL);

   pthread_create(&(ptchild[0]), NULL, (void*) &var_inc, (void*) &(num[0]));
   printf("timer: %d\n", timer);
   sleep(1);
   timer++;
   //printf("here1!!\n"); //test1
   pthread_create(&(ptchild[1]), NULL, (void*) &var_inc, (void*) &(num[1]));
   printf("timer: %d\n", timer);
   sleep(1);
   timer++;
   pthread_create(&(ptchild[2]), NULL, (void*) &var_inc, (void*) &(num[2]));
   printf("timer: %d\n", timer);
   sleep(1);
   timer++;
   pthread_create(&(ptchild[3]), NULL, (void*) &var_read, (void*) &(num[3]));
   printf("timer: %d\n", timer);
   sleep(1);
   timer++;
   pthread_create(&(ptchild[4]), NULL, (void*) &var_read, (void*) &(num[4]));
   printf("timer: %d\n", timer);
   sleep(1);
   timer++;

   while(1)
   {
      printf("timer: %d\n", timer);
      timer++;
      sleep(1);
   }

   return 0;
}

void var_read(void* i)
{
   int num = *((int*)i);

   while(1)
   {
      printf("\nnum:%d waiting!!\n\n", num);
      
      pthread_rwlock_rdlock(&var_rwlock);

      printf("\nnum:%d reading var:%d\n", num, var);
      printf("num:%d sleep 8 secs!!\n\n", num);
      sleep(8);

      pthread_rwlock_unlock(&var_rwlock);

      sleep(2);
   }
}

void var_inc(void* i)
{
   int num = *((int*)i);
   
   while(1)
   {
      //printf("here2!! num:%d\n", num); //test1

      printf("\nnum:%d waiting!!\n\n", num);
      
      pthread_rwlock_wrlock(&var_rwlock);

      var++;
      printf("\nnum:%d inc var:%d\n", num, var);
      printf("num:%d sleep 18 secs!!\n\n", num);
      sleep(18);

      pthread_rwlock_unlock(&var_rwlock);

      sleep(2);
   }
}

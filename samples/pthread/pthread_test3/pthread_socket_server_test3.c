#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <poll.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <pthread.h>
#include <sys/types.h>
#include <unistd.h>

void afd_poll(void* argv);
void pcreate(void* argv);

struct afd_poll_argv
{
   int afd;
   int i;
};

int main()
{
   int fd;
   int flag = 1;
   struct sockaddr_in* saddr;
   socklen_t n = sizeof(struct sockaddr_in);
   int afd;
   //char buf[100];
   //int str_len;
   int p; //poll check
   //int r; //read check
   int i;
   //int j; //counter
   struct pollfd pfds[1];
   //pthread_t ptchild[10];
   struct afd_poll_argv argv_temp;

   printf("main(): pid: %d, tid: %u\n", getpid(), pthread_self()); //test1

   fd = socket(PF_INET, SOCK_STREAM, 0);
   setsockopt(fd, SOL_SOCKET, SO_REUSEADDR, (char *)&flag, sizeof(int));
   saddr = malloc(sizeof(struct sockaddr_in));
   saddr->sin_family = AF_INET;
   saddr->sin_port = htons(5564);
   saddr->sin_addr.s_addr = htonl(INADDR_ANY);
   fcntl(fd, F_SETFD, FD_CLOEXEC);
   fcntl(fd, F_SETFL, O_NONBLOCK);
   if(bind(fd, (struct sockaddr *)saddr, sizeof(struct sockaddr_in)) < 0)
   {
      printf("Can't bind!!\n");
   }
   if(listen(fd, 1) < 0)
   {
      printf("Can't listen!!\n");
   }
   //getsockname(fd, (struct sockaddr *)saddr, &n);
   
   //printf("port:%x, addr:%x\n", saddr->sin_port, saddr->sin_addr.s_addr);
   i = 0;
   while(1)
   {
      //printf("here1\n"); //test1
      pfds[0].fd = fd;
      pfds[0].events = POLLIN;
      p = poll(pfds, 1, 300000);
      if(p > 0)
      {
         if(pfds[0].revents & POLLIN)
         {
            afd = accept(fd, (struct sockaddr *)saddr, &n);
            //printf("here2\n"); //test1
            if(afd > 0)
            {
               if(i < 10)
               {
                  argv_temp.afd = afd;
                  argv_temp.i = i;

//                  pthread_create(&(ptchild[i]), NULL, (void*) &afd_poll, (void*) &argv_temp);
                  pcreate((void*) &argv_temp);
                  i++;
               }
            }
            pfds[0].revents &= ~POLLIN;
         }
      }
   }
   
   close(fd);
   return 0;
}

void pcreate(void* argv)
{
   pthread_t ptchild;

   pthread_create(&ptchild, NULL, (void*) &afd_poll, argv);
}

void afd_poll(void* argv)
{
   struct afd_poll_argv argv_temp;
   argv_temp = *((struct afd_poll_argv*)argv);
   int afd = argv_temp.afd;
   int i = argv_temp.i;
   int p = 0;
   struct pollfd pafds[1];
   int r = 0;
   char buf[100];
   int str_len;

   printf("afd_poll(): pid: %d, tid: %u\n", getpid(), pthread_self()); //test1

   fcntl(afd, F_SETFD, FD_CLOEXEC);
   fcntl(afd, F_SETFL, O_NONBLOCK);
   pafds[0].fd = afd;
   pafds[0].events = POLLIN;
   printf("%d connected!\n", i);

   while((p == 0) || (r != 0))
   {
      printf("here3! num: %d\n", i); //test1
      p = poll(pafds, 1, 5000);
      printf("here4! num: %d\n", i); //test
      if(p > 0)
      {
         if(pafds[0].revents & (POLLERR | POLLHUP | POLLNVAL))
         {
            printf("%d hangs up!!\n", i);
         }
         else if(pafds[0].revents & POLLIN)
         {
            r = recv(pafds[0].fd, buf, 100, 0);
            printf("i:%d r:%d buf:%s\n", i, r, buf);
            str_len = strlen(buf) + 1;
            while(str_len < r)
            {
               printf("i:%d r:%d buf:%s\n", i, r, buf + str_len);
               str_len += strlen(buf + str_len) + 1;
            }
            pafds[0].revents &= ~POLLIN;
         }
      }
      //sleep(5); //test2
   }
   close(pafds[0].fd);
   printf("%d disconnected!! hangs up!!\n", i);
}

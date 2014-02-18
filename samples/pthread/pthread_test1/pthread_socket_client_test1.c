#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

int main()
{
   int fd;
   struct sockaddr_in* dest;
   char buf[100];

   fd = socket(PF_INET, SOCK_STREAM, 0);
   dest = malloc(sizeof(struct sockaddr_in));
   dest->sin_family = AF_INET;
   dest->sin_port = htons(5564);
   inet_aton("127.0.0.1", &(dest->sin_addr));
   if(connect(fd, (struct sockaddr *)dest, sizeof(struct sockaddr_in)) < 0)
   {
      printf("Can't connect!!\n");
   }
   else
   {
      printf("Connect!!\n");
   }
   
   strcpy(buf, "Hello Server!! XD");
   write(fd, buf, strlen(buf) + 1);
   //printf("port:%x, addr:%x\n", dest->sin_port, dest->sin_addr.s_addr);

   while(1)
   {
      scanf("%s", buf);
      if(write(fd, buf, strlen(buf) + 1) < 0)
      {
         printf("(write error!!\n)");
      }
      if(strcmp(buf, "close") == 0)
      {
         close(fd);
         fd = 0;
         break;
      }
      read(fd, buf, 100);
      printf("%s\n", buf);
   }

   if(fd != 0)
   {
      printf("Cntl C!!\n");
      close(fd);
   }
   return 0;
}

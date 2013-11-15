/* broad_servo.c */

#include <stdio.h>

#include <unistd.h>

#include <stdlib.h>

#include <sys/socket.h>

#include <sys/types.h>

#include <netinet/in.h>

#include <arpa/inet.h>

#include <netdb.h>

#include <time.h>

#include <string.h>

/* 隨機產生骰子數的函數 */

void test(int count, char *buf)

{

  int i;

  srand((int)time(0));

  i=(rand() % 6)+1;

  sleep(2);

  sprintf(buf, "次數為: %d  骰子值為: %d",count, i);

}

int main()

{

  struct sockaddr_in    sv_addr, bc_addr;

  int                   sockfd;

  static int    so_broadcast = 1;  

  char          buf[1024];

  int           z, i;

  /* 建立IPv4位址 */

  bzero(&sv_addr, sizeof(sv_addr));

  sv_addr.sin_family = AF_INET;

  sv_addr.sin_port = htons(8001);

  sv_addr.sin_addr.s_addr = inet_addr("140.114.78.222");

  /* 建立廣播位址 */

  bzero(&bc_addr, sizeof(bc_addr));

  bc_addr.sin_family = AF_INET;

  bc_addr.sin_port = htons(8000);

  bc_addr.sin_addr.s_addr = inet_addr("140.114.78.255");

  /* 建立socket */

  sockfd = socket(AF_INET, SOCK_DGRAM, 0);

  if (sockfd == -1) {

        perror("socket error");

        exit(1);

  }

  /* 設定socket，讓主機具廣播功能 */

  z = setsockopt(sockfd, SOL_SOCKET, SO_BROADCAST,

             &so_broadcast, sizeof(so_broadcast));

  if (z == -1) {

        perror("setsockopt error");

        exit(1);

  }

  /* 繫結socket */

  z = bind(sockfd, (struct sockaddr *)&sv_addr, sizeof(sv_addr));

  if (z == -1) {

        perror("bind error");

        exit(1);

  }

  printf("廣播 server 執行中...\n");

  /* 將20筆資訊廣播給client端 */

  for (i=0; i<20; i++) {

        test(i,buf);

        printf("%s\n",buf);

        z = sendto(sockfd, buf, strlen(buf)+1, 0,

                 (struct sockaddr *)&bc_addr, sizeof(bc_addr));

        if (z < 0) {

                perror("sendto error");

        }

  }

  /* 將stop字串傳給client */

  sprintf(buf, "STOP");

  z = sendto(sockfd, buf, strlen(buf)+1, 0,

                 (struct sockaddr *)&bc_addr, sizeof(bc_addr));

  if (z < 0) {

        perror("sendto error");

        exit(1);

  }

  printf("廣播 server 停止...\n");

  close(sockfd);

  exit(0);

}

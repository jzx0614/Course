/* broad_client.c */

#include <stdio.h>

#include <unistd.h>

#include <string.h>

#include <stdlib.h>

#include <sys/socket.h>

#include <sys/types.h>

#include <netinet/in.h>

#include <arpa/inet.h>

#include <netdb.h>

int main()

{

  struct sockaddr_in    sv_addr;

  int                   sockfd;

  char          buf[1024];

  static int    so_reuseaddr = 1;

  int           z;

  

  /* 建立IPv4位址 */

  bzero(&sv_addr, sizeof(sv_addr));

  sv_addr.sin_family = AF_INET;

  sv_addr.sin_port = htons(8000);

  sv_addr.sin_addr.s_addr = inet_addr("140.114.78.255");

 

  /* 建立socket */

  sockfd = socket(AF_INET, SOCK_DGRAM, 0);

  if (sockfd == -1) {

        perror("socket error");

        exit(1);

  }

  /* 設定socket，讓主機不同程序可以重複使用相同的IP位址及port */

  z = setsockopt(sockfd, SOL_SOCKET, SO_REUSEADDR,

             &so_reuseaddr, sizeof(so_reuseaddr));

  if (z == -1) {

        perror("setsockopt error");

        exit(1);

  }

  /* ?結socket */

  z = bind(sockfd, (struct sockaddr *)&sv_addr, sizeof(sv_addr));

  if (z == -1) {

        perror("bind error");

        exit(1);

  }

  while(1) {

    int         i;

    socklen_t   j;

        /* 接收來自server的訊息 */

    i = recvfrom(sockfd, buf, sizeof(buf), 0,

                 (struct sockaddr *)&sv_addr, &j);

    if (i < 0) {

                perror("recvfrom error");

                exit(1);

    }

    buf[i] = 0;

        /* 若收到stop字串，結束與server的連結 */

    if (!strcasecmp(buf, "STOP"))

                break;

        /* 將收到的訊息顯示出來 */

    printf("廣播訊息為 %s\n", buf);

  }

  close(sockfd);

  exit(0);

}

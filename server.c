#include <stdio.h>
#include <sys/types.h> 
#include <sys/socket.h>
#include <netinet/in.h>

int main()
{
     int sockfd, newsocket, portno, clilen;
     char buffer[256];
     struct sockaddr_in serv_addr, cli_addr;
     int n;
     if (argc < 2) 
	 {
         fprintf(stderr,"ERROR, no port provided\n");
         exit(1);
     }
     
     sockfd = socket(AF_INET, SOCK_STREAM, 0);
     if (sockfd < 0) 
        error("ERROR opening socket");
     bzero((char *) &serv_addr, sizeof(serv_addr));
     portno = atoi(argv[1]);
     serv_addr.sin_family = AF_INET;
     serv_addr.sin_addr.s_addr = INADDR_ANY;
     serv_addr.sin_port = htons(portno);
     if (bind(sockfd, (struct sockaddr *) &serv_addr,sizeof(serv_addr)) < 0) 
        error("ERROR on binding");
     listen(sockfd,5);
     clilen = sizeof(cli_addr);
     newSocket = accept(sockfd, (struct sockaddr *) &cli_addr, &clilen);
     if (newSocket < 0) 
          error("ERROR on accept");
     bzero(buffer,256);
     n = read(newssocket,buffer,255);
     if (n < 0) 
	 printf("ERROR reading from socket");
     else
	 printf("Connected %s\n",buffer);
     return 0; 
}

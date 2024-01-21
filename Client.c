#include "Ser_Cl.h"

int main(int argc, char *argv[]) {

    srand(time(NULL));
    
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <server_address> <server_port>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    const char *serverAddress = argv[1];
    int serverPort = atoi(argv[2]);

    // Creating socket
    int sockfd;
    if ((sockfd = socket(AF_INET, SOCK_DGRAM, 0)) == -1) {
        perror("Error creating socket");
        exit(EXIT_FAILURE);
    }

    struct sockaddr_in serverAddr;
    memset(&serverAddr, 0, sizeof(serverAddr));

    // Server address configuration
    serverAddr.sin_family = AF_INET;
    serverAddr.sin_port = htons(serverPort);
    if (inet_pton(AF_INET, serverAddress, &serverAddr.sin_addr) <= 0) {
        perror("Invalid server address");
        exit(EXIT_FAILURE);
    }

    // Generating a random number between 1 and max
    int max = 100;
    int number = rand() % NMAX + 1;
    printf("I'm sending the question \x1b[1m%d\x1b[0m to the server.\n", number);

    // Sending the number to the server
    sendto(sockfd, &number, sizeof(number), 0, (struct sockaddr *)&serverAddr, sizeof(serverAddr));

    // Receiving and printing the response from the server
    int response[number];
    recvfrom(sockfd, &response, sizeof(response), 0, NULL, NULL);
    if(response[0] !=0){
	  	printf("The response is a list that consists of \x1b[1m%d\x1b[0m random numbers.\n\n", number);
		for (int i = 0; i < number; i++) 
		{
	        	printf("%d || ", response[i]);
	        }
		   	printf("\n");
	} else {
		printf("The server didn't send the list.\n");
	}

    // Closing the socket
    close(sockfd);

    return 0;
}

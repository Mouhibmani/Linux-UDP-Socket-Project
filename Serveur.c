#include "Ser_Cl.h"

int main(int argc, char *argv[]) {

    srand(time(NULL));
    
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <server_port>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    int serverPort = atoi(argv[1]);
    
    printf("\x1b[32mServer ON.\x1b[0m\n");

    // Creating socket
    int sockfd;
    if ((sockfd = socket(AF_INET, SOCK_DGRAM, 0)) == -1) {
        perror("Error creating socket");
        exit(EXIT_FAILURE);
    }

    struct sockaddr_in serverAddr, clientAddr;
    socklen_t clientLen = sizeof(clientAddr);

    // Server address configuration
    memset(&serverAddr, 0, sizeof(serverAddr));
    serverAddr.sin_family = AF_INET;
    serverAddr.sin_addr.s_addr = INADDR_ANY;
    serverAddr.sin_port = htons(serverPort);

    // Binding the socket to the server address
    if (bind(sockfd, (struct sockaddr *)&serverAddr, sizeof(serverAddr)) == -1) {
        perror("Bind failed");
        exit(EXIT_FAILURE);
    }

    // Receiving the number from the client
    int number;
    recvfrom(sockfd, &number, sizeof(number), 0, (struct sockaddr *)&clientAddr, &clientLen);
    
    if (sizeof(number) == sizeof(int) && number > 0 && number <= NMAX) 
        {

            char clientAddressStr[INET_ADDRSTRLEN];
   	    inet_ntop(AF_INET, &clientAddr.sin_addr, clientAddressStr, INET_ADDRSTRLEN);
         
            printf("The number received from the client with the address \x1b[1m%s\x1b[0m is \x1b[1m%d\x1b[0m.\n",clientAddressStr,  number);
            
            
            // Generating and sending n random numbers to the client
    	    int numbers[number];
    	    for (int i = 0; i < number; i++) {
        	numbers[i] = (rand() % NMAX)+ 1;
    	    }
    	    
    	    printf("Sending to the client...\n");
    	    sendto(sockfd, numbers, sizeof(numbers), 0, (struct sockaddr *)&clientAddr, clientLen);
    	    printf("Done.\n");
            
        }
        else{
        	printf("Not a valid number. Sorry we are closing the session.\n");
        }

    

    // Closing the socket
    close(sockfd);

    return 0;
}

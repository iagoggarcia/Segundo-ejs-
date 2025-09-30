#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <unistd.h>

int main(int argc, char *argv[]) {
    char *ip = (char*)malloc(16*sizeof(char));
    int clientSocket, clientPort;
    struct sockaddr_in serverAddr;
    socklen_t longitud = sizeof(struct sockaddr_in);

    printf("Introduce la IP: \n");
    scanf("%s", ip);
    printf("Introduce el puerto: \n");
    scanf("%d", &clientPort);

    printf("\n");

    clientSocket = socket(AF_INET, SOCK_STREAM, 0);

    serverAddr.sin_family = AF_INET;
    serverAddr.sin_port = htons(9002);

    inet_pton(AF_INET, ip, &serverAddr.sin_addr);

    if (connect(clientSocket, (struct sockaddr*)&serverAddr, longitud) == -1) {
        perror("No se pudo conectar al servidor");
        exit(EXIT_FAILURE);
    }

    char buffer[256]; // buffer para guardar el mensaje del servidor
    int bytesRecibidos;

    // sleep(2);

    //bytesRecibidos = recv(clientSocket, buffer, sizeof(buffer)-1, 0);
    while ((bytesRecibidos = recv(clientSocket, buffer, 10, 0)) > 0) {
        buffer[bytesRecibidos] = '\0';
        printf("%s\n", buffer);
        printf("Número de bytes recibidos: %d\n", bytesRecibidos);
    }
    /*
    if (bytesRecibidos > 0) {
        buffer[bytesRecibidos] = '\0';
        printf("%s\n", buffer);
        printf("Número de bytes recibidos: %d\n", bytesRecibidos);
    } 
      
    else {
        perror("Error al recibir datos");
        exit(EXIT_FAILURE);
    }
    */
    close(clientSocket);

    free(ip);
    return 0;
}
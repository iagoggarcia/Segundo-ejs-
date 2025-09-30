#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <unistd.h>

int main(int argc, char *argv[]) {
    FILE *archivo;
    char archiveName[20];

    char *ip = (char*)malloc(16*sizeof(char));
    int clientSocket, clientPort;
    struct sockaddr_in serverAddr;
    socklen_t longitud = sizeof(struct sockaddr_in);

    printf("Introduce el nombre del archivo: \n");
    scanf("%s", archiveName);
    archivo = fopen(archiveName, "r");
    if (archivo == NULL) {
        perror("Error abriendo el archivo\n");
    }

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

    char linea[256];
    while (fgets(linea, sizeof(linea), archivo) != NULL) {
        printf("%s", linea);
        if (send(clientSocket, linea, strlen(linea), 0) == -1) {
            perror("Error al enviar la línea");
            break;
        }
    }

    close(clientSocket);

    free(ip);
    return 0;
}
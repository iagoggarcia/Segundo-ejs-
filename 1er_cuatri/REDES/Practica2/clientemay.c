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

    printf("Introduce el nombre del archivo: ");
    scanf("%s", archiveName);
    archivo = fopen(archiveName, "r");
    if (archivo == NULL) {
        perror("Error abriendo el archivo\n");
    }

    printf("Introduce la IP: ");
    scanf("%s", ip);
    printf("Introduce el puerto: ");
    scanf("%d", &clientPort);

    printf("\n");

    clientSocket = socket(AF_INET, SOCK_STREAM, 0);

    serverAddr.sin_family = AF_INET;
    serverAddr.sin_port = htons(clientPort);

    inet_pton(AF_INET, ip, &serverAddr.sin_addr);

    if (connect(clientSocket, (struct sockaddr*)&serverAddr, longitud) == -1) {
        perror("No se pudo conectar al servidor");
        exit(EXIT_FAILURE);
    }

    
    char message[255];
    int n = recv(clientSocket, message, sizeof(message)-1, 0);
    if (n > 0) {
        message[n] = '\0';
    }
    printf("%s\n", message);

    char linea[256];
    FILE *finalFile = fopen("fichero_final.txt", "w");
    if (finalFile == NULL) {
        perror("Error creando el archivo final\n");
        fclose(archivo);
        close(clientSocket);
        free(ip);
        return -1;
    }
    
    while (fgets(linea, sizeof(linea), archivo) != NULL) {
        printf("%s", linea);
        if (send(clientSocket, linea, strlen(linea), 0) == -1) {
            perror("Error al enviar la línea");
            break;
        }

        char buffer2[256];
        int bytesRecibidos = recv(clientSocket, buffer2, sizeof(buffer2)-1, 0);
        if (bytesRecibidos == -1) {
            perror("Error al recibir la línea");
            break;
        }
        else if (bytesRecibidos == 0) {
            printf("El servidor cerró la conexión\n");
            break;
        }
        buffer2[bytesRecibidos] = '\0';
        printf("Respuesta del servidor: %s", buffer2);
        fprintf(finalFile, "%s", buffer2);
    }

    fclose(archivo);
    close(clientSocket);

    free(ip);
    return 0;
}
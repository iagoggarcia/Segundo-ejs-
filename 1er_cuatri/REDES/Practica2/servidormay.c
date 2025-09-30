#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <unistd.h>
#include <ctype.h>

int main(int argc, char *argv[]) {
    int serverSocket, conectionSocket;
    char message[255] = "Has entrado al servidor\n";

    if ((serverSocket = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        perror("No se pudo crear el socket");
        return -1;
    }

    struct sockaddr_in direction_server;
    direction_server.sin_family = AF_INET;
    direction_server.sin_port = htons(9002);
    direction_server.sin_addr.s_addr = htonl(INADDR_ANY);

    if (bind(serverSocket, (struct sockaddr*)&direction_server, sizeof(direction_server)) < 0) {
        perror("No se pudo asignar dirección");
        exit(EXIT_FAILURE);
    }

    if (listen(serverSocket, 15) == -1) {
        perror("No se pudo escuchar en el socket");
        exit(EXIT_FAILURE);
    }

    struct sockaddr_in direction_conection;
    socklen_t addr_len = sizeof(direction_conection);

    if ((conectionSocket = accept(serverSocket, (struct sockaddr *)&direction_conection, &addr_len)) < 0) {
        perror("No se pudo aceptar la conexión");
        exit(EXIT_FAILURE);
    }

    char client_ip[INET_ADDRSTRLEN];
    inet_ntop(AF_INET, &(direction_conection.sin_addr), client_ip, INET_ADDRSTRLEN);
    printf("Cliente conectado con IP: %s y puerto %d\n", client_ip, ntohs(direction_conection.sin_port));

    if (send(conectionSocket, message, strlen(message), 0) == -1) {
        perror("Error al enviar datos");
        exit(EXIT_FAILURE);
    }

    char buffer[256];
    int bytesRecibidos;

    while ((bytesRecibidos = recv(conectionSocket, buffer, sizeof(buffer)-1, 0)) > 0) {
        buffer[bytesRecibidos] = '\0';
        for (int i = 0; buffer[i]; i++) {
            buffer[i] = toupper(buffer[i]);
        }
        send(conectionSocket, buffer, bytesRecibidos, 0);
        if (send(conectionSocket, buffer, bytesRecibidos, 0) == -1) {
            perror("Error al enviar la línea");
            break;
        }
    }

    close(conectionSocket);
    close(serverSocket);

    return 0;
}
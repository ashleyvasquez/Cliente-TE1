//
// Created by ashley on 18/2/20.
//

#include <QtCore/QString>
#include <QObject>
#include "Cliente.h"


Cliente::Cliente() {
}

bool Cliente::conectar() {
    descriptor = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
    if (descriptor < 0)
        return false;
    info.sin_family = AF_INET;
    info.sin_addr.s_addr = inet_addr("127.0.0.1");
    info.sin_port = ntohs(4050);
    memset(&info.sin_zero, 0, sizeof(info.sin_zero));

    if ((::connect(descriptor, (sockaddr *) &info, (socklen_t) sizeof(info))) < 0)
    return false;

    pthread_t hilo;
    pthread_create(&hilo, 0, Cliente::controlador, (void *) this);
    pthread_detach(hilo);
    return true;
}


void * Cliente::controlador(void *obj) {
    Cliente *padre = (Cliente *) obj;

    while (true) {
        string mensaje;
        while (1) {
            char buffer[10] = {0};
            int bytes = recv(padre->descriptor, buffer, 10, 0);
            mensaje.append(buffer, bytes);
            if (bytes <= 0) {
                close(padre->descriptor);
                pthread_exit(NULL);
            }
            if (bytes < 10)
                break;
        }
        //cout << "Servidor:" << mensaje << endl;
        //msj = mensaje.c_str();
        emit padre->NewMensaje(QString::fromStdString(mensaje));
    }
    close(padre->descriptor);
    pthread_exit(NULL);
}


void Cliente::setMensaje(const char *msn) {
    cout << "" << send(descriptor, msn, strlen(msn), 0) << endl;
}



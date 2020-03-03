//
// Created by ashley on 18/2/20.
//

#ifndef T_EXTRACLASECLIENTE_CLIENTE_H
#define T_EXTRACLASECLIENTE_CLIENTE_H


#include <sys/socket.h>
#include <sys/types.h>
#include <netdb.h>
#include <string.h>
#include <string>
#include <iostream>
#include <pthread.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <QtCore/QArgument>
#include <QObject>

/**
 * Clase que crea al cliente y lo conecta por medio de sockets
 */
using namespace std;
class Cliente: public QObject {
    Q_OBJECT

public:
    /**
     *@brief Constructor
     * @return
     */
    Cliente();
    /**
     *@brief Crea el socket
     * @return
     */
    bool conectar();
    /**
     * @brief Envia el mensaje al servidor
     */
    void setMensaje(const char *msn);

private:
    int descriptor;
    sockaddr_in info;
    /**
     * @brief Recibe los mensajes del servidor
     */
    static void * controlador(void *obj);

    signals:
            void NewMensaje(QString msn);

};
#endif //T_EXTRACLASECLIENTE_CLIENTE_H

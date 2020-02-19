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

using namespace std;
class Cliente {

public:
    Cliente();
    bool conectar();
    void setMensaje(const char *msn);
    //string msn;
private:
    int descriptor;
    sockaddr_in info;
    static void * controlador(void *obj);

};
#endif //T_EXTRACLASECLIENTE_CLIENTE_H

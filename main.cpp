#include <iostream>
#include "Cliente.h"

 Cliente *client;

int main() {
    client = new Cliente;
    client->conectar();


    while (1) {
        string mensaje;
        cin >> mensaje;
        client->setMensaje(mensaje.c_str());
    }
}

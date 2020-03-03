//
// Created by ashley on 2/3/20.
//

#include "Window.h"
#include <QtWidgets/QMessageBox>
#include <QtWidgets/QPlainTextEdit>


using namespace std;
Cliente *client;

void * clienterun(void *)
{
    try{
        client->conectar();
    }catch(string ex)
    {
        cout << ex;
    }

    pthread_exit(NULL);
}


Window::Window(QWidget *parent) {


    // create the scene
    scene = new QGraphicsScene();
    setScene(scene);
    setFixedSize(900,600);
    scene->setBackgroundBrush(QColor(72,37,37));

    client = new Cliente;
    pthread_t hiloCliente;
    pthread_create(&hiloCliente,0,clienterun,NULL);
    pthread_detach(hiloCliente);


    titulo=new QLabel(this);
    titulo->setGeometry(400,20,300,100);
    titulo->setText("CLIENTE");
    titulo->font();

    inicio=new QLabel(this);
    inicio->setGeometry(400,150,300,100);
    inicio->setText("Ingrese el vertice de inicio");
    inicio->font();

    vertice=new QLineEdit(this);
    vertice->setGeometry(250,250,300,100);

    enviar1 = new QPushButton(this);
    enviar1->setGeometry(600,270,100,50);
    enviar1->setText("Enviar");
    connect(enviar1 ,&QPushButton::clicked, this, &Window::saveVertice1);

    final=new QLabel(this);
    final->setGeometry(400,350,300,100);
    final->setText("Ingrese el vertice final");
    final->font();

    enviar2 = new QPushButton(this);
    enviar2->setGeometry(600,470,100,50);
    enviar2->setText("Enviar");
    connect(enviar2 ,&QPushButton::clicked, this, &Window::saveVertice2);

    vertice2=new QLineEdit(this);
    vertice2->setGeometry(250,450,300,100);


}


void Window::mousePressEvent(QMouseEvent *event) {
    QGraphicsView::mousePressEvent(event);
}

void Window::saveVertice1()
{
    QString text = vertice->text();
    string textStd = text.toStdString();
    client->setMensaje(textStd.c_str());
}

void Window::saveVertice2()
{
    QString text = vertice2->text();
    string textStd = text.toStdString();
    client->setMensaje(textStd.c_str());
}


Window::~Window() {

}
//
// Created by ashley on 2/3/20.
//

#ifndef T_EXTRACLASECLIENTE_WINDOW_H
#define T_EXTRACLASECLIENTE_WINDOW_H

#include <QGraphicsView>
#include <QGraphicsScene>
#include <QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPlainTextEdit>
#include "iostream"
#include "Window.h"
#include "cliente/Cliente.h"

using namespace std;

/**
 * Clase que maneja la interfaz
 * tiene todos las variables para la ventana, botones, cajas de texto y labels
 */
class Window : public QGraphicsView{
public:
    Window(QWidget * parent=0);
    QGraphicsScene* scene;
    QLabel *titulo;
    QLabel * inicio;
    QLabel * final;
    QLineEdit *vertice;
    QLineEdit *vertice2;
    QPlainTextEdit *txt_log;

    /**
     * Evento de clic de los botones
     * @param event
     */
    void mousePressEvent(QMouseEvent *event);
    QPushButton *enviar1;
    QPushButton *enviar2;

    ~Window();

    /**
     * Mètodo que recupera la info escrita en la caja de texto1
     */
    void saveVertice1();

    /**
    * Mètodo que recupera la info escrita en la caja de texto2
    */
    void saveVertice2();
};

#endif //T_EXTRACLASECLIENTE_WINDOW_H

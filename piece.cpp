#include "piece.h"
#include "ui_piece.h"
#include <QDebug>

Piece::Piece(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Piece)
{
    ui->setupUi(this);
    type = 0;
}

void Piece::paintEvent(QPaintEvent *e)
{
    QPainter painter(this);
    int w = (this->width()),
            h = (this->height());

    painter.setRenderHint(QPainter::Antialiasing);
    painter.setClipRect(e->rect()); // this tells QPainter to restrict painting to only this rect

    switch(type)
    {
        case 2:
            painter.setBrush(QBrush(Qt::black));
            painter.setPen(QPen(Qt::black,.5));
            painter.drawEllipse(6,6,h/1.2,w/1.2);
            break;
        case 1:
            painter.setBrush(QBrush(Qt::white));
            painter.setPen(QPen(Qt::white,.5));
            painter.drawEllipse(6,6,h/1.2,w/1.2);
        default:
        break;
     }

}
void Piece::setType(int t)
{
    type = t;
    repaint();
}


void Piece::mousePressEvent(QMouseEvent *e)
{
    //type = 1;
    //repaint();
    qDebug()<<"in mouse press event";
    emit clickedSquare(x,y,type);
}

Piece::~Piece()
{
    delete ui;
}
void Piece::setXY(int X, int Y)
{
    x = X;
    y = Y;
}


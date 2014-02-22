#ifndef PIECE_H
#define PIECE_H

#include <QWidget>
#include <QPainter>
#include <QPaintEvent>
#include <math.h>
#include <QPen>
#include <QDebug>
#include <cstdlib>
#include <iostream>

using namespace std;

namespace Ui {
class Piece;
}

class Piece : public QWidget
{
    Q_OBJECT
    
public:
    explicit Piece(QWidget *parent = 0);
    void setType(int t);
    void setXY(int X, int Y);
    ~Piece();
signals:
    void clickedSquare(int x, int y, int player);

protected:
    void mousePressEvent(QMouseEvent *e);

private:
    void paintEvent(QPaintEvent *e);
    int type, x, y;


    Ui::Piece *ui;
};

#endif // PIECE_H

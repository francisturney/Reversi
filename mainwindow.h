#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QtGui>
#include <QtCore>
#include <QGraphicsScene>
#include <square.h>
#include <piece.h>
#include <iostream>
#include <cstdlib>
#include <QDebug>

using namespace std;

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT
    
public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    void initializeWID();
    void initialize(square gameboard[][8]);
    void updateGameboard();
    bool flip(int X, int Y);
    bool flipWest(int X, int Y);
    bool flipEast(int X, int Y);
    bool flipNorth(int X, int Y);
    bool flipSouth(int X, int Y);
    bool flipNE(int X, int Y);
    bool flipNW(int X, int Y);
    bool flipSE(int X, int Y);
    bool flipSW(int X, int Y);
    void playerFlip();
    void SetPass(int x);
    bool boardFull();
    int winner();
    void computer();
    void squareClickAi(int x, int y, int player);
    void delayMoment();


    
public slots:
    void squareClick(int x, int y, int player);

private slots:
    void on_pushButton_2_clicked();

    void on_pushButton_clicked();

    void on_PvC_clicked();

    void on_PvP_clicked();

private:
    Ui::MainWindow *ui;
    QGraphicsScene *scene;
    int player, pass,count,a,b;
    square gameboard[8][8];
    bool gameOver,passCheck,AI,change=true;
    bool PvC = true;







};

#endif // MAINWINDOW_H

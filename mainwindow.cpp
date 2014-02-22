#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <iostream>
#include <cstdlib>

using namespace std;



MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{


    ui->setupUi(this);
    scene = new QGraphicsScene(this);
    ui->graphicsView->setScene(scene);

    PvC = false;
    count = 0;
    a = 0;
    b = 0;
    gameOver = false;
    passCheck = false;
    AI = false;
    player = 1;
    pass = 0;
    initializeWID();
    initialize(gameboard);

    for (int x=0; x<=400; x+=50)
        scene->addLine(x,0,x,400, QPen(Qt::black));

    for (int y=0; y<=400; y+=50)
        scene->addLine(0,y,400,y, QPen(Qt::black));
    ui->graphicsView->setBackgroundBrush(QBrush(Qt::darkCyan));

    ui->frame->setFrameStyle(3);
    ui->frame->setFrameShadow(QFrame::Sunken);
    ui->frame->setLineWidth(2);
    ui->frame->setMidLineWidth(3);

    // Fit the view in the scene's bounding rect
    //ui->graphicsView->fitInView(scene->itemsBoundingRect());
}
void MainWindow::squareClick(int x, int y, int owner)
{
    if(gameOver)
    {
      initialize(gameboard);
      gameOver = false;
    }
    if(owner == 0)
    {

        if(flip(x,y))
        {
            gameboard[x][y].setOwner(player);
            playerFlip();
            SetPass(0);

            updateGameboard();
            if(PvC)
            {
                delayMoment();
                computer();
            }
        }
     }
    if(boardFull())
    {
        player = winner();
        qDebug()<< " in board full";
    }

    updateGameboard();
//    if(PvC)
//{
//    void delayMoment();
//    computer();
//}


}
void MainWindow::squareClickAi(int x, int y, int owner)
{

    if(gameOver)
    {
      initialize(gameboard);
      gameOver = false;
    }
    if(owner == 0)
    {
        if(flip(x,y))
        {
            gameboard[x][y].setOwner(player);
            playerFlip();
            SetPass(0);
        }
     }
    if(boardFull())
    {
        player = winner();
        qDebug()<< " in board full";
    }
    updateGameboard();

}
void MainWindow :: playerFlip()
{
    //qDebug()<< "          In PLAYER FLIP gameboard at 4,2 = " << gameboard[4][2].getOwner();

//    if(PvC)
//    {
//        if(player == 1)
//            computer();
//        else if (player == 2)
//            player = 1;
//    }

        if(player == 1)
            player =2;
        else if(player == 2)
        {
            player = 1;
         }

}
void MainWindow::SetPass(int x)
{
    pass = x;
}
bool MainWindow::boardFull()
{
  for(int i=0;i<8;i++)
      for(int j=0;j<8;j++)
      {
        if(gameboard[i][j].getOwner()==0)
            return false;
      }
  return true;
}



bool MainWindow::flip(int X, int Y)
{
      bool possible = false;
//      if(player == 1)
//          change = true;
      if(gameboard[X][Y].getOwner() == 0)
      {
          //cout<<"Passcheck: "<<passCheck<<" "<<endl;
          //qDebug()<< "           Passcheck              =" << passCheck;
          if(flipWest(X,Y))
              possible = true;
          if(flipEast(X,Y))
              possible = true;
          if(flipSouth(X,Y))
              possible = true;
          if(flipNorth(X,Y))
              possible = true;
          if(flipNE(X,Y))
              possible = true;
          if(flipNW(X,Y))
              possible = true;
          if(flipSE(X,Y))
              possible = true;
          if(flipSW(X,Y))
              possible = true;
      }

      return possible;
}

bool MainWindow :: flipWest(int X, int Y)
{
    bool possible = false;
    square *squareItr = &gameboard[X][Y];
    while(squareItr->W_link()!=NULL)
    {
        //qDebug()<<"            In flip west point = " << X <<  "," << Y << "player = " << player;
        squareItr = squareItr->W_link();
        if(squareItr->getOwner() == player)
        {
            squareItr = squareItr->E_link();
            if(squareItr->getOwner() == 0)
                break;
            else
                possible = true;

            while(squareItr->getOwner()!= 0)
            {
                if(!passCheck)
                    squareItr->setOwner(player);
                if(AI)
                    count++;
                squareItr = squareItr->E_link();
            }
            if(squareItr->getOwner() == 0)
                break;

        }
        if(squareItr->getOwner() == 0)
            break;
    }
    return possible;
}
bool MainWindow :: flipEast(int X, int Y)
{
    bool possible = false;
    square *squareItr = &gameboard[X][Y];
    while(squareItr->E_link()!=NULL)
    {
        qDebug()<<"After check Null";
        squareItr = squareItr->E_link();
        if(squareItr->getOwner() == player)
        {
            squareItr = squareItr->W_link();
            if(squareItr->getOwner() == 0)
                break;
            else
                possible = true;

            while(squareItr->getOwner()!= 0)
            {
                if(!passCheck)
                    squareItr->setOwner(player);
                if(AI)
                    count++;
                squareItr = squareItr->W_link();
            }
        }
        if(squareItr->getOwner() == 0)
            break;
    }
    return possible;
}
bool MainWindow :: flipNorth(int X, int Y)
{
    bool possible = false;
    square *squareItr = &gameboard[X][Y];
    while(squareItr->N_link()!=NULL)
    {
        squareItr = squareItr->N_link();
        if(squareItr->getOwner() == player)
        {
            squareItr = squareItr->S_link();
            if(squareItr->getOwner() == 0)
                break;
            else
                possible = true;

            while(squareItr->getOwner()!= 0)
            {
                if(!passCheck)
                    squareItr->setOwner(player);
                if(AI)
                    count++;
                squareItr = squareItr->S_link();
            }
        }
        if(squareItr->getOwner() == 0)
            break;
    }
    return possible;
}
bool MainWindow :: flipSouth(int X, int Y)
{
    //qDebug()<<"            In flip south point = " << X <<  "," << Y << "player = " << player;

    bool possible = false;
    square *squareItr = &gameboard[X][Y];
    while(squareItr->S_link()!=NULL)
    {
        squareItr = squareItr->S_link();
        if(squareItr->getOwner() == player)
        {
            qDebug()<<"            FOUND OWN PEICE = " << X <<  "," << Y << "player = " << player;

            squareItr = squareItr->N_link();
            if(squareItr->getOwner() == 0)
                break;
            else
                possible = true;

            while(squareItr->getOwner()!= 0)
            {
            qDebug()<<"            In flip south point = " << X <<  "," << Y << "player = " << player;

                if(!passCheck)
                    squareItr->setOwner(player);
                if(AI)
                    count++;
                squareItr = squareItr->N_link();
            }
        }
        if(squareItr->getOwner() == 0)
            break;
    }
    return possible;
}

bool MainWindow :: flipNE(int X, int Y)
{
    bool possible = false;
    square *squareItr = &gameboard[X][Y];
    while(squareItr->NE_link()!=NULL)
    {
        squareItr = squareItr->NE_link();
        if(squareItr->getOwner() == player)
        {
            squareItr = squareItr->SW_link();
            if(squareItr->getOwner() == 0)
                break;
            else
                possible = true;

            while(squareItr->getOwner()!= 0)
            {
                if(!passCheck)
                    squareItr->setOwner(player);
                if(AI)
                    count++;
                squareItr = squareItr->SW_link();
            }
        }
        if(squareItr->getOwner() == 0)
            break;
    }
    return possible;
}
bool MainWindow :: flipNW(int X, int Y)
{
    bool possible = false;
    square *squareItr = &gameboard[X][Y];
    while(squareItr->NW_link()!=NULL)
    {
        squareItr = squareItr->NW_link();
        if(squareItr->getOwner() == player)
        {
            squareItr = squareItr->SE_link();
            if(squareItr->getOwner() == 0)
                break;
            else
                possible = true;

            while(squareItr->getOwner()!= 0)
            {
                if(!passCheck)
                    squareItr->setOwner(player);
                if(AI)
                    count++;
                squareItr = squareItr->SE_link();
            }
        }
        if(squareItr->getOwner() == 0)
            break;
    }
    return possible;
}
bool MainWindow :: flipSW(int X, int Y)
{
    bool possible = false;
    square *squareItr = &gameboard[X][Y];
    while(squareItr->SW_link()!=NULL)
    {
        squareItr = squareItr->SW_link();
        if(squareItr->getOwner() == player)
        {
            squareItr = squareItr->NE_link();
            if(squareItr->getOwner() == 0)
                break;
            else
                possible = true;

            while(squareItr->getOwner()!= 0)
            {
                if(!passCheck)
                    squareItr->setOwner(player);
                if(AI)
                    count++;
                squareItr = squareItr->NE_link();
            }
        }
        if(squareItr->getOwner() == 0)
            break;
    }
    return possible;
}
bool MainWindow :: flipSE(int X, int Y)
{
    bool possible = false;
    square *squareItr = &gameboard[X][Y];
    while(squareItr->SE_link()!=NULL)
    {
        squareItr = squareItr->SE_link();
        if(squareItr->getOwner() == player)
        {
            squareItr = squareItr->NW_link();
            if(squareItr->getOwner() == 0)
                break;
            else
                possible = true;

            while(squareItr->getOwner()!= 0)
            {
                if(!passCheck)
                    squareItr->setOwner(player);
                if(AI)
                    count++;
                squareItr = squareItr->NW_link();

            }
        }
        if(squareItr->getOwner() == 0)
            break;
    }
    return possible;
}


void MainWindow::initialize(square spaces[][8])
{
    square ptrObject;

    cout<<"checking for null ptr "<<ptrObject.ptrNull()<<endl;  //checking ptrNull fcn.
    square something;
    square* ptrToSomething = &something;

    for(int i=0;i<8;i++)
        for(int j=0;j<8;j++)
        {
            spaces[i][j].setN(ptrToSomething);
            spaces[i][j].setE(ptrToSomething);
            spaces[i][j].setW(ptrToSomething);
            spaces[i][j].setS(ptrToSomething);
            spaces[i][j].setNE(ptrToSomething);
            spaces[i][j].setNW(ptrToSomething);
            spaces[i][j].setSE(ptrToSomething);
            spaces[i][j].setSW(ptrToSomething);
        }

    for(int i=0;i<8;i++)
    {
        spaces[0][i].setN(ptrObject.ptrNull());
        spaces[0][i].setNW(ptrObject.ptrNull());
        spaces[0][i].setNE(ptrObject.ptrNull());
    }
    for(int i=0;i<8;i++)
    {
        spaces[8-1][i].setS(ptrObject.ptrNull());
        spaces[8-1][i].setSW(ptrObject.ptrNull());
        spaces[8-1][i].setSE(ptrObject.ptrNull());
    }
    for(int i=0;i<8;i++)
    {
        spaces[i][0].setW(ptrObject.ptrNull());
        spaces[i][0].setNW(ptrObject.ptrNull());
        spaces[i][0].setSW(ptrObject.ptrNull());
    }
    for(int i=0;i<8;i++)
    {
        spaces[i][8-1].setE(ptrObject.ptrNull());
        spaces[i][8-1].setNE(ptrObject.ptrNull());
        spaces[i][8-1].setSE(ptrObject.ptrNull());
    }
    square *tempPtr;
    for(int i=0;i<8;i++)
       for(int j=0;j<8;j++)
        {
            spaces[i][j].setOwner(0);
            if(spaces[i][j].N_link() != NULL)
            {
                tempPtr = ptrObject.ptr(spaces[i-1][j]);
                spaces[i][j].setN(tempPtr);
            }
            if(spaces[i][j].E_link() != NULL)
            {
                tempPtr = ptrObject.ptr(spaces[i][j+1]);
                spaces[i][j].setE(tempPtr);
            }
            if(spaces[i][j].W_link() != NULL)
                spaces[i][j].setW(ptrObject.ptr(spaces[i][j-1]));
            if(spaces[i][j].S_link() != NULL)
                spaces[i][j].setS(ptrObject.ptr(spaces[i+1][j]));
            if(spaces[i][j].NE_link() != NULL)
                spaces[i][j].setNE(ptrObject.ptr(spaces[i-1][j+1]));
            if(spaces[i][j].NW_link() != NULL)
                spaces[i][j].setNW(ptrObject.ptr(spaces[i-1][j-1]));
            if(spaces[i][j].SW_link() != NULL)
                spaces[i][j].setSW(ptrObject.ptr(spaces[i+1][j-1]));
            if(spaces[i][j].SE_link() != NULL)
                spaces[i][j].setSE(ptrObject.ptr(spaces[i+1][j+1]));
        }
     spaces[3][3].setOwner(1);
     spaces[3][4].setOwner(2);
     spaces[4][3].setOwner(2);
     spaces[4][4].setOwner(1);
//     spaces[2][2].setOwner(2);
//     spaces[1][1].setOwner(2);
//     spaces[1][0].setOwner(1);
//     spaces[2][1].setOwner(1);
//     spaces[0][2].setOwner(2);
//     spaces[0][1].setOwner(2);
//     spaces[0][0].setOwner(1);
     updateGameboard();

}
void MainWindow ::updateGameboard()
{
    ui->widget1->setType(gameboard[0][0].getOwner());
    ui->widget2->setType(gameboard[0][1].getOwner());
    ui->widget3->setType(gameboard[0][2].getOwner());
    ui->widget4->setType(gameboard[0][3].getOwner());
    ui->widget5->setType(gameboard[0][4].getOwner());
    ui->widget6->setType(gameboard[0][5].getOwner());
    ui->widget7->setType(gameboard[0][6].getOwner());
    ui->widget8->setType(gameboard[0][7].getOwner());
    ui->widget9->setType(gameboard[1][0].getOwner());
    ui->widget10->setType(gameboard[1][1].getOwner());
    ui->widget11->setType(gameboard[1][2].getOwner());
    ui->widget12->setType(gameboard[1][3].getOwner());
    ui->widget13->setType(gameboard[1][4].getOwner());
    ui->widget14->setType(gameboard[1][5].getOwner());
    ui->widget15->setType(gameboard[1][6].getOwner());
    ui->widget16->setType(gameboard[1][7].getOwner());
    ui->widget17->setType(gameboard[2][0].getOwner());
    ui->widget18->setType(gameboard[2][1].getOwner());
    ui->widget19->setType(gameboard[2][2].getOwner());
    ui->widget20->setType(gameboard[2][3].getOwner());
    ui->widget21->setType(gameboard[2][4].getOwner());
    ui->widget22->setType(gameboard[2][5].getOwner());
    ui->widget23->setType(gameboard[2][6].getOwner());
    ui->widget24->setType(gameboard[2][7].getOwner());
    ui->widget25->setType(gameboard[3][0].getOwner());
    ui->widget26->setType(gameboard[3][1].getOwner());
    ui->widget27->setType(gameboard[3][2].getOwner());
    ui->widget28->setType(gameboard[3][3].getOwner());
    ui->widget29->setType(gameboard[3][4].getOwner());
    ui->widget30->setType(gameboard[3][5].getOwner());
    ui->widget31->setType(gameboard[3][6].getOwner());
    ui->widget32->setType(gameboard[3][7].getOwner());
    ui->widget33->setType(gameboard[4][0].getOwner());
    ui->widget34->setType(gameboard[4][1].getOwner());
    ui->widget35->setType(gameboard[4][2].getOwner());
    ui->widget36->setType(gameboard[4][3].getOwner());
    ui->widget37->setType(gameboard[4][4].getOwner());
    ui->widget38->setType(gameboard[4][5].getOwner());
    ui->widget39->setType(gameboard[4][6].getOwner());
    ui->widget40->setType(gameboard[4][7].getOwner());
    ui->widget41->setType(gameboard[5][0].getOwner());
    ui->widget42->setType(gameboard[5][1].getOwner());
    ui->widget43->setType(gameboard[5][2].getOwner());
    ui->widget44->setType(gameboard[5][3].getOwner());
    ui->widget45->setType(gameboard[5][4].getOwner());
    ui->widget46->setType(gameboard[5][5].getOwner());
    ui->widget47->setType(gameboard[5][6].getOwner());
    ui->widget48->setType(gameboard[5][7].getOwner());
    ui->widget49->setType(gameboard[6][0].getOwner());
    ui->widget50->setType(gameboard[6][1].getOwner());
    ui->widget51->setType(gameboard[6][2].getOwner());
    ui->widget52->setType(gameboard[6][3].getOwner());
    ui->widget53->setType(gameboard[6][4].getOwner());
    ui->widget54->setType(gameboard[6][5].getOwner());
    ui->widget55->setType(gameboard[6][6].getOwner());
    ui->widget56->setType(gameboard[6][7].getOwner());
    ui->widget57->setType(gameboard[7][0].getOwner());
    ui->widget58->setType(gameboard[7][1].getOwner());
    ui->widget59->setType(gameboard[7][2].getOwner());
    ui->widget60->setType(gameboard[7][3].getOwner());
    ui->widget61->setType(gameboard[7][4].getOwner());
    ui->widget62->setType(gameboard[7][5].getOwner());
    ui->widget63->setType(gameboard[7][6].getOwner());
    ui->widget64->setType(gameboard[7][7].getOwner());
    if(gameOver)
    {
        player = winner();
        if (player == 2)
        {
            ui->textBrowser->setText("Black Wins!");
            ui->textBrowser->setAlignment(Qt::AlignCenter);
        }

        if (player == 1)
        {
            ui->textBrowser->setText("White Wins!");
            ui->textBrowser->setAlignment(Qt::AlignCenter);
        }
        if (player == 0)
        {
            ui->textBrowser->setText("Its a Tie!");
            ui->textBrowser->setAlignment(Qt::AlignCenter);
            player = 1;
        }
     }
    else
    {
        if (player == 2)
        {
            ui->textBrowser->setText("Black's Turn");
            ui->textBrowser->setAlignment(Qt::AlignCenter);
        }

        if (player == 1)
        {
            ui->textBrowser->setText("White's Turn");
            ui->textBrowser->setAlignment(Qt::AlignCenter);
        }
    }
}
void MainWindow::initializeWID()
{
    ui->widget1->setXY(0,0);
    ui->widget2->setXY(0,1);
    ui->widget3->setXY(0,2);
    ui->widget4->setXY(0,3);
    ui->widget5->setXY(0,4);
    ui->widget6->setXY(0,5);
    ui->widget7->setXY(0,6);
    ui->widget8->setXY(0,7);
    ui->widget9->setXY(1,0);
    ui->widget10->setXY(1,1);
    ui->widget11->setXY(1,2);
    ui->widget12->setXY(1,3);
    ui->widget13->setXY(1,4);
    ui->widget14->setXY(1,5);
    ui->widget15->setXY(1,6);
    ui->widget16->setXY(1,7);
    ui->widget17->setXY(2,0);
    ui->widget18->setXY(2,1);
    ui->widget19->setXY(2,2);
    ui->widget20->setXY(2,3);
    ui->widget21->setXY(2,4);
    ui->widget22->setXY(2,5);
    ui->widget23->setXY(2,6);
    ui->widget24->setXY(2,7);
    ui->widget25->setXY(3,0);
    ui->widget26->setXY(3,1);
    ui->widget27->setXY(3,2);
    ui->widget28->setXY(3,3);
    ui->widget29->setXY(3,4);
    ui->widget30->setXY(3,5);
    ui->widget31->setXY(3,6);
    ui->widget32->setXY(3,7);
    ui->widget33->setXY(4,0);
    ui->widget34->setXY(4,1);
    ui->widget35->setXY(4,2);
    ui->widget36->setXY(4,3);
    ui->widget37->setXY(4,4);
    ui->widget38->setXY(4,5);
    ui->widget39->setXY(4,6);
    ui->widget40->setXY(4,7);
    ui->widget41->setXY(5,0);
    ui->widget42->setXY(5,1);
    ui->widget43->setXY(5,2);
    ui->widget44->setXY(5,3);
    ui->widget45->setXY(5,4);
    ui->widget46->setXY(5,5);
    ui->widget47->setXY(5,6);
    ui->widget48->setXY(5,7);
    ui->widget49->setXY(6,0);
    ui->widget50->setXY(6,1);
    ui->widget51->setXY(6,2);
    ui->widget52->setXY(6,3);
    ui->widget53->setXY(6,4);
    ui->widget54->setXY(6,5);
    ui->widget55->setXY(6,6);
    ui->widget56->setXY(6,7);
    ui->widget57->setXY(7,0);
    ui->widget58->setXY(7,1);
    ui->widget59->setXY(7,2);
    ui->widget60->setXY(7,3);
    ui->widget61->setXY(7,4);
    ui->widget62->setXY(7,5);
    ui->widget63->setXY(7,6);
    ui->widget64->setXY(7,7);

//    ui->widget28->setType(1);
//    ui->widget29->setType(2);
//    ui->widget36->setType(2);
//    ui->widget37->setType(1);

    connect(ui->widget1,SIGNAL(clickedSquare(int,int,int)),this,SLOT(squareClick(int,int,int)));
    connect(ui->widget2,SIGNAL(clickedSquare(int,int,int)),this,SLOT(squareClick(int,int,int)));
    connect(ui->widget3,SIGNAL(clickedSquare(int,int,int)),this,SLOT(squareClick(int,int,int)));
    connect(ui->widget4,SIGNAL(clickedSquare(int,int,int)),this,SLOT(squareClick(int,int,int)));
    connect(ui->widget5,SIGNAL(clickedSquare(int,int,int)),this,SLOT(squareClick(int,int,int)));
    connect(ui->widget6,SIGNAL(clickedSquare(int,int,int)),this,SLOT(squareClick(int,int,int)));
    connect(ui->widget7,SIGNAL(clickedSquare(int,int,int)),this,SLOT(squareClick(int,int,int)));
    connect(ui->widget8,SIGNAL(clickedSquare(int,int,int)),this,SLOT(squareClick(int,int,int)));
    connect(ui->widget9,SIGNAL(clickedSquare(int,int,int)),this,SLOT(squareClick(int,int,int)));
    connect(ui->widget10,SIGNAL(clickedSquare(int,int,int)),this,SLOT(squareClick(int,int,int)));
    connect(ui->widget11,SIGNAL(clickedSquare(int,int,int)),this,SLOT(squareClick(int,int,int)));
    connect(ui->widget12,SIGNAL(clickedSquare(int,int,int)),this,SLOT(squareClick(int,int,int)));
    connect(ui->widget13,SIGNAL(clickedSquare(int,int,int)),this,SLOT(squareClick(int,int,int)));
    connect(ui->widget14,SIGNAL(clickedSquare(int,int,int)),this,SLOT(squareClick(int,int,int)));
    connect(ui->widget15,SIGNAL(clickedSquare(int,int,int)),this,SLOT(squareClick(int,int,int)));
    connect(ui->widget16,SIGNAL(clickedSquare(int,int,int)),this,SLOT(squareClick(int,int,int)));
    connect(ui->widget17,SIGNAL(clickedSquare(int,int,int)),this,SLOT(squareClick(int,int,int)));
    connect(ui->widget18,SIGNAL(clickedSquare(int,int,int)),this,SLOT(squareClick(int,int,int)));
    connect(ui->widget19,SIGNAL(clickedSquare(int,int,int)),this,SLOT(squareClick(int,int,int)));
    connect(ui->widget20,SIGNAL(clickedSquare(int,int,int)),this,SLOT(squareClick(int,int,int)));
    connect(ui->widget21,SIGNAL(clickedSquare(int,int,int)),this,SLOT(squareClick(int,int,int)));
    connect(ui->widget22,SIGNAL(clickedSquare(int,int,int)),this,SLOT(squareClick(int,int,int)));
    connect(ui->widget23,SIGNAL(clickedSquare(int,int,int)),this,SLOT(squareClick(int,int,int)));
    connect(ui->widget24,SIGNAL(clickedSquare(int,int,int)),this,SLOT(squareClick(int,int,int)));
    connect(ui->widget25,SIGNAL(clickedSquare(int,int,int)),this,SLOT(squareClick(int,int,int)));
    connect(ui->widget26,SIGNAL(clickedSquare(int,int,int)),this,SLOT(squareClick(int,int,int)));
    connect(ui->widget27,SIGNAL(clickedSquare(int,int,int)),this,SLOT(squareClick(int,int,int)));
    connect(ui->widget28,SIGNAL(clickedSquare(int,int,int)),this,SLOT(squareClick(int,int,int)));
    connect(ui->widget29,SIGNAL(clickedSquare(int,int,int)),this,SLOT(squareClick(int,int,int)));
    connect(ui->widget30,SIGNAL(clickedSquare(int,int,int)),this,SLOT(squareClick(int,int,int)));
    connect(ui->widget31,SIGNAL(clickedSquare(int,int,int)),this,SLOT(squareClick(int,int,int)));
    connect(ui->widget32,SIGNAL(clickedSquare(int,int,int)),this,SLOT(squareClick(int,int,int)));
    connect(ui->widget33,SIGNAL(clickedSquare(int,int,int)),this,SLOT(squareClick(int,int,int)));
    connect(ui->widget34,SIGNAL(clickedSquare(int,int,int)),this,SLOT(squareClick(int,int,int)));
    connect(ui->widget35,SIGNAL(clickedSquare(int,int,int)),this,SLOT(squareClick(int,int,int)));
    connect(ui->widget36,SIGNAL(clickedSquare(int,int,int)),this,SLOT(squareClick(int,int,int)));
    connect(ui->widget37,SIGNAL(clickedSquare(int,int,int)),this,SLOT(squareClick(int,int,int)));
    connect(ui->widget38,SIGNAL(clickedSquare(int,int,int)),this,SLOT(squareClick(int,int,int)));
    connect(ui->widget39,SIGNAL(clickedSquare(int,int,int)),this,SLOT(squareClick(int,int,int)));
    connect(ui->widget40,SIGNAL(clickedSquare(int,int,int)),this,SLOT(squareClick(int,int,int)));
    connect(ui->widget41,SIGNAL(clickedSquare(int,int,int)),this,SLOT(squareClick(int,int,int)));
    connect(ui->widget42,SIGNAL(clickedSquare(int,int,int)),this,SLOT(squareClick(int,int,int)));
    connect(ui->widget43,SIGNAL(clickedSquare(int,int,int)),this,SLOT(squareClick(int,int,int)));
    connect(ui->widget44,SIGNAL(clickedSquare(int,int,int)),this,SLOT(squareClick(int,int,int)));
    connect(ui->widget45,SIGNAL(clickedSquare(int,int,int)),this,SLOT(squareClick(int,int,int)));
    connect(ui->widget46,SIGNAL(clickedSquare(int,int,int)),this,SLOT(squareClick(int,int,int)));
    connect(ui->widget47,SIGNAL(clickedSquare(int,int,int)),this,SLOT(squareClick(int,int,int)));
    connect(ui->widget48,SIGNAL(clickedSquare(int,int,int)),this,SLOT(squareClick(int,int,int)));
    connect(ui->widget49,SIGNAL(clickedSquare(int,int,int)),this,SLOT(squareClick(int,int,int)));
    connect(ui->widget50,SIGNAL(clickedSquare(int,int,int)),this,SLOT(squareClick(int,int,int)));
    connect(ui->widget51,SIGNAL(clickedSquare(int,int,int)),this,SLOT(squareClick(int,int,int)));
    connect(ui->widget52,SIGNAL(clickedSquare(int,int,int)),this,SLOT(squareClick(int,int,int)));
    connect(ui->widget53,SIGNAL(clickedSquare(int,int,int)),this,SLOT(squareClick(int,int,int)));
    connect(ui->widget54,SIGNAL(clickedSquare(int,int,int)),this,SLOT(squareClick(int,int,int)));
    connect(ui->widget55,SIGNAL(clickedSquare(int,int,int)),this,SLOT(squareClick(int,int,int)));
    connect(ui->widget56,SIGNAL(clickedSquare(int,int,int)),this,SLOT(squareClick(int,int,int)));
    connect(ui->widget57,SIGNAL(clickedSquare(int,int,int)),this,SLOT(squareClick(int,int,int)));
    connect(ui->widget58,SIGNAL(clickedSquare(int,int,int)),this,SLOT(squareClick(int,int,int)));
    connect(ui->widget59,SIGNAL(clickedSquare(int,int,int)),this,SLOT(squareClick(int,int,int)));
    connect(ui->widget60,SIGNAL(clickedSquare(int,int,int)),this,SLOT(squareClick(int,int,int)));
    connect(ui->widget61,SIGNAL(clickedSquare(int,int,int)),this,SLOT(squareClick(int,int,int)));
    connect(ui->widget62,SIGNAL(clickedSquare(int,int,int)),this,SLOT(squareClick(int,int,int)));
    connect(ui->widget63,SIGNAL(clickedSquare(int,int,int)),this,SLOT(squareClick(int,int,int)));
    connect(ui->widget64,SIGNAL(clickedSquare(int,int,int)),this,SLOT(squareClick(int,int,int)));

}


MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_2_clicked()
{
    initialize(gameboard);
    updateGameboard();

}
int MainWindow::winner()
{
  int player1 = 0,player2 = 0;
  for(int i=0;i<8;i++)
      for(int j=0;j<8;j++)
      {
          if(gameboard[i][j].getOwner() == 1)
             player1++;
          if(gameboard[i][j].getOwner() == 2)
            player2++;
      }
  gameOver = true;
  pass = 0;
  if(player1 > player2)
    return 1;
  if(player2 > player1)
    return 2;
  else
    return 0;
}

void MainWindow::on_pushButton_clicked()
{
    bool skip = true;
    passCheck = true;

    for(int i=0;i<8;i++)
        for(int j=0;j<8;j++)
        {
            if(flip(i,j))
            {
                skip = false;
            }
        }
    passCheck = false;
    if(skip)
    {
        pass=pass+1;
        if(!gameOver)playerFlip();          //fixed player1 player2 win shift
        if(pass == 2)
        winner();
        cout<<"winner";
        updateGameboard();
    }
    else
        ui->textBrowser->setText("Cannot Pass!");
        ui->textBrowser->setAlignment(Qt::AlignCenter);

}
void MainWindow::computer()
{
    //qDebug()<< "          In BEGGINING OF COMP gameboard at 4,2 = " << gameboard[4][2].getOwner();
    AI = true;
    player = 2;
    int highCount = 0;
    cout<<"CALLED COMPUTER()!!!!!!"<<endl;
    passCheck = true;
    count = 0;
    for(int i=0;i<8;i++)
        for(int j=0;j<8;j++)
        {
            if(flip(i,j))
            {
                gameboard[i][j].setCount(count);
                cout<< "      count        " << count << " xy =            " << j << " , " << i <<endl;
                count = 0;
            }
        }
    passCheck = false;
    //highCount = gameboard[0][0].getCount();
    //cout<<"highCount = "<<highCount<<endl;
    for(int i=0;i<8;i++)
        for(int j=0;j<8;j++)
        {
            if(highCount < gameboard[i][j].getCount())
            {
                highCount = gameboard[i][j].getCount();
                a = i;
                b = j;
            }
        }
    passCheck = false;
    //qDebug()<< "          in COMPUTER gameboard at 4,2 = " << gameboard[4][2].getOwner();

    cout<<"highCount = "<<highCount<<endl;
    cout<<"x = "<<b<<" y = "<<a<<endl;
    cout<<"                 computor out                ";
    if(highCount != 0)
       squareClickAi(a,b,0);
    if(highCount == 0)
        on_pushButton_clicked();
    for(int i = 0; i < 8; i ++)
        for(int j = 0; j< 8; j ++)
            gameboard[i][j].setCount(0);

}
void MainWindow::delayMoment()
{
    QTime moment= QTime::currentTime().addSecs(1);
    while( QTime::currentTime() < moment )
    QCoreApplication::processEvents(QEventLoop::AllEvents, 100);
}


void MainWindow::on_PvC_clicked()
{
    PvC = true;
    initialize(gameboard);

}

void MainWindow::on_PvP_clicked()
{
    PvC = false;
    initialize(gameboard);
}

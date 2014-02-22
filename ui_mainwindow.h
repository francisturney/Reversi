/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.0.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGraphicsView>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include "piece.h"

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionSave;
    QAction *actionOpen;
    QAction *actionPlayer_vs_Player;
    QAction *actionPlayer_vs_Computer;
    QAction *actionComputer_vs_Computer;
    QWidget *centralWidget;
    QGraphicsView *graphicsView;
    QFrame *frame;
    QVBoxLayout *verticalLayout;
    QTextBrowser *textBrowser;
    QSpacerItem *verticalSpacer_3;
    QPushButton *pushButton;
    QSpacerItem *verticalSpacer_4;
    QPushButton *pushButton_2;
    QSpacerItem *verticalSpacer;
    QWidget *gridLayoutWidget;
    QGridLayout *gridLayout;
    Piece *widget17;
    Piece *widget20;
    Piece *widget8;
    Piece *widget41;
    Piece *widget10;
    Piece *widget40;
    Piece *widget44;
    Piece *widget4;
    Piece *widget32;
    Piece *widget28;
    Piece *widget49;
    Piece *widget6;
    Piece *widget24;
    Piece *widget1;
    Piece *widget16;
    Piece *widget22;
    Piece *widget62;
    Piece *widget57;
    Piece *widget33;
    Piece *widget38;
    Piece *widget54;
    Piece *widget19;
    Piece *widget52;
    Piece *widget56;
    Piece *widget12;
    Piece *widget60;
    Piece *widget30;
    Piece *widget25;
    Piece *widget9;
    Piece *widget36;
    Piece *widget14;
    Piece *widget46;
    Piece *widget13;
    Piece *widget48;
    Piece *widget15;
    Piece *widget34;
    Piece *widget26;
    Piece *widget27;
    Piece *widget35;
    Piece *widget42;
    Piece *widget43;
    Piece *widget50;
    Piece *widget51;
    Piece *widget58;
    Piece *widget59;
    Piece *widget61;
    Piece *widget53;
    Piece *widget45;
    Piece *widget37;
    Piece *widget29;
    Piece *widget21;
    Piece *widget18;
    Piece *widget11;
    Piece *widget2;
    Piece *widget3;
    Piece *widget5;
    Piece *widget7;
    Piece *widget23;
    Piece *widget31;
    Piece *widget39;
    Piece *widget47;
    Piece *widget55;
    Piece *widget63;
    Piece *widget64;
    QMenuBar *menuBar;
    QMenu *menuOthello;
    QMenu *menuNew;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(718, 499);
        actionSave = new QAction(MainWindow);
        actionSave->setObjectName(QStringLiteral("actionSave"));
        actionOpen = new QAction(MainWindow);
        actionOpen->setObjectName(QStringLiteral("actionOpen"));
        actionPlayer_vs_Player = new QAction(MainWindow);
        actionPlayer_vs_Player->setObjectName(QStringLiteral("actionPlayer_vs_Player"));
        actionPlayer_vs_Computer = new QAction(MainWindow);
        actionPlayer_vs_Computer->setObjectName(QStringLiteral("actionPlayer_vs_Computer"));
        actionComputer_vs_Computer = new QAction(MainWindow);
        actionComputer_vs_Computer->setObjectName(QStringLiteral("actionComputer_vs_Computer"));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        graphicsView = new QGraphicsView(centralWidget);
        graphicsView->setObjectName(QStringLiteral("graphicsView"));
        graphicsView->setGeometry(QRect(10, 10, 403, 403));
        frame = new QFrame(centralWidget);
        frame->setObjectName(QStringLiteral("frame"));
        frame->setGeometry(QRect(420, 10, 231, 401));
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        verticalLayout = new QVBoxLayout(frame);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        textBrowser = new QTextBrowser(frame);
        textBrowser->setObjectName(QStringLiteral("textBrowser"));
        textBrowser->setMinimumSize(QSize(0, 6));
        textBrowser->setMaximumSize(QSize(16777215, 16777214));
        QFont font;
        font.setFamily(QStringLiteral("Terminal"));
        font.setPointSize(18);
        font.setBold(true);
        font.setWeight(75);
        textBrowser->setFont(font);

        verticalLayout->addWidget(textBrowser);

        verticalSpacer_3 = new QSpacerItem(208, 28, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer_3);

        pushButton = new QPushButton(frame);
        pushButton->setObjectName(QStringLiteral("pushButton"));

        verticalLayout->addWidget(pushButton);

        verticalSpacer_4 = new QSpacerItem(208, 18, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer_4);

        pushButton_2 = new QPushButton(frame);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));

        verticalLayout->addWidget(pushButton_2);

        verticalSpacer = new QSpacerItem(208, 78, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer);

        gridLayoutWidget = new QWidget(centralWidget);
        gridLayoutWidget->setObjectName(QStringLiteral("gridLayoutWidget"));
        gridLayoutWidget->setGeometry(QRect(10, 10, 401, 401));
        gridLayout = new QGridLayout(gridLayoutWidget);
        gridLayout->setSpacing(0);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        gridLayout->setSizeConstraint(QLayout::SetDefaultConstraint);
        gridLayout->setContentsMargins(0, 0, 0, 0);
        widget17 = new Piece(gridLayoutWidget);
        widget17->setObjectName(QStringLiteral("widget17"));

        gridLayout->addWidget(widget17, 4, 0, 1, 1);

        widget20 = new Piece(gridLayoutWidget);
        widget20->setObjectName(QStringLiteral("widget20"));

        gridLayout->addWidget(widget20, 4, 3, 1, 1);

        widget8 = new Piece(gridLayoutWidget);
        widget8->setObjectName(QStringLiteral("widget8"));

        gridLayout->addWidget(widget8, 2, 7, 1, 1);

        widget41 = new Piece(gridLayoutWidget);
        widget41->setObjectName(QStringLiteral("widget41"));

        gridLayout->addWidget(widget41, 7, 0, 1, 1);

        widget10 = new Piece(gridLayoutWidget);
        widget10->setObjectName(QStringLiteral("widget10"));

        gridLayout->addWidget(widget10, 3, 1, 1, 1);

        widget40 = new Piece(gridLayoutWidget);
        widget40->setObjectName(QStringLiteral("widget40"));

        gridLayout->addWidget(widget40, 6, 7, 1, 1);

        widget44 = new Piece(gridLayoutWidget);
        widget44->setObjectName(QStringLiteral("widget44"));

        gridLayout->addWidget(widget44, 7, 3, 1, 1);

        widget4 = new Piece(gridLayoutWidget);
        widget4->setObjectName(QStringLiteral("widget4"));

        gridLayout->addWidget(widget4, 2, 3, 1, 1);

        widget32 = new Piece(gridLayoutWidget);
        widget32->setObjectName(QStringLiteral("widget32"));

        gridLayout->addWidget(widget32, 5, 7, 1, 1);

        widget28 = new Piece(gridLayoutWidget);
        widget28->setObjectName(QStringLiteral("widget28"));

        gridLayout->addWidget(widget28, 5, 3, 1, 1);

        widget49 = new Piece(gridLayoutWidget);
        widget49->setObjectName(QStringLiteral("widget49"));

        gridLayout->addWidget(widget49, 8, 0, 1, 1);

        widget6 = new Piece(gridLayoutWidget);
        widget6->setObjectName(QStringLiteral("widget6"));

        gridLayout->addWidget(widget6, 2, 5, 1, 1);

        widget24 = new Piece(gridLayoutWidget);
        widget24->setObjectName(QStringLiteral("widget24"));

        gridLayout->addWidget(widget24, 4, 7, 1, 1);

        widget1 = new Piece(gridLayoutWidget);
        widget1->setObjectName(QStringLiteral("widget1"));
        widget1->setEnabled(true);
        QSizePolicy sizePolicy(QSizePolicy::Minimum, QSizePolicy::Minimum);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(widget1->sizePolicy().hasHeightForWidth());
        widget1->setSizePolicy(sizePolicy);
        widget1->setMaximumSize(QSize(16777215, 16777215));

        gridLayout->addWidget(widget1, 2, 0, 1, 1);

        widget16 = new Piece(gridLayoutWidget);
        widget16->setObjectName(QStringLiteral("widget16"));

        gridLayout->addWidget(widget16, 3, 7, 1, 1);

        widget22 = new Piece(gridLayoutWidget);
        widget22->setObjectName(QStringLiteral("widget22"));

        gridLayout->addWidget(widget22, 4, 5, 1, 1);

        widget62 = new Piece(gridLayoutWidget);
        widget62->setObjectName(QStringLiteral("widget62"));

        gridLayout->addWidget(widget62, 9, 5, 1, 1);

        widget57 = new Piece(gridLayoutWidget);
        widget57->setObjectName(QStringLiteral("widget57"));

        gridLayout->addWidget(widget57, 9, 0, 1, 1);

        widget33 = new Piece(gridLayoutWidget);
        widget33->setObjectName(QStringLiteral("widget33"));

        gridLayout->addWidget(widget33, 6, 0, 1, 1);

        widget38 = new Piece(gridLayoutWidget);
        widget38->setObjectName(QStringLiteral("widget38"));

        gridLayout->addWidget(widget38, 6, 5, 1, 1);

        widget54 = new Piece(gridLayoutWidget);
        widget54->setObjectName(QStringLiteral("widget54"));

        gridLayout->addWidget(widget54, 8, 5, 1, 1);

        widget19 = new Piece(gridLayoutWidget);
        widget19->setObjectName(QStringLiteral("widget19"));

        gridLayout->addWidget(widget19, 4, 2, 1, 1);

        widget52 = new Piece(gridLayoutWidget);
        widget52->setObjectName(QStringLiteral("widget52"));

        gridLayout->addWidget(widget52, 8, 3, 1, 1);

        widget56 = new Piece(gridLayoutWidget);
        widget56->setObjectName(QStringLiteral("widget56"));

        gridLayout->addWidget(widget56, 8, 7, 1, 1);

        widget12 = new Piece(gridLayoutWidget);
        widget12->setObjectName(QStringLiteral("widget12"));

        gridLayout->addWidget(widget12, 3, 3, 1, 1);

        widget60 = new Piece(gridLayoutWidget);
        widget60->setObjectName(QStringLiteral("widget60"));

        gridLayout->addWidget(widget60, 9, 3, 1, 1);

        widget30 = new Piece(gridLayoutWidget);
        widget30->setObjectName(QStringLiteral("widget30"));

        gridLayout->addWidget(widget30, 5, 5, 1, 1);

        widget25 = new Piece(gridLayoutWidget);
        widget25->setObjectName(QStringLiteral("widget25"));

        gridLayout->addWidget(widget25, 5, 0, 1, 1);

        widget9 = new Piece(gridLayoutWidget);
        widget9->setObjectName(QStringLiteral("widget9"));

        gridLayout->addWidget(widget9, 3, 0, 1, 1);

        widget36 = new Piece(gridLayoutWidget);
        widget36->setObjectName(QStringLiteral("widget36"));

        gridLayout->addWidget(widget36, 6, 3, 1, 1);

        widget14 = new Piece(gridLayoutWidget);
        widget14->setObjectName(QStringLiteral("widget14"));

        gridLayout->addWidget(widget14, 3, 5, 1, 1);

        widget46 = new Piece(gridLayoutWidget);
        widget46->setObjectName(QStringLiteral("widget46"));

        gridLayout->addWidget(widget46, 7, 5, 1, 1);

        widget13 = new Piece(gridLayoutWidget);
        widget13->setObjectName(QStringLiteral("widget13"));

        gridLayout->addWidget(widget13, 3, 4, 1, 1);

        widget48 = new Piece(gridLayoutWidget);
        widget48->setObjectName(QStringLiteral("widget48"));

        gridLayout->addWidget(widget48, 7, 7, 1, 1);

        widget15 = new Piece(gridLayoutWidget);
        widget15->setObjectName(QStringLiteral("widget15"));

        gridLayout->addWidget(widget15, 3, 6, 1, 1);

        widget34 = new Piece(gridLayoutWidget);
        widget34->setObjectName(QStringLiteral("widget34"));

        gridLayout->addWidget(widget34, 6, 1, 1, 1);

        widget26 = new Piece(gridLayoutWidget);
        widget26->setObjectName(QStringLiteral("widget26"));

        gridLayout->addWidget(widget26, 5, 1, 1, 1);

        widget27 = new Piece(gridLayoutWidget);
        widget27->setObjectName(QStringLiteral("widget27"));

        gridLayout->addWidget(widget27, 5, 2, 1, 1);

        widget35 = new Piece(gridLayoutWidget);
        widget35->setObjectName(QStringLiteral("widget35"));

        gridLayout->addWidget(widget35, 6, 2, 1, 1);

        widget42 = new Piece(gridLayoutWidget);
        widget42->setObjectName(QStringLiteral("widget42"));

        gridLayout->addWidget(widget42, 7, 1, 1, 1);

        widget43 = new Piece(gridLayoutWidget);
        widget43->setObjectName(QStringLiteral("widget43"));

        gridLayout->addWidget(widget43, 7, 2, 1, 1);

        widget50 = new Piece(gridLayoutWidget);
        widget50->setObjectName(QStringLiteral("widget50"));

        gridLayout->addWidget(widget50, 8, 1, 1, 1);

        widget51 = new Piece(gridLayoutWidget);
        widget51->setObjectName(QStringLiteral("widget51"));

        gridLayout->addWidget(widget51, 8, 2, 1, 1);

        widget58 = new Piece(gridLayoutWidget);
        widget58->setObjectName(QStringLiteral("widget58"));

        gridLayout->addWidget(widget58, 9, 1, 1, 1);

        widget59 = new Piece(gridLayoutWidget);
        widget59->setObjectName(QStringLiteral("widget59"));

        gridLayout->addWidget(widget59, 9, 2, 1, 1);

        widget61 = new Piece(gridLayoutWidget);
        widget61->setObjectName(QStringLiteral("widget61"));

        gridLayout->addWidget(widget61, 9, 4, 1, 1);

        widget53 = new Piece(gridLayoutWidget);
        widget53->setObjectName(QStringLiteral("widget53"));

        gridLayout->addWidget(widget53, 8, 4, 1, 1);

        widget45 = new Piece(gridLayoutWidget);
        widget45->setObjectName(QStringLiteral("widget45"));

        gridLayout->addWidget(widget45, 7, 4, 1, 1);

        widget37 = new Piece(gridLayoutWidget);
        widget37->setObjectName(QStringLiteral("widget37"));

        gridLayout->addWidget(widget37, 6, 4, 1, 1);

        widget29 = new Piece(gridLayoutWidget);
        widget29->setObjectName(QStringLiteral("widget29"));

        gridLayout->addWidget(widget29, 5, 4, 1, 1);

        widget21 = new Piece(gridLayoutWidget);
        widget21->setObjectName(QStringLiteral("widget21"));

        gridLayout->addWidget(widget21, 4, 4, 1, 1);

        widget18 = new Piece(gridLayoutWidget);
        widget18->setObjectName(QStringLiteral("widget18"));

        gridLayout->addWidget(widget18, 4, 1, 1, 1);

        widget11 = new Piece(gridLayoutWidget);
        widget11->setObjectName(QStringLiteral("widget11"));

        gridLayout->addWidget(widget11, 3, 2, 1, 1);

        widget2 = new Piece(gridLayoutWidget);
        widget2->setObjectName(QStringLiteral("widget2"));

        gridLayout->addWidget(widget2, 2, 1, 1, 1);

        widget3 = new Piece(gridLayoutWidget);
        widget3->setObjectName(QStringLiteral("widget3"));

        gridLayout->addWidget(widget3, 2, 2, 1, 1);

        widget5 = new Piece(gridLayoutWidget);
        widget5->setObjectName(QStringLiteral("widget5"));

        gridLayout->addWidget(widget5, 2, 4, 1, 1);

        widget7 = new Piece(gridLayoutWidget);
        widget7->setObjectName(QStringLiteral("widget7"));

        gridLayout->addWidget(widget7, 2, 6, 1, 1);

        widget23 = new Piece(gridLayoutWidget);
        widget23->setObjectName(QStringLiteral("widget23"));

        gridLayout->addWidget(widget23, 4, 6, 1, 1);

        widget31 = new Piece(gridLayoutWidget);
        widget31->setObjectName(QStringLiteral("widget31"));

        gridLayout->addWidget(widget31, 5, 6, 1, 1);

        widget39 = new Piece(gridLayoutWidget);
        widget39->setObjectName(QStringLiteral("widget39"));

        gridLayout->addWidget(widget39, 6, 6, 1, 1);

        widget47 = new Piece(gridLayoutWidget);
        widget47->setObjectName(QStringLiteral("widget47"));

        gridLayout->addWidget(widget47, 7, 6, 1, 1);

        widget55 = new Piece(gridLayoutWidget);
        widget55->setObjectName(QStringLiteral("widget55"));

        gridLayout->addWidget(widget55, 8, 6, 1, 1);

        widget63 = new Piece(gridLayoutWidget);
        widget63->setObjectName(QStringLiteral("widget63"));

        gridLayout->addWidget(widget63, 9, 6, 1, 1);

        widget64 = new Piece(gridLayoutWidget);
        widget64->setObjectName(QStringLiteral("widget64"));

        gridLayout->addWidget(widget64, 9, 7, 1, 1);

        MainWindow->setCentralWidget(centralWidget);
        graphicsView->raise();
        frame->raise();
        gridLayoutWidget->raise();
        textBrowser->raise();
        widget64->raise();
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 718, 21));
        menuOthello = new QMenu(menuBar);
        menuOthello->setObjectName(QStringLiteral("menuOthello"));
        menuNew = new QMenu(menuOthello);
        menuNew->setObjectName(QStringLiteral("menuNew"));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);

        menuBar->addAction(menuOthello->menuAction());
        menuOthello->addAction(actionSave);
        menuOthello->addAction(actionOpen);
        menuOthello->addAction(menuNew->menuAction());
        menuNew->addAction(actionPlayer_vs_Player);
        menuNew->addAction(actionPlayer_vs_Computer);
        menuNew->addAction(actionComputer_vs_Computer);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", 0));
        actionSave->setText(QApplication::translate("MainWindow", "Save", 0));
        actionOpen->setText(QApplication::translate("MainWindow", "Open", 0));
        actionPlayer_vs_Player->setText(QApplication::translate("MainWindow", "Player vs. Player", 0));
        actionPlayer_vs_Computer->setText(QApplication::translate("MainWindow", "Player vs. Computer", 0));
        actionComputer_vs_Computer->setText(QApplication::translate("MainWindow", "Computer vs. Computer", 0));
        textBrowser->setHtml(QApplication::translate("MainWindow", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'Terminal'; font-size:18pt; font-weight:600; font-style:normal;\">\n"
"<p align=\"center\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'MS Shell Dlg 2'; color:#b80119;\">Player 1</span></p>\n"
"<p align=\"center\" style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-family:'MS Shell Dlg 2'; color:#b80119;\"><br /></p></body></html>", 0));
        pushButton->setText(QApplication::translate("MainWindow", "Pass", 0));
        pushButton_2->setText(QApplication::translate("MainWindow", "Reset", 0));
        menuOthello->setTitle(QApplication::translate("MainWindow", "File", 0));
        menuNew->setTitle(QApplication::translate("MainWindow", "New", 0));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H

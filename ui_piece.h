/********************************************************************************
** Form generated from reading UI file 'piece.ui'
**
** Created by: Qt User Interface Compiler version 5.0.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PIECE_H
#define UI_PIECE_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Piece
{
public:

    void setupUi(QWidget *Piece)
    {
        if (Piece->objectName().isEmpty())
            Piece->setObjectName(QStringLiteral("Piece"));
        Piece->resize(400, 300);

        retranslateUi(Piece);

        QMetaObject::connectSlotsByName(Piece);
    } // setupUi

    void retranslateUi(QWidget *Piece)
    {
        Piece->setWindowTitle(QApplication::translate("Piece", "Form", 0));
    } // retranslateUi

};

namespace Ui {
    class Piece: public Ui_Piece {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PIECE_H

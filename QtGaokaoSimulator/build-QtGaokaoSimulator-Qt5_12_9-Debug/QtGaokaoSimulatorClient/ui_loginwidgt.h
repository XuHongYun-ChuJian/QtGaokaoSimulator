/********************************************************************************
** Form generated from reading UI file 'loginwidgt.ui'
**
** Created by: Qt User Interface Compiler version 5.12.9
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LOGINWIDGT_H
#define UI_LOGINWIDGT_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_LoginWidgt
{
public:
    QWidget *widget;
    QVBoxLayout *verticalLayout;
    QLabel *label_3;
    QSpacerItem *verticalSpacer_2;
    QGridLayout *gridLayout;
    QLineEdit *lineEdit;
    QLineEdit *lineEdit_2;
    QSpacerItem *verticalSpacer;
    QSpacerItem *horizontalSpacer_2;
    QPushButton *pushButton;
    QSpacerItem *horizontalSpacer;

    void setupUi(QWidget *LoginWidgt)
    {
        if (LoginWidgt->objectName().isEmpty())
            LoginWidgt->setObjectName(QString::fromUtf8("LoginWidgt"));
        LoginWidgt->resize(586, 491);
        widget = new QWidget(LoginWidgt);
        widget->setObjectName(QString::fromUtf8("widget"));
        widget->setGeometry(QRect(131, 120, 281, 251));
        verticalLayout = new QVBoxLayout(widget);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        label_3 = new QLabel(widget);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(label_3);

        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Fixed);

        verticalLayout->addItem(verticalSpacer_2);

        gridLayout = new QGridLayout();
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        lineEdit = new QLineEdit(widget);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));

        gridLayout->addWidget(lineEdit, 0, 0, 1, 1);

        lineEdit_2 = new QLineEdit(widget);
        lineEdit_2->setObjectName(QString::fromUtf8("lineEdit_2"));

        gridLayout->addWidget(lineEdit_2, 1, 0, 1, 1);


        verticalLayout->addLayout(gridLayout);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        verticalLayout->addItem(horizontalSpacer_2);

        pushButton = new QPushButton(widget);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));

        verticalLayout->addWidget(pushButton);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        verticalLayout->addItem(horizontalSpacer);


        retranslateUi(LoginWidgt);

        QMetaObject::connectSlotsByName(LoginWidgt);
    } // setupUi

    void retranslateUi(QWidget *LoginWidgt)
    {
        LoginWidgt->setWindowTitle(QApplication::translate("LoginWidgt", "Form", nullptr));
        label_3->setText(QApplication::translate("LoginWidgt", "<html><head/><body><p><span style=\" font-size:16pt; font-weight:600;\">\346\250\241\346\213\237\345\241\253\346\212\245\347\263\273\347\273\237\345\256\242\346\210\267\347\253\257</span></p></body></html>", nullptr));
        lineEdit->setInputMask(QApplication::translate("LoginWidgt", "\350\264\246\345\217\267", nullptr));
        lineEdit_2->setText(QString());
        pushButton->setText(QApplication::translate("LoginWidgt", "\347\231\273\345\275\225", nullptr));
    } // retranslateUi

};

namespace Ui {
    class LoginWidgt: public Ui_LoginWidgt {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LOGINWIDGT_H

/********************************************************************************
** Form generated from reading UI file 'signalwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.4.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SIGNALWINDOW_H
#define UI_SIGNALWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_SignalWindow
{
public:
    QWidget *centralWidget;

    void setupUi(QMainWindow *SignalWindow)
    {
        if (SignalWindow->objectName().isEmpty())
            SignalWindow->setObjectName(QStringLiteral("SignalWindow"));
        SignalWindow->resize(400, 300);
        centralWidget = new QWidget(SignalWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        SignalWindow->setCentralWidget(centralWidget);

        retranslateUi(SignalWindow);

        QMetaObject::connectSlotsByName(SignalWindow);
    } // setupUi

    void retranslateUi(QMainWindow *SignalWindow)
    {
        SignalWindow->setWindowTitle(QApplication::translate("SignalWindow", "SignalWindow", 0));
    } // retranslateUi

};

namespace Ui {
    class SignalWindow: public Ui_SignalWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SIGNALWINDOW_H

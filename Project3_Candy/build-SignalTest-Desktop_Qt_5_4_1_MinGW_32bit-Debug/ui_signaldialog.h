/********************************************************************************
** Form generated from reading UI file 'signaldialog.ui'
**
** Created by: Qt User Interface Compiler version 5.4.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SIGNALDIALOG_H
#define UI_SIGNALDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_SignalDialog
{
public:
    QVBoxLayout *verticalLayout;
    QLabel *label;
    QLabel *StarLabel;
    QLabel *ScoreLabel;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QPushButton *pushButton;
    QSpacerItem *horizontalSpacer_2;

    void setupUi(QDialog *SignalDialog)
    {
        if (SignalDialog->objectName().isEmpty())
            SignalDialog->setObjectName(QStringLiteral("SignalDialog"));
        SignalDialog->resize(357, 204);
        verticalLayout = new QVBoxLayout(SignalDialog);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        label = new QLabel(SignalDialog);
        label->setObjectName(QStringLiteral("label"));
        QFont font;
        font.setFamily(QStringLiteral("Consolas"));
        font.setPointSize(20);
        label->setFont(font);
        label->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(label);

        StarLabel = new QLabel(SignalDialog);
        StarLabel->setObjectName(QStringLiteral("StarLabel"));
        StarLabel->setFont(font);
        StarLabel->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(StarLabel);

        ScoreLabel = new QLabel(SignalDialog);
        ScoreLabel->setObjectName(QStringLiteral("ScoreLabel"));
        ScoreLabel->setFont(font);
        ScoreLabel->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(ScoreLabel);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        pushButton = new QPushButton(SignalDialog);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        QSizePolicy sizePolicy(QSizePolicy::Minimum, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(pushButton->sizePolicy().hasHeightForWidth());
        pushButton->setSizePolicy(sizePolicy);
        QFont font1;
        font1.setFamily(QStringLiteral("Consolas"));
        font1.setPointSize(14);
        pushButton->setFont(font1);

        horizontalLayout->addWidget(pushButton);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_2);


        verticalLayout->addLayout(horizontalLayout);


        retranslateUi(SignalDialog);

        QMetaObject::connectSlotsByName(SignalDialog);
    } // setupUi

    void retranslateUi(QDialog *SignalDialog)
    {
        SignalDialog->setWindowTitle(QApplication::translate("SignalDialog", "Dialog", 0));
        label->setText(QApplication::translate("SignalDialog", "Quit Signal", 0));
        StarLabel->setText(QApplication::translate("SignalDialog", "Star:", 0));
        ScoreLabel->setText(QApplication::translate("SignalDialog", "Score:", 0));
        pushButton->setText(QApplication::translate("SignalDialog", "Exit", 0));
    } // retranslateUi

};

namespace Ui {
    class SignalDialog: public Ui_SignalDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SIGNALDIALOG_H

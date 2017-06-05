/********************************************************************************
** Form generated from reading UI file 'Form.ui'
**
** Created by: Qt User Interface Compiler version 5.5.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FORM_H
#define UI_FORM_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MyForm
{
public:
    QVBoxLayout *verticalLayout_5;
    QVBoxLayout *verticalLayout_4;
    QVBoxLayout *verticalLayout_3;
    QHBoxLayout *horizontalLayout_2;
    QFrame *frame;
    QVBoxLayout *verticalLayout;
    QRadioButton *Vermell;
    QRadioButton *Verd;
    QRadioButton *Blau;
    QFrame *frame_2;
    QVBoxLayout *verticalLayout_2;
    QLabel *labelVermell;
    QLabel *labelVerd;
    QLabel *labelBlau;
    QSpacerItem *verticalSpacer;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QPushButton *pushButton;

    void setupUi(QWidget *MyForm)
    {
        if (MyForm->objectName().isEmpty())
            MyForm->setObjectName(QStringLiteral("MyForm"));
        MyForm->resize(342, 204);
        verticalLayout_5 = new QVBoxLayout(MyForm);
        verticalLayout_5->setObjectName(QStringLiteral("verticalLayout_5"));
        verticalLayout_4 = new QVBoxLayout();
        verticalLayout_4->setObjectName(QStringLiteral("verticalLayout_4"));
        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        frame = new QFrame(MyForm);
        frame->setObjectName(QStringLiteral("frame"));
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        verticalLayout = new QVBoxLayout(frame);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        Vermell = new QRadioButton(frame);
        Vermell->setObjectName(QStringLiteral("Vermell"));

        verticalLayout->addWidget(Vermell);

        Verd = new QRadioButton(frame);
        Verd->setObjectName(QStringLiteral("Verd"));

        verticalLayout->addWidget(Verd);

        Blau = new QRadioButton(frame);
        Blau->setObjectName(QStringLiteral("Blau"));

        verticalLayout->addWidget(Blau);


        horizontalLayout_2->addWidget(frame);

        frame_2 = new QFrame(MyForm);
        frame_2->setObjectName(QStringLiteral("frame_2"));
        frame_2->setFrameShape(QFrame::StyledPanel);
        frame_2->setFrameShadow(QFrame::Raised);
        verticalLayout_2 = new QVBoxLayout(frame_2);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        labelVermell = new QLabel(frame_2);
        labelVermell->setObjectName(QStringLiteral("labelVermell"));
        labelVermell->setEnabled(false);
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(labelVermell->sizePolicy().hasHeightForWidth());
        labelVermell->setSizePolicy(sizePolicy);
        labelVermell->setStyleSheet(QStringLiteral("background-color: rgb(255,0,0);"));

        verticalLayout_2->addWidget(labelVermell);

        labelVerd = new QLabel(frame_2);
        labelVerd->setObjectName(QStringLiteral("labelVerd"));
        labelVerd->setEnabled(false);
        sizePolicy.setHeightForWidth(labelVerd->sizePolicy().hasHeightForWidth());
        labelVerd->setSizePolicy(sizePolicy);
        labelVerd->setAutoFillBackground(false);
        labelVerd->setStyleSheet(QStringLiteral("background-color: rgb(0,255,0);"));

        verticalLayout_2->addWidget(labelVerd);

        labelBlau = new QLabel(frame_2);
        labelBlau->setObjectName(QStringLiteral("labelBlau"));
        sizePolicy.setHeightForWidth(labelBlau->sizePolicy().hasHeightForWidth());
        labelBlau->setSizePolicy(sizePolicy);
        labelBlau->setAutoFillBackground(false);
        labelBlau->setStyleSheet(QStringLiteral("background-color: blue;"));

        verticalLayout_2->addWidget(labelBlau);


        horizontalLayout_2->addWidget(frame_2);


        verticalLayout_3->addLayout(horizontalLayout_2);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Fixed);

        verticalLayout_3->addItem(verticalSpacer);


        verticalLayout_4->addLayout(verticalLayout_3);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        pushButton = new QPushButton(MyForm);
        pushButton->setObjectName(QStringLiteral("pushButton"));

        horizontalLayout->addWidget(pushButton);


        verticalLayout_4->addLayout(horizontalLayout);


        verticalLayout_5->addLayout(verticalLayout_4);


        retranslateUi(MyForm);
        QObject::connect(pushButton, SIGNAL(clicked()), MyForm, SLOT(close()));
        QObject::connect(Vermell, SIGNAL(clicked(bool)), labelVermell, SLOT(setEnabled(bool)));
        QObject::connect(Verd, SIGNAL(clicked(bool)), labelVerd, SLOT(setEnabled(bool)));
        QObject::connect(Blau, SIGNAL(clicked(bool)), labelBlau, SLOT(setEnabled(bool)));
        QObject::connect(Vermell, SIGNAL(clicked(bool)), labelBlau, SLOT(setDisabled(bool)));
        QObject::connect(Vermell, SIGNAL(clicked(bool)), labelVerd, SLOT(setDisabled(bool)));

        QMetaObject::connectSlotsByName(MyForm);
    } // setupUi

    void retranslateUi(QWidget *MyForm)
    {
        MyForm->setWindowTitle(QApplication::translate("MyForm", "Form", 0));
        Vermell->setText(QApplication::translate("MyForm", "Vermell", 0));
        Verd->setText(QApplication::translate("MyForm", "Verd", 0));
        Blau->setText(QApplication::translate("MyForm", "Blau", 0));
        labelVermell->setText(QApplication::translate("MyForm", "Vermell", 0));
        labelVerd->setText(QApplication::translate("MyForm", "Verd", 0));
        labelBlau->setText(QApplication::translate("MyForm", "Blau", 0));
        pushButton->setText(QApplication::translate("MyForm", "&Sortir", 0));
    } // retranslateUi

};

namespace Ui {
    class MyForm: public Ui_MyForm {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FORM_H

/********************************************************************************
** Form generated from reading UI file 'MyForm.ui'
**
** Created by: Qt User Interface Compiler version 5.5.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MYFORM_H
#define UI_MYFORM_H

#include <MyGLWidget.h>
#include <MyLabel.h>
#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDial>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MyForm
{
public:
    QHBoxLayout *horizontalLayout_4;
    MyGLWidget *widget;
    QVBoxLayout *verticalLayout_5;
    QSpacerItem *verticalSpacer_2;
    QGroupBox *groupBox;
    QVBoxLayout *verticalLayout;
    QRadioButton *radioButton;
    QRadioButton *radioButton_2;
    QVBoxLayout *verticalLayout_2;
    QLabel *label;
    QSlider *horizontalSlider;
    QSpinBox *spinBox;
    QGroupBox *groupBox_2;
    QVBoxLayout *verticalLayout_3;
    QRadioButton *radioButton_3;
    QRadioButton *radioButton_4;
    QGroupBox *groupBox_3;
    QHBoxLayout *horizontalLayout_2;
    QDial *dial;
    QDial *dial_2;
    QVBoxLayout *verticalLayout_4;
    MyLabel *label_2;
    QHBoxLayout *horizontalLayout_3;
    QSpinBox *spinBox_2;
    QSpinBox *spinBox_3;
    QSpinBox *spinBox_4;
    QSpacerItem *verticalSpacer;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QPushButton *pushButton;

    void setupUi(QWidget *MyForm)
    {
        if (MyForm->objectName().isEmpty())
            MyForm->setObjectName(QStringLiteral("MyForm"));
        MyForm->resize(795, 726);
        horizontalLayout_4 = new QHBoxLayout(MyForm);
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        widget = new MyGLWidget(MyForm);
        widget->setObjectName(QStringLiteral("widget"));
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(widget->sizePolicy().hasHeightForWidth());
        widget->setSizePolicy(sizePolicy);

        horizontalLayout_4->addWidget(widget);

        verticalLayout_5 = new QVBoxLayout();
        verticalLayout_5->setObjectName(QStringLiteral("verticalLayout_5"));
        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_5->addItem(verticalSpacer_2);

        groupBox = new QGroupBox(MyForm);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        verticalLayout = new QVBoxLayout(groupBox);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        radioButton = new QRadioButton(groupBox);
        radioButton->setObjectName(QStringLiteral("radioButton"));
        radioButton->setChecked(true);

        verticalLayout->addWidget(radioButton);

        radioButton_2 = new QRadioButton(groupBox);
        radioButton_2->setObjectName(QStringLiteral("radioButton_2"));

        verticalLayout->addWidget(radioButton_2);


        verticalLayout_5->addWidget(groupBox);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        label = new QLabel(MyForm);
        label->setObjectName(QStringLiteral("label"));

        verticalLayout_2->addWidget(label);

        horizontalSlider = new QSlider(MyForm);
        horizontalSlider->setObjectName(QStringLiteral("horizontalSlider"));
        QSizePolicy sizePolicy1(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(horizontalSlider->sizePolicy().hasHeightForWidth());
        horizontalSlider->setSizePolicy(sizePolicy1);
        horizontalSlider->setMinimum(15);
        horizontalSlider->setMaximum(60);
        horizontalSlider->setSliderPosition(30);
        horizontalSlider->setOrientation(Qt::Horizontal);

        verticalLayout_2->addWidget(horizontalSlider);

        spinBox = new QSpinBox(MyForm);
        spinBox->setObjectName(QStringLiteral("spinBox"));
        QSizePolicy sizePolicy2(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(spinBox->sizePolicy().hasHeightForWidth());
        spinBox->setSizePolicy(sizePolicy2);
        spinBox->setMinimum(15);
        spinBox->setMaximum(90);
        spinBox->setValue(30);

        verticalLayout_2->addWidget(spinBox);


        verticalLayout_5->addLayout(verticalLayout_2);

        groupBox_2 = new QGroupBox(MyForm);
        groupBox_2->setObjectName(QStringLiteral("groupBox_2"));
        verticalLayout_3 = new QVBoxLayout(groupBox_2);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        radioButton_3 = new QRadioButton(groupBox_2);
        radioButton_3->setObjectName(QStringLiteral("radioButton_3"));
        radioButton_3->setChecked(true);

        verticalLayout_3->addWidget(radioButton_3);

        radioButton_4 = new QRadioButton(groupBox_2);
        radioButton_4->setObjectName(QStringLiteral("radioButton_4"));

        verticalLayout_3->addWidget(radioButton_4);


        verticalLayout_5->addWidget(groupBox_2);

        groupBox_3 = new QGroupBox(MyForm);
        groupBox_3->setObjectName(QStringLiteral("groupBox_3"));
        QSizePolicy sizePolicy3(QSizePolicy::Minimum, QSizePolicy::Preferred);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(groupBox_3->sizePolicy().hasHeightForWidth());
        groupBox_3->setSizePolicy(sizePolicy3);
        horizontalLayout_2 = new QHBoxLayout(groupBox_3);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        dial = new QDial(groupBox_3);
        dial->setObjectName(QStringLiteral("dial"));
        sizePolicy2.setHeightForWidth(dial->sizePolicy().hasHeightForWidth());
        dial->setSizePolicy(sizePolicy2);
        dial->setMaximum(360);

        horizontalLayout_2->addWidget(dial);

        dial_2 = new QDial(groupBox_3);
        dial_2->setObjectName(QStringLiteral("dial_2"));
        sizePolicy3.setHeightForWidth(dial_2->sizePolicy().hasHeightForWidth());
        dial_2->setSizePolicy(sizePolicy3);
        dial_2->setMaximum(360);

        horizontalLayout_2->addWidget(dial_2);


        verticalLayout_5->addWidget(groupBox_3);

        verticalLayout_4 = new QVBoxLayout();
        verticalLayout_4->setObjectName(QStringLiteral("verticalLayout_4"));
        label_2 = new MyLabel(MyForm);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setAutoFillBackground(true);

        verticalLayout_4->addWidget(label_2);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        spinBox_2 = new QSpinBox(MyForm);
        spinBox_2->setObjectName(QStringLiteral("spinBox_2"));
        spinBox_2->setMaximum(255);

        horizontalLayout_3->addWidget(spinBox_2);

        spinBox_3 = new QSpinBox(MyForm);
        spinBox_3->setObjectName(QStringLiteral("spinBox_3"));
        spinBox_3->setMaximum(255);

        horizontalLayout_3->addWidget(spinBox_3);

        spinBox_4 = new QSpinBox(MyForm);
        spinBox_4->setObjectName(QStringLiteral("spinBox_4"));
        spinBox_4->setMaximum(255);

        horizontalLayout_3->addWidget(spinBox_4);


        verticalLayout_4->addLayout(horizontalLayout_3);


        verticalLayout_5->addLayout(verticalLayout_4);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_5->addItem(verticalSpacer);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Minimum, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        pushButton = new QPushButton(MyForm);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        sizePolicy2.setHeightForWidth(pushButton->sizePolicy().hasHeightForWidth());
        pushButton->setSizePolicy(sizePolicy2);

        horizontalLayout->addWidget(pushButton);


        verticalLayout_5->addLayout(horizontalLayout);


        horizontalLayout_4->addLayout(verticalLayout_5);


        retranslateUi(MyForm);
        QObject::connect(pushButton, SIGNAL(clicked()), MyForm, SLOT(close()));
        QObject::connect(horizontalSlider, SIGNAL(sliderMoved(int)), spinBox, SLOT(setValue(int)));
        QObject::connect(spinBox, SIGNAL(valueChanged(int)), horizontalSlider, SLOT(setValue(int)));
        QObject::connect(horizontalSlider, SIGNAL(sliderMoved(int)), widget, SLOT(repAngleZoom(int)));
        QObject::connect(spinBox, SIGNAL(valueChanged(int)), widget, SLOT(repAngleZoom(int)));
        QObject::connect(radioButton, SIGNAL(clicked(bool)), widget, SLOT(repModelPatr(bool)));
        QObject::connect(radioButton_2, SIGNAL(clicked(bool)), widget, SLOT(repModelLego(bool)));
        QObject::connect(radioButton_3, SIGNAL(clicked(bool)), widget, SLOT(repCameraPersp(bool)));
        QObject::connect(radioButton_4, SIGNAL(clicked(bool)), widget, SLOT(repCameraOrt(bool)));
        QObject::connect(dial, SIGNAL(valueChanged(int)), widget, SLOT(repAngleX(int)));
        QObject::connect(dial_2, SIGNAL(valueChanged(int)), widget, SLOT(repAngleY(int)));
        QObject::connect(widget, SIGNAL(enviaAngleX(int)), dial, SLOT(setValue(int)));
        QObject::connect(widget, SIGNAL(enviaAngleY(int)), dial_2, SLOT(setValue(int)));
        QObject::connect(spinBox_2, SIGNAL(valueChanged(int)), label_2, SLOT(setColorR(int)));
        QObject::connect(spinBox_3, SIGNAL(valueChanged(int)), label_2, SLOT(setColorG(int)));
        QObject::connect(spinBox_4, SIGNAL(valueChanged(int)), label_2, SLOT(setColorB(int)));
        QObject::connect(spinBox_2, SIGNAL(valueChanged(int)), widget, SLOT(repColorR(int)));
        QObject::connect(spinBox_3, SIGNAL(valueChanged(int)), widget, SLOT(repColorG(int)));
        QObject::connect(spinBox_4, SIGNAL(valueChanged(int)), widget, SLOT(repColorB(int)));

        QMetaObject::connectSlotsByName(MyForm);
    } // setupUi

    void retranslateUi(QWidget *MyForm)
    {
        MyForm->setWindowTitle(QApplication::translate("MyForm", "Form", 0));
        groupBox->setTitle(QApplication::translate("MyForm", "Models", 0));
        radioButton->setText(QApplication::translate("MyForm", "Patricio", 0));
        radioButton_2->setText(QApplication::translate("MyForm", "Legoman", 0));
        label->setText(QApplication::translate("MyForm", "Angle Zoom \302\272", 0));
        groupBox_2->setTitle(QApplication::translate("MyForm", "Camera", 0));
        radioButton_3->setText(QApplication::translate("MyForm", "Perspectiva", 0));
        radioButton_4->setText(QApplication::translate("MyForm", "Ortogonal", 0));
        groupBox_3->setTitle(QApplication::translate("MyForm", "Angles Euler (X i Y)", 0));
        label_2->setText(QApplication::translate("MyForm", "Color Terra (R,G,B)", 0));
        pushButton->setText(QApplication::translate("MyForm", "&Sortir", 0));
    } // retranslateUi

};

namespace Ui {
    class MyForm: public Ui_MyForm {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MYFORM_H

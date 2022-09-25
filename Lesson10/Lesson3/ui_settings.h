/********************************************************************************
** Form generated from reading UI file 'settings.ui'
**
** Created by: Qt User Interface Compiler version 5.12.12
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SETTINGS_H
#define UI_SETTINGS_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTableView>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_Settings
{
public:
    QGridLayout *gridLayout;
    QHBoxLayout *horizontalLayout_3;
    QSpacerItem *horizontalSpacer;
    QPushButton *pushButtonOk;
    QGroupBox *groupBoxLang;
    QVBoxLayout *verticalLayout_5;
    QVBoxLayout *verticalLayout;
    QRadioButton *radioButtonRu;
    QRadioButton *radioButtonEng;
    QGroupBox *groupBoxScheme;
    QVBoxLayout *verticalLayout_4;
    QVBoxLayout *verticalLayout_2;
    QRadioButton *radioButtonDark;
    QRadioButton *radioButtonLight;
    QVBoxLayout *verticalLayout_3;
    QLabel *labelHotKeys;
    QHBoxLayout *horizontalLayout;
    QTableView *tableView;

    void setupUi(QDialog *Settings)
    {
        if (Settings->objectName().isEmpty())
            Settings->setObjectName(QString::fromUtf8("Settings"));
        Settings->resize(562, 353);
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(Settings->sizePolicy().hasHeightForWidth());
        Settings->setSizePolicy(sizePolicy);
        gridLayout = new QGridLayout(Settings);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        horizontalLayout_3->setContentsMargins(-1, 0, -1, -1);
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer);

        pushButtonOk = new QPushButton(Settings);
        pushButtonOk->setObjectName(QString::fromUtf8("pushButtonOk"));
        QSizePolicy sizePolicy1(QSizePolicy::Minimum, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(pushButtonOk->sizePolicy().hasHeightForWidth());
        pushButtonOk->setSizePolicy(sizePolicy1);

        horizontalLayout_3->addWidget(pushButtonOk);


        gridLayout->addLayout(horizontalLayout_3, 2, 0, 1, 2);

        groupBoxLang = new QGroupBox(Settings);
        groupBoxLang->setObjectName(QString::fromUtf8("groupBoxLang"));
        verticalLayout_5 = new QVBoxLayout(groupBoxLang);
        verticalLayout_5->setObjectName(QString::fromUtf8("verticalLayout_5"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        radioButtonRu = new QRadioButton(groupBoxLang);
        radioButtonRu->setObjectName(QString::fromUtf8("radioButtonRu"));
        sizePolicy1.setHeightForWidth(radioButtonRu->sizePolicy().hasHeightForWidth());
        radioButtonRu->setSizePolicy(sizePolicy1);

        verticalLayout->addWidget(radioButtonRu);

        radioButtonEng = new QRadioButton(groupBoxLang);
        radioButtonEng->setObjectName(QString::fromUtf8("radioButtonEng"));
        sizePolicy1.setHeightForWidth(radioButtonEng->sizePolicy().hasHeightForWidth());
        radioButtonEng->setSizePolicy(sizePolicy1);

        verticalLayout->addWidget(radioButtonEng);


        verticalLayout_5->addLayout(verticalLayout);


        gridLayout->addWidget(groupBoxLang, 0, 0, 1, 1);

        groupBoxScheme = new QGroupBox(Settings);
        groupBoxScheme->setObjectName(QString::fromUtf8("groupBoxScheme"));
        verticalLayout_4 = new QVBoxLayout(groupBoxScheme);
        verticalLayout_4->setObjectName(QString::fromUtf8("verticalLayout_4"));
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        radioButtonDark = new QRadioButton(groupBoxScheme);
        radioButtonDark->setObjectName(QString::fromUtf8("radioButtonDark"));
        sizePolicy1.setHeightForWidth(radioButtonDark->sizePolicy().hasHeightForWidth());
        radioButtonDark->setSizePolicy(sizePolicy1);

        verticalLayout_2->addWidget(radioButtonDark);

        radioButtonLight = new QRadioButton(groupBoxScheme);
        radioButtonLight->setObjectName(QString::fromUtf8("radioButtonLight"));
        sizePolicy1.setHeightForWidth(radioButtonLight->sizePolicy().hasHeightForWidth());
        radioButtonLight->setSizePolicy(sizePolicy1);

        verticalLayout_2->addWidget(radioButtonLight);


        verticalLayout_4->addLayout(verticalLayout_2);


        gridLayout->addWidget(groupBoxScheme, 0, 1, 1, 1);

        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        verticalLayout_3->setContentsMargins(-1, 9, -1, -1);
        labelHotKeys = new QLabel(Settings);
        labelHotKeys->setObjectName(QString::fromUtf8("labelHotKeys"));
        QSizePolicy sizePolicy2(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(labelHotKeys->sizePolicy().hasHeightForWidth());
        labelHotKeys->setSizePolicy(sizePolicy2);

        verticalLayout_3->addWidget(labelHotKeys);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        tableView = new QTableView(Settings);
        tableView->setObjectName(QString::fromUtf8("tableView"));
        QSizePolicy sizePolicy3(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(tableView->sizePolicy().hasHeightForWidth());
        tableView->setSizePolicy(sizePolicy3);

        horizontalLayout->addWidget(tableView);


        verticalLayout_3->addLayout(horizontalLayout);


        gridLayout->addLayout(verticalLayout_3, 1, 0, 1, 2);


        retranslateUi(Settings);

        QMetaObject::connectSlotsByName(Settings);
    } // setupUi

    void retranslateUi(QDialog *Settings)
    {
        Settings->setWindowTitle(QApplication::translate("Settings", "Dialog", nullptr));
        pushButtonOk->setText(QApplication::translate("Settings", "PushButton", nullptr));
        groupBoxLang->setTitle(QApplication::translate("Settings", "GroupBox", nullptr));
        radioButtonRu->setText(QApplication::translate("Settings", "RadioButton", nullptr));
        radioButtonEng->setText(QApplication::translate("Settings", "RadioButton", nullptr));
        groupBoxScheme->setTitle(QApplication::translate("Settings", "GroupBox", nullptr));
        radioButtonDark->setText(QApplication::translate("Settings", "RadioButton", nullptr));
        radioButtonLight->setText(QApplication::translate("Settings", "RadioButton", nullptr));
        labelHotKeys->setText(QApplication::translate("Settings", "TextLabel", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Settings: public Ui_Settings {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SETTINGS_H

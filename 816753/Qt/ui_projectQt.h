/********************************************************************************
** Form generated from reading UI file 'projectQt.ui'
**
** Created by: Qt User Interface Compiler version 5.12.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PROJECTQT_H
#define UI_PROJECTQT_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ProjectQt
{
public:
    QWidget *centralWidget;
    QWidget *gridLayoutWidget_2;
    QGridLayout *gridLayout_3;
    QHBoxLayout *horizontalLayout;
    QGridLayout *gridLayout_2;
    QLineEdit *lineEditEmail;
    QLineEdit *lineEditPassword;
    QLabel *label_3;
    QLabel *label_2;
    QPushButton *pushButtonAccess;
    QGridLayout *gridLayout;
    QLabel *label;
    QPushButton *pushButtonRecovery;
    QVBoxLayout *verticalLayout;
    QGridLayout *gridLayout_4;
    QLineEdit *lineEditNewSurname;
    QLineEdit *lineEditNewName;
    QLineEdit *lineEditNewEmail;
    QLineEdit *lineEditNewPassword;
    QHBoxLayout *horizontalLayout_3;
    QVBoxLayout *verticalLayout_3;
    QLabel *label_4;
    QHBoxLayout *horizontalLayout_2;
    QSpinBox *spinBoxDay;
    QSpinBox *spinBoxMonth;
    QSpinBox *spinBoxYear;
    QVBoxLayout *verticalLayout_2;
    QRadioButton *radioButtonMan;
    QRadioButton *radioButtonWoman;
    QFrame *line;
    QPushButton *pushButtonSubmit;
    QStatusBar *statusBar;
    QToolBar *mainToolBar;

    void setupUi(QMainWindow *ProjectQt)
    {
        if (ProjectQt->objectName().isEmpty())
            ProjectQt->setObjectName(QString::fromUtf8("ProjectQt"));
        ProjectQt->setWindowModality(Qt::NonModal);
        ProjectQt->setEnabled(true);
        ProjectQt->resize(600, 450);
        QSizePolicy sizePolicy(QSizePolicy::Maximum, QSizePolicy::Maximum);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(ProjectQt->sizePolicy().hasHeightForWidth());
        ProjectQt->setSizePolicy(sizePolicy);
        ProjectQt->setMinimumSize(QSize(467, 390));
        ProjectQt->setMaximumSize(QSize(600, 450));
        QPalette palette;
        QBrush brush(QColor(0, 0, 0, 255));
        brush.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::WindowText, brush);
        QBrush brush1(QColor(211, 215, 207, 255));
        brush1.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Button, brush1);
        QBrush brush2(QColor(255, 255, 255, 255));
        brush2.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Light, brush2);
        QBrush brush3(QColor(233, 235, 231, 255));
        brush3.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Midlight, brush3);
        QBrush brush4(QColor(105, 107, 103, 255));
        brush4.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Dark, brush4);
        QBrush brush5(QColor(141, 143, 138, 255));
        brush5.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Mid, brush5);
        palette.setBrush(QPalette::Active, QPalette::Text, brush);
        palette.setBrush(QPalette::Active, QPalette::BrightText, brush2);
        palette.setBrush(QPalette::Active, QPalette::ButtonText, brush);
        palette.setBrush(QPalette::Active, QPalette::Base, brush2);
        palette.setBrush(QPalette::Active, QPalette::Window, brush1);
        palette.setBrush(QPalette::Active, QPalette::Shadow, brush);
        palette.setBrush(QPalette::Active, QPalette::AlternateBase, brush3);
        QBrush brush6(QColor(255, 255, 220, 255));
        brush6.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::ToolTipBase, brush6);
        palette.setBrush(QPalette::Active, QPalette::ToolTipText, brush);
        QBrush brush7(QColor(0, 0, 0, 128));
        brush7.setStyle(Qt::SolidPattern);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette.setBrush(QPalette::Active, QPalette::PlaceholderText, brush7);
#endif
        palette.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        palette.setBrush(QPalette::Inactive, QPalette::Button, brush1);
        palette.setBrush(QPalette::Inactive, QPalette::Light, brush2);
        palette.setBrush(QPalette::Inactive, QPalette::Midlight, brush3);
        palette.setBrush(QPalette::Inactive, QPalette::Dark, brush4);
        palette.setBrush(QPalette::Inactive, QPalette::Mid, brush5);
        palette.setBrush(QPalette::Inactive, QPalette::Text, brush);
        palette.setBrush(QPalette::Inactive, QPalette::BrightText, brush2);
        palette.setBrush(QPalette::Inactive, QPalette::ButtonText, brush);
        palette.setBrush(QPalette::Inactive, QPalette::Base, brush2);
        palette.setBrush(QPalette::Inactive, QPalette::Window, brush1);
        palette.setBrush(QPalette::Inactive, QPalette::Shadow, brush);
        palette.setBrush(QPalette::Inactive, QPalette::AlternateBase, brush3);
        palette.setBrush(QPalette::Inactive, QPalette::ToolTipBase, brush6);
        palette.setBrush(QPalette::Inactive, QPalette::ToolTipText, brush);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette.setBrush(QPalette::Inactive, QPalette::PlaceholderText, brush7);
#endif
        palette.setBrush(QPalette::Disabled, QPalette::WindowText, brush4);
        palette.setBrush(QPalette::Disabled, QPalette::Button, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::Light, brush2);
        palette.setBrush(QPalette::Disabled, QPalette::Midlight, brush3);
        palette.setBrush(QPalette::Disabled, QPalette::Dark, brush4);
        palette.setBrush(QPalette::Disabled, QPalette::Mid, brush5);
        palette.setBrush(QPalette::Disabled, QPalette::Text, brush4);
        palette.setBrush(QPalette::Disabled, QPalette::BrightText, brush2);
        palette.setBrush(QPalette::Disabled, QPalette::ButtonText, brush4);
        palette.setBrush(QPalette::Disabled, QPalette::Base, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::Window, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::Shadow, brush);
        palette.setBrush(QPalette::Disabled, QPalette::AlternateBase, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::ToolTipBase, brush6);
        palette.setBrush(QPalette::Disabled, QPalette::ToolTipText, brush);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette.setBrush(QPalette::Disabled, QPalette::PlaceholderText, brush7);
#endif
        ProjectQt->setPalette(palette);
        ProjectQt->setContextMenuPolicy(Qt::DefaultContextMenu);
        ProjectQt->setAutoFillBackground(true);
        centralWidget = new QWidget(ProjectQt);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        sizePolicy.setHeightForWidth(centralWidget->sizePolicy().hasHeightForWidth());
        centralWidget->setSizePolicy(sizePolicy);
        centralWidget->setMaximumSize(QSize(700, 400));
        gridLayoutWidget_2 = new QWidget(centralWidget);
        gridLayoutWidget_2->setObjectName(QString::fromUtf8("gridLayoutWidget_2"));
        gridLayoutWidget_2->setGeometry(QRect(20, 10, 451, 374));
        gridLayout_3 = new QGridLayout(gridLayoutWidget_2);
        gridLayout_3->setSpacing(6);
        gridLayout_3->setContentsMargins(11, 11, 11, 11);
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
        gridLayout_3->setSizeConstraint(QLayout::SetDefaultConstraint);
        gridLayout_3->setContentsMargins(6, 6, 6, 6);
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        gridLayout_2 = new QGridLayout();
        gridLayout_2->setSpacing(6);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        gridLayout_2->setSizeConstraint(QLayout::SetDefaultConstraint);
        lineEditEmail = new QLineEdit(gridLayoutWidget_2);
        lineEditEmail->setObjectName(QString::fromUtf8("lineEditEmail"));
        QSizePolicy sizePolicy1(QSizePolicy::Expanding, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(lineEditEmail->sizePolicy().hasHeightForWidth());
        lineEditEmail->setSizePolicy(sizePolicy1);

        gridLayout_2->addWidget(lineEditEmail, 1, 0, 1, 1);

        lineEditPassword = new QLineEdit(gridLayoutWidget_2);
        lineEditPassword->setObjectName(QString::fromUtf8("lineEditPassword"));
        sizePolicy1.setHeightForWidth(lineEditPassword->sizePolicy().hasHeightForWidth());
        lineEditPassword->setSizePolicy(sizePolicy1);
        lineEditPassword->setInputMethodHints(Qt::ImhHiddenText|Qt::ImhNoAutoUppercase|Qt::ImhNoPredictiveText|Qt::ImhSensitiveData);
        lineEditPassword->setEchoMode(QLineEdit::Password);

        gridLayout_2->addWidget(lineEditPassword, 1, 1, 1, 1);

        label_3 = new QLabel(gridLayoutWidget_2);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        gridLayout_2->addWidget(label_3, 0, 1, 1, 1);

        label_2 = new QLabel(gridLayoutWidget_2);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        gridLayout_2->addWidget(label_2, 0, 0, 1, 1);


        horizontalLayout->addLayout(gridLayout_2);

        pushButtonAccess = new QPushButton(gridLayoutWidget_2);
        pushButtonAccess->setObjectName(QString::fromUtf8("pushButtonAccess"));
        QSizePolicy sizePolicy2(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(pushButtonAccess->sizePolicy().hasHeightForWidth());
        pushButtonAccess->setSizePolicy(sizePolicy2);

        horizontalLayout->addWidget(pushButtonAccess);


        gridLayout_3->addLayout(horizontalLayout, 0, 1, 1, 1);

        gridLayout = new QGridLayout();
        gridLayout->setSpacing(6);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setSizeConstraint(QLayout::SetDefaultConstraint);
        label = new QLabel(gridLayoutWidget_2);
        label->setObjectName(QString::fromUtf8("label"));
        QSizePolicy sizePolicy3(QSizePolicy::Preferred, QSizePolicy::Minimum);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(label->sizePolicy().hasHeightForWidth());
        label->setSizePolicy(sizePolicy3);
        QFont font;
        font.setPointSize(10);
        label->setFont(font);
        label->setTextFormat(Qt::AutoText);

        gridLayout->addWidget(label, 0, 0, 1, 1);

        pushButtonRecovery = new QPushButton(gridLayoutWidget_2);
        pushButtonRecovery->setObjectName(QString::fromUtf8("pushButtonRecovery"));
        sizePolicy2.setHeightForWidth(pushButtonRecovery->sizePolicy().hasHeightForWidth());
        pushButtonRecovery->setSizePolicy(sizePolicy2);

        gridLayout->addWidget(pushButtonRecovery, 0, 1, 1, 1);


        gridLayout_3->addLayout(gridLayout, 1, 1, 1, 1);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setSizeConstraint(QLayout::SetDefaultConstraint);
        verticalLayout->setContentsMargins(20, -1, 20, -1);
        gridLayout_4 = new QGridLayout();
        gridLayout_4->setSpacing(6);
        gridLayout_4->setObjectName(QString::fromUtf8("gridLayout_4"));
        gridLayout_4->setSizeConstraint(QLayout::SetDefaultConstraint);
        gridLayout_4->setHorizontalSpacing(10);
        gridLayout_4->setContentsMargins(0, -1, 0, -1);
        lineEditNewSurname = new QLineEdit(gridLayoutWidget_2);
        lineEditNewSurname->setObjectName(QString::fromUtf8("lineEditNewSurname"));
        sizePolicy2.setHeightForWidth(lineEditNewSurname->sizePolicy().hasHeightForWidth());
        lineEditNewSurname->setSizePolicy(sizePolicy2);

        gridLayout_4->addWidget(lineEditNewSurname, 0, 1, 1, 1);

        lineEditNewName = new QLineEdit(gridLayoutWidget_2);
        lineEditNewName->setObjectName(QString::fromUtf8("lineEditNewName"));
        lineEditNewName->setEnabled(true);
        sizePolicy2.setHeightForWidth(lineEditNewName->sizePolicy().hasHeightForWidth());
        lineEditNewName->setSizePolicy(sizePolicy2);
        lineEditNewName->setAutoFillBackground(false);
        lineEditNewName->setInputMethodHints(Qt::ImhNone);
        lineEditNewName->setFrame(true);
        lineEditNewName->setDragEnabled(false);
        lineEditNewName->setClearButtonEnabled(false);

        gridLayout_4->addWidget(lineEditNewName, 0, 0, 1, 1);


        verticalLayout->addLayout(gridLayout_4);

        lineEditNewEmail = new QLineEdit(gridLayoutWidget_2);
        lineEditNewEmail->setObjectName(QString::fromUtf8("lineEditNewEmail"));
        sizePolicy2.setHeightForWidth(lineEditNewEmail->sizePolicy().hasHeightForWidth());
        lineEditNewEmail->setSizePolicy(sizePolicy2);
        lineEditNewEmail->setInputMask(QString::fromUtf8(""));
        lineEditNewEmail->setText(QString::fromUtf8(""));
        lineEditNewEmail->setFrame(true);
        lineEditNewEmail->setEchoMode(QLineEdit::Normal);

        verticalLayout->addWidget(lineEditNewEmail);

        lineEditNewPassword = new QLineEdit(gridLayoutWidget_2);
        lineEditNewPassword->setObjectName(QString::fromUtf8("lineEditNewPassword"));
        sizePolicy2.setHeightForWidth(lineEditNewPassword->sizePolicy().hasHeightForWidth());
        lineEditNewPassword->setSizePolicy(sizePolicy2);
        lineEditNewPassword->setEchoMode(QLineEdit::PasswordEchoOnEdit);

        verticalLayout->addWidget(lineEditNewPassword);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        horizontalLayout_3->setSizeConstraint(QLayout::SetDefaultConstraint);
        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setSpacing(6);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        label_4 = new QLabel(gridLayoutWidget_2);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        verticalLayout_3->addWidget(label_4);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        spinBoxDay = new QSpinBox(gridLayoutWidget_2);
        spinBoxDay->setObjectName(QString::fromUtf8("spinBoxDay"));
        sizePolicy2.setHeightForWidth(spinBoxDay->sizePolicy().hasHeightForWidth());
        spinBoxDay->setSizePolicy(sizePolicy2);
        spinBoxDay->setMinimum(1);
        spinBoxDay->setMaximum(31);
        spinBoxDay->setDisplayIntegerBase(10);

        horizontalLayout_2->addWidget(spinBoxDay);

        spinBoxMonth = new QSpinBox(gridLayoutWidget_2);
        spinBoxMonth->setObjectName(QString::fromUtf8("spinBoxMonth"));
        sizePolicy2.setHeightForWidth(spinBoxMonth->sizePolicy().hasHeightForWidth());
        spinBoxMonth->setSizePolicy(sizePolicy2);
        spinBoxMonth->setMinimum(1);
        spinBoxMonth->setMaximum(12);
        spinBoxMonth->setValue(4);

        horizontalLayout_2->addWidget(spinBoxMonth);

        spinBoxYear = new QSpinBox(gridLayoutWidget_2);
        spinBoxYear->setObjectName(QString::fromUtf8("spinBoxYear"));
        sizePolicy2.setHeightForWidth(spinBoxYear->sizePolicy().hasHeightForWidth());
        spinBoxYear->setSizePolicy(sizePolicy2);
        spinBoxYear->setMinimum(1900);
        spinBoxYear->setMaximum(2099);
        spinBoxYear->setValue(2019);

        horizontalLayout_2->addWidget(spinBoxYear);


        verticalLayout_3->addLayout(horizontalLayout_2);


        horizontalLayout_3->addLayout(verticalLayout_3);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(60, -1, -1, -1);
        radioButtonMan = new QRadioButton(gridLayoutWidget_2);
        radioButtonMan->setObjectName(QString::fromUtf8("radioButtonMan"));
        sizePolicy2.setHeightForWidth(radioButtonMan->sizePolicy().hasHeightForWidth());
        radioButtonMan->setSizePolicy(sizePolicy2);
        radioButtonMan->setCheckable(true);
        radioButtonMan->setChecked(false);

        verticalLayout_2->addWidget(radioButtonMan);

        radioButtonWoman = new QRadioButton(gridLayoutWidget_2);
        radioButtonWoman->setObjectName(QString::fromUtf8("radioButtonWoman"));
        sizePolicy2.setHeightForWidth(radioButtonWoman->sizePolicy().hasHeightForWidth());
        radioButtonWoman->setSizePolicy(sizePolicy2);

        verticalLayout_2->addWidget(radioButtonWoman);


        horizontalLayout_3->addLayout(verticalLayout_2);


        verticalLayout->addLayout(horizontalLayout_3);


        gridLayout_3->addLayout(verticalLayout, 3, 1, 1, 1);

        line = new QFrame(gridLayoutWidget_2);
        line->setObjectName(QString::fromUtf8("line"));
        sizePolicy2.setHeightForWidth(line->sizePolicy().hasHeightForWidth());
        line->setSizePolicy(sizePolicy2);
        line->setMinimumSize(QSize(400, 0));
        line->setLineWidth(3);
        line->setFrameShape(QFrame::HLine);
        line->setFrameShadow(QFrame::Sunken);

        gridLayout_3->addWidget(line, 2, 1, 1, 1);

        pushButtonSubmit = new QPushButton(gridLayoutWidget_2);
        pushButtonSubmit->setObjectName(QString::fromUtf8("pushButtonSubmit"));
        sizePolicy2.setHeightForWidth(pushButtonSubmit->sizePolicy().hasHeightForWidth());
        pushButtonSubmit->setSizePolicy(sizePolicy2);
        QPalette palette1;
        palette1.setBrush(QPalette::Active, QPalette::WindowText, brush);
        QBrush brush8(QColor(78, 154, 6, 255));
        brush8.setStyle(Qt::SolidPattern);
        palette1.setBrush(QPalette::Active, QPalette::Button, brush8);
        QBrush brush9(QColor(117, 231, 9, 255));
        brush9.setStyle(Qt::SolidPattern);
        palette1.setBrush(QPalette::Active, QPalette::Light, brush9);
        QBrush brush10(QColor(97, 192, 7, 255));
        brush10.setStyle(Qt::SolidPattern);
        palette1.setBrush(QPalette::Active, QPalette::Midlight, brush10);
        QBrush brush11(QColor(39, 77, 3, 255));
        brush11.setStyle(Qt::SolidPattern);
        palette1.setBrush(QPalette::Active, QPalette::Dark, brush11);
        QBrush brush12(QColor(52, 103, 4, 255));
        brush12.setStyle(Qt::SolidPattern);
        palette1.setBrush(QPalette::Active, QPalette::Mid, brush12);
        palette1.setBrush(QPalette::Active, QPalette::Text, brush);
        palette1.setBrush(QPalette::Active, QPalette::BrightText, brush2);
        palette1.setBrush(QPalette::Active, QPalette::ButtonText, brush2);
        palette1.setBrush(QPalette::Active, QPalette::Base, brush2);
        palette1.setBrush(QPalette::Active, QPalette::Window, brush8);
        palette1.setBrush(QPalette::Active, QPalette::Shadow, brush);
        QBrush brush13(QColor(166, 204, 130, 255));
        brush13.setStyle(Qt::SolidPattern);
        palette1.setBrush(QPalette::Active, QPalette::AlternateBase, brush13);
        palette1.setBrush(QPalette::Active, QPalette::ToolTipBase, brush6);
        palette1.setBrush(QPalette::Active, QPalette::ToolTipText, brush);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette1.setBrush(QPalette::Active, QPalette::PlaceholderText, brush7);
#endif
        palette1.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        palette1.setBrush(QPalette::Inactive, QPalette::Button, brush8);
        palette1.setBrush(QPalette::Inactive, QPalette::Light, brush9);
        palette1.setBrush(QPalette::Inactive, QPalette::Midlight, brush10);
        palette1.setBrush(QPalette::Inactive, QPalette::Dark, brush11);
        palette1.setBrush(QPalette::Inactive, QPalette::Mid, brush12);
        palette1.setBrush(QPalette::Inactive, QPalette::Text, brush);
        palette1.setBrush(QPalette::Inactive, QPalette::BrightText, brush2);
        palette1.setBrush(QPalette::Inactive, QPalette::ButtonText, brush2);
        palette1.setBrush(QPalette::Inactive, QPalette::Base, brush2);
        palette1.setBrush(QPalette::Inactive, QPalette::Window, brush8);
        palette1.setBrush(QPalette::Inactive, QPalette::Shadow, brush);
        palette1.setBrush(QPalette::Inactive, QPalette::AlternateBase, brush13);
        palette1.setBrush(QPalette::Inactive, QPalette::ToolTipBase, brush6);
        palette1.setBrush(QPalette::Inactive, QPalette::ToolTipText, brush);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette1.setBrush(QPalette::Inactive, QPalette::PlaceholderText, brush7);
#endif
        palette1.setBrush(QPalette::Disabled, QPalette::WindowText, brush11);
        palette1.setBrush(QPalette::Disabled, QPalette::Button, brush8);
        palette1.setBrush(QPalette::Disabled, QPalette::Light, brush9);
        palette1.setBrush(QPalette::Disabled, QPalette::Midlight, brush10);
        palette1.setBrush(QPalette::Disabled, QPalette::Dark, brush11);
        palette1.setBrush(QPalette::Disabled, QPalette::Mid, brush12);
        palette1.setBrush(QPalette::Disabled, QPalette::Text, brush11);
        palette1.setBrush(QPalette::Disabled, QPalette::BrightText, brush2);
        palette1.setBrush(QPalette::Disabled, QPalette::ButtonText, brush11);
        palette1.setBrush(QPalette::Disabled, QPalette::Base, brush8);
        palette1.setBrush(QPalette::Disabled, QPalette::Window, brush8);
        palette1.setBrush(QPalette::Disabled, QPalette::Shadow, brush);
        palette1.setBrush(QPalette::Disabled, QPalette::AlternateBase, brush8);
        palette1.setBrush(QPalette::Disabled, QPalette::ToolTipBase, brush6);
        palette1.setBrush(QPalette::Disabled, QPalette::ToolTipText, brush);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette1.setBrush(QPalette::Disabled, QPalette::PlaceholderText, brush7);
#endif
        pushButtonSubmit->setPalette(palette1);
        QFont font1;
        font1.setPointSize(14);
        font1.setBold(true);
        font1.setWeight(75);
        font1.setKerning(true);
        pushButtonSubmit->setFont(font1);
        pushButtonSubmit->setCheckable(false);

        gridLayout_3->addWidget(pushButtonSubmit, 4, 1, 1, 1);

        ProjectQt->setCentralWidget(centralWidget);
        statusBar = new QStatusBar(ProjectQt);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        ProjectQt->setStatusBar(statusBar);
        mainToolBar = new QToolBar(ProjectQt);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        ProjectQt->addToolBar(Qt::TopToolBarArea, mainToolBar);

        retranslateUi(ProjectQt);

        QMetaObject::connectSlotsByName(ProjectQt);
    } // setupUi

    void retranslateUi(QMainWindow *ProjectQt)
    {
        ProjectQt->setWindowTitle(QApplication::translate("ProjectQt", "Project Qt", nullptr));
        lineEditEmail->setInputMask(QString());
        lineEditEmail->setText(QString());
        label_3->setText(QApplication::translate("ProjectQt", "Password", nullptr));
        label_2->setText(QApplication::translate("ProjectQt", "E-mail o telefono", nullptr));
        pushButtonAccess->setText(QApplication::translate("ProjectQt", "Accedi", nullptr));
        label->setText(QApplication::translate("ProjectQt", "Non ricordi piu' come accedere all'account?", nullptr));
        pushButtonRecovery->setText(QApplication::translate("ProjectQt", "Recupera password", nullptr));
        lineEditNewSurname->setInputMask(QString());
        lineEditNewSurname->setText(QString());
        lineEditNewSurname->setPlaceholderText(QApplication::translate("ProjectQt", "Cognome", nullptr));
        lineEditNewName->setInputMask(QString());
        lineEditNewName->setText(QString());
        lineEditNewName->setPlaceholderText(QApplication::translate("ProjectQt", "Nome", nullptr));
        lineEditNewEmail->setPlaceholderText(QApplication::translate("ProjectQt", "Email o numero di telefono", nullptr));
        lineEditNewPassword->setInputMask(QString());
        lineEditNewPassword->setText(QString());
        lineEditNewPassword->setPlaceholderText(QApplication::translate("ProjectQt", "Nuova password", nullptr));
        label_4->setText(QApplication::translate("ProjectQt", "Data di nascita:", nullptr));
        radioButtonMan->setText(QApplication::translate("ProjectQt", "Uomo", nullptr));
        radioButtonWoman->setText(QApplication::translate("ProjectQt", "Donna", nullptr));
        pushButtonSubmit->setText(QApplication::translate("ProjectQt", "Iscriviti", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ProjectQt: public Ui_ProjectQt {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PROJECTQT_H
/********************************************************************************
** Form generated from reading UI file 'mainview.ui'
**
** Created by: Qt User Interface Compiler version 5.10.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINVIEW_H
#define UI_MAINVIEW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainView
{
public:
    QWidget *centralWidget;
    QWidget *layoutWidget;
    QHBoxLayout *horizontalLayout;
    QGroupBox *filterBox;
    QVBoxLayout *verticalLayout_3;
    QVBoxLayout *filterLayout;
    QVBoxLayout *verticalLayout;
    QLabel *dateLabel;
    QLineEdit *dateFilter;
    QLabel *idLabel;
    QLineEdit *idFilter;
    QLabel *numLabel;
    QLineEdit *numberFilter;
    QLabel *constLabel;
    QLineEdit *constantFilter;
    QLabel *digLabel;
    QLineEdit *digitsFilter;
    QLabel *decLabel;
    QLineEdit *decimalsFilter;
    QPushButton *searchBtn;
    QGroupBox *listBox;
    QGridLayout *gridLayout;
    QListView *listView;
    QMenuBar *menuBar;
    QMenu *menuCuteCliuent;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainView)
    {
        if (MainView->objectName().isEmpty())
            MainView->setObjectName(QStringLiteral("MainView"));
        MainView->resize(1154, 753);
        centralWidget = new QWidget(MainView);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        layoutWidget = new QWidget(centralWidget);
        layoutWidget->setObjectName(QStringLiteral("layoutWidget"));
        layoutWidget->setGeometry(QRect(9, 9, 1131, 681));
        horizontalLayout = new QHBoxLayout(layoutWidget);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        filterBox = new QGroupBox(layoutWidget);
        filterBox->setObjectName(QStringLiteral("filterBox"));
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(filterBox->sizePolicy().hasHeightForWidth());
        filterBox->setSizePolicy(sizePolicy);
        filterBox->setMinimumSize(QSize(150, 350));
        filterBox->setMaximumSize(QSize(400, 700));
        verticalLayout_3 = new QVBoxLayout(filterBox);
        verticalLayout_3->setSpacing(6);
        verticalLayout_3->setContentsMargins(11, 11, 11, 11);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        filterLayout = new QVBoxLayout();
        filterLayout->setSpacing(6);
        filterLayout->setObjectName(QStringLiteral("filterLayout"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(10);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(15, 15, 15, 15);
        dateLabel = new QLabel(filterBox);
        dateLabel->setObjectName(QStringLiteral("dateLabel"));

        verticalLayout->addWidget(dateLabel);

        dateFilter = new QLineEdit(filterBox);
        dateFilter->setObjectName(QStringLiteral("dateFilter"));

        verticalLayout->addWidget(dateFilter);

        idLabel = new QLabel(filterBox);
        idLabel->setObjectName(QStringLiteral("idLabel"));

        verticalLayout->addWidget(idLabel);

        idFilter = new QLineEdit(filterBox);
        idFilter->setObjectName(QStringLiteral("idFilter"));

        verticalLayout->addWidget(idFilter);

        numLabel = new QLabel(filterBox);
        numLabel->setObjectName(QStringLiteral("numLabel"));

        verticalLayout->addWidget(numLabel);

        numberFilter = new QLineEdit(filterBox);
        numberFilter->setObjectName(QStringLiteral("numberFilter"));

        verticalLayout->addWidget(numberFilter);

        constLabel = new QLabel(filterBox);
        constLabel->setObjectName(QStringLiteral("constLabel"));

        verticalLayout->addWidget(constLabel);

        constantFilter = new QLineEdit(filterBox);
        constantFilter->setObjectName(QStringLiteral("constantFilter"));

        verticalLayout->addWidget(constantFilter);

        digLabel = new QLabel(filterBox);
        digLabel->setObjectName(QStringLiteral("digLabel"));

        verticalLayout->addWidget(digLabel);

        digitsFilter = new QLineEdit(filterBox);
        digitsFilter->setObjectName(QStringLiteral("digitsFilter"));

        verticalLayout->addWidget(digitsFilter);

        decLabel = new QLabel(filterBox);
        decLabel->setObjectName(QStringLiteral("decLabel"));

        verticalLayout->addWidget(decLabel);

        decimalsFilter = new QLineEdit(filterBox);
        decimalsFilter->setObjectName(QStringLiteral("decimalsFilter"));
        QSizePolicy sizePolicy1(QSizePolicy::Expanding, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(decimalsFilter->sizePolicy().hasHeightForWidth());
        decimalsFilter->setSizePolicy(sizePolicy1);

        verticalLayout->addWidget(decimalsFilter);

        searchBtn = new QPushButton(filterBox);
        searchBtn->setObjectName(QStringLiteral("searchBtn"));
        QSizePolicy sizePolicy2(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(searchBtn->sizePolicy().hasHeightForWidth());
        searchBtn->setSizePolicy(sizePolicy2);
        searchBtn->setLayoutDirection(Qt::RightToLeft);

        verticalLayout->addWidget(searchBtn);


        filterLayout->addLayout(verticalLayout);


        verticalLayout_3->addLayout(filterLayout);


        horizontalLayout->addWidget(filterBox);

        listBox = new QGroupBox(layoutWidget);
        listBox->setObjectName(QStringLiteral("listBox"));
        gridLayout = new QGridLayout(listBox);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        listView = new QListView(listBox);
        listView->setObjectName(QStringLiteral("listView"));
        listView->setMinimumSize(QSize(150, 350));

        gridLayout->addWidget(listView, 1, 0, 1, 1);


        horizontalLayout->addWidget(listBox);

        MainView->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainView);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 1154, 21));
        menuCuteCliuent = new QMenu(menuBar);
        menuCuteCliuent->setObjectName(QStringLiteral("menuCuteCliuent"));
        MainView->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainView);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        MainView->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainView);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainView->setStatusBar(statusBar);
#ifndef QT_NO_SHORTCUT
        dateLabel->setBuddy(dateFilter);
        idLabel->setBuddy(idFilter);
        numLabel->setBuddy(numberFilter);
        constLabel->setBuddy(constantFilter);
        digLabel->setBuddy(digitsFilter);
        decLabel->setBuddy(decimalsFilter);
#endif // QT_NO_SHORTCUT
        QWidget::setTabOrder(dateFilter, idFilter);
        QWidget::setTabOrder(idFilter, numberFilter);
        QWidget::setTabOrder(numberFilter, constantFilter);
        QWidget::setTabOrder(constantFilter, digitsFilter);
        QWidget::setTabOrder(digitsFilter, decimalsFilter);
        QWidget::setTabOrder(decimalsFilter, searchBtn);

        menuBar->addAction(menuCuteCliuent->menuAction());

        retranslateUi(MainView);

        QMetaObject::connectSlotsByName(MainView);
    } // setupUi

    void retranslateUi(QMainWindow *MainView)
    {
        MainView->setWindowTitle(QApplication::translate("MainView", "MainView", nullptr));
        filterBox->setTitle(QApplication::translate("MainView", "Filters", nullptr));
        dateLabel->setText(QApplication::translate("MainView", "Date", nullptr));
        idLabel->setText(QApplication::translate("MainView", "ExternalID", nullptr));
        numLabel->setText(QApplication::translate("MainView", "Number", nullptr));
        constLabel->setText(QApplication::translate("MainView", "Constant", nullptr));
        digLabel->setText(QApplication::translate("MainView", "Digits", nullptr));
        decLabel->setText(QApplication::translate("MainView", "Decimals", nullptr));
        searchBtn->setText(QApplication::translate("MainView", "Search", nullptr));
        listBox->setTitle(QApplication::translate("MainView", "    Date                    ExternalID                                    Number               Constant        Digits              Decimals", nullptr));
        menuCuteCliuent->setTitle(QApplication::translate("MainView", "CuteClient", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainView: public Ui_MainView {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINVIEW_H

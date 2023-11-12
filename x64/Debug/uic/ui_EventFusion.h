/********************************************************************************
** Form generated from reading UI file 'EventFusion.ui'
**
** Created by: Qt User Interface Compiler version 6.6.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_EVENTFUSION_H
#define UI_EVENTFUSION_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_EventFusionClass
{
public:
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QWidget *centralWidget;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *EventFusionClass)
    {
        if (EventFusionClass->objectName().isEmpty())
            EventFusionClass->setObjectName("EventFusionClass");
        EventFusionClass->resize(600, 400);
        menuBar = new QMenuBar(EventFusionClass);
        menuBar->setObjectName("menuBar");
        EventFusionClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(EventFusionClass);
        mainToolBar->setObjectName("mainToolBar");
        EventFusionClass->addToolBar(mainToolBar);
        centralWidget = new QWidget(EventFusionClass);
        centralWidget->setObjectName("centralWidget");
        EventFusionClass->setCentralWidget(centralWidget);
        statusBar = new QStatusBar(EventFusionClass);
        statusBar->setObjectName("statusBar");
        EventFusionClass->setStatusBar(statusBar);

        retranslateUi(EventFusionClass);

        QMetaObject::connectSlotsByName(EventFusionClass);
    } // setupUi

    void retranslateUi(QMainWindow *EventFusionClass)
    {
        EventFusionClass->setWindowTitle(QCoreApplication::translate("EventFusionClass", "EventFusion", nullptr));
    } // retranslateUi

};

namespace Ui {
    class EventFusionClass: public Ui_EventFusionClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_EVENTFUSION_H

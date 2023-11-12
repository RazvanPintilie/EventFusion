#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_EventFusion.h"

class EventFusion : public QMainWindow
{
    Q_OBJECT

public:
    EventFusion(QWidget *parent = nullptr);
    ~EventFusion();

private:
    Ui::EventFusionClass ui;
};

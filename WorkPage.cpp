﻿#include "WorkPage.h"

WorkPage::WorkPage(QWidget* parent) : QWidget(parent) {
    setWindowTitle("Work Page");

    QHBoxLayout* mainLayout = new QHBoxLayout(this);
    QVBoxLayout* buttonsLayout = new QVBoxLayout();

    remainingValue = 100;
    QLabel* capacitateRamasaString = new QLabel("Capacitate ramasa: ", this);
    QLabel* capacitateCurentaString = new QLabel("Capacitate curenta: ", this);
    remainingValueLabel = new QLabel(QString::number(remainingValue), this);
    currentValueLabel = new QLabel(QString::number(currentValue), this);

    capacitateRamasaString->move(690, 0);
    remainingValueLabel->move(800, 0);
    capacitateCurentaString->move(690, 30);
    currentValueLabel->move(800, 30);

    QString basePath = "";
    int imageIndex = 0;
    for (int index = 0; index < 4; ++index)
    {
        int buttonId = index;
        QString imagePath = basePath + QString::number(index) + ".png";
        QIcon buttonIcon(imagePath);
        QPushButton* button = new QPushButton(buttonIcon, "", this);
        button->setIcon(buttonIcon);
        button->setIconSize(QSize(100, 100));
        button->setFixedSize(QSize(50, 50));
        button->setStyleSheet("QPushButton { border: 1px solid #000000; padding: 0; }");
        auto generateImage = [=]() {
            DraggableImage* imageLabel = new DraggableImage(buttonIcon.pixmap(QSize(100, 100)), this);
            imageLabel->setFixedSize(50, 50);
            imageLabel->hide();
            imageLabel->move(button->pos() + QPoint(0, 0));
            imageLabel->show();
            decreaseValue(buttonId);
        };
        connect(button, &QPushButton::clicked, this, generateImage);
        buttonMap[buttonId] = button;
        buttonsLayout->addWidget(button);
    }

    QFrame* frame = new QFrame(this);
    frame->setFrameShape(QFrame::Box);
    frame->setLineWidth(2);
    frame->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    QVBoxLayout* frameLayout = new QVBoxLayout(frame);
    frame->lower();
    frame->setFixedSize(800, 420);
    frame->setStyleSheet("background-color: white;");
    frame->setLayout(frameLayout);
    mainLayout->addLayout(buttonsLayout);
    mainLayout->addWidget(frame);

    setLayout(mainLayout);
}

void WorkPage::decreaseValue(int buttonId) {
    int capacity = 0;

    switch (buttonId) {
    case 0:
        capacity = 8;
        break;
    case 1:
        capacity = 8;
        break;
    case 2:
        capacity = 3;
        break;
    default:
        capacity = 2;
        break;
    }

    if (remainingValue - capacity < 0)
    {
        QMessageBox::information(this, "Warning", "Capacitate depasita");
    }
    else
    {
        remainingValue -= capacity;
        currentValue += capacity;
        remainingValueLabel->setText(QString::number(remainingValue));
        currentValueLabel->setText(QString::number(currentValue));
    }
}

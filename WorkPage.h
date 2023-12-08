#ifndef WORKPAGE_H
#define WORKPAGE_H

#include <QWidget>
#include <QPushButton>
#include <QLineEdit>
#include <QVBoxLayout>
#include <QMessageBox>
#include <QLabel>
#include <QDrag>
#include <QMouseEvent>
#include <QMimeData>
#include <QGridLayout>
#include <QLayout>
#include "DraggableImage.h"
class WorkPage : public QWidget
{
    Q_OBJECT
public:
    WorkPage(QWidget* parent = nullptr);
private slots:
    void decreaseValue(int buttonId);
private:
    QLabel* currentValueLabel;
    QMap<int, QPushButton*> buttonMap; // Mapare ID buton - Buton
    int currentValue;
    QVBoxLayout* mainLayout;
};

#endif

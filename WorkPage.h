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
#include <qfile.h>
#include "DraggableImage.h"
#include "ImageDetail.cpp"
#include <vector>

class WorkPage : public QWidget
{
    Q_OBJECT
public:
    WorkPage(QWidget* parent = nullptr);
private slots:
    void decreaseValue(int buttonId);
    void increaseValue(int buttonId);

private:
    void saveCoordinatesToFile(const QString& fileName, std::vector<ImageDetail> image);
    void loadCoordinatesAndGenerateImages();
    QLabel* currentValueLabel;
    QLabel* remainingValueLabel;
    QMap<int, QPushButton*> buttonMap; // Mapare ID buton - Buton
    int remainingValue;
    int currentValue = 0;
    QVBoxLayout* mainLayout;
};

#endif

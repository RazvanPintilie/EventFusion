#ifndef WORKPAGE_H
#define WORKPAGE_H

#include <QWidget>
#include <QPushButton>
#include <QLineEdit>
#include <QVBoxLayout>
#include <QMessageBox>
#include <QLabel>
#include <QDrag>
#include <QRegularexpression>
#include <QMouseEvent>
#include <QMimeData>
#include <QGridLayout>
#include <QLayout>
#include <QFileDialog>
#include <qfile.h>
#include <Qdir>
#include "DraggableImage.h"
#include "ImageDetail.cpp"
#include <vector>
#include <QObject>
#include <functional>

class WorkPage : public QWidget
{
    Q_OBJECT
public:
    WorkPage(bool newProject, QWidget* parent = nullptr);
    void saveDetails();
    void incarcaDate();

private slots:
    void decreaseValue(int buttonId);
    void increaseValue(int buttonId);

signals:
    void loadExistingProject();

private:
    QLabel* currentValueLabel;
    QLabel* remainingValueLabel;
    QLabel* currentUsernameLabel;
    QMap<int, QPushButton*> buttonMap; // Mapare ID buton - Buton
    int remainingValue;
    int currentValue = 0;
    QVBoxLayout* mainLayout;
    DraggableImage* highlightedImage;
    std::vector<ImageDetail> imageDetails;
    void generateImage(int buttonId, const QIcon& buttonIcon,int x, int y, int rotateIndex);

};

#endif

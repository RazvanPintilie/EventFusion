#include "WorkPage.h"
#include <iostream>
#include "User.h"

WorkPage::WorkPage(QWidget* parent) : QWidget(parent) {
    setWindowTitle("Work Page");

    std::vector<ImageDetail> imageDetails;
    QHBoxLayout* mainLayout = new QHBoxLayout(this);
    QVBoxLayout* buttonsLayout = new QVBoxLayout();

    remainingValue = 100;
    QLabel* capacitateRamasaString = new QLabel("Capacitate ramasa: ", this);
    QLabel* capacitateCurentaString = new QLabel("Capacitate curenta: ", this);
    QLabel* currentUsernameString = new QLabel("Conectat ca:"+User::getInstance().getUsername(), this);
    QLabel* currentUsernameLabel= new QLabel(User::getInstance().getUsername(), this);
    remainingValueLabel = new QLabel(QString::number(remainingValue), this);
    currentValueLabel = new QLabel(QString::number(currentValue), this);

    QPushButton* saveImageButton = new QPushButton("Salvează Imaginile", this);

    capacitateRamasaString->move(690, 0);
    remainingValueLabel->move(800, 0);
    capacitateCurentaString->move(690, 30);
    currentValueLabel->move(800, 30);
    
    QString login = User::getInstance().getUsername();
    
    QString basePath = "";
    for (int index = 0; index < 4; ++index)
    {
        qDebug() << "dasdasddasadssad";
        int buttonId = index;
        QString imagePath = basePath + QString::number(index) + ".png";
        QIcon buttonIcon(imagePath);
        QPushButton* button = new QPushButton(buttonIcon, "", this);
        button->setIcon(buttonIcon);
        button->setIconSize(QSize(100, 100));
        button->setFixedSize(QSize(50, 50));
        button->setStyleSheet("QPushButton { border: 1px solid #000000; padding: 0; }");
        auto generateImage = [=]() {
            DraggableImage* imageLabel = new DraggableImage(buttonIcon.pixmap(QSize(100, 100)),buttonId, this);
            imageLabel->setFixedSize(50, 50);
            imageLabel->move(button->pos() + QPoint(0, 0));
            imageLabel->show();
            imageLabel->setFocusPolicy(Qt::StrongFocus);
            decreaseValue(buttonId);
            connect(imageLabel, &DraggableImage::deleteKeyPressed, this, [=]() {this->increaseValue(buttonId); });
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

void WorkPage::increaseValue(int buttonId)
{
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

    remainingValue += capacity;
    currentValue -= capacity;
    remainingValueLabel->setText(QString::number(remainingValue));
    currentValueLabel->setText(QString::number(currentValue));
}

void WorkPage::saveCoordinatesToFile(const QString& fileName,  std::vector<ImageDetail> imageDetails) {
    QFile file(fileName);
    if (file.open(QIODevice::WriteOnly | QIODevice::Text)) {
        QTextStream out(&file);

        for (ImageDetail image : imageDetails) {
            out << "ID: " << image.getId() << ", X: " << image.getX() << ", Y: " << image.getY() << "\n";
        }

        file.close();
    }
    else {
    }
}

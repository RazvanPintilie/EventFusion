#include "WorkPage.h"
#include <iostream>
#include "User.h"


WorkPage::WorkPage(QWidget* parent) : QWidget(parent), highlightedImage(nullptr)
{
	setWindowTitle("Work Page");
	int indeximage = 0;

	QHBoxLayout* mainLayout = new QHBoxLayout(this);
	QVBoxLayout* buttonsLayout = new QVBoxLayout();
	QString username = User::getInstance().getUsername();

	remainingValue = 100;
	QLabel* capacitateRamasaString = new QLabel("Capacitate ramasa: ", this);
	QLabel* capacitateCurentaString = new QLabel("Capacitate curenta: ", this);
	QLabel* currentUsernameString = new QLabel("Conectat ca: ", this);

	remainingValueLabel = new QLabel(QString::number(remainingValue), this);
	currentValueLabel = new QLabel(QString::number(currentValue), this);
	currentUsernameLabel = new QLabel(User::getInstance().getUsername(), this);

	
	//save button
	QPushButton* showDetailsButton = new QPushButton("Afișează Detalii", this);

	//load button
	QPushButton* loadDataButton = new QPushButton("Încarcă Date", this);
	connect(loadDataButton, &QPushButton::clicked, this, &WorkPage::incarcaDate);

	buttonsLayout->addWidget(loadDataButton);
	
	capacitateRamasaString->move(690, 0);
	remainingValueLabel->move(800, 0);
	capacitateCurentaString->move(690, 30);
	currentValueLabel->move(800, 30);
	currentUsernameString->move(400, 0);

	currentUsernameLabel->move(470, 0);

	QString basePath = "";
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
		auto generateImage = [=]()
		{

			// Check if there's a highlighted image and unhighlight it
			if (highlightedImage)
			{
				highlightedImage->setSelected(false);
			}

			currentUsernameLabel = new QLabel(User::getInstance().getUsername(), this);
			DraggableImage* imageLabel = new DraggableImage(buttonIcon.pixmap(QSize(100, 100)), buttonId, this);
			imageLabel->setFixedSize(50, 50);
			imageLabel->move(button->pos() + QPoint(100, 10));
			imageLabel->show();
			imageLabel->setFocusPolicy(Qt::StrongFocus);

			// Highlight the newly generated image
			imageLabel->setSelected(true);

			// Connect the deleteKeyPressed signal
			connect(imageLabel, &DraggableImage::deleteKeyPressed, this, [=]()
				{
					this->increaseValue(buttonId);
					auto it = std::remove_if(imageDetails.begin(), imageDetails.end(),
						[=](ImageDetail& detail)
						{
							return detail.getId() == buttonId &&
								detail.getX() == imageLabel->pos().x() &&
								detail.getY() == imageLabel->pos().y();
								
						});

					imageDetails.erase(it, imageDetails.end());

					// Disconnect the signal when the image is deleted
					disconnect(imageLabel, &DraggableImage::deleteKeyPressed, this, nullptr);
					// Reset the highlightedImage after deleting
					highlightedImage = nullptr;
				}
			);
			

			// Update the highlightedImage to the newly generated image
			highlightedImage = imageLabel;

			decreaseValue(buttonId);
			connect(imageLabel, &DraggableImage::deleteKeyPressed, this, [=]() {this->increaseValue(buttonId); });
			ImageDetail imageDetail(imageLabel->pos().x(), imageLabel->pos().y(), buttonId,imageLabel->getRotateNumber());
			imageDetails.push_back(imageDetail);
			connect(imageLabel, &DraggableImage::imageMoved, this, [=](const QPoint& newPos)
				{
					if (highlightedImage)
					{
						// Find the corresponding ImageDetail and update its position
						for (auto& imageDetail : imageDetails)
						{
							if (imageDetail.getId()== buttonId)
							{
								imageDetail.setX(newPos.x());
								imageDetail.setY(newPos.y());
								break;
							}
						}
					}
				});
		};
		connect(button, &QPushButton::clicked, this, generateImage);
		
		buttonMap[buttonId] = button;
		buttonsLayout->addWidget(button);
	}
	
	connect(showDetailsButton, &QPushButton::clicked, this, &WorkPage::afiseazaDetalii);
	buttonsLayout->addWidget(showDetailsButton);
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

void WorkPage::decreaseValue(int buttonId)
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


void WorkPage::afiseazaDetalii()
{
	QString username = User::getInstance().getUsername();

	// Open a file dialog to get the file name and location
	QString filePath = QFileDialog::getSaveFileName(this, "Selectare Fișier", QDir::currentPath() + "/project/" + username, "Text Files (*.txt);;All Files (*)");

	if (!filePath.isEmpty())
	{
		// Open the file for writing
		QFile file(filePath);
		if (file.open(QIODevice::WriteOnly | QIODevice::Text))
		{
			QTextStream stream(&file);

			// Write the image details to the file
			for (ImageDetail& imageDetail : imageDetails)
			{
				stream << "X: " << imageDetail.getX() << ", Y: " << imageDetail.getY() << ", ID: " << imageDetail.getId() << ", ROTATE: "<<imageDetail.getRotateIndex()<<" \n";
			}


			// Close the file
			file.close();

			QMessageBox::information(this, "Detalii", "Detaliile au fost salvate în fișierul " + filePath);
		}
		else
		{
			QMessageBox::warning(this, "Eroare", "Nu s-a putut deschide fișierul pentru salvarea detaliilor.");
		}
	}
	else
	{
		// User canceled the file dialog
		QMessageBox::information(this, "Anulat", "Operația de salvare a fost anulată.");
	}
}

void WorkPage::incarcaDate()
{
	QString fileName = QFileDialog::getOpenFileName(this, tr("Open Data File"), "", tr("Text Files (*.txt);;All Files (*)"));

	if (fileName.isEmpty())
	{
		qDebug() << "Fisierul nu a fost selectat.";
		return;
	}

	QFile file(fileName);

	if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
	{
		qDebug() << "Nu s-a putut deschide fisierul: " << file.errorString();
		return;
	}

	QTextStream in(&file);
	while (!in.atEnd())
	{
		QString line = in.readLine();

		// Căutăm în linie valorile pentru X, Y și ID
		QRegularExpressionMatch match = QRegularExpression("X: (\\d+), Y: (\\d+), ID: (\\d+), ROTATE: (\\d+)").match(line);
		if (match.hasMatch())
		{
			int x = match.captured(1).toInt();
			int y = match.captured(2).toInt();
			int id = match.captured(3).toInt();
			int rotateIndex = match.captured(4).toInt();

			// Verificăm dacă există un buton cu id-ul specificat
			if (buttonMap.contains(id))
			{
				// Generăm imaginea în funcție de informațiile din fișier
				generateImage(id, buttonMap[id]->icon(),x,y,rotateIndex);
			}
		}
	}

	file.close();
}

void WorkPage::generateImage(int buttonId, const QIcon& buttonIcon, int x,int y,int rotateIndex)
{
	// Check if there's a highlighted image and unhighlight it
	if (highlightedImage)
	{
		highlightedImage->setSelected(false);
	}

	currentUsernameLabel = new QLabel(User::getInstance().getUsername(), this);
	DraggableImage* imageLabel = new DraggableImage(buttonIcon.pixmap(QSize(100, 100)), buttonId, this);
	imageLabel->setFixedSize(50, 50);
	imageLabel->move(QPoint(x,y));
	imageLabel->show();
	imageLabel->setFocusPolicy(Qt::StrongFocus);

	// Highlight the newly generated image
	imageLabel->setSelected(true);

	// Connect the deleteKeyPressed signal
	connect(imageLabel, &DraggableImage::deleteKeyPressed, this, [=]()
		{
			this->increaseValue(buttonId);

			// Iterate through imageDetails and remove the corresponding item

			// Disconnect the signal when the image is deleted
			disconnect(imageLabel, &DraggableImage::deleteKeyPressed, this, nullptr);
			// Reset the highlightedImage after deleting
			highlightedImage = nullptr;
		});

	// Update the highlightedImage to the newly generated image
	highlightedImage = imageLabel;

	decreaseValue(buttonId);
	connect(imageLabel, &DraggableImage::deleteKeyPressed, this, [=]() {this->increaseValue(buttonId); });
	ImageDetail imageDetail(imageLabel->pos().x(), imageLabel->pos().y(), buttonId, rotateIndex);
	imageLabel->rotateImage(rotateIndex);
	imageDetails.push_back(imageDetail);
	connect(imageLabel, &DraggableImage::imageMoved, this, [=](const QPoint& newPos)
		{
			if (highlightedImage)
			{
				// Find the corresponding ImageDetail and update its position
				for (auto& imageDetail : imageDetails)
				{
					if (imageDetail.getId() == buttonId)
					{
						imageDetail.setX(newPos.x());
						imageDetail.setY(newPos.y());
						imageDetail.setRotateIndex(rotateIndex);
						
						break;
					}
				}
			}
			
		});
}


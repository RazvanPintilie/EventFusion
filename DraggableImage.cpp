#include "DraggableImage.h"

DraggableImage* DraggableImage::selectedImage = nullptr;

DraggableImage::DraggableImage(const QPixmap& pixmap, int buttonId, QWidget* parent, int rotateNumber) : QLabel(parent), isDragging(false)
{
	setPixmap(pixmap);
	setScaledContents(true);
	originalPosition = QPoint(0, 0);
	this->rotateNumber = rotateNumber;
}

void DraggableImage::mousePressEvent(QMouseEvent* event)
{
	// Deselect the previously selected image (if any)
	if (selectedImage != nullptr && selectedImage != this)
	{
		selectedImage->setSelected(false);
	}

	// Select the current image
	selectedImage = this;
	setSelected(true);

	if (event->button() == Qt::LeftButton)
	{
		isDragging = true;
		offset = event->pos();
		setSelected(true);
		event->accept();
	}
	else if (event->button() == Qt::RightButton)
	{
		this->rotateNumber++;
		rotateImage(1);
		event->accept();
		emit rightClick();
	}
	QLabel::mousePressEvent(event);

}

void DraggableImage::rotateImage(int roateNumber)
{

	QTransform transform;
	int angle = 90 * roateNumber;
	transform.rotate(angle);

	QPixmap rotatedPixmap = pixmap().transformed(transform);
	setPixmap(rotatedPixmap);
}

void DraggableImage::mouseMoveEvent(QMouseEvent* event)
{
	if (isDragging)
	{
		QPoint newPosition = event->pos() + this->pos() - offset;
		this->move(newPosition);
		event->accept();
		emit imageMoved(newPosition);
	}

	QLabel::mouseMoveEvent(event);
}

void DraggableImage::mouseReleaseEvent(QMouseEvent* event)
{
	if (event->button() == Qt::LeftButton && isDragging)
	{
		isDragging = false;
		// setSelected(false);
		event->accept();
	}
	QLabel::mouseReleaseEvent(event);
}

void DraggableImage::restoreOriginalPosition()
{
	this->move(originalPosition);
}

void DraggableImage::keyPressEvent(QKeyEvent* event)
{
	if (event->key() == Qt::Key_Delete)
	{
		emit deleteKeyPressed(buttonId);
		selectedImage->setSelected(false);
		selectedImage = nullptr;
		this->deleteLater();
		event->accept();
	}
	else
	{
		QLabel::keyPressEvent(event);
	}
}

void DraggableImage::setSelected(bool selected)
{
	if (selected)
	{
		QWidget::setStyleSheet("border: 2px solid red;");
	}
	else
	{
		QWidget::setStyleSheet("border: none;");
	}
}
int DraggableImage::getRotateNumber()
{
	return this->rotateNumber;
}


﻿#include "DraggableImage.h"

DraggableImage::DraggableImage(const QPixmap& pixmap, int buttonId, QWidget* parent) : QLabel(parent), isDragging(false)
{
	setPixmap(pixmap);
	setScaledContents(true);
	originalPosition = QPoint(0, 0);
}

void DraggableImage::mousePressEvent(QMouseEvent* event)
{
	if (event->button() == Qt::LeftButton)
	{
		isDragging = true;
		offset = event->pos();
		setSelected(true);
		event->accept();
	}
	else if (event->button() == Qt::RightButton)
	{
		rotateImage();
		event->accept();
	}
	QLabel::mousePressEvent(event);
}

void DraggableImage::rotateImage()
{
	QTransform transform;
	int angle = 90;
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
	}
	QLabel::mouseMoveEvent(event);
}

void DraggableImage::mouseReleaseEvent(QMouseEvent* event)
{
	if (event->button() == Qt::LeftButton && isDragging)
	{
		isDragging = false;
		setSelected(false);
		event->accept();
	}
	QLabel::mouseReleaseEvent(event);
}

void DraggableImage::restoreOriginalPosition() {
	this->move(originalPosition);
}

void DraggableImage::keyPressEvent(QKeyEvent* event)
{
	if (event->key() == Qt::Key_Delete)
	{
		emit deleteKeyPressed(buttonId);
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
		QWidget::setStyleSheet("border: 2px solid black;");
	}
	else
	{
		QWidget::setStyleSheet("border: none;");
	}
}


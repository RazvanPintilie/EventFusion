#include "DraggableImage.h"

DraggableImage::DraggableImage(const QPixmap& pixmap, QWidget* parent)
    : QLabel(parent), isDragging(false) {
    setPixmap(pixmap);
    setScaledContents(true);
    originalPosition = QPoint(0, 0);
}

void DraggableImage::mousePressEvent(QMouseEvent* event) {
    if (event->button() == Qt::LeftButton) {
        isDragging = true;
        offset = event->pos();
        event->accept();
    }
    else if (event->button() == Qt::RightButton) {
        rotateImage(); 
        event->accept();
    }
    QLabel::mousePressEvent(event);
}

void DraggableImage::rotateImage() {
    QTransform transform;
    int angle = 90; 
    transform.rotate(angle);

    QPixmap rotatedPixmap = pixmap().transformed(transform);
    setPixmap(rotatedPixmap);
}

void DraggableImage::mouseMoveEvent(QMouseEvent* event) {
    if (isDragging) {
        QPoint newPosition = event->pos() + this->pos() - offset;
        this->move(newPosition);
        event->accept();
    }
    QLabel::mouseMoveEvent(event);
}

void DraggableImage::mouseReleaseEvent(QMouseEvent* event) {
    if (event->button() == Qt::LeftButton && isDragging) {
        isDragging = false;
        event->accept();
    }
    QLabel::mouseReleaseEvent(event);
}

void DraggableImage::restoreOriginalPosition() {
    this->move(originalPosition);
}

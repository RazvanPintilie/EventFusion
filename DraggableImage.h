#ifndef DRAGGABLEIMAGE_H
#define DRAGGABLEIMAGE_H

#include <QLabel>
#include <QMouseEvent>

class DraggableImage : public QLabel {
    Q_OBJECT

public:
    DraggableImage(const QPixmap& pixmap, QWidget* parent = nullptr);

signals:
    void imageMoved(const QPoint& newPos);

protected:
    void mousePressEvent(QMouseEvent* event) override;
    void mouseMoveEvent(QMouseEvent* event) override;
    void mouseReleaseEvent(QMouseEvent* event) override;
    void restoreOriginalPosition();
    void rotateImage();

private:
    bool isDragging;
    QPoint offset;
    QPoint originalPosition;
};

#endif
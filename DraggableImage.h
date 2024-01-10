#ifndef DRAGGABLEIMAGE_H
#define DRAGGABLEIMAGE_H

#include <QLabel>
#include <QMouseEvent>

class DraggableImage : public QLabel
{
    Q_OBJECT

public:
    DraggableImage(const QPixmap& pixmap, int buttonId, QWidget* parent = nullptr);
    void setSelected(bool selected);

signals:
    void imageMoved(const QPoint& newPos);
    void deleteKeyPressed(int buttonId);

protected:
    void mousePressEvent(QMouseEvent* event) override;
    void mouseMoveEvent(QMouseEvent* event) override;
    void mouseReleaseEvent(QMouseEvent* event) override;
    void restoreOriginalPosition();
    void keyPressEvent(QKeyEvent* event);
    void rotateImage();

private:
    static DraggableImage* selectedImage;
    int buttonId;
    bool isDragging;
    QPoint offset;
    QPoint originalPosition;
};

#endif
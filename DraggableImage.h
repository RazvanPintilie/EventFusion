#ifndef DRAGGABLEIMAGE_H
#define DRAGGABLEIMAGE_H

#include <QLabel>
#include <QMouseEvent>

class DraggableImage : public QLabel
{
    Q_OBJECT

public:
    DraggableImage(const QPixmap& pixmap, int buttonId, QWidget* parent = nullptr, int rotateNumber = 0);
    void setSelected(bool selected);

signals:
    void imageMoved(const QPoint& newPos);
    void deleteKeyPressed(int buttonId);
    void rightClick();
    void imageMovedd();

protected:
    void mousePressEvent(QMouseEvent* event) override;
    void mouseMoveEvent(QMouseEvent* event) override;
    void mouseReleaseEvent(QMouseEvent* event) override;
    void restoreOriginalPosition();
    void keyPressEvent(QKeyEvent* event);
public:
    int getRotateNumber();
    void rotateImage(int roateNumber);

private:
    static DraggableImage* selectedImage;
    int buttonId;
    bool isDragging;
    QPoint offset;
    QPoint originalPosition;
    int rotateNumber;
};

#endif
#ifndef RENDERAREA_H
#define RENDERAREA_H

#include <QWidget>
#include <QMouseEvent>
#include <memory>
#include "Shape.h"

class RenderArea : public QWidget {
    Q_OBJECT

public:
    explicit RenderArea(QWidget *parent = nullptr);
    QSize minimumSizeHint() const override;
    QSize sizeHint() const override;
    void addShape(std::unique_ptr<Shape> shape);
    int getNumOfShapes() const;

protected:
    void paintEvent(QPaintEvent *event) override;
    void mousePressEvent(QMouseEvent *event) override;
    void mouseMoveEvent(QMouseEvent *event) override;
    void mouseReleaseEvent(QMouseEvent *event) override;

private:
    std::vector<std::unique_ptr<Shape>> shapeChoices;
    Shape *selectedShape;
    QPoint lastMousePosition;
    int numberOfShapes;
};

#endif // RENDERAREA_H

#include "renderArea.h"
#include <QPainter>

RenderArea::RenderArea(QWidget *parent)
    : QWidget(parent), selectedShape(nullptr), numberOfShapes(0) {
    setFixedSize(1000, 500); // Set fixed size for the drawing area
}

QSize RenderArea::minimumSizeHint() const {
    return QSize(100, 100);
}

QSize RenderArea::sizeHint() const {
    return QSize(1000, 500);
}

void RenderArea::addShape(Shape* shape) {
    shapeChoices.push_back(shape);
    numberOfShapes++;
    update();
}

int RenderArea::getNumOfShapes() const {
    return numberOfShapes;
}

void RenderArea::paintEvent(QPaintEvent *event) {
    QPaintDevice* device(this);
    for (auto &shape : shapeChoices) {
        if (shape) {
            shape->draw(device);
        }
    }
}

void RenderArea::mousePressEvent(QMouseEvent *event) {
    for (auto it = shapeChoices.begin(); it != shapeChoices.end(); ++it) {
        if ((*it)->getRect().contains(event->pos())) {
            selectedShape = *it;
            lastMousePosition = event->pos();
            break;
        }
    }
}

void RenderArea::mouseMoveEvent(QMouseEvent *event) {
    if (selectedShape) {
        QPoint delta = event->pos() - lastMousePosition;
        selectedShape->move(delta.x(), delta.y());
        lastMousePosition = event->pos();
        update();
    }
}

void RenderArea::mouseReleaseEvent(QMouseEvent *event) {
    selectedShape = nullptr;
}

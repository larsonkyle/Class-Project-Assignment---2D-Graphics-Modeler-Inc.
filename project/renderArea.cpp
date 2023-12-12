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

void RenderArea::addShape(std::unique_ptr<Shape> shape) {
    shapeChoices.push_back(std::move(shape));
    numberOfShapes++;
    update();
}

int RenderArea::getNumOfShapes() const {
    return numberOfShapes;
}

void RenderArea::paintEvent(QPaintEvent *event) {
    QPainter painter(this);
    for (auto &shape : shapeChoices) {
        if (shape) {
            shape->draw(&painter);
        }
    }
}

void RenderArea::mousePressEvent(QMouseEvent *event) {
    for (auto it = shapeChoices.rbegin(); it != shapeChoices.rend(); ++it) {
        if ((*it)->getRect().contains(event->pos())) {
            selectedShape = it->get();
            lastMousePosition = event->pos();
            break;
        }
    }
}

void RenderArea::mouseMoveEvent(QMouseEvent *event) {
    if (selectedShape) {
        QPoint delta = event->pos() - lastMousePosition;
        selectedShape->move(delta.x(), delta.y(), 0);
        lastMousePosition = event->pos();
        update();
    }
}

void RenderArea::mouseReleaseEvent(QMouseEvent *event) {
    selectedShape = nullptr;
}

std::vector<std::unique_ptr<Shape>>& RenderArea::get_vector(){
    return shapeChoices;
}

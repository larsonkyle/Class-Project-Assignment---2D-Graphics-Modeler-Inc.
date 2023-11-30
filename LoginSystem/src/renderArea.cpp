// RenderArea.cpp

#include "renderArea.h"
#include <QPainter>

RenderArea::RenderArea(QWidget *parent)
    : QWidget(parent)
{
    setBackgroundRole(QPalette::Base);
    setFixedSize(sizeHint());
    setAutoFillBackground(true);
}

void RenderArea::addShape(Shape* shape)
{
    shapeChoices.push_back(shape);
    update();  // Schedule a repaint
}

QSize RenderArea::minimumSizeHint() const
{
    return QSize(1200, 600);
}

QSize RenderArea::sizeHint() const
{
    return QSize(1200, 600);
}

int RenderArea::getNumOfShapes() const
{
    return shapeChoices.size();
}

void RenderArea::paintEvent(QPaintEvent *)
{
    QPaintDevice *device = this;;

    for (int i = 0; i < shapeChoices.size(); i++) {
        shapeChoices[i]->draw(device);
    }
}


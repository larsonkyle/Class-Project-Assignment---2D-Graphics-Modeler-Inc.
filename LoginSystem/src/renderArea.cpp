// renderArea.cpp
#include "renderArea.h"
#include <QPainter>

RenderArea::RenderArea(QWidget *parent)
    : QWidget(parent), shapeChoices(9)
{
    setBackgroundRole(QPalette::Base);
    setAutoFillBackground(true);
    setFixedSize(1000, 500);
    numberOfShapes = 0;
}

QSize RenderArea::minimumSizeHint() const
{
    return QSize(100, 100);
}

QSize RenderArea::sizeHint() const
{
    return QSize(1000, 500);
}

const vector<Shape*>& RenderArea::getShape() const
{
    return shapeChoices;
}

void RenderArea::addShape(Shape* shapeAdd)
{
    shapeChoices.push_back(shapeAdd);
    ++numberOfShapes;
    update(); 
}

int RenderArea::getSize() const
{
    return numberOfShapes;
}

int RenderArea::getNumOfShapes() const
{
    return numberOfShapes;
}

void RenderArea::paintEvent(QPaintEvent *)
{
    QPaintDevice* device = this;
    for(int i = 0; i < shapeChoices.size(); i++)
        shapeChoices[i]->draw(device);
}

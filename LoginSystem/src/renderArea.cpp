// renderArea.cpp
#include "renderArea.h"
#include <QPainter>

RenderArea::RenderArea(QWidget *parent)
    : QWidget(parent), numberOfShapes(0)
{
    setAttribute(Qt::WA_StaticContents);
    setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    setBackgroundRole(QPalette::Base);
    setFixedSize(400, 200);
    setAutoFillBackground(true);
}

QSize RenderArea::minimumSizeHint() const
{
    return QSize(100, 100);
}

QSize RenderArea::sizeHint() const
{
    return QSize(400, 200);
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

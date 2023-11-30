#include "renderArea.h"

#include <QPainter>
#include <QPainterPath>

RenderArea::RenderArea(QWidget *parent)        //constructor
    : QWidget(parent), shapeChoice(10)
{
    numberOfShapes = 0;
    setBackgroundRole(QPalette::Base);
    setFixedSize(sizeHint());     
    setAutoFillBackground(true);
    
}
void RenderArea::addShape(Shape* shape)       //adds a new shape
{
    shape.push_back(shape);
    numberOfShapes++;
}

QSize RenderArea::minimumSizeHint() const   //minimum size
{
    return QSize(1200, 600);
}

QSize RenderArea::sizeHint() const           //size setter
{
    return QSize(1200, 600);
}

void RenderArea::setShape(Shape shape)       //sets the shape
{
    this->shape = shape;
    update();
}
int RenderArea::getNumOfShapes()               //gets number of shapes in program
{ 
    return numberOfShapes
}

void RenderArea::setPen(const QPen &pen)
{
    this->pen = pen;
    update();
}

void RenderArea::setBrush(const QBrush &brush)
{
    this->brush = brush;
    update();
}

void RenderArea::setAntialiased(bool antialiased)
{
    this->antialiased = antialiased;
    update();
}

void RenderArea::setTransformed(bool transformed)
{
    this->transformed = transformed;
    update();
}

void RenderArea::paintEvent(QPaintEvent *)
{
   QPaintDevice* shapeDevice = this;
    for(int i = 0; i < shape.size(); i++)
        shape[i]->draw(shapeDevice);
}

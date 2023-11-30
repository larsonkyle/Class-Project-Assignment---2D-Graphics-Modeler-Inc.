// renderArea.cpp
#include "renderArea.h"
#include <QPainter>

RenderArea::RenderArea(QWidget *parent)
    : QWidget(parent), numberOfShapes(0)
{
    setAttribute(Qt::WA_StaticContents);
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
    update(); // Trigger repaint
}

int RenderArea::getSize() const
{
    return numberOfShapes;
}

int RenderArea::getNumOfShapes() const
{
    return numberOfShapes;
}

void RenderArea::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);
    painter.setRenderHint(QPainter::Antialiasing, true);

    for (const auto& shape : shapeChoices)
    {
        if (shape)
        {
            shape->draw(0, 0);
        }
    }

    painter.end();
}

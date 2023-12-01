#ifndef RENDERAREA_H
#define RENDERAREA_H

#include "Shape.h"
#include "vector_doubles.h"
#include <QBrush>
#include <QPen>
#include <QWidget>
#include <QImage>
#include <QMenu>
#include <QContextMenuEvent>

class Shape;

class RenderArea : public QWidget
{
    Q_OBJECT

public:
    RenderArea(QWidget *parent = nullptr);
    QSize minimumSizeHint() const override;
    QSize sizeHint() const override;
    const vector<Shape*>& getShape() const;
    void addShape(Shape* shapeAdd);
    int getSize() const;
    int getNumOfShapes() const;
    //QMenu* getShapeMenu() const;

protected:
    void paintEvent(QPaintEvent *event) override;
    //void contextMenuEvent(QContextMenuEvent *event) override;

private:
    QImage renderArea;
    int numberOfShapes;
    vector<Shape*> shapeChoices;
    //QMenu* shapeMenu;
};

#endif // RENDERAREA_H

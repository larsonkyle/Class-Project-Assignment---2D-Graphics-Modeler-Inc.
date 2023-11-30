#ifndef RENDERAREA_H
#define RENDERAREA_H

#include "vector_doubles.h"
#include "Shape.h"
#include <QBrush>
#include <QPaintEvent>
#include <QPen>
#include <QWidget>
#include <QFile>
#include <QMessageBox>

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
    void paintEvent(QPaintEvent *event) override;

private:
    QImage renderArea;
    int numberOfShapes;
    vector<Shape*> shapeChoices;
};

#endif // RENDERAREA_H

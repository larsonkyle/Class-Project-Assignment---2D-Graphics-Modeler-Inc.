#ifndef RENDERAREA_H
#define RENDERAREA_H

#include "vector_doubles.h"
#include "shape.h"
#include <QBrush>
#include <QPen>
#include <QWidget>

class RenderArea : public QWidget
{   
public:
    RenderArea(QWidget *parent = nullptr);
    QSize minimumSizeHint() const override;
    QSize sizeHint() const override;
    const vector<Shape*>& getShape();
    void addShape(Shape* shape)

    void setShape(Shape shape);
    void setPen(const QPen &pen);
    void setBrush(const QBrush &brush);
    void setAntialiased(bool antialiased);
    void setTransformed(bool transformed);
    void paintEvent(QPaintEvent *event) override;
    
private:
    const QImage renderArea;
    vector<Shape*> shapes;
    Shape shape;
    QPen pen;
    QBrush brush;
    bool antialiased;
    bool transformed;
};

#endif // RENDERAREA_H

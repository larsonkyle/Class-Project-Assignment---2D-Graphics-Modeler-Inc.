#ifndef ELLIPSE_H_
#define ELLIPSE_H_

#include "Shape.h"

class Ellipse : public Shape{
public:
    Ellipse(QPaintDevice * device, int id = -1) : Shape{device, id, ShapeType::Ellipse} { }
    Ellipse() : Shape{nullptr, -1, ShapeType::Ellipse} {}

    ~Ellipse() override {}
    void set_ellipse(const QRect& new_ellipse) {ellipse = new_ellipse;}
    QRect getRect() override {return ellipse;}
    bool isCircle() const;

    void move(int x, int y, int vertex) override;
    void draw(QPainter *painter) override;

private:
    QRect ellipse;
    double width;
    double height;
    QPoint location;
};


#endif

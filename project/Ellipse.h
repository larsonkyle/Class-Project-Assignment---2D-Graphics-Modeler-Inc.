#ifndef ELLIPSE_H_
#define ELLIPSE_H_

#include "Shape.h"

class Ellipse : public Shape{
public:
    Ellipse(QPaintDevice * device, int id = -1) : Shape{device, id, ShapeType::Ellipse} { }
    Ellipse() : Shape{nullptr, -1, ShapeType::Ellipse} {}
    ~Ellipse() override {}

    bool isCircle() const;
    void set_ellipse(const QRect& new_ellipse) {ellipse = new_ellipse;}
    QRect getRect() override {return ellipse;}

    void draw(QPaintDevice* device) override;
    void move(int translate_x, int translate_y) override;
    double getPerimeter() override;
    double getArea() override;

private:
    QRect ellipse;
};


#endif

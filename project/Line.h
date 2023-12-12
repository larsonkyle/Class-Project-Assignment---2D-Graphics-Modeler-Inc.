#ifndef LINE_H_
#define LINE_H_

#include "Shape.h"

class Line : public Shape {
public:
    Line(QPaintDevice * device, int id = -1) : Shape{device, id, ShapeType::Line} {}
    Line() : Shape{nullptr, -1, ShapeType::Line} {}
    ~Line() override {}

    void set_point(const QPoint& point_begin, const QPoint& point_end);

    QPoint getPointBegin() override {return point_begin;}
    QPoint getPointEnd() override {return point_end;}

    void draw(QPaintDevice* device) override;
    void move(int translate_x, int translate_y) override;
    double getPerimeter() override {return 0;}
    double getArea() override {return 0;}

private:
    QPoint point_begin;
    QPoint point_end;
};

#endif // LINE_H_

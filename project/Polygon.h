#ifndef POLYGON_H_
#define POLYGON_H_

#include "Shape.h"

class Polygon : public Shape{
public:
    Polygon(QPaintDevice * device, int id = -1) : Shape{device, id, ShapeType::Polygon} {}
    Polygon() : Shape{nullptr, -1, ShapeType::Polygon} {}
    ~Polygon() override {}

    void set_point(const QPoint& point);
    vector<QPoint> getPoints() override {return points;}

    void draw(QPaintDevice* device) override;
    void move(int translate_X, int translate_y) override;
    double getPerimeter() override;
    double getArea() override;

private:
    vector<QPoint> points;
};

#endif


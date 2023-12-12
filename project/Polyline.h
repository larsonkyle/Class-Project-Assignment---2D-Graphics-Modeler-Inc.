#ifndef POLYLINE_H_
#define POLYLINE_H_
#include "Shape.h"

class Polyline : public Shape{
public:
    Polyline(QPaintDevice * device, int id = -1) : Shape{device, id, ShapeType::Polyline} {}
    Polyline() : Shape{nullptr, -1, ShapeType::Polyline} {}
    ~Polyline() override {}

    void set_point(const QPoint& point);
    vector<QPoint> getPoints() override {return points;} //to read current points

    void draw(QPaintDevice* device) override;
    void move(int translate_x, int translate_y) override;
    double getPerimeter() override {return 0;}
    double getArea() override {return 0;}

private:
    vector<QPoint> points;
};

#endif

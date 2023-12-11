#ifndef RECTANGLE_H_
#define RECTANGLE_H_

#include "Shape.h"

class Rectangle : public Shape{
public:
    Rectangle(QPaintDevice * device, int id = -1) : Shape{device, id, ShapeType::Rectangle} { }
    Rectangle() : Shape{nullptr, -1, ShapeType::Rectangle} {}

    ~Rectangle() override {}

    bool isSquare() const;
    void set_rect(const QRect& rect);
    const vector<QPoint>& getPoints() const;

    void move(int x, int y, int vertex) override;
    void draw(QPainter *painter) override;
    void setLocation(int x, int y);
    void setDimensions(double w, double h);
    double getWidth();
    double getHeight();
    QPoint& getLocation();

private:
    vector<QPoint> points; //QRect rect;
    double width;
    double height;
    QRect rect;
    QPoint location;
};

#endif

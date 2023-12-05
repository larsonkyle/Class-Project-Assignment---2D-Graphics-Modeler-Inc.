#ifndef RECTANGLE_H_
#define RECTANGLE_H_

#include "Shape.h"

class Rectangle : public Shape{
	public:
        Rectangle(int id = -1) : Shape{id, ShapeType::Rectangle} { }
        //~Rectangle() override {}

		bool isSquare() const;
        void set_rect(const QRect& new_rect) {rect = new_rect;}
        QRect getRect() override {return rect;}

        void draw(QPaintDevice* device) override;
        void move(int translate_x, int translate_y) override;
        double getPerimeter() override {return (2 * rect.width() + 2 * rect.height());}
        double getArea() override {return rect.width() * rect.height();}

    private:
        QRect rect;
};

#endif 

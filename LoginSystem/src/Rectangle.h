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

    private:
        QRect rect;
};

#endif 

#ifndef RECTANGLE_H_
#define RECTANGLE_H_

#include "Shape.h"

class Rectangle : public Shape{
	public:
        Rectangle(QPaintDevice* device = nullptr, int id = -1) : Shape{device, id, ShapeType::Rectangle} { }
        ~Rectangle() {}

		bool isSquare() const;
		void set_rect(const QRect& rect);

		void draw(const int translate_x = 0, const int translate_y = 0) override;

	private:
		vector<QPoint> points; //QRect rect;
};

#endif 

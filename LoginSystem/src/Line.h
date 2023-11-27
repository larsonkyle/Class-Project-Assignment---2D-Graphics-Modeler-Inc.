#ifndef LINE_H_
#define LINE_H_

#include "Shape.h"

class Line : public Shape{
    public:
        Line(QPaintDevice* device = nullptr, int id = -1) : Shape{device, id, ShapeType::Line} {}
        //~Line() { }

		void set_point(const QPoint& point_begin, const QPoint& point_end);

		void draw(const int translate_x = 0, const int translate_y = 0) override;

	private:
		QPoint point_begin;
		QPoint point_end;
};


#endif

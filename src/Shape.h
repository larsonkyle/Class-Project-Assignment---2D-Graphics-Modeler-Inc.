#ifndef SHAPE_H_
#define SHAPE_H_

#include <QPaintDevice>
#include <QPainter>
#include <QObject>
#include <QPen>
#include <QBrush>
#include <QRect>
#include "../vector_doubles.h"

using namespace myStd;
using namespace Qt;

class Shape{
	public:
		enum class ShapeType {NoShape, Line, Polyline, Polygon, Rectangle, Ellipse, Text};

        Shape(QPaintDevice* device = nullptr, int id = -1, ShapeType shape = ShapeType::NoShape); // :;
		virtual ~Shape() {  }


		ShapeType get_shape() const;
		const QPen& get_pen() const;
		const QBrush& get_brush() const;

		void set_shape(ShapeType shape);
		void set_pen(Qt::GlobalColor, int width, Qt::PenStyle, Qt::PenCapStyle, Qt::PenJoinStyle);
		void set_pen(Qt::GlobalColor);
		void set_brush(Qt::GlobalColor, Qt::BrushStyle);

		void default_style();
		void draw_rect(int width, int height);

		virtual void draw(const int translate_x, const int translate_y) = 0;

	protected:
		QPainter& get_qpainter();

	private:
		QPainter* p_qpainter; //Maybe use Unique Pointer???

		int id;
		ShapeType shape;
		QPen pen;
		QBrush brush;
};

#endif

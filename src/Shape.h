#ifndef SHAPE_H_
#define SHAPE_H_

#include <QPaintDevice>
#include <QPainter>
#include <QObject>
#include <QPen>
#include <QBrush>
#include <QRect>
#include <memory>
#include "../LoginSystem/vector_doubles.h"

using namespace myStd;
using namespace Qt;

class Shape{
	public:
		enum class ShapeType {NoShape, Line, Polyline, Polygon, Rectangle, Ellipse, Text};

        Shape(QPaintDevice* device = nullptr, int setId = -1, ShapeType sh = ShapeType::NoShape);
        virtual ~Shape();


		ShapeType get_shape() const;
		const QPen& get_pen() const;
		const QBrush& get_brush() const;
        int getId() const;

        void set_shape(ShapeType sh);
        void set_pen(Qt::GlobalColor pc, int width, Qt::PenStyle ps, Qt::PenCapStyle pcs, Qt::PenJoinStyle pjs);
        void set_pen(Qt::GlobalColor pc);
        void set_brush(Qt::GlobalColor bc, Qt::BrushStyle bs);
        void set_id(int setId);

		void default_style();
		void draw_rect(int width, int height);

		virtual void draw(const int translate_x, const int translate_y) = 0;

	protected:
		QPainter& get_qpainter();

	private:
         std::unique_ptr<QPainter> p_qpainter; //UNIQUE PTR woo

		int id;
		ShapeType shape;
		QPen pen;
		QBrush brush;
};

#endif

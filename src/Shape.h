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
        //virtual ~Shape();

        //deliverable: must disable copy operations
        Shape(const Shape&) = delete;
        Shape& operator=(const Shape&) = delete;


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

        //used to sort by ID
        bool operator==(const Shape& right);
        //Precondtions: an initialized Shape object with a valid ID
        //Postconditions: will return a true/false whether the IDs are equal
        bool operator<(const Shape& right);
        //Precondtions: an initialized Shape object with a valid ID
        //Postconditions: will return a true/false whether the left object's ID
        //               is less than the right object's ID


		virtual void draw(const int translate_x, const int translate_y) = 0;

	protected:
		QPainter& get_qpainter();

	private:
        QPainter qpainter;

		int id;
		ShapeType shape;
		QPen pen;
		QBrush brush;
};

#endif

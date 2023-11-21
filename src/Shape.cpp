#include "Shape.h"
Shape::Shape(QPaintDevice* device, int setId, ShapeType sh){
//     std::make_unique<QPainter>(device);
    // assign paint device to qpainter??? wat

    id = setId;
    shape = sh;
}

Shape::~Shape(){
  //unique ptr :D
}

/*****GETTERS*****/
int Shape::getId() const{
   return  id;
}

Shape::ShapeType Shape::get_shape() const{
    return shape;
}

const QPen& Shape::get_pen() const{
    return pen;
}

const QBrush& Shape::get_brush() const{
    return brush;
}
//protected:
 QPainter& Shape::get_qpainter(){
    return *p_qpainter;
}

/*****SETTERS*******/
void Shape::set_shape(ShapeType sh){
    shape = sh;
}

void Shape::set_pen(Qt::GlobalColor pc, int width, Qt::PenStyle ps, Qt::PenCapStyle pcs, Qt::PenJoinStyle pjs){
    pen.setColor(pc);
    pen.setWidth(width);
    pen.setStyle(ps);
    pen.setCapStyle(pcs);
    pen.setJoinStyle(pjs);
}

void Shape::set_pen(Qt::GlobalColor pc){
    pen.setColor(pc);
}

void Shape::set_brush(Qt::GlobalColor bc, Qt::BrushStyle bs){
    brush.setColor(bc);
    brush.setStyle(bs);
}

void Shape::set_id(int setId){
    id = setId;
}
/******set default style*****/
void Shape::default_style(){
    pen = Qt::SolidLine;
    brush = Qt::NoBrush;

    p_qpainter->setPen(pen);
    p_qpainter->setBrush(brush);
}

void Shape::draw_rect(int width, int height){
 //??
}

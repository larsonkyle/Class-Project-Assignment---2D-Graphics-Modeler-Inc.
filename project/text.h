#ifndef TEXT_H_
#define TEXT_H_

#include "Shape.h"

class Text : public Shape{
public:
    Text(QPaintDevice * device, int id = -1) : Shape(device, id, ShapeType::Text) { }
    Text() : Shape{nullptr, -1, ShapeType::Text} {}
    ~Text() override {}

    void set_text(const QRect& tO, const QString t, const QColor c, const AlignmentFlag a,
                  const int pS, const QString f, const QFont::Style s, const QFont::Weight w);

    QRect getRect() override {return textBox;}
    QFont get_font() override {return font;}

    QString getTextString() override {return text;}
    QColor getTextColor() override {return color;}
    AlignmentFlag getAlign() override {return align;}

    void draw(QPaintDevice* device) override;
    void move(int translate_x, int translate_y) override;
    double getPerimeter() override {return (2 * textBox.width() + 2 * textBox.height());}
    double getArea() override {return textBox.width() * textBox.height();}

private:
    QRect textBox;
    QString text {"Class Project - 2D Graphics Modeler"};
    QColor color {blue};
    AlignmentFlag align {AlignCenter};

    int pointSize {10};
    QString family {"Comic Sans MS"};
    QFont::Style style {QFont::StyleNormal};
    QFont::Weight weight {QFont::Normal};
    QFont font; //in set_text, feed everything from above into here. Then give to qpainter.

};

#endif

#ifndef TEXT_H_
#define TEXT_H_

#include "Shape.h"

class Text : public Shape{
public:
    Text(QPaintDevice * device, int id = -1) : Shape(device, id, ShapeType::Text) { }
    Text() : Shape{nullptr, -1, ShapeType::Text} {}
    ~Text() override {}

    void set_textBox(const QRect& new_textBox) {textBox = new_textBox;}
    void set_font(const int pS, const std::string f, const QFont::Style s, const QFont::Weight w) {
        font.setFamily(QString(f.c_str()));
        font.setStyle(s);
        font.setPointSize(pS);
        font.setWeight(w);
    }
    void set_text(const std::string t, const AlignmentFlag a);

    QRect getRect() override {return textBox;}
    QFont get_font() override {return font;}

    QString getTextString() override {return text;}
    QColor getTextColor() override {return get_pen().color();}
    AlignmentFlag getAlign() override {return align;}

    void draw(QPaintDevice* device) override;
    void move(int translate_x, int translate_y) override;
    double getPerimeter() override {return (2 * textBox.width() + 2 * textBox.height());}
    double getArea() override {return textBox.width() * textBox.height();}

private:
    QRect textBox;
    QString text;
    AlignmentFlag align;

    QFont font; //in set_text, feed everything from above into here. Then give to qpainter.

};

#endif

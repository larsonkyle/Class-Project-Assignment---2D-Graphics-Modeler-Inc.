#ifndef TEXT_H_
#define TEXT_H_

#include "Shape.h"

class Text : public Shape{
public:
    Text(QPaintDevice * device, int id = -1) : Shape(device, id, ShapeType::Text) { }
    Text() : Shape{nullptr, -1, ShapeType::Text} {}

    ~Text() override {}

    void set_text(const QRect& tO, const QString t, const QColor c, const Qt::AlignmentFlag a,
                  const int pS, const QString f, const QFont::Style s, const QFont::Weight w);

    const QFont& get_font() const;
    //Preconditions: the text object has been set with set_text(...)
    //Postconditions: will return a reference to the font attribute to read what the font is.

    void move(int x, int y, int vertex) override;
    void draw(QPainter *painter) override;
    void setLocation(int x, int y);
private:
    QRect rect;
    QString text {"Class Project - 2D Graphics Modeler"};
    QColor color {Qt::blue};
    Qt::AlignmentFlag align {Qt::AlignCenter};
    int pointSize {10};
    QString family {"Comic Sans MS"};
    QFont::Style style {QFont::StyleNormal};
    QFont::Weight weight {QFont::Normal};
    QPoint location;
    QFont font; //in set_text, feed everything from above into here. Then give to qpainter.
};



#endif

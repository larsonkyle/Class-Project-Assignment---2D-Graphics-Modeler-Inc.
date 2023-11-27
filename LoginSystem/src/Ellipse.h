#ifndef ELLIPSE_H
#define ELLIPSE_H

#include "Shape.h"

class Ellipse : public Shape{
    public:
        Ellipse(QPaintDevice* device = nullptr, int id = -1) : Shape{device, id, ShapeType::Ellipse} { }
        //~Ellipse() { }

        bool isCircle() const;
        void set_ellipse(const QRect& rect);

        void draw(const int translate_x = 0, const int translate_y = 0) override;

    private:
        QRect rect;
};

#endif

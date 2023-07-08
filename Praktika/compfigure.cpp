#include "pch.h"
#include <iostream>
#include "compfigure.h"

CompFigure::CompFigure(int x1, int x2, int y, int a, int r) {
    double ca = sqrt((x2 - x1) * (x2 - x1) + (a * a) / 4);
    double cb = (a / 2) * sqrt((2 * ca - a) / (2 * ca + a));
    if (!((cb - r) < 5 && (cb - r) > -5)) {
        throw gcnew System::Exception("Ошибка сложной фигуры: Окружность с данным радиусом не вписывается в треугольник");
    }
    else {
        c = new Circle(x1 + r, y, r);
        t = new Triangle(x1, x2, y, a);
    }
};

void CompFigure::show(Graphics^ g) {
    t->show(g);
    c->show(g);
};

void CompFigure::hide(Graphics^ g) {
    t->hide(g);
    c->hide(g);
};

void CompFigure::replace(int newx, int newy, Graphics^ g) {
    t->replace(newx, newy, g);
    c->replace(newx + c->getrad(), newy, g);
};

CompFigure::~CompFigure() {
    delete c;
    delete t;
};
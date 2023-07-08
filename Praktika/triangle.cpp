#include "pch.h"
#include <iostream>
#include "triangle.h"

Triangle::Triangle(int x1, int _x2, int y, int _a) : Figure(x1, y), x2(_x2), a(_a) {
    if (x2 <= x) {
        throw gcnew System::Exception("Ошибка ввода: X2 должен быть больше X1");
    }
    if (y + a / 2 > 560 || x2 > 683 || y - a / 2<0) {
        throw gcnew System::Exception("Фигура выходит за границу окна");
    }
};

void Triangle::show(Graphics^ g) {
    cli::array<Point>^ p = gcnew cli::array<Point>(3);
    p[0].X = x; p[0].Y = y + a / 2;
    p[1].X = x; p[1].Y = y - a / 2;
    p[2].X = x2; p[2].Y = y;
    g->FillPolygon(Brushes::Green, p);
    g->DrawPolygon(Pens::Black, p);
};

void Triangle::hide(Graphics^ g) {
    cli::array<Point>^ p = gcnew cli::array<Point>(3);
    p[0].X = x; p[0].Y = y + a / 2;
    p[1].X = x; p[1].Y = y - a / 2;
    p[2].X = x2; p[2].Y = y;
    Pen^ pen = gcnew Pen(System::Windows::Forms::Control::DefaultBackColor);
    SolidBrush^ bruh = gcnew SolidBrush(System::Windows::Forms::Control::DefaultBackColor);
    g->FillPolygon(bruh, p);
    g->DrawPolygon(pen, p);
};

void Triangle::replace(int newx, int newy, Graphics^ g) {
    if (newy + a / 2 > 560 || newx + (x2 - x) > 683 || newy - a / 2 < 0) {
        throw gcnew System::Exception("Перемещение за границу окна");
    }
    else {
        x2 = newx + (x2 - x);
        x = newx;
        y = newy;
    }
};
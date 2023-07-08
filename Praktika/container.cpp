#include "pch.h"
#include <iostream>
#include "container.h"

void Contain::add(Figure* f) {
    Figures.push_back(f);
};
void Contain::showall(Graphics^ g) {
    for (int i = 0; i < Figures.size(); i++) {
        if (Figures[i]->isvisible == true) {
            Figures[i]->show(g);
        }
    }
}
void Contain::allvisible() {
    for (int i = 0; i < Figures.size(); i++) {
        Figures[i]->isvisible = true;
    }
}
void Contain::showbyid(int id) {
    Figures[id]->isvisible = true;
}
void Contain::hidebyid(int id) {
    Figures[id]->isvisible = false;
}
void Contain::replacebyid(int newx, int newy, int id, Graphics^ g) {
    Figures[id]->replace(newx, newy, g);
}
bool Contain::checkbyid(int id) {
    return Figures[id]->isvisible;
}
int Contain::getsize() {
    return(Figures.size());
}
void Contain::clean(Graphics^ g) {
    for (int i = 0; i < Figures.size(); i++) {
        Figures[i]->hide(g);
    }
    Figures.clear();
}
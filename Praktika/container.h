#pragma once
#include <vector>
#include "baseclass.h"

class Contain {
private:
    vector<Figure*> Figures;
public:
    void add(Figure* f);
    void showall(Graphics^ g);
    void allvisible();
    void showbyid(int id);
    void hidebyid(int id);
    void replacebyid(int newx, int newy, int id, Graphics^ g);
    bool checkbyid(int id);
    int getsize();
    void clean(Graphics^ g);
};
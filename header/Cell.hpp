#ifndef _Cell_h_
#define _Cell_h_

#include <string>
#include <stdio.h>

using namespace std;

class Cell
{
private:
    int id;
    int x1;
    int x2;
    int y1;
    int y2;

public:
    Cell(int id, int x1, int x2, int y1, int y2);
    bool isInCell(int x, int y);
    int cellId() const;
};

int inline Cell::cellId() const { return id; }

#endif
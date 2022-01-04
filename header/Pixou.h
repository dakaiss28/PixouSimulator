#include "Position.h"
#include <stdio.h>
#include <string>
using namespace std;

class Pixou
{
private:
    string nom;
    Position position;
    int points;

public:
    Pixou(string nom, int points = 0);
    void movePixou(int sp);
    void updatePoints(int upd);
    ~Pixou();
};

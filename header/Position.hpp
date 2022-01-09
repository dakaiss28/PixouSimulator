#ifndef _Position_hpp_
#define _Position_hpp_

class Position
{
private:
    int _x;
    int _y;

public:
    Position();
    Position(int x, int y);
    int x() const;
    int y() const;
    void set_x(int x);
    void set_y(int y);
    bool operator==(const Position &p);
    ~Position() = default;
};

inline int Position::x() const { return _x; }
inline int Position::y() const { return _y; }
inline void Position::set_x(int x) { _x = x; }
inline void Position::set_y(int y) { _y = y; }

#endif
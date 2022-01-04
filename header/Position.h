class Position
{
private:
    int _x;
    int _y;

public:
    Position(int x, int y);
    int x() const;
    int y() const;
    void set_x(int x);
    void set_y(int y);
    friend bool operator==(const Position &p1, const Position &p2);
    ~Position();
};

inline int Position::x() const { return _x; }
inline int Position::y() const { return _y; }
inline void Position::set_x(int x) { _x = x; }
inline void Position::set_y(int y) { _y = y; }

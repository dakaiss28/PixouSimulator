#include "Position.h"

class Reward

{
private:
    Position _position;
    int _rewards;
    int _speed;

public:
    Reward(int rw, int sp);
    Position position() const;
    int rewards() const;
    int speed() const;
    virtual void dropReward() = 0;
    ~Reward();
};

inline Position Reward::position() const { return _position; }
inline int Reward::rewards() const { return _rewards; }
inline int Reward::speed() const { return _speed; }

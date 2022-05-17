//
// Created by peron on 01/05/2022.
//

#include <iostream>

#ifndef PROJET_POSITION_H
#define PROJET_POSITION_H

class Position {

    friend bool operator==(const Position& p1, const Position& p2);
    friend std::ostream& operator<<(std::ostream&f, const Position p);

private:
    int x;
    int y;
public:
    Position() : x(0), y(0) {}
    Position(int x, int y) : x(x), y(y) {}
    Position(const Position& p) = default;
    Position& operator=(const Position& p) = default;
    ~Position() = default;
    int getPositionX() const { return x; }
    int getPositionY() const { return y; }
    void setPosition(int x, int y) { this->x = x; this->y = y; }

};

#endif //PROJET_POSITION_H

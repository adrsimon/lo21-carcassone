//
// Created by peron on 01/05/2022.
//

#include "position.h"

bool operator==(const Position& p1, const Position& p2) {
    if(p1.x == p2.x && p1.y == p2.y) return true;
    return false;
}

std::ostream& operator<<(std::ostream&f, const Position p) {
    f << "(" << p.getPositionX() << "," << p.getPositionY() << ")";
    return f;
}
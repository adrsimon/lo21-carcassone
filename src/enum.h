#ifndef enum_h
#define enum_h

#include <list>
#include <string>


class TypeCardinaux {
public:
    enum points {nord, est, sud, ouest, ouest_nord, nord_ouest, nord_est, est_nord, est_sud, sud_est, sud_ouest, ouest_sud, last};
    static points getOrientationInverse(points t);
    static points getNextOrientations(points t);
    static std::string toString(points t);
    static bool isStraight(points t1, points t2);
};

class TypeExtension {
public:
    enum points {main, riviere, auberge, paysan, abbe};
    static std::string toString(points t);
};

class TypeElement {
public:
    enum points {riviere, ville, abbaye, pre, route, jardin, last};
    static std::string toString(points t);
};

class TypeMeeple {
public:
    enum points { normal, big, abbe};
    static std::string toString(points t);
};

class TypeCouleur {
public:
    enum points {rouge, bleu, vert, jaune, rose, orange};
    static std::string toString(points t);
};


#endif /* enum_h */

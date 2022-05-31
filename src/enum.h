#ifndef enum_h
#define enum_h

#include <list>
#include <string>

const std::list<std::string> orientationPrincipale = {"N", "E", "S", "O"};
const std::list<std::string> orientationPre = { "ON", "NO", "NE", "EN", "ES", "SE", "SO", "OS"};

class TypeCardinaux {
public:
    enum points {nord, est, sud, ouest, ouest_nord, nord_ouest, nord_est, est_nord, est_sud, sud_est, sud_ouest, ouest_sud};
    points getOrientationInverse(points t);
    points getNextOrientations(points t);
};

enum class TypeElement {riviere, ville, abbaye, pre, route, jardin, last};

enum class TypeMeeple { normal, big, abbe, paysan, last};

#endif /* enum_h */

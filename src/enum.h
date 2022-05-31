#ifndef enum_h
#define enum_h

#include <list>
#include <string>

class TypeCardinaux {
public:
    enum points {nord, est, sud, ouest, ouest_nord, nord_ouest, nord_est, est_nord, est_sud, sud_est, sud_ouest, ouest_sud};
    static points getOrientationInverse(points t);
    static points getNextOrientations(points t);
};

enum class TypeExtension {main, riviere, auberge};

enum class TypeElement {riviere, ville, abbaye, pre, route, jardin, last};

enum class TypeMeeple { normal, big, abbe, paysan, last};

#endif /* enum_h */

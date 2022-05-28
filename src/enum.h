#ifndef enum_h
#define enum_h

#include <list>
#include <string>

const std::list<std::string> orientationPrincipale = {"N", "E", "S", "O"};
const std::list<std::string> orientationPre = { "ON", "NO", "NE", "EN", "ES", "SE", "SO", "OS"};

const std::list<std::string> Type = {"riviere", "ville", "abbaye", "pre", "route", "jardin"};
const std::list<std::string> meeple_type = {"Normal", "Abbe", "Big"};

#endif /* enum_h */

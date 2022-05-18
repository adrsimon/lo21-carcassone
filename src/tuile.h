#ifndef tuile_h
#define tuile_h

#include "element.h"
#include "position.h"

class Tuile {
private:
    Position position;
    int nombreElement;
    int ID;
    bool hasMonastere;
    bool hasJardin;
    Element** liste;
public:
    Tuile(int& nb, bool& m, bool& j, int& id );
    ~Tuile() {
        for (int i=0; i < nombreElement; i++){
            liste[i]->~Element();
        }
        delete[] liste;
    };
    void changeOrientation(orientation* nouvOrient);
    void updatePosition (const int& x, const int& y);
    Position* getPosition ();

    Element** getElement()const{
        return liste;
    }

    Tuile(Tuile *pTuile);
};

#endif
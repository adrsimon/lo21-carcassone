#include "Tuile_GameEngine.h"
Tuile :: Tuile (int nb, bool m, bool j, int id ) : nombreElement (nb), hasMonastere(m), hasJardin(j), ID (id) {
    position = Position (-1,-1);
    liste= new Element** [nb];
    for (int i=0, i<nb, i++){
        //import du fichier des elements avec restriction sur l'id de la tuile)
        liste [i]= Element ();
    }
}

void Tuile ::changeOrientation ()
{
    for (int i =0, i<nb, i++){
        liste[i].updateOrientation();
    }
}
void Tuile :: updatePosition (const int& x, const int& y){
    position.x = x;
    position.y=y;
    for (int i =0, i<nombreElement, i++){
        liste[i].updatePosition( int x, int y);
    }
}

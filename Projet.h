class Position {

public :
    updateX();
    updateY();
private:
    int x;
    int y;
}


class Tuile {
public:
    Tuile (): nombreElement (nb), hasMonastere(m), hasJardin(j), ID (id) {
        position* = Position (-1,-1);
        liste= new Element** [nb];
        for (int i=0, i<nb, i++){
            //import du fichier des elements avec restriction sur l'id de la tuile)
            liste [i]= Element ();
        }
    }
    ~Tuile() {
        delete position;
        for (int i=0, i<nb, i++){
            liste [i]= ~Element ();
        delete [nombreElement] liste;

    };
    void changeOrientation ()
    {
        for (int i =0, i<nb, i++){
            liste[i].updateOrientation();
    }
    }
    void updatePosition (int x, int y){
        position.x = x;
        position.y=y;
        for (int i =0, i<nombreElement, i++){
            liste[i].updatePosition( int x, int y);
    }
    }
    getElement(){
        return liste;
    }
private:
    Position* position =nullptr ;
    int nombreElement;
    const int ID;
    bool hasMonastere;
    bool hasJardin;
    Element** liste;

}
//Tuile(nombre, ID, Monastere, Jardin, tabo){
//    nb = n;
//    ID = ID;
//    hasMonastere = Monastere;
//    hasJardin = Jardin;
//    for ( i=0, i<5, i++){
//        orientation [i]=tabo[i];
//    }
//}
updatePosition (int x, int y){
    this.position.x = x;
    this.position.x = y;
}

updateOrientation (){
    for (i =0, i<4, i++){
        if (orientation[i] ==N){
            orientation[i]=E;

        }
        if (orientation[i] ==W){
            orientation[i]=N;
        }
        if (orientation[i] ==E){
            orientation[i]=S;
        }
        if (orientation[i] ==S){
            orientation[i]=W;
        }

    }
}
class GameEngine{
private:
    Jeu jeu;
public:
    GameEngine();
    ~GameEngine();
    void gererExtensions(); // selectionne des options pour creer le singleton jeu après
    void creerJeu();//appelle el constructeur du jeu en rentrant les données souhaitées
    void creerJoueur();// creer un objet joueur et l'ajoute dans Jeu
    void creerCartes (); //genere les cartes avec le fichier ( si riviere est cochée) alors mettre ces cartes au debut)
};

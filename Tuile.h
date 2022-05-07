

class Tuile {
public:
    Tuile (int& nb, bool& m, bool& j, int& id );
    ~Tuile() {
        delete position;
        for (int i=0, i<nombreElement, i++){
            liste [i]= ~Element ();
        delete [nombreElement] liste;

    };
    void changeOrientation ();
    void updatePosition (const int& x, const int& y);
    getElement()const{
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


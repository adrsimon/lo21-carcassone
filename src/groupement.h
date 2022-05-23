#if !defined(_GROUPEMENT_H)
#define _GROUPEMENT_H
#include <iostream>
#include <string>


using namespace std;
enum class Types : char {riviere, ville, abbaye, pre, route, jardin};

class Groupement{
private:
    Meeple** liste[]; // Liste de pointeurs pointant sur la classe Meeple
    unsigned int dim_l;
    Types types;
    unsigned int points;
    Element* element[];
    unsigned int dim_e;
    unsigned int id;
    bool complete=false;
public:
    unsigned int getPoint() const {return points;}
    unsigned int getID() const {return id;}
    Meeple** getMeeple() const {return (**liste).Id;}
    Types getType() const {return types;}
    void setMeeple();

    bool isComplete(){
        complete=true;
        return complete;
    }

    virtual ~Groupement(){delete[] element; delete[] liste;}
    
    Groupement(const Groupement& g): dim_l(g.dim_l), dim_e(g.dim_e),liste(new Meeple** [dim_l]),element(new double [dim_e]),id(g.id),types(g.types),complete(FALSE){
        for (unsigned int i=0; i<dim_l; i++){
            liste[i]=g.liste[i];
        }
        for (unsigned int i=0; i<dim_e; i++){
            element[i]=g.element[i];
        }
    }
    
    virtual Groupement& operator=(const Groupement& g)=delete;
    
    class iterator{ //Accès en écriture ici
        friend class Groupement;
        double* courant;
        double* fin;
        iterator(double* deb, double* f):courant(deb), fin(f){}
    public:
        void next(){
            if(courant==fin) throw "erreur:débordement d'iterator";
            ++courant;
        }
        bool is_done(){return courant==fin;}
        double& current_item(){return *courant;}
    };
    iterator get_iterator(){return iterator(liste, liste+dim_l);}
};

    
    
    class GroupementRoute: public Groupement{
    private:
        int nbSegments;
        int nbAuberges;
    public:
        GroupementRoute(const GroupementRoute& g): nbSegments(g.nbSegments), nbAuberges(g.nbAuberges){}
        ~GroupementRoute()=default;
        int getNbSegments()const {return nbSegments;}
        int getNbAuberges()const {return nbAuberges;}
        
    };
    
    class GroupementVille: public Groupement{
    private:
        int nbSegments;
        int nbBlasons;
    public:
        GroupementVille(const GroupementVille& g): nbSegments(g.nbSegments), nbBlasons(g.nbBlasons){}
        ~GroupementVille()=default;
        int getNbSegments()const {return nbSegments;}
        int getNbBlasons()const {return nbBlasons;}
    };
    
    class GroupementPre: public Groupement{
    private:
        int nbSegments;
    public:
        GroupementPre(const GroupementPre& g): nbSegments(g.nbSegments){}
        ~GroupementPre()=default;
        int getNbSegments()const {return nbSegments;}
    };
    
    class GroupementAbbaye: public Groupement{
    private:
        int nbCases;
    public:
        GroupementAbbaye(const GroupementAbbaye& g): nbCases(g.nbCases){}
        ~GroupementAbbaye()=default;
        int getNbCases()const {return nbCases;}
    };
    
    class GroupementJardin: public Groupement{
    private:
        int nbCases;
    public:
        GroupementJardin(const GroupementJardin& g): nbCases(g.nbCases){}
        ~GroupementJardin()=default;
        int getNbCases()const {return nbCases;}
    };

#endif



//
//  meeple.hpp
//  
//
//  Created by Claire Louard on 18/05/2022.
//

#ifndef meeple_hpp
#define meeple_hpp

#include <stdio.h>

#endif /* meeple_hpp */

enum meeple_type{Normal, Abbé, Big};

class Meeple{
    meeple_type type;
    bool disponible;
public:
    meeple_type getType() const {return type;}
    bool getDisponible() const {return disponible;}
    Meeple(const meeple_type& type, const bool& d): type(type),disponible(d){}
    void updateMeeple(){
        if(getDisponible()==true) {
            disponible=false;
        }
        else {disponible = true;}
    }
};

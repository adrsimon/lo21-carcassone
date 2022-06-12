//
// Created by Leo Peron on 31/05/2022.
//

#include "enum.h"

TypeCardinaux::points TypeCardinaux::getOrientationInverse(points t) {
    switch (t) {
        case nord: return sud;
        case est: return ouest;
        case sud: return nord;
        case ouest: return est;
        case nord_est: return sud_est;
        case nord_ouest: return sud_ouest;
        case sud_est: return nord_est;
        case sud_ouest: return nord_ouest;
        case est_sud: return ouest_sud;
        case est_nord: return ouest_nord;
        case ouest_nord: return est_nord;
        case ouest_sud: return est_sud;
        case last: return last;
    }
    return last;
}

TypeCardinaux::points TypeCardinaux::getNextOrientations(points t) {
    switch (t) {
        case nord: return est;
        case est: return sud;
        case sud: return ouest;
        case ouest: return nord;
        case nord_est: return est_sud;
        case nord_ouest: return est_nord;
        case sud_est: return sud_ouest;
        case sud_ouest: return ouest_nord;
        case est_sud: return sud_ouest;
        case est_nord: return sud_est;
        case ouest_nord: return nord_est;
        case ouest_sud: return nord_ouest;
        case last: return last;
    }
    return last;
}

std::string TypeCardinaux::toString(points t) {
    switch (t) {
        case nord: return "Nord";
        case est: return "Est";
        case sud: return "Sud";
        case ouest: return "Ouest";
        case nord_est: return "Nord Est";
        case nord_ouest: return "Nord Ouest";
        case sud_est: return "Sud Est";
        case sud_ouest: return "Sud Ouest";
        case est_sud: return "Est Sud";
        case est_nord: return "Est Nord";
        case ouest_nord: return "Ouest Nord";
        case ouest_sud: return "Ouest Sud";
        case last: return "Non";
    }
    return "Non";
}

bool TypeCardinaux::isStraight(points t1, points t2) {
    if((t1 == nord && t2 == sud) || (t2 == nord && t1 == sud)) return true;
    if((t1 == est && t2 == ouest) || (t2 == est && t1 == ouest)) return true;
    return false;
}

std::string TypeExtension::toString(points t) {
    switch (t) {
        case main: return "Principale";
        case riviere: return "Rivière";
        case auberge: return "Auberge et Cathédrale";
        case abbe: return "Abbé";
        case paysan: return "Paysan";
    }
    return "None";
}

std::string TypeElement::toString(points t) {
    switch (t) {
        case riviere: return "Rivière";
        case route: return "Route";
        case ville: return "Ville";
        case pre: return "Pré";
        case abbaye: return "Abbaye";
        case jardin: return "Jardin";
        case last: return "None";
    }
    return "None";
}

std::string TypeMeeple::toString(points t) {
    switch (t) {
        case normal: return "Normal";
        case big: return "Big";
        case abbe: return "Abbé";
    }
}

std::string TypeCouleur::toString(points t) {
    switch (t) {
        case rouge: return "rouge";
        case vert: return "vert";
        case bleu: return "bleu";
        case jaune: return "jaune";
        case orange: return "orange";
        case rose: return "rose";
    }
}
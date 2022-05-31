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

    }
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
    }
}
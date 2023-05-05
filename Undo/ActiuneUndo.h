//
// Created by Valentin Serban on 27.04.2023.
//

#ifndef LAB6_7_ACTIUNEUNDO_H
#define LAB6_7_ACTIUNEUNDO_H

#include "../Domain/Film.h"

class ActiuneUndo{
public:
    virtual void doUndo() = 0; // Functie pur virtuala
    // Destructor ActiuneUndo
    virtual ~ActiuneUndo()= default;
};

#endif //LAB6_7_ACTIUNEUNDO_H

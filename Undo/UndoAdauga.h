//
// Created by Valentin Serban on 27.04.2023.
//

#ifndef LAB6_7_UNDOADAUGA_H
#define LAB6_7_UNDOADAUGA_H

#include "UndoAdauga.h"
#include "ActiuneUndo.h"
#include "../Repository/Filme.h"

class UndoAdauga: public ActiuneUndo{
private:
    int id_movie;
    Filme& movies;
public:
    UndoAdauga(Filme& movies, int id): movies{movies}, id_movie{id} {}
    void doUndo() override {
        movies.delete_movie(id_movie);
    }
};

#endif //LAB6_7_UNDOADAUGA_H

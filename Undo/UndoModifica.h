//
// Created by Valentin Serban on 27.04.2023.
//

#ifndef LAB6_7_UNDOMODIFICA_H
#define LAB6_7_UNDOMODIFICA_H

#include <iostream>
#include "ActiuneUndo.h"
#include "../Repository/Filme.h"

class UndoModifica : public ActiuneUndo {
private:
    Film mv_prev;
    Filme& mvs;
public:
    UndoModifica(const Film& mv, Filme& mvs) : mv_prev{mv}, mvs{mvs} {};
    void doUndo() override {
        mvs.delete_movie(mv_prev.get_id());
        std::cout << mv_prev.get_title() << "\n";
        mvs.add_movie(mv_prev);
        mvs.show_movies_table();
    }
};

#endif //LAB6_7_UNDOMODIFICA_H

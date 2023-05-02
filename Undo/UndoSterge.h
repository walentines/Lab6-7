//
// Created by Valentin Serban on 27.04.2023.
//

#ifndef LAB6_7_UNDOSTERGE_H
#define LAB6_7_UNDOSTERGE_H

#include "ActiuneUndo.h"
#include "../Repository/Filme.h"

class UndoSterge : public ActiuneUndo {
private:
    Film mv_to_add;
    Filme& mvs;
public:
    UndoSterge(const Film& mv, Filme& mvs) : mv_to_add{mv}, mvs{mvs} {};
    void doUndo() override {
        mvs.add_movie(mv_to_add);
    }
};

#endif //LAB6_7_UNDOSTERGE_H

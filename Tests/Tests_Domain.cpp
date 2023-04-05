//
// Created by Valentin Serban on 01.04.2023.
//

#include "Tests_Domain.h"

Film generate_movie(){
    Film mv;
    mv.set_title("Terminator");
    mv.set_year("2000");
    mv.set_type("Action");
    mv.set_actor("Silvester Stalone");
    mv.set_id(1);

    return mv;
}

void test_domain(){
    Film mv = generate_movie();
    assert(mv.get_title() == "Terminator");
    assert(mv.get_id() == 1);
    assert(mv.get_year() == "2000");
    assert(mv.get_actor() == "Silvester Stalone");
    assert(mv.get_type() == "Action");
}

void test_all_domain(){
    test_domain();
}
//
// Created by Valentin Serban on 01.04.2023.
//

#include "Tests_Repository.h"
#include <iostream>
#include <vector>
#include "../Utils/utils.h"

using std::vector;

void test_add(){
    Filme mvs;
    Film mv;
    vector<Film> filme_vector;
    int ok;
    mv.set_title("Terminator");
    mv.set_year("2000");
    mv.set_type("Action");
    mv.set_actor("Silvester Stalone");
    mv.set_id(1);

    ok = mvs.add_movie(mv);
    filme_vector.push_back(mv);
    assert(ok == 1);
    assert(mvs.get_length() == 1);
    assert(mvs.get_movie_by_id(1) == mv);
    assert(mvs.get_movie_by_pos(0) == mv);
    assert(filme_vector[0] == mv);
    Film mv1;
    mv1.set_title("Terminator");
    mv1.set_year("2000");
    mv1.set_type("Action");
    mv1.set_actor("Silvester Stalone");
    mv1.set_id(1);
    ok = mvs.add_movie(mv1);
    assert(ok == 0);
    assert(mvs.get_length() == 1);
}

void test_delete(){
    Filme mvs;
    Film mv;
    int ok_delete;
    mv.set_title("Terminator");
    mv.set_year("2000");
    mv.set_type("Action");
    mv.set_actor("Silvester Stalone");
    mv.set_id(1);

    mvs.add_movie(mv);
    ok_delete = mvs.delete_movie(1);
    assert(ok_delete != -1);
    assert(mvs.get_length() == 0);
    mvs.add_movie(mv);
    assert(mvs.get_length() == 1);
    ok_delete = mvs.delete_movie(2);
    assert(ok_delete == -1);
    assert(mvs.get_length() == 1);
}

void test_modify_movie(){
    Filme mvs;
    Film mv;
    int ok;
    mv.set_title("Terminator");
    mv.set_year("2000");
    mv.set_type("Action");
    mv.set_actor("Silvester Stalone");
    mv.set_id(1);

    mvs.add_movie(mv);
    ok = mvs.modify_movie(1, "Terminator 2", "Adventure", "2001", "Silvester");
    assert(ok == 1);
    assert(mvs.get_movie_by_id(1).get_type() == "Adventure");
    assert(mvs.get_movie_by_id(1).get_actor() == "Silvester");
    assert(mvs.get_movie_by_id(1).get_year() == "2001");
    assert(mvs.get_movie_by_id(1).get_title() == "Terminator 2");
    ok = mvs.modify_movie(2, "Terminator 2", "Adventure", "2001", "Silvester");
    assert(ok == -1);
}

void test_show_movies(){
    std::cout.setstate(std::ios_base::failbit);
    std::cout << "Second message" << std::endl;

    Filme mvs;
    Film mv;
    mv.set_title("Terminator");
    mv.set_year("2000");
    mv.set_type("Action");
    mv.set_actor("Silvester Stalone");
    mv.set_id(1);

    mvs.add_movie(mv);
    mvs.show_movies();
    mvs.show_movies_table();
    Filme mvs2;
    mvs2.show_movies_table();
    mvs.add_movie_bag("Terminator");
    mvs.show_bag_table();
    std::cout.clear();
}

void test_search_movies(){
    Filme mvs;
    Film mv;
    mv.set_title("Terminator");
    mv.set_year("2000");
    mv.set_type("Action");
    mv.set_actor("Silvester Stalone");
    mv.set_id(1);

    mvs.add_movie(mv);
    vector<Film> searched_mvs = mvs.search_movie(1, "", "", "", "");
    assert(searched_mvs.size() == 1);
    vector<Film> searched_mvs1 = mvs.search_movie(0, "Terminator", "", "", "");
    assert(searched_mvs1.size() == 1);
    vector<Film> searched_mvs2 = mvs.search_movie(0, "", "Action", "", "");
    assert(searched_mvs2.size() == 1);
    vector<Film> searched_mvs3 = mvs.search_movie(0, "", "", "2000", "");
    assert(searched_mvs3.size() == 1);
    vector<Film> searched_mvs4 = mvs.search_movie(0, "", "", "", "Silvester Stalone");
    assert(searched_mvs4.size() == 1);
    vector<Film> searched_mvs5 = mvs.search_movie(0, "", "", "", "");
    assert(searched_mvs4.size() == 1);
}

void test_add_bag(){
    Filme mvs;
    generate_movies(mvs);
    mvs.add_movie_bag("Uncharted");
    assert(mvs.get_bag_length() == 1);
}

void test_clear_bag(){
    Filme mvs;
    generate_movies(mvs);
    mvs.add_movie_bag("Uncharted");
    mvs.empty_bag();
    assert(mvs.get_bag_length() == 0);
}

void test_all_repo(){
    test_add();
    test_delete();
    test_modify_movie();
    test_show_movies();
    test_search_movies();
    test_add_bag();
    test_clear_bag();
}
//
// Created by Valentin Serban on 01.04.2023.
//

#include "test_all_service.h"
#include "../Utils/utils.h"
#include <iostream>

// Teste validatoare si schimbat std::string!!

void test_add_service(){
    Filme repo;
    FilmeS mvs(&repo);
    Film mv;
    int ok;
    mv.set_title("Terminator");
    mv.set_year("2000");
    mv.set_type("Action");
    mv.set_actor("Silvester Stalone");
    mv.set_id(1);

    ok = mvs.add_movie(mv);
    assert(ok == 1);
    assert(mvs.get_length() == 1);
    assert(mvs.get_movie_by_id(1) == mv);
    assert(mvs.get_movie_by_pos(0) == mv);
}

void test_delete_service(){
    Filme repo;
    FilmeS mvs(&repo);
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
}

void test_modify_movie_service(){
    Filme repo;
    FilmeS mvs(&repo);
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
}

void test_show_movies_service(){
    std::cout.setstate(std::ios_base::failbit);
    std::cout << "Second message" << std::endl;

    Filme repo;
    FilmeS mvs(&repo);
    Film mv;
    mv.set_title("Terminator");
    mv.set_year("2000");
    mv.set_type("Action");
    mv.set_actor("Silvester Stalone");
    mv.set_id(1);

    mvs.add_movie(mv);
    mvs.add_movie_bag_service("Terminator");
    mvs.show_bag_table_service();
    mvs.show_movies();
    mvs.show_movies_table();
    std::cout.clear();
}

void test_search_movies_service(){
    Filme repo;
    FilmeS mvs(&repo);
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
}

void test_filter_movies_by_title(){
    Filme repo;
    FilmeS mvs(&repo);
    Film mv;
    mv.set_title("Terminator");
    mv.set_year("2000");
    mv.set_type("Action");
    mv.set_actor("Silvester Stalone");
    mv.set_id(1);

    mvs.add_movie(mv);

    Film mv1;
    mv1.set_title("Abracadabra");
    mv1.set_year("2000");
    mv1.set_type("Action");
    mv1.set_actor("Silvester Stalone");
    mv1.set_id(2);
    mvs.add_movie(mv1);

    vector<Film> filtered_movies = mvs.filter_movies_by_title_service("Terminator");
    assert(filtered_movies.size() == 1);
    assert(filtered_movies[0] == mv);
}

void test_filter_movies_by_year(){
    Filme repo;
    FilmeS mvs(&repo);
    Film mv;
    mv.set_title("Terminator");
    mv.set_year("2000");
    mv.set_type("Action");
    mv.set_actor("Silvester Stalone");
    mv.set_id(1);

    mvs.add_movie(mv);

    Film mv1;
    mv1.set_title("Abracadabra");
    mv1.set_year("2000");
    mv1.set_type("Action");
    mv1.set_actor("Silvester Stalone");
    mv1.set_id(2);
    mvs.add_movie(mv1);

    vector<Film> filtered_movies = mvs.filter_movies_by_year_service("1999");
    assert(filtered_movies.size() == 2);
}

void test_generate_movies(){
    Filme repo;
    FilmeS mvs(&repo);
    mvs.generate_movies_service();
    assert(mvs.get_length() == 10);
}

void test_sort_movies_title(){
    Filme repo;
    FilmeS mvs(&repo);
    Film mv;
    mv.set_title("Terminator");
    mv.set_year("2000");
    mv.set_type("Action");
    mv.set_actor("Silvester Stalone");
    mv.set_id(1);

    mvs.add_movie(mv);

    Film mv1;
    mv1.set_title("Abracadabra");
    mv1.set_year("2000");
    mv1.set_type("Action");
    mv1.set_actor("Silvester Stalone");
    mv1.set_id(2);
    mvs.add_movie(mv1);

    vector<Film> sorted_movies_asc = mvs.sort_movies_by_title("asc");
    assert(sorted_movies_asc[0] == mv1);
    assert(sorted_movies_asc[1] == mv);

    vector<Film> sorted_movies_desc = mvs.sort_movies_by_title("desc");
    assert(sorted_movies_desc[0] == mv);
    assert(sorted_movies_desc[1] == mv1);
}

void test_sort_movies_actor(){
    Filme repo;
    FilmeS mvs(&repo);
    Film mv;
    mv.set_title("Terminator");
    mv.set_year("2000");
    mv.set_type("Action");
    mv.set_actor("Silvester Stalone");
    mv.set_id(1);

    mvs.add_movie(mv);

    Film mv1;
    mv1.set_title("Abracadabra");
    mv1.set_year("2000");
    mv1.set_type("Action");
    mv1.set_actor("Tilvester Stalone");
    mv1.set_id(2);
    mvs.add_movie(mv1);

    vector<Film> sorted_movies_asc = mvs.sort_movies_by_actor("asc");
    assert(sorted_movies_asc[0] == mv);
    assert(sorted_movies_asc[1] == mv1);

    vector<Film> sorted_movies_desc = mvs.sort_movies_by_actor("desc");
    assert(sorted_movies_desc[0] == mv1);
    assert(sorted_movies_desc[1] == mv);
}

void test_sort_movies_year(){
    Filme repo;
    FilmeS mvs(&repo);
    Film mv;
    mv.set_title("Terminator");
    mv.set_year("2001");
    mv.set_type("Action");
    mv.set_actor("Silvester Stalone");
    mv.set_id(1);

    mvs.add_movie(mv);

    Film mv1;
    mv1.set_title("Abracadabra");
    mv1.set_year("2000");
    mv1.set_type("Action");
    mv1.set_actor("Silvester Stalone");
    mv1.set_id(2);
    mvs.add_movie(mv1);

    vector<Film> sorted_movies_asc = mvs.sort_movies_by_year("asc");
    assert(sorted_movies_asc[0] == mv1);
    assert(sorted_movies_asc[1] == mv);

    vector<Film> sorted_movies_desc = mvs.sort_movies_by_year("desc");
    assert(sorted_movies_desc[0] == mv);
    assert(sorted_movies_desc[1] == mv1);
}

void test_sort_movies_type(){
    Filme repo;
    FilmeS mvs(&repo);
    Film mv;
    mv.set_title("Terminator");
    mv.set_year("2000");
    mv.set_type("Comedy");
    mv.set_actor("Silvester Stalone");
    mv.set_id(1);

    mvs.add_movie(mv);

    Film mv1;
    mv1.set_title("Abracadabra");
    mv1.set_year("2000");
    mv1.set_type("Action");
    mv1.set_actor("Silvester Stalone");
    mv1.set_id(2);
    mvs.add_movie(mv1);

    vector<Film> sorted_movies_asc = mvs.sort_movies_by_type("asc");
    assert(sorted_movies_asc[0] == mv1);
    assert(sorted_movies_asc[1] == mv);

    vector<Film> sorted_movies_desc = mvs.sort_movies_by_type("desc");
    assert(sorted_movies_desc[0] == mv);
    assert(sorted_movies_desc[1] == mv1);
}

void test_empty_bag(){
    Filme repo;
    FilmeS mvs(&repo);
    mvs.generate_movies_service();
    mvs.add_movie_bag_service("Uncharted");
    mvs.empty_bag_service();
    assert(mvs.get_bag_size() == 0);
}

void test_add_movie_bag(){
    Filme repo;
    FilmeS mvs(&repo);
    mvs.generate_movies_service();
    mvs.add_movie_bag_service("Uncharted");
    assert(mvs.get_bag_size() == 1);
}

void test_fill_the_bag(){
    Filme repo;
    FilmeS mvs(&repo);
    mvs.generate_movies_service();
    mvs.fill_the_bag(3);
    assert(mvs.get_bag_size() == 3);
}

void test_export_mvs(){
    Filme repo;
    FilmeS mvs(&repo);
    mvs.generate_movies_service();
    mvs.fill_the_bag(3);
    mvs.export_mvs("test_export.csv");
    assert(mvs.get_bag_size() == 3);
}

void test_all_service(){
    test_add_service();
    test_delete_service();
    test_modify_movie_service();
    test_show_movies_service();
    test_search_movies_service();
    test_filter_movies_by_title();
    test_filter_movies_by_year();
    test_generate_movies();
    test_sort_movies_title();
    test_sort_movies_actor();
    test_sort_movies_year();
    test_sort_movies_type();
    test_empty_bag();
    test_add_movie_bag();
    test_fill_the_bag();
    test_export_mvs();
}
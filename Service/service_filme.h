//
// Created by Valentin Serban on 29.03.2023.
//

#ifndef LAB6_7_SERVICE_FILME_H
#define LAB6_7_SERVICE_FILME_H

#include "../Repository/Filme.h"

class FilmeS {
private:
    Filme serviceFilme;
public:
    FilmeS()= default;
    int add_movie(const Film& mv);
    int delete_movie(int id);
    int modify_movie(int id, const std::string& new_title, const std::string& new_type, const std::string& new_year, const std::string& new_actor);
    void show_movies();
    ~FilmeS() = default;

    Vector<Film> search_movie(int id, const std::string &new_title, const std::string &new_type, const std::string &new_year,
                      const std::string &new_actor);

    Vector<Film> filter_movies_by_title_service(const std::string &title);

    Vector<Film> filter_movies_by_year_service(const std::string &year);

    void generate_movies_service();

    Vector<Film> sort_movies_by_title(const std::string &type);

    Vector<Film> sort_movies_by_actor(const std::string &type);

    Vector<Film> sort_movies_by_year(const std::string &type);

    Vector<Film> sort_movies_by_type(const std::string &type);

    Film get_movie_by_id(int id);

    Film get_movie_by_pos(int pos);

    int get_length();

    void show_movies_table();
};


#endif //LAB6_7_SERVICE_FILME_H

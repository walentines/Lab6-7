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

    vector<Film> search_movie(int id, const std::string &new_title, const std::string &new_type, const std::string &new_year,
                      const std::string &new_actor);

    vector<Film> filter_movies_by_title_service(const std::string &title);

    vector<Film> filter_movies_by_year_service(const std::string &year);

    void generate_movies_service();

    vector<Film> sort_movies_by_title(const std::string &type);

    vector<Film> sort_movies_by_actor(const std::string &type);

    vector<Film> sort_movies_by_year(const std::string &type);

    vector<Film> sort_movies_by_type(const std::string &type);

    Film get_movie_by_id(int id);

    Film get_movie_by_pos(int pos);

    int get_length();

    void show_movies_table();

    void empty_bag_service();

    void add_movie_bag_service(const std::string &title);

    void show_bag_table_service();

    void fill_the_bag(int number_of_movies);

    void export_mvs(const std::string &file);

    int get_bag_size();
};


#endif //LAB6_7_SERVICE_FILME_H

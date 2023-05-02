//
// Created by Valentin Serban on 29.03.2023.
//

#ifndef LAB6_7_FILME_H
#define LAB6_7_FILME_H

#include "../Vector/VectorClass.h"
#include "../Domain/Film.h"
#include <vector>

using std::vector;

class Filme{
private:
    vector<Film> filme;
    vector<Film> bag;
    int length;
public:
    explicit Filme();

    [[nodiscard]] int get_length() const;

    int add_movie(const Film& elem);

    int delete_movie(int id);

    [[nodiscard]] int modify_movie(int id, const std::string& new_title, const std::string& new_type, const std::string& new_year, const std::string& new_actor);

    [[nodiscard]] Film get_movie_by_id(int id);

    void show_movies();

    ~Filme() = default;

    vector<Film> search_movie(int id, const std::string& title, const std::string& type, const std::string& year, const std::string& actor);

    [[nodiscard]] Film get_movie_by_pos(int position) const;


    void show_movies_table();

    void empty_bag();

    void add_movie_bag(const std::string &title);

    void show_bag_table();

    int get_bag_length();
};

#endif //LAB6_7_FILME_H

//
// Created by Valentin Serban on 30.03.2023.
//

#ifndef LAB6_7_UTILS_H
#define LAB6_7_UTILS_H

#include <string>
#include "../Repository/Filme.h"
#include "../Domain/Film.h"

bool remove_condition(const Film& f, int id);
vector<Film> filter_movies_by_title(const Filme& movies, const std::string& title) ;
vector<Film> filter_movies_by_year(const Filme& movies, const std::string& year);
void generate_movies(Filme *movies);
vector<Film> sort_movies_title(const Filme& movies, const std::string& type);
int compare_title_asc(const Film &a, const Film &b);
int compare_title_desc(const Film &a, const Film &b);
vector<Film> sort_movies_actor(const Filme& movies, const std::string& type);
int compare_actor_asc(const Film &a, const Film &b);
int compare_actor_desc(const Film &a, const Film &b);
vector<Film> sort_movies_year(const Filme& movies, const std::string& type);
int compare_year_asc(const Film &a, const Film &b);
int compare_year_desc(const Film &a, const Film &b);
vector<Film> sort_movies_type(const Filme& movies, const std::string& type);
int compare_type_asc(const Film &a, const Film &b);
int compare_type_desc(const Film &a, const Film &b);
std::string show_movie(const Film& movie);
void get_random_elements(Filme& movies, int number_of_elem);
void export_movies(Filme &movies, const std::string& file);

#endif //LAB6_7_UTILS_H

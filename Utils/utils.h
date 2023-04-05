//
// Created by Valentin Serban on 30.03.2023.
//

#ifndef LAB6_7_UTILS_H
#define LAB6_7_UTILS_H

#include <string>
#include "../Repository/Filme.h"
#include "../Domain/Film.h"

Vector<Film> filter_movies_by_title(const Filme& movies, const std::string& title) ;
Vector<Film> filter_movies_by_year(const Filme& movies, const std::string& year);
void generate_movies(Filme &movies);
Vector<Film> sort_movies_title(const Filme& movies, const std::string& type);
int compare_title_asc(const Film &a, const Film &b);
int compare_title_desc(const Film &a, const Film &b);
Vector<Film> sort_movies_actor(const Filme& movies, const std::string& type);
int compare_actor_asc(const Film &a, const Film &b);
int compare_actor_desc(const Film &a, const Film &b);
Vector<Film> sort_movies_year(const Filme& movies, const std::string& type);
int compare_year_asc(const Film &a, const Film &b);
int compare_year_desc(const Film &a, const Film &b);
Vector<Film> sort_movies_type(const Filme& movies, const std::string& type);
int compare_type_asc(const Film &a, const Film &b);
int compare_type_desc(const Film &a, const Film &b);
std::string show_movie(const Film& movie);

#endif //LAB6_7_UTILS_H

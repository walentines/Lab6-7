//
// Created by Valentin Serban on 29.03.2023.
//

#include "service_filme.h"
#include "../Utils/utils.h"

/// Functie pentru adaugarea unui film in lista de filme
/// \param mv (Film)
/// \return int
int FilmeS::add_movie(const Film& mv) {
    return this->serviceFilme.add_movie(mv);
}

/// Functie pentru returnarea unui film dupa id-ul acestuia
/// \param id (int)
/// \return Film
Film FilmeS::get_movie_by_id(int id) {
    return this->serviceFilme.get_movie_by_id(id);
}

/// Functie pentru returnarea unui film in functie de pozitia acestuia in lista de filme.
/// \param pos (int)
/// \return Film
Film FilmeS::get_movie_by_pos(int pos) {
    return this->serviceFilme.get_movie_by_pos(pos);
}

/// Functie pentru returnarea lungimii listei de filme.
/// \return int
int FilmeS::get_length() {
    return this->serviceFilme.get_length();
}

/// Functie pentru stergerea unui film din lista de filme.
/// \param id (int)
/// \return int
int FilmeS::delete_movie(int id){
    return this->serviceFilme.delete_movie(id);
}

/// Functie pentru modificarea unui film.
/// \param id (int)
/// \param new_title (string)
/// \param new_type (string)
/// \param new_year (string)
/// \param new_actor (string)
/// \return int
int FilmeS::modify_movie(int id, const std::string& new_title, const std::string& new_type, const std::string& new_year, const std::string& new_actor) {
    return this->serviceFilme.modify_movie(id, new_title, new_type, new_year, new_actor);
}

/// Functie pentru afisarea listei de filme
void FilmeS::show_movies() {
    this->serviceFilme.show_movies();
}

/// Functie pentru cautarea unui film
/// \param id (int)
/// \param new_title (string)
/// \param new_type (string)
/// \param new_year (string
/// \param new_actor (string)
/// \return Vector<Film>
Vector<Film> FilmeS::search_movie(int id, const std::string& new_title, const std::string& new_type, const std::string& new_year, const std::string& new_actor){
    return this->serviceFilme.search_movie(id, new_title, new_type, new_year, new_actor);
}

/// Functie pentru filtrarea filmelor dupa titlu.
/// \param title (string)
/// \return Vector<Film>
Vector<Film> FilmeS::filter_movies_by_title_service(const std::string& title){
    return filter_movies_by_title(this->serviceFilme, title);
}

/// Functie pentru filtrarea filmelor dupa an.
/// \param year (string)
/// \return Vector<Film>
Vector<Film> FilmeS::filter_movies_by_year_service(const std::string& year){
    return filter_movies_by_year(this->serviceFilme, year);
}

/// Functie pentru generarea de filme
void FilmeS::generate_movies_service(){
    generate_movies(this->serviceFilme);
}

/// Functie pentru sortarea filmelor dupa titlu si tipul type
/// \param type (string)
/// \return Vector<Film>
Vector<Film> FilmeS::sort_movies_by_title(const std::string &type){
    return sort_movies_title(this->serviceFilme, type);
}

/// Functie pentru sortarea filmelor dupa actor si tipul type
/// \param type (string)
/// \return Vector<Film>
Vector<Film> FilmeS::sort_movies_by_actor(const std::string &type){
    return sort_movies_actor(this->serviceFilme, type);
}

/// Functie pentru sortarea filmelor dupa an si tipul type
/// \param type (string)
/// \return Vector<Film>
Vector<Film> FilmeS::sort_movies_by_year(const std::string &type){
    return sort_movies_year(this->serviceFilme, type);
}

/// Functie pentru sortarea filmelor dupa tip si tipul type
/// \param type (string)
/// \return Vector<Film>
Vector<Film> FilmeS::sort_movies_by_type(const std::string &type){
    return sort_movies_type(this->serviceFilme, type);
}

/// Functie pentru afisarea listei de filme sub forma de tabel
void FilmeS::show_movies_table(){
    this->serviceFilme.show_movies_table();
}
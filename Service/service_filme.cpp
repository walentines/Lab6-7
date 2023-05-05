//
// Created by Valentin Serban on 29.03.2023.
//

#include "service_filme.h"
#include "../Utils/utils.h"
#include "../Undo/UndoAdauga.h"
#include "../Exceptions/ExceptionClass.h"
#include "../Undo/UndoSterge.h"
#include "../Undo/UndoModifica.h"

/// Functie pentru adaugarea unui film in lista de filme
/// \param mv (Film)
/// \return int
int FilmeS::add_movie(const Film& mv) {
    undoActions.push_back(new UndoAdauga{*this->serviceFilme, mv.get_id()});
    return this->serviceFilme->add_movie(mv);
}

/// Functie pentru returnarea unui film dupa id-ul acestuia
/// \param id (int)
/// \return Film
Film FilmeS::get_movie_by_id(int id) {
    return this->serviceFilme->get_movie_by_id(id);
}

/// Functie pentru returnarea unui film in functie de pozitia acestuia in lista de filme.
/// \param pos (int)
/// \return Film
Film FilmeS::get_movie_by_pos(int pos) {
    return this->serviceFilme->get_movie_by_pos(pos);
}

/// Functie pentru returnarea lungimii listei de filme.
/// \return int
int FilmeS::get_length() {
    return this->serviceFilme->get_length();
}

/// Functie pentru stergerea unui film din lista de filme.
/// \param id (int)
/// \return int
int FilmeS::delete_movie(int id){
    undoActions.push_back(new UndoSterge{this->get_movie_by_id(id), *this->serviceFilme});
    return this->serviceFilme->delete_movie(id);
}

/// Functie pentru modificarea unui film.
/// \param id (int)
/// \param new_title (string)
/// \param new_type (string)
/// \param new_year (string)
/// \param new_actor (string)
/// \return int
int FilmeS::modify_movie(int id, const std::string& new_title, const std::string& new_type, const std::string& new_year, const std::string& new_actor) {
    Film cp_film;
    cp_film.set_title(this->get_movie_by_id(id).get_title());
    cp_film.set_type(this->get_movie_by_id(id).get_type());
    cp_film.set_year(this->get_movie_by_id(id).get_year());
    cp_film.set_actor(this->get_movie_by_id(id).get_actor());
    cp_film.set_id(id);

    undoActions.push_back(new UndoModifica{cp_film, *this->serviceFilme});
    return this->serviceFilme->modify_movie(id, new_title, new_type, new_year, new_actor);
}

/// Functie pentru afisarea listei de filme
void FilmeS::show_movies() {
    this->serviceFilme->show_movies();
}

/// Functie pentru cautarea unui film
/// \param id (int)
/// \param new_title (string)
/// \param new_type (string)
/// \param new_year (string
/// \param new_actor (string)
/// \return vector<Film>
vector<Film> FilmeS::search_movie(int id, const std::string& new_title, const std::string& new_type, const std::string& new_year, const std::string& new_actor){
    return this->serviceFilme->search_movie(id, new_title, new_type, new_year, new_actor);
}

/// Functie pentru filtrarea filmelor dupa titlu.
/// \param title (string)
/// \return vector<Film>
vector<Film> FilmeS::filter_movies_by_title_service(const std::string& title){
    return filter_movies_by_title(*this->serviceFilme, title);
}

/// Functie pentru filtrarea filmelor dupa an.
/// \param year (string)
/// \return vector<Film>
vector<Film> FilmeS::filter_movies_by_year_service(const std::string& year){
    return filter_movies_by_year(*this->serviceFilme, year);
}

/// Functie pentru generarea de filme
void FilmeS::generate_movies_service(){
    generate_movies(this->serviceFilme);
}

/// Functie pentru sortarea filmelor dupa titlu si tipul type
/// \param type (string)
/// \return vector<Film>
vector<Film> FilmeS::sort_movies_by_title(const std::string &type){
    return sort_movies_title(*this->serviceFilme, type);
}

/// Functie pentru sortarea filmelor dupa actor si tipul type
/// \param type (string)
/// \return vector<Film>
vector<Film> FilmeS::sort_movies_by_actor(const std::string &type){
    return sort_movies_actor(*this->serviceFilme, type);
}

/// Functie pentru sortarea filmelor dupa an si tipul type
/// \param type (string)
/// \return vector<Film>
vector<Film> FilmeS::sort_movies_by_year(const std::string &type){
    return sort_movies_year(*this->serviceFilme, type);
}

/// Functie pentru sortarea filmelor dupa tip si tipul type
/// \param type (string)
/// \return vector<Film>
vector<Film> FilmeS::sort_movies_by_type(const std::string &type){
    return sort_movies_type(*this->serviceFilme, type);
}

/// Functie pentru afisarea listei de filme sub forma de tabel
void FilmeS::show_movies_table(){
    this->serviceFilme->show_movies_table();
}

void FilmeS::empty_bag_service(){
    this->serviceFilme->empty_bag();
}

void FilmeS::add_movie_bag_service(const std::string &title){
    this->serviceFilme->add_movie_bag(title);
}

void FilmeS::show_bag_table_service() {
    this->serviceFilme->show_bag_table();
}

void FilmeS::fill_the_bag(int number_of_movies){
    get_random_elements(*this->serviceFilme, number_of_movies);
}

void FilmeS::export_mvs(const std::string &file){
    export_movies(*this->serviceFilme, file);
}

int FilmeS::get_bag_size(){
    return this->serviceFilme->get_bag_length();
}

int FilmeS::undo(){
    try{
        if(undoActions.empty()){
            throw EmptyUndo();
        }
    }
    catch(EmptyUndo& eu){
        return -1;
    }
    ActiuneUndo* act = undoActions.back();
    act->doUndo();
    undoActions.pop_back();
    delete act;

    return 0;
}
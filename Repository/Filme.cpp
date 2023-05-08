//
// Created by Valentin Serban on 29.03.2023.
//

#include "Filme.h"
#include "../Vector/VectorClass.cpp"
#include "../Utils/utils.h"
#include <iostream>
#include <vector>
#include <algorithm>

using std::vector;

/// Constructor
Filme::Filme() {
    this->length = 0;
}

/// Returneaza lungimea listei de filme.
/// \return length (int)
int Filme::get_length() const{
    return this->length;
}

/// Adauga film la lista de filme.
/// \param elem (Film)
/// \return 1/0 daca s-a adaugat cu succes
int Filme::add_movie(const Film& elem){
    int ok = 1;
    for(int i = 0; i < this->length; ++i){
        if(this->filme[i].get_id() == elem.get_id()){
            ok = 0;
        }
    }
    if(!ok){
        return ok;
    }
    this->filme.push_back(elem);
    this->length++;
    return 1;
}

/// Functie pentru stergerea unui film.
/// \param id (int)
/// \return 1/0 daca s-a efectuat cu succes
int Filme::delete_movie(int id){
    int pos = -1;
    for(int i = 0; i < this->filme.size(); ++i){
        if(filme[i].get_id() == id){
            pos = i;
        }
    }
    if(pos == -1){
        return pos;
    }
    this->filme.erase(this->filme.begin()+pos);
    this->length--;
    return 1;
}

/// Returneaza un film dupa id-ul acestuia
/// \param id (int)
/// \return Film
Film Filme::get_movie_by_id(int id) {
//    for(int i = 0; i < this->length; ++i){
//        if(filme[i].get_id() == id){
//            return filme[i];
//        }
//    }
    auto it = std::find_if(this->filme.begin(), this->filme.end(), [id](Film& f)->bool {
        if(f.get_id() == id){
            return true;
        }
        return false;
    });
    if(it != this->filme.end()){
        return *it;
    }
    std::string ex_title, ex_type, ex_year, ex_actor;
    Film f;
    f.set_actor(ex_actor);
    f.set_type(ex_type);
    f.set_year(ex_year);
    f.set_title(ex_title);
    f.set_id(0);

    return f;
}

/// Modifica un film dupa atributele din parametri
/// \param id (int)
/// \param new_title (string)
/// \param new_type (string)
/// \param new_year (string)
/// \param new_actor (string)
/// \return 1/0 daca s a efectuat cu succes
int Filme::modify_movie(int id, const std::string& new_title, const std::string& new_type, const std::string& new_year, const std::string& new_actor){
    auto it = std::find_if(this->filme.begin(), this->filme.end(), [new_title, new_type, new_actor, new_year, id](Film& f)->bool {
        if (f.get_id() == id) {
            if(!new_title.empty()){
                f.set_title(new_title);
            }
            if(!new_type.empty()){
                f.set_type(new_type);
            }
            if(!new_year.empty()){
                f.set_year(new_year);
            }
            if(!new_actor.empty()){
                f.set_actor(new_actor);
            }
            return true;
        }
        return false;
    });
    if(this->get_movie_by_id(id).get_id() == 0){
        return -1;
    }

    return 1;
}

vector<Film> Filme::get_bag(){
    return this->bag;
}

/// Functie pentru afisarea filmelor
void Filme::show_movies(){
    for(int i = 0; i < this->length; ++i){
        this->filme[i].show_movie();
    }
}

/// Functie pentru cautarea unui film dupa un atribut.
/// \param id (int)
/// \param title (string)
/// \param type (string)
/// \param year (string)
/// \param actor (string)
/// \return Vector<Film>
vector<Film> Filme::search_movie(int id, const std::string& title, const std::string& type, const std::string& year, const std::string& actor){
    std::string search_type;
    vector<Film> searched_movies;
    if(id != 0){
        search_type = "id";
    }
    else if(!title.empty()){
        search_type = "title";
    }
    else if(!type.empty()){
        search_type = "type";
    }
    else if(!year.empty()){
        search_type = "year";
    }
    else if(!actor.empty()){
        search_type = "actor";
    }
    if(search_type == "id"){
        for(int i = 0; i < this->length; ++i){
            if(id == this->filme[i].get_id()){
                searched_movies.push_back(this->filme[i]);
            }
        }
    }
    else if(search_type == "title"){
        for(int i = 0; i < this->length; ++i){
            if(title == this->filme[i].get_title()){
                searched_movies.push_back(this->filme[i]);
            }
        }
    }
    else if(search_type == "type"){
        for(int i = 0; i < this->length; ++i){
            if(type == this->filme[i].get_type()){
                searched_movies.push_back(this->filme[i]);
            }
        }
    }
    else if(search_type == "year"){
        for(int i = 0; i < this->length; ++i){
            if(year == this->filme[i].get_year()){
                searched_movies.push_back(this->filme[i]);
            }
        }
    }
    else if(search_type == "actor"){
        for(int i = 0; i < this->length; ++i){
            if(actor == this->filme[i].get_actor()){
                searched_movies.push_back(this->filme[i]);
            }
        }
    }

    if(searched_movies.empty()){
        Film f;
        f.set_id(0);
        f.set_actor("");
        f.set_type("");
        f.set_year("");
        f.set_title("");
        searched_movies.push_back(f);
    }

    return searched_movies;
}

/// Functie pentru afisarea filmelor sub forma de tabel.
void Filme::show_movies_table()
/**
 * functia de printare oferte disponibile (salvate deja)
 * afiseaza un mesaj specific daca nu exista nicio oferta
 * @param ptr_consola pointer spre structul de tip consola cu care se lucreaza
 */
{
    if (this->length == 0){
        std::cout<<("There is no movie!\n");
        return;
    }
    int numar_filme = this->length;
    std::cout<<"+";
    for(int j=0; j<8; j++)
        std::cout<<("-");
    std::cout<<"+";
    for(int j=0; j<22; j++)
        std::cout<<"-";
    std::cout<<"+";
    for(int j=0; j<22; j++)
        std::cout<<"-";
    std::cout<<"+";
    for(int j=0; j<8; j++)
        std::cout<<"-";
    std::cout<<"+";
    for(int j=0; j<20; j++)
        std::cout<<"-";
    std::cout<<"+";
    std::cout<<"\n";
    std::cout<<"|";
    for(int j=0; j<3; j++)
        std::cout<<" ";
    std::cout<<"ID";
    for(int j=0; j<3; j++)
        std::cout<<" ";
    std::cout<<"|";
    for(int j=0; j<8; j++)
        std::cout<<" ";
    std::cout<<"TITLU";
    for(int j=0; j<9; j++)
        std::cout<<" ";
    std::cout<<"|";
    for(int j=0; j<9; j++)
        std::cout<<" ";
    std::cout<<"TIP";
    for(int j=0; j<10; j++)
        std::cout<<" ";
    std::cout<<"|";
    for(int j=0; j<3; j++)
        std::cout<<" ";
    std::cout<<"AN";
    for(int j=0; j<3; j++)
        std::cout<<" ";
    std::cout<<"|";
    for(int j=0; j<7; j++)
        std::cout<<" ";
    std::cout<<"ACTOR";
    for(int j=0; j<8; j++)
        std::cout<<" ";
    std::cout<<"|";
    std::cout<<"\n";
    std::cout<<"+";
    for(int j=0; j<8; j++)
        std::cout<<"-";
    std::cout<<"+";
    for(int j=0; j<22; j++)
        std::cout<<"-";
    std::cout<<"+";
    for(int j=0; j<22; j++)
        std::cout<<"-";
    std::cout<<"+";
    for(int j=0; j<8; j++)
        std::cout<<"-";
    std::cout<<"+";
    for(int j=0; j<20; j++)
        std::cout<<"-";
    std::cout<<"+";
    std::cout<<"\n";
    for(int i = 0; i<numar_filme; i++)
    {
        std::string afisarea_ofertei;
        afisarea_ofertei = show_movie(this->filme[i]);
        std::cout << afisarea_ofertei;
        std::cout<<"+";
        for(int j=0; j<8; j++)
            std::cout<<"-";
        std::cout<<"+";
        for(int j=0; j<22; j++)
            std::cout<<"-";
        std::cout<<"+";
        for(int j=0; j<22; j++)
            std::cout<<"-";
        std::cout<<"+";
        for(int j=0; j<8; j++)
            std::cout<<"-";
        std::cout<<"+";
        for(int j=0; j<20; j++)
            std::cout<<"-";
        std::cout<<"+";
        std::cout<<"\n";
    }
}

/// Functie pentru returnarea unui film dupa pozitia in lista de filme
/// \param position (int)
/// \return Film
Film Filme::get_movie_by_pos(int position) const{
    return filme[position];
}

Film Filme::get_movie_by_pos_bag(int position) const{
    return bag[position];
}

void Filme::empty_bag(){
    this->bag.clear();
}

int Filme::get_bag_length(){
    return (int)this->bag.size();
}

void Filme::add_movie_bag(const std::string &title){
    for(const auto& it: this->filme){
        if(it.get_title() == title){
            this->bag.push_back(it);
        }
    }
}

void Filme::show_bag_table()
/**
 * functia de printare oferte disponibile (salvate deja)
 * afiseaza un mesaj specific daca nu exista nicio oferta
 * @param ptr_consola pointer spre structul de tip consola cu care se lucreaza
 */
{
    if (this->bag.empty()){
        std::cout<<("There is no movie!\n");
        return;
    }
    int numar_filme = (int)this->bag.size();
    std::cout<<"+";
    for(int j=0; j<8; j++)
        std::cout<<("-");
    std::cout<<"+";
    for(int j=0; j<22; j++)
        std::cout<<"-";
    std::cout<<"+";
    for(int j=0; j<22; j++)
        std::cout<<"-";
    std::cout<<"+";
    for(int j=0; j<8; j++)
        std::cout<<"-";
    std::cout<<"+";
    for(int j=0; j<20; j++)
        std::cout<<"-";
    std::cout<<"+";
    std::cout<<"\n";
    std::cout<<"|";
    for(int j=0; j<3; j++)
        std::cout<<" ";
    std::cout<<"ID";
    for(int j=0; j<3; j++)
        std::cout<<" ";
    std::cout<<"|";
    for(int j=0; j<8; j++)
        std::cout<<" ";
    std::cout<<"TITLU";
    for(int j=0; j<9; j++)
        std::cout<<" ";
    std::cout<<"|";
    for(int j=0; j<9; j++)
        std::cout<<" ";
    std::cout<<"TIP";
    for(int j=0; j<10; j++)
        std::cout<<" ";
    std::cout<<"|";
    for(int j=0; j<3; j++)
        std::cout<<" ";
    std::cout<<"AN";
    for(int j=0; j<3; j++)
        std::cout<<" ";
    std::cout<<"|";
    for(int j=0; j<7; j++)
        std::cout<<" ";
    std::cout<<"ACTOR";
    for(int j=0; j<8; j++)
        std::cout<<" ";
    std::cout<<"|";
    std::cout<<"\n";
    std::cout<<"+";
    for(int j=0; j<8; j++)
        std::cout<<"-";
    std::cout<<"+";
    for(int j=0; j<22; j++)
        std::cout<<"-";
    std::cout<<"+";
    for(int j=0; j<22; j++)
        std::cout<<"-";
    std::cout<<"+";
    for(int j=0; j<8; j++)
        std::cout<<"-";
    std::cout<<"+";
    for(int j=0; j<20; j++)
        std::cout<<"-";
    std::cout<<"+";
    std::cout<<"\n";
    for(int i = 0; i<numar_filme; i++)
    {
        std::string afisarea_ofertei;
        afisarea_ofertei = show_movie(this->bag[i]);
        std::cout << afisarea_ofertei;
        std::cout<<"+";
        for(int j=0; j<8; j++)
            std::cout<<"-";
        std::cout<<"+";
        for(int j=0; j<22; j++)
            std::cout<<"-";
        std::cout<<"+";
        for(int j=0; j<22; j++)
            std::cout<<"-";
        std::cout<<"+";
        for(int j=0; j<8; j++)
            std::cout<<"-";
        std::cout<<"+";
        for(int j=0; j<20; j++)
            std::cout<<"-";
        std::cout<<"+";
        std::cout<<"\n";
    }
}

int Filme::get_pos_by_id(int id){
    for(int i = 0; i < this->filme.size(); ++i){
        if(this->filme[i].get_id() == id){
            return i;
        }
    }
    return -1;
}
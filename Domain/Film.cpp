//
// Created by Valentin Serban on 29.03.2023.
//

#include "Film.h"
#include <iostream>
#include <string>
#include <utility>

/// Getter pentru titlu.
/// \return
std::string Film::get_title() const{
    return this->title;
}

/// Getter pentru tip.
/// \return
std::string Film::get_type() const{
    return this->type;
}

/// Getter pentru an.
/// \return
std::string Film::get_year() const{
    return this->year;
}

/// Getter pentru actor.
/// \return
std::string Film::get_actor() const{
    return this->actor;
}

/// Getter pentru id.
/// \return
int Film::get_id() const{
    return this->id;
}

/// Setter pentru titlu.
/// \param new_title (string)
void Film::set_title(std::string new_title){
    this->title = std::move(new_title);
}

/// Setter pentru tip.
/// \param new_type (string)
void Film::set_type(std::string new_type){
    this->type = std::move(new_type);
}

/// Setter pentru an.
/// \param new_year (string)
void Film::set_year(std::string new_year){
    this->year = std::move(new_year);
}

/// Setter pentru actor.
/// \param new_actor (string)
void Film::set_actor(std::string new_actor){
    this->actor = std::move(new_actor);
}

/// Setter pentru id.
/// \param new_id (string)
void Film::set_id(int new_id){
    this->id = new_id;
}

/// Functie pentru afisarea unui film.
void Film::show_movie() const{
    std::cout << "ID: " << this->get_id() << "\n";
    std::cout << "TITLE: " << this->get_title() << "\n";
    std::cout << "TYPE: " << this->get_type() << "\n";
    std::cout << "YEAR: " << this->get_year() << "\n";
    std::cout << "ACTOR: " << this->get_actor() << "\n";
}
/// Operator overloading pentru ==
/// \param f1
/// \return
bool Film::operator == (const Film &f1) const{
    return f1.get_id() == this->get_id();
}

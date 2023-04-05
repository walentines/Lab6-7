//
// Created by Valentin Serban on 01.04.2023.
//

#include "validators.h"
#include <string>

/// Functie pentru verificarea daca stringul este un numar
/// \param str (string)
/// \return bool
bool check_number(const std::string& str){
    if(std::all_of(str.begin(), str.end(), [](char i) {return isdigit(i);})){
        return true;
    }
    return false;
}

/// Functie pentru validarea titlului
/// \param title (string)
/// \return bool
bool validate_title(const std::string& title){
    if(!title.empty()){
        return true;
    }
    return false;
}

/// Functie pentru validarea tipului
/// \param type (string)
/// \return bool
bool validate_type(const std::string& type){
    if(!type.empty()){
        return true;
    }
    return false;
}

/// Functie pentru validarea actorului
/// \param actor (string)
/// \return bool
bool validate_actor(const std::string& actor){
    if(!actor.empty()){
        return true;
    }
    return false;
}

/// Functie pentru validarea anului
/// \param year (string)
/// \return bool
bool validate_year(const std::string& year){
    if(year.empty()){
        return false;
    }
    if(check_number(year)){
        return true;
    }
    return false;
}

/// Functie pentru validarea id-ului
/// \param id (string)
/// \return bool
bool validate_id(const std::string& id){
    if(id.empty()){
        return false;
    }
    if(check_number(id)){
        return true;
    }
    return false;
}
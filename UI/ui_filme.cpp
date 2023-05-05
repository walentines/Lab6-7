//
// Created by Valentin Serban on 29.03.2023.
//

#include "ui_filme.h"
#include <iostream>
#include <utility>
#include "../Vector/VectorClass.cpp"
#include "../Validator/validators.h"
#include "../Utils/utils.h"
#include "../Exceptions/ExceptionClass.h"


/// Functie pentru afisarea meniului
void show_menu() {
    std::cout << "Netflix\n";
    std::cout << "1. Show all rented movies.\n";
    std::cout << "2. Add a movie.\n";
    std::cout << "3. Delete a movie.\n";
    std::cout << "4. Modify a movie.\n";
    std::cout << "5. Search a movie.\n";
    std::cout << "6. Filter movies.\n";
    std::cout << "7. Generate movies.\n";
    std::cout << "8. Sort movies.\n";
    std::cout << "9. Empty bag.\n";
    std::cout << "10. Add movie to bag.\n";
    std::cout << "11. Show bag.\n";
    std::cout << "12. Generate bag of movies.\n";
    std::cout << "13. Export movies.\n";
    std::cout << "14. Undo.\n";
    std::cout << "15. Exit the app.\n";
}

/// Functie pentru construirea unui film
/// \param id (int)
/// \param title (string)
/// \param type (string)
/// \param year (string)
/// \param actor (string)
/// \return Film
Film ui_filme::build_film(int id, std::string title, std::string type, std::string year, std::string actor){
    Film f;
    f.set_title(std::move(title));
    f.set_year(std::move(year));
    f.set_actor(std::move(actor));
    f.set_type(std::move(type));
    f.set_id(id);

    return f;
}

/// Functie pentru adaugarea unui film la lista de filme
void ui_filme::add_movie(){
    std::string title, type, year, actor;
    std::string id_string;
    std::cout << "Insert ID: ";
    std::getline(std::cin, id_string);
    while(!validate_id(id_string)){
        try{
            if(!validate_id(id_string)){
                throw InvalidID();
            }
        }
        catch (InvalidID& inv_id){
            std::cout << inv_id.what() << "\n";
        }
        std::cout << "Insert ID: ";
        std::getline(std::cin, id_string);
    }
    std::cout << "Insert the name of the movie: ";
    std::getline(std::cin, title);
    while(!validate_title(title)){
        try{
            if(!validate_title(title)){
                throw InvalidTitle();
            }
        }
        catch (InvalidTitle& inv_title){
            std::cout << inv_title.what() << "\n";
        }
        std::cout << "Insert the name of the movie: ";
        std::getline(std::cin, title);
    }
    std::cout << "Insert the type of the movie: ";
    std::getline(std::cin, type);
    while(!validate_type(type)){
        try{
            if(!validate_type(type)){
                throw InvalidType();
            }
        }
        catch (InvalidType& inv_type){
            std::cout << inv_type.what() << "\n";
        }
        std::cout << "Insert the type of the movie: ";
        std::getline(std::cin, type);
    }
    std::cout << "Insert the year of the movie: ";
    std::getline(std::cin, year);
    while(!validate_year(year)){
        try{
            if(!validate_year(year)){
                throw InvalidYear();
            }
        }
        catch (InvalidYear& inv_year){
            std::cout << inv_year.what() << "\n";
        }
        std::cout << "Insert the year of the movie: ";
        std::getline(std::cin, year);
    }
    std::cout << "Insert the actor of the movie: ";
    std::getline(std::cin, actor);
    while(!validate_actor(actor)){
        try{
            if(!validate_actor(actor)){
                throw InvalidActor();
            }
        }
        catch (InvalidActor& inv_actor){
            std::cout << inv_actor.what() << "\n";
        }
        std::cout << "Insert the actor of the movie: ";
        std::getline(std::cin, actor);
    }
    int id = stoi(id_string);
    Film f = build_film(id, title, type, year, actor);
    int ok = this->uiFilme->add_movie(f);
    if(!ok){
        std::cout << "This ID already exists!\n";
    }
}

/// Functie pentru stergerea unui film
void ui_filme::delete_movie() {
    std::string id_string;
    std::cout << "Enter the ID of the movie you want to delete: ";
    std::getline(std::cin, id_string);
    while(!validate_id(id_string)){
        try{
            if(!validate_id(id_string)){
                throw InvalidID();
            }
        }
        catch (InvalidID& inv_id){
            std::cout << inv_id.what() << "\n";
        }
        std::cout << "Enter the ID of the movie you want to delete: ";
        std::getline(std::cin, id_string);
    }
    int id = stoi(id_string);
    vector<Film> f = this->uiFilme->search_movie(id, "", "", "", "");
    if(f[0].get_id() == 0){
        std::cout << "There's no such ID!\n";
    }
    else{
        this->uiFilme->delete_movie(id);
    }
}

/// Functie pentru modificarea unui film
void ui_filme::modify_movie() {
    std::string id_string;
    std::string title, year, actor, type;
    std::cout << "Enter the ID of the movie you want to modify: ";
    std::getline(std::cin, id_string);
    while(!validate_id(id_string)){
        try{
            if(!validate_id(id_string)){
                throw InvalidID();
            }
        }
        catch (InvalidID& inv_id){
            std::cout << inv_id.what() << "\n";
        }
        std::cout << "Enter the ID of the movie you want to modify: ";
        std::getline(std::cin, id_string);
    }
    std::cout << "Enter the title in which you want to change or nothing: ";
    std::getline(std::cin, title);
    std::cout << "Enter the type in which you want to change or nothing: ";
    std::getline(std::cin, type);
    std::cout << "Enter the year in which you want to change or nothing: ";
    std::getline(std::cin, year);
    while(!validate_year(year) && !year.empty()){
        try{
            if(!validate_year(year) && !year.empty()){
                throw InvalidYear();
            }
        }
        catch (InvalidYear& inv_year){
            std::cout << inv_year.what() << "\n";
        }
        std::cout << "Enter the year in which you want to change or nothing: ";
        std::getline(std::cin, year);
    }
    std::cout << "Enter the actor in which you want to change or nothing: ";
    std::getline(std::cin, actor);
    int id = stoi(id_string);
    int ok = this->uiFilme->modify_movie(id, title, type, year, actor);
    if(ok == -1){
        std::cout << "There's no such ID!\n";
    }
}

/// Functie pentru cautarea unui film
void ui_filme::search_movie(){
    int id = 0;
    std::string title, year, actor, type;
    std::cout << "Enter the title of the movie you want to find: ";
    std::getline(std::cin, title);
    std::cout << "Enter the type of the movie you want to find: ";
    std::getline(std::cin, type);
    std::cout << "Enter the year of the movie you want to find: ";
    std::getline(std::cin, year);
    while(!validate_year(year) && !year.empty()){
        try{
            if(!validate_year(year) && !year.empty()){
                throw InvalidYear();
            }
        }
        catch (InvalidYear& inv_year){
            std::cout << inv_year.what() << "\n";
        }
        std::cout << "Enter the year of the movie you want to find: ";
        std::getline(std::cin, year);
    }
    std::cout << "Enter the actor of the movie you want to find: ";
    std::getline(std::cin, actor);

    vector<Film> searched_movies = this->uiFilme->search_movie(id, title, type, year, actor);
    if(searched_movies.empty()){
        std::cout << "There's no such movie!\n";
    }
    show_movies_table(searched_movies);
}

/// Functie pentru filtrarea unui film
void ui_filme::filter_movies(){
    std::string filter_type;
    std::cout << "Enter filter type (title/year): ";
//    std::cin.get();
    std::getline(std::cin, filter_type);
    if(filter_type == "title"){
        std::string title;
        std::cout << "Enter the title by which you want to filter: ";
        std::getline(std::cin, title);
        while(!validate_title(title)){
            try{
                if(!validate_title(title)){
                    throw InvalidTitle();
                }
            }
            catch (InvalidTitle& inv_title){
                std::cout << inv_title.what() << "\n";
            }
            std::cout << "Enter the title by which you want to filter: ";
            std::getline(std::cin, title);
        }
        vector<Film> filtered_movies = this->uiFilme->filter_movies_by_title_service(title);
        show_movies_table(filtered_movies);
    }
    else if(filter_type == "year"){
        std::string year;
        std::cout << "Enter the year by which you want to filter: ";
        std::getline(std::cin, year);
        while(!validate_year(year)){
            try{
                if(!validate_year(year)){
                    throw InvalidYear();
                }
            }
            catch (InvalidYear& inv_year){
                std::cout << inv_year.what() << "\n";
            }
            std::cout << "Enter the year by which you want to filter: ";
            std::getline(std::cin, year);
        }
        vector<Film> filtered_movies = this->uiFilme->filter_movies_by_year_service(year);
        show_movies_table(filtered_movies);

    }
    else{
        std::cout << "Enter a valid filter!";
        return;
    }
}

/// Functie pentru afisarea listei de filme sub forma de tabel
void ui_filme::show_movies() {
//    uiFilme.show_movies();
    uiFilme->show_movies_table();
}

/// Functie pentru afisarea listei de filme sub forma de tabel
void ui_filme::show_movies_table(const vector<Film> & movies)
{
    if (movies.empty()){
        printf("There is no movie!\n");
        return;
    }
    int numar_filme = (int)movies.size();
    printf("+");
    for(int j=0; j<8; j++)
        printf("-");
    printf("+");
    for(int j=0; j<22; j++)
        printf("-");
    printf("+");
    for(int j=0; j<22; j++)
        printf("-");
    printf("+");
    for(int j=0; j<8; j++)
        printf("-");
    printf("+");
    for(int j=0; j<20; j++)
        printf("-");
    printf("+");
    printf("\n");
    printf("|");
    for(int j=0; j<3; j++)
        printf(" ");
    printf("ID");
    for(int j=0; j<3; j++)
        printf(" ");
    printf("|");
    for(int j=0; j<8; j++)
        printf(" ");
    printf("TITLU");
    for(int j=0; j<9; j++)
        printf(" ");
    printf("|");
    for(int j=0; j<9; j++)
        printf(" ");
    printf("TIP");
    for(int j=0; j<10; j++)
        printf(" ");
    printf("|");
    for(int j=0; j<3; j++)
        printf(" ");
    printf("AN");
    for(int j=0; j<3; j++)
        printf(" ");
    printf("|");
    for(int j=0; j<7; j++)
        printf(" ");
    printf("ACTOR");
    for(int j=0; j<8; j++)
        printf(" ");
    printf("|");
    printf("\n");
    printf("+");
    for(int j=0; j<8; j++)
        printf("-");
    printf("+");
    for(int j=0; j<22; j++)
        printf("-");
    printf("+");
    for(int j=0; j<22; j++)
        printf("-");
    printf("+");
    for(int j=0; j<8; j++)
        printf("-");
    printf("+");
    for(int j=0; j<20; j++)
        printf("-");
    printf("+");
    printf("\n");
    for(int i = 0; i<numar_filme; i++)
    {
        std::string afisarea_ofertei;
        afisarea_ofertei = show_movie(movies[i]);
        std::cout << afisarea_ofertei;
        printf("+");
        for(int j=0; j<8; j++)
            printf("-");
        printf("+");
        for(int j=0; j<22; j++)
            printf("-");
        printf("+");
        for(int j=0; j<22; j++)
            printf("-");
        printf("+");
        for(int j=0; j<8; j++)
            printf("-");
        printf("+");
        for(int j=0; j<20; j++)
            printf("-");
        printf("+");
        printf("\n");
    }
}

/// Functie pentru generarea unor filme
void ui_filme::generate_movies_ui(){
    this->uiFilme->generate_movies_service();
}

/// Functie pentru sortarea unor filme
void ui_filme::sort_movies(){
    std::string sort_type, type;
    std::cout << "Enter the sorting type(title, actor, year, type): ";
//    std::cin.get();
    std::getline(std::cin, sort_type);
    std::cout << "Enter the sorting type(asc, desc): ";
    std::getline(std::cin, type);
    if(!(type == "asc" || type == "desc")){
        std::cout << "Enter a valid sorting type!\n";
        return;
    }
    if(sort_type == "title"){
        vector<Film> sorted_movies = this->uiFilme->sort_movies_by_title(type);
        show_movies_table(sorted_movies);
    }
    else if(sort_type == "actor"){
        vector<Film> sorted_movies = this->uiFilme->sort_movies_by_actor(type);
        show_movies_table(sorted_movies);
    }
    else if(sort_type == "year"){
        vector<Film> sorted_movies = this->uiFilme->sort_movies_by_year(type);
        show_movies_table(sorted_movies);
    }
    else if(sort_type == "type"){
        vector<Film> sorted_movies = this->uiFilme->sort_movies_by_type(type);
        show_movies_table(sorted_movies);
    }
    else{
        std::cout << "Enter a valid sorting type!\n";
    }
}

void ui_filme::empty_bag_ui(){
    this->uiFilme->empty_bag_service();
    std::cout << "Number of movies in the bag: " << this->uiFilme->get_bag_size() << "\n";
}

void ui_filme::add_movie_bag_ui(){
    std::string chosen_title;
    std::cout << "Enter the title of the movie you want to add to the bag: ";
    std::getline(std::cin, chosen_title);
    while(!validate_title(chosen_title)){
        try{
            if(!validate_title(chosen_title)){
                throw InvalidTitle();
            }
        }
        catch (InvalidTitle& inv_title){
            std::cout << inv_title.what() << "\n";
        }
        std::cout << "Enter the title of the movie you want to add to the bag: ";
        std::getline(std::cin, chosen_title);
    }
    this->uiFilme->add_movie_bag_service(chosen_title);
    std::cout << "Number of movies in the bag: " << this->uiFilme->get_bag_size() << "\n";
}

void ui_filme::show_bag_table_ui(){
    this->uiFilme->show_bag_table_service();
    std::cout << "Number of movies in the bag: " << this->uiFilme->get_bag_size() << "\n";
}

void ui_filme::generate_bag_of_movies(){
    std::string number_of_movies;
    int errors = 0;
    std::cout << "Enter the number of movies you want to generate: ";
    std::getline(std::cin, number_of_movies);
    while(!validate_id(number_of_movies)){
        if(!validate_id(number_of_movies)){
            std::cout << "Enter a valid number of movies\n";
            errors++;
        }
        std::cout << "Enter the number of movies you want to generate: ";
        std::getline(std::cin, number_of_movies);
    }
    if(!errors){
        int number_of_movies_int = std::stoi(number_of_movies);
        this->uiFilme->fill_the_bag(number_of_movies_int);
        std::cout << "Number of movies in the bag: " << this->uiFilme->get_bag_size() << "\n";
    }
}

void ui_filme::export_movies(){
    std::string export_file;
    std::cout << "Enter the file name: ";
    std::getline(std::cin, export_file);
    while(!validate_title(export_file)){
        if(!validate_title(export_file)){
            std::cout << "Enter a valid file\n";
        }
        std::cout << "Enter the file name: ";
        std::getline(std::cin, export_file);
    }
    this->uiFilme->export_mvs(export_file);
    std::cout << "Number of movies in the bag: " << this->uiFilme->get_bag_size() << "\n";
}

void ui_filme::undo_ui(){
    if (this->uiFilme->undo() == -1){
        std::cout << "You can't undo anymore!\n";
        return;
    }
    std::cout << "Undo done successfully!\n";
}

/// Functie de rulare a aplicatiei
void ui_filme::run(){
    while(true){
        show_menu();
        int command, ok = 0;
        std::string comanda;
        std::cout << "Enter the chosen command: ";
        std::getline(std::cin, comanda);
        if(validate_id(comanda)){
           command = stoi(comanda);
        }
        else{
            std::cout << "Introdu un numar valid!\n";
            continue;
        }
        switch(command){
            case 1:
                show_movies();
                break;
            case 2:
                add_movie();
                break;
            case 3:
                delete_movie();
                break;
            case 4:
                modify_movie();
                break;
            case 5:
                search_movie();
                break;
            case 6:
                filter_movies();
                break;
            case 7:
                generate_movies_ui();
                break;
            case 8:
                sort_movies();
                break;
            case 9:
                empty_bag_ui();
                break;
            case 10:
                add_movie_bag_ui();
                break;
            case 11:
                show_bag_table_ui();
                break;
            case 12:
                generate_bag_of_movies();
                break;
            case 13:
                export_movies();
                break;
            case 14:
                undo_ui();
                break;
            case 15:
                ok = 1;
                break;
            default:
                break;
        }
        if(ok){
            break;
        }
    }
}
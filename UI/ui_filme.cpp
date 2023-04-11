//
// Created by Valentin Serban on 29.03.2023.
//

#include "ui_filme.h"
#include <iostream>
#include <utility>
#include "../Vector/VectorClass.cpp"
#include "../Validator/validators.h"
#include "../Utils/utils.h"


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
    std::cout << "9. Exit application.\n";
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
    int errors = 0;
//    std::cin.get();
    std::string id_string;
    std::cout << "Insert ID: ";
    std::getline(std::cin, id_string);
    std::cout << "Insert the name of the movie: ";
    std::getline(std::cin, title);
    std::cout << "Insert the type of the movie: ";
    std::getline(std::cin, type);
    std::cout << "Insert the year of the movie: ";
    std::getline(std::cin, year);
    std::cout << "Insert the actor of the movie: ";
    std::getline(std::cin, actor);
    if(!validate_id(id_string)){
        std::cout << "Enter a valid ID\n";
        errors++;
    }
    if(!validate_title(title)){
        std::cout << "Enter a valid title\n";
        errors++;
    }
    if(!validate_type(type)){
        std::cout << "Enter a valid type\n";
        errors++;
    }
    if(!validate_year(year)){
        std::cout << "Enter a valid year\n";
        errors++;
    }
    if(!validate_actor(actor)){
        std::cout << "Enter a valid actor\n";
        errors++;
    }
    if(!errors) {
        int id = stoi(id_string);
        Film f = build_film(id, title, type, year, actor);
        int ok = this->uiFilme.add_movie(f);
        if(!ok){
            std::cout << "This ID already exists!\n";
        }
    }
}

/// Functie pentru stergerea unui film
void ui_filme::delete_movie() {
    std::string id_string;
    int errors = 0;
//    std::cin.get();
    std::cout << "Enter the ID of the movie you want to delete: ";
    std::getline(std::cin, id_string);
    if(!validate_id(id_string)){
        std::cout << "Enter a valid ID\n";
        errors++;
    }
    if(!errors){
        int id = stoi(id_string);
        Vector<Film> f = this->uiFilme.search_movie(id, "", "", "", "");
        if(f[0].get_id() == 0){
            std::cout << "There's no such ID!\n";
        }
        else{
            this->uiFilme.delete_movie(id);
        }
    }
}

/// Functie pentru modificarea unui film
void ui_filme::modify_movie() {
    int errors = 0;
    std::string id_string;
    std::string title, year, actor, type;
//    std::cin.get();
    std::cout << "Enter the ID of the movie you want to modify: ";
    std::getline(std::cin, id_string);
    std::cout << "Enter the title in which you want to change or nothing: ";
    std::getline(std::cin, title);
    std::cout << "Enter the type in which you want to change or nothing: ";
    std::getline(std::cin, type);
    std::cout << "Enter the year in which you want to change or nothing: ";
    std::getline(std::cin, year);
    std::cout << "Enter the actor in which you want to change or nothing: ";
    std::getline(std::cin, actor);
    if(!validate_id(id_string)){
        std::cout << "Enter a valid ID\n";
        errors++;
    }
    if(!year.empty() && !validate_year(year)){
        std::cout << "Enter a valid year\n";
        errors++;
    }
    if(!errors){
        int id = stoi(id_string);
        int ok = this->uiFilme.modify_movie(id, title, type, year, actor);
        if(ok == -1){
            std::cout << "There's no such ID!\n";
        }
    }
}

/// Functie pentru cautarea unui film
void ui_filme::search_movie(){
    int errors = 0;
    int id = 0;
    std::string title, year, actor, type;
//    std::cin.get();
    std::cout << "Enter the title of the movie you want to find: ";
    std::getline(std::cin, title);
    std::cout << "Enter the type of the movie you want to find: ";
    std::getline(std::cin, type);
    std::cout << "Enter the year of the movie you want to find: ";
    std::getline(std::cin, year);
    std::cout << "Enter the actor of the movie you want to find: ";
    std::getline(std::cin, actor);
    if(!year.empty() && !validate_year(year)){
        std::cout << "Enter a valid year\n";
        errors++;
    }
    if(!errors){
        Vector<Film> searched_movies = this->uiFilme.search_movie(id, title, type, year, actor);
        if(searched_movies.size() == 0){
            std::cout << "There's no such movie!\n";
        }
//        for(int i = 0; i < searched_movies.size(); ++i){
//            searched_movies[i].show_movie();
//            std::cout << "\n";
        show_movies_table(searched_movies);
//        }

    }
}

/// Functie pentru filtrarea unui film
void ui_filme::filter_movies(){
    std::string filter_type;
    std::cout << "Enter filter type (title/year): ";
//    std::cin.get();
    std::getline(std::cin, filter_type);
    if(filter_type == "title"){
        std::string title;
        int errors = 0;
        std::cout << "Enter the title by which you want to filter: ";
        std::getline(std::cin, title);
        if(!validate_title(title)){
            std::cout << "Enter a valid title\n";
            errors++;
        }
        if(!errors){
            Vector<Film> filtered_movies = this->uiFilme.filter_movies_by_title_service(title);
//            for(int i = 0; i < filtered_movies.size(); ++i){
//                filtered_movies[i].show_movie();
//                std::cout << "\n";
//            }
            show_movies_table(filtered_movies);
        }
    }
    else if(filter_type == "year"){
        std::string year;
        int errors = 0;
        std::cout << "Enter the year by which you want to filter: ";
        std::getline(std::cin, year);
        if(!validate_year(year)){
            std::cout << "Enter a valid year\n";
            errors++;
        }
        if(!errors){
            Vector<Film> filtered_movies = this->uiFilme.filter_movies_by_year_service(year);

//            for(int i = 0; i < filtered_movies.size(); ++i){
//                filtered_movies[i].show_movie();
//                std::cout << "\n";
//            }
            show_movies_table(filtered_movies);
        }
    }
    else{
        std::cout << "Enter a valid filter!";
        return;
    }
}

/// Functie pentru afisarea listei de filme sub forma de tabel
void ui_filme::show_movies() {
//    uiFilme.show_movies();
    uiFilme.show_movies_table();
}

/// Functie pentru afisarea listei de filme sub forma de tabel
void ui_filme::show_movies_table(const Vector<Film> & movies)
{
    if (movies.size() == 0){
        printf("There is no movie!\n");
        return;
    }
    int numar_filme = movies.size();
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
    this->uiFilme.generate_movies_service();
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
        Vector<Film> sorted_movies = this->uiFilme.sort_movies_by_title(type);

//        for(int i = 0; i < sorted_movies.size(); ++i){
//            sorted_movies[i].show_movie();
//            std::cout << "\n";
//        }
        show_movies_table(sorted_movies);
    }
    else if(sort_type == "actor"){
        Vector<Film> sorted_movies = this->uiFilme.sort_movies_by_actor(type);

//        for(int i = 0; i < sorted_movies.size(); ++i){
//            sorted_movies[i].show_movie();
//            std::cout << "\n";
//        }
        show_movies_table(sorted_movies);
    }
    else if(sort_type == "year"){
        Vector<Film> sorted_movies = this->uiFilme.sort_movies_by_year(type);

//        for(int i = 0; i < sorted_movies.size(); ++i){
//            sorted_movies[i].show_movie();
//            std::cout << "\n";
//        }
        show_movies_table(sorted_movies);
    }
    else if(sort_type == "type"){
        Vector<Film> sorted_movies = this->uiFilme.sort_movies_by_type(type);

//        for(int i = 0; i < sorted_movies.size(); ++i){
//            sorted_movies[i].show_movie();
//            std::cout << "\n";
//        }
        show_movies_table(sorted_movies);
    }
    else{
        std::cout << "Enter a valid sorting type!\n";
    }
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
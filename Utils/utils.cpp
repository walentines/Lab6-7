//
// Created by Valentin Serban on 30.03.2023.
//

#include "utils.h"
#include "../Vector/VectorClass.cpp"
#include <vector>
#include <random>
#include <algorithm>
#include <fstream>

using std::vector;

/// Functie pentru compararea a doua filme dupa titlu desc
/// \param a Film
/// \param b Film
/// \return int
int compare_title_desc(const Film &a, const Film &b){
    std::string s1 = a.get_title();
    std::string s2 = b.get_title();
    std::transform(s1.begin(), s1.end(), s1.begin(), ::tolower);
    std::transform(s2.begin(), s2.end(), s2.begin(), ::tolower);
    return s1 > s2;
}

/// Functie pentru compararea a doua filme dupa titlu asc
/// \param a Film
/// \param b Film
/// \return int
int compare_title_asc(const Film &a, const Film &b){
    std::string s1 = a.get_title();
    std::string s2 = b.get_title();
    std::transform(s1.begin(), s1.end(), s1.begin(), ::tolower);
    std::transform(s2.begin(), s2.end(), s2.begin(), ::tolower);
    return s1 < s2;
}

/// Functie pentru compararea a doua filme dupa actor asc
/// \param a Film
/// \param b Film
/// \return int
int compare_actor_asc(const Film &a, const Film &b){
    std::string s1 = a.get_actor();
    std::string s2 = b.get_actor();
    std::transform(s1.begin(), s1.end(), s1.begin(), ::tolower);
    std::transform(s2.begin(), s2.end(), s2.begin(), ::tolower);
    return s1 < s2;
}

/// Functie pentru compararea a doua filme dupa actor desc
/// \param a Film
/// \param b Film
/// \return int
int compare_actor_desc(const Film &a, const Film &b){
    std::string s1 = a.get_actor();
    std::string s2 = b.get_actor();
    std::transform(s1.begin(), s1.end(), s1.begin(), ::tolower);
    std::transform(s2.begin(), s2.end(), s2.begin(), ::tolower);
    return s1 > s2;
}

/// Functie pentru compararea a doua filme dupa an desc
/// \param a Film
/// \param b Film
/// \return int
int compare_year_desc(const Film &a, const Film &b){
    std::string s1 = a.get_year();
    std::string s2 = b.get_year();
    std::transform(s1.begin(), s1.end(), s1.begin(), ::tolower);
    std::transform(s2.begin(), s2.end(), s2.begin(), ::tolower);
    return s1 > s2;
}

/// Functie pentru compararea a doua filme dupa an asc
/// \param a Film
/// \param b Film
/// \return int
int compare_year_asc(const Film &a, const Film &b){
    std::string s1 = a.get_year();
    std::string s2 = b.get_year();
    std::transform(s1.begin(), s1.end(), s1.begin(), ::tolower);
    std::transform(s2.begin(), s2.end(), s2.begin(), ::tolower);
    return s1 < s2;
}

/// Functie pentru compararea a doua filme dupa tip desc
/// \param a Film
/// \param b Film
/// \return int
int compare_type_desc(const Film &a, const Film &b){
    std::string s1 = a.get_type();
    std::string s2 = b.get_type();
    std::transform(s1.begin(), s1.end(), s1.begin(), ::tolower);
    std::transform(s2.begin(), s2.end(), s2.begin(), ::tolower);
    return s1 > s2;
}

/// Functie pentru compararea a doua filme dupa tip asc
/// \param a Film
/// \param b Film
/// \return int
int compare_type_asc(const Film &a, const Film &b){
    std::string s1 = a.get_type();
    std::string s2 = b.get_type();
    std::transform(s1.begin(), s1.end(), s1.begin(), ::tolower);
    std::transform(s2.begin(), s2.end(), s2.begin(), ::tolower);
    return s1 < s2;
}

/// Functie pentru filtarea filmelor dupa titlu
/// \param movies Filme
/// \param title string
/// \return vector<Film>
vector<Film> filter_movies_by_title(const Filme& movies, const std::string& title) {
    vector<Film> filtered_movies;
    for(int i = 0; i < movies.get_length(); ++i){
        Film mv = movies.get_movie_by_pos(i);
        if(mv.get_title() == title){
            filtered_movies.push_back(mv);
        }
    }

    return filtered_movies;
}

/// Functie pentru filtarea filmelor dupa an
/// \param movies Filme
/// \param title string
/// \return vector<Film>
vector<Film> filter_movies_by_year(const Filme& movies, const std::string& year){
    vector<Film> filtered_movies;
    for(int i = 0; i < movies.get_length(); ++i){
        if(movies.get_movie_by_pos(i).get_year() >= year){
            filtered_movies.push_back(movies.get_movie_by_pos(i));
        }
    }

    return filtered_movies;
}

/// Functie pentru sortarea filmelor dupa titlu dupa tipul asc sau desc
/// \param movies Filme
/// \param type (string)
/// \return vector<Film>
vector<Film> sort_movies_title(const Filme& movies, const std::string& type){
    vector<Film> mvs;
    mvs.reserve(movies.get_length());
for(int i = 0; i < movies.get_length(); ++i){
        mvs.push_back(movies.get_movie_by_pos(i));
    }
    if(type == "asc"){
        sort(mvs.begin(), mvs.end(), compare_title_asc);
    }
    else if(type == "desc"){
        sort(mvs.begin(), mvs.end(), compare_title_desc);
    }

    return mvs;
}

/// Functie pentru sortarea filmelor dupa actor dupa tipul asc sau desc
/// \param movies Filme
/// \param type (string)
/// \return vector<Film>
vector<Film> sort_movies_actor(const Filme& movies, const std::string& type){
    vector<Film> mvs;
    mvs.reserve(movies.get_length());
for(int i = 0; i < movies.get_length(); ++i){
        mvs.push_back(movies.get_movie_by_pos(i));
    }
    if(type == "asc"){
        sort(mvs.begin(), mvs.end(), compare_actor_asc);
    }
    else if(type == "desc"){
        sort(mvs.begin(), mvs.end(), compare_actor_desc);
    }

    return mvs;
}

/// Functie pentru sortarea filmelor dupa an dupa tipul asc sau desc
/// \param movies Filme
/// \param type (string)
/// \return vector<Film>
vector<Film> sort_movies_year(const Filme& movies, const std::string& type){
    vector<Film> mvs;
    mvs.reserve(movies.get_length());
for(int i = 0; i < movies.get_length(); ++i){
        mvs.push_back(movies.get_movie_by_pos(i));
    }
    if(type == "asc"){
        sort(mvs.begin(), mvs.end(), compare_year_asc);
    }
    else if(type == "desc"){
        sort(mvs.begin(), mvs.end(), compare_year_desc);

    }

    return mvs;
}

/// Functie pentru sortarea filmelor dupa tip dupa tipul asc sau desc
/// \param movies Filme
/// \param type (string)
/// \return vector<Film>
vector<Film> sort_movies_type(const Filme& movies, const std::string& type){
    vector<Film> mvs;
    mvs.reserve(movies.get_length());
for(int i = 0; i < movies.get_length(); ++i){
        mvs.push_back(movies.get_movie_by_pos(i));
    }
    if(type == "asc"){
        sort(mvs.begin(), mvs.end(), compare_type_asc);
    }
    else if(type == "desc"){
        sort(mvs.begin(), mvs.end(), compare_type_desc);
    }

    return mvs;
}

/// Functie pentru calcularea numarului de cifre al unui numar
/// \param n int
/// \return int
int nr_cifre_ceva(int n)
/**
 * afla numarul de cifre ale nr-ul n primit
 * @param n numar intreg
 * @return numarul de cifre
 */
{
    int i = 0;
    while(n > 0){
        i++;
        n/=10;
    }
    return i;
}

/// Functie pentru afisarea filmelor sub forma de tabel
/// \param movie Filme
/// \return string
std::string show_movie(const Film& movie){
    std::string printare;
    std::string id_str;
    int cifre_id;
    int nr_spatiu_1;
    int nr_spatiu_2;
    int i;

    id_str = std::to_string(movie.get_id());
    cifre_id = nr_cifre_ceva(movie.get_id());
    cifre_id = 8 - cifre_id;
    if(cifre_id % 2 == 0){
        nr_spatiu_1 = cifre_id/2;
        nr_spatiu_2 = cifre_id/2;
    } else{
        nr_spatiu_1 = cifre_id/2;
        nr_spatiu_2 = nr_spatiu_1 + 1;
    }
    printare = "|";
    for(i = 1; i<=nr_spatiu_1; i++)
        printare += " ";
    printare += id_str;
    for(i = 1; i<=nr_spatiu_2; i++)
        printare += " ";

    printare += "|";

    cifre_id = (int)movie.get_title().size();
    cifre_id = 22 - cifre_id;
    if(cifre_id % 2 == 0){
        nr_spatiu_1 = cifre_id/2;
        nr_spatiu_2 = cifre_id/2;
    } else{
        nr_spatiu_1 = cifre_id/2;
        nr_spatiu_2 = nr_spatiu_1 + 1;
    }

    for(i = 1; i<=nr_spatiu_1; i++)
        printare += " ";
    printare += movie.get_title();
    for(i = 1; i<=nr_spatiu_2; i++)
        printare += " ";
    printare += "|";

    cifre_id = (int)movie.get_type().size();
    cifre_id = 22 - cifre_id;
    if(cifre_id % 2 == 0){
        nr_spatiu_1 = cifre_id/2;
        nr_spatiu_2 = cifre_id/2;
    } else{
        nr_spatiu_1 = cifre_id/2;
        nr_spatiu_2 = nr_spatiu_1 + 1;
    }
    for(i = 1; i<=nr_spatiu_1; i++)
        printare += " ";
    printare += movie.get_type();
    for(i = 1; i<=nr_spatiu_2; i++)
        printare += " ";

    cifre_id = (int)movie.get_year().size();
    cifre_id = 8 - cifre_id;
    if(cifre_id % 2 == 0){
        nr_spatiu_1 = cifre_id/2;
        nr_spatiu_2 = cifre_id/2;
    } else{
        nr_spatiu_1 = cifre_id/2;
        nr_spatiu_2 = nr_spatiu_1 + 1;
    }
    printare += "|";
    for(i = 1; i<=nr_spatiu_1; i++)
        printare += " ";
    printare += movie.get_year();
    for(i = 1; i<=nr_spatiu_2; i++)
        printare += " ";

    cifre_id = (int)movie.get_actor().size();
    cifre_id = 20 - cifre_id;
    if(cifre_id % 2 == 0){
        nr_spatiu_1 = cifre_id/2;
        nr_spatiu_2 = cifre_id/2;
    } else{
        nr_spatiu_1 = cifre_id/2;
        nr_spatiu_2 = nr_spatiu_1 + 1;
    }
    printare += "|";
    for(i = 1; i<=nr_spatiu_1; i++)
        printare += " ";
    printare += movie.get_actor();
    for(i = 1; i<=nr_spatiu_2; i++)
        printare += " ";

    printare += "|\n";
    return printare;
}

/// Functie pentru generarea filmelor
/// \param movies Filme
void generate_movies(Filme &movies){
    Film f;
    f.set_id(1);
    f.set_type("Action");
    f.set_year("2000");
    f.set_actor("Silvester Stallone");
    f.set_title("Terminator");
    movies.add_movie(f);

    f.set_id(2);
    f.set_type("Comedy");
    f.set_year("1997");
    f.set_actor("Jenniffer Aniston");
    f.set_title("Friends");
    movies.add_movie(f);

    f.set_id(3);
    f.set_type("Adventure");
    f.set_year("2002");
    f.set_actor("Tobey Maguire");
    f.set_title("Spider-Man 2");
    movies.add_movie(f);

    f.set_id(4);
    f.set_type("Adventure");
    f.set_year("2019");
    f.set_actor("Tom Holland");
    f.set_title("Uncharted");
    movies.add_movie(f);

    f.set_id(5);
    f.set_type("Comedy");
    f.set_year("2013");
    f.set_actor("Sheldon");
    f.set_title("The Big Bang Theory");
    movies.add_movie(f);

    f.set_id(6);
    f.set_type("Comedy");
    f.set_year("2015");
    f.set_actor("Morty");
    f.set_title("Rick and Morty");
    movies.add_movie(f);

    f.set_id(7);
    f.set_type("Adventure");
    f.set_year("1999");
    f.set_actor("Frodo Baggins");
    f.set_title("The Lord of the Rings");
    movies.add_movie(f);

    f.set_id(8);
    f.set_type("Action");
    f.set_year("2016");
    f.set_actor("Jessica Jones");
    f.set_title("Hunger Games");
    movies.add_movie(f);

    f.set_id(9);
    f.set_type("Horror");
    f.set_year("2022");
    f.set_actor("Margaret Mead");
    f.set_title("The Conjuring");
    movies.add_movie(f);

    f.set_id(10);
    f.set_type("Comedy");
    f.set_year("2000");
    f.set_actor("LeBron James");
    f.set_title("Scary Movie");
    movies.add_movie(f);
}

void get_random_elements(Filme& movies, int number_of_elem){
    std::mt19937 mt{ std::random_device{}() };
    while(number_of_elem--){
        std::uniform_int_distribution<> dist(0, movies.get_length()-1);
        int rndNr = dist(mt);
        movies.add_movie_bag(movies.get_movie_by_pos(rndNr).get_title());
    }
}

void write_to_csv(const Film& mv, std::fstream& fout){
    fout << mv.get_id() << ", ";
    fout << mv.get_title() << ", ";
    fout << mv.get_type() << ", ";
    fout << mv.get_year() << ", ";
    fout << mv.get_actor();
    fout << "\n";
}

void export_movies(Filme &movies, const std::string& file){
    std::fstream fout;
    fout.open(file, std::ios::out);
    for(int i = 0; i < movies.get_bag_length(); ++i){
        Film mov = movies.get_movie_by_pos(i);
        write_to_csv(mov, fout);
    }
}
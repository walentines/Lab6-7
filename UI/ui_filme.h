//
// Created by Valentin Serban on 29.03.2023.
//

#ifndef LAB6_7_UI_FILME_H
#define LAB6_7_UI_FILME_H

#include "../Service/service_filme.h"

class ui_filme {
private:
    FilmeS uiFilme;
public:

    ui_filme() = default;

    void add_movie();

    void delete_movie();

    void modify_movie();

    void show_movies();

    void run();

    ~ui_filme() = default;

    static Film build_film(int id, std::string title, std::string type, std::string year, std::string actor);

    void search_movie();

    void filter_movies();

    void generate_movies_ui();

    void sort_movies();

    static void show_movies_table(const Vector<Film> &movies);
};


#endif //LAB6_7_UI_FILME_H

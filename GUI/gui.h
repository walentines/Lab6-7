//
// Created by Valentin Serban on 05.05.2023.
//

#ifndef LAB6_7_GUI_H
#define LAB6_7_GUI_H

#include <QtWidgets>
#include "../Service/service_filme.h"
#include <iostream>
#include "../Domain/Film.h"
#include "../Validator/validators.h"

class gui : public QWidget {
private:
    FilmeS *service;
public:
    explicit gui(FilmeS* service_filme){
        service = service_filme;
    }
    void init_window();
    void add_movie(QListWidget *list_mv_show, QLineEdit *id, QLineEdit *title, QLineEdit *type, QLineEdit *year, QLineEdit *actor);

    ~gui() override = default;

    void delete_movie(QListWidget *list_mv_show, QLineEdit *id);

    void show_item(QListWidget *lst_mv, QLineEdit *id, QLineEdit *title, QLineEdit *type, QLineEdit *year, QLineEdit *actor);

    void modify_movie(QListWidget *list_mv_show, QLineEdit *id, QLineEdit *title, QLineEdit *type, QLineEdit *year,
                      QLineEdit *actor);

    void filter_movies_by_title(QLineEdit *title);

    void create_new_window(const vector<Film> &filtered_mvs);

    void create_new_window_bag(const vector<Film> &filtered_mvs);

    void filter_movies_by_year(QLineEdit *year);

    void sort_movies_by_title_asc();

    void sort_movies_by_title_desc();

    void generate_movies(QListWidget *list_mv_show);

    void sort_movies_by_type_asc();

    void sort_movies_by_type_desc();

    void sort_movies_by_year_asc();

    void sort_movies_by_year_desc();

    void sort_movies_by_actor_asc();

    void sort_movies_by_actor_desc();

    void generate_bag_window();

    void add_movie_to_bag(QListWidget *list_mv_show, QLineEdit *title_2);

    void clear_mv_bag(QListWidget *list_mv_show);

    void export_mv_bag(QLineEdit *file);

    void fill_mv_bag(QListWidget *list_mv_show, QLineEdit *mvs);

    void undo_mv(QListWidget *list_mv_show);

    void filter_movies_by_type(QLineEdit *type);
};


#endif //LAB6_7_GUI_H

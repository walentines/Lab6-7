//
// Created by Valentin Serban on 05.05.2023.
//

#include "gui.h"

void gui::init_window() {
    auto* widget = new QWidget();
    auto *lay = new QFormLayout(widget);
    auto *lbl = new QLabel("ID:", widget);
    auto *id = new QLineEdit(widget);
    lay->addRow(lbl, id);
    lbl = new QLabel("Title:", widget);
    auto *title = new QLineEdit(widget);
    lay->addRow(lbl, title);
    lbl = new QLabel("Type:", widget);
    auto *type = new QLineEdit(widget);
    lay->addRow(lbl, type);
    lbl = new QLabel("Year:", widget);
    auto *year = new QLineEdit(widget);
    lay->addRow(lbl, year);
    lbl = new QLabel("Actor:", widget);
    auto *actor = new QLineEdit(widget);
    lay->addRow(lbl, actor);
    auto* add = new QPushButton("Add movie!");
    connect(add, &QPushButton::released, widget, [id, title, type, year, actor, this]{add_movie(id, title, type, year, actor);});
    lay->addRow(add);
    auto *list = new QListWidget(widget);
    new QListWidgetItem("Item1", list);
    new QListWidgetItem("Item2", list);

    auto* widget2 = new QWidget();
    auto *lay2 = new QHBoxLayout(widget2);
    lay2->addWidget(list);
    widget->show();
    widget2->show();
    widget->setWindowTitle("Rent a Movie!");
    widget->setFixedHeight(widget->sizeHint().height());
}

void gui::add_movie(QLineEdit *id, QLineEdit *title, QLineEdit *type, QLineEdit *year, QLineEdit *actor) {
    // Getting the data
    QString id_string = id->text();
    std::ignore = id_string;
    QString title_string = title->text();
    std::ignore = title_string;
    QString type_string = type->text();
    std::ignore = type_string;
    QString year_string = year->text();
    std::ignore = year_string;
    QString actor_string = actor->text();
    std::ignore = actor_string;

    // Validation
    std::string id_str = id_string.toStdString();
    std::string title_str = title_string.toStdString();
    std::string type_str = type_string.toStdString();
    std::string year_str = year_string.toStdString();
    std::string actor_str = actor_string.toStdString();

    if(!validate_id(id_str) || !validate_title(title_str) || !validate_type(type_str) || !validate_year(year_str) || !validate_actor(actor_str)){
        return;
    }

    // Building a movie object
    Film mv;
    int id_int = stoi(id_str);
    mv.set_id(id_int);
    mv.set_title(title_str);
    mv.set_type(type_str);
    mv.set_year(year_str);
    mv.set_actor(actor_str);

    int ok = this->service->add_movie(mv);
    if(!ok){
        std::cout << "Ceva nu e bine!\n";
    }
    this->service->show_movies_table();
}

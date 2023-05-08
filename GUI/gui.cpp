//
// Created by Valentin Serban on 05.05.2023.
//

#include "gui.h"

void gui::init_window() {
    auto main = new QWidget();
    main->setBaseSize(720, 300);
    auto hlay = new QHBoxLayout();  //orizontal
    auto vlay = new QVBoxLayout();  //vertical

    auto buton_adauga = new QPushButton("  Add movie!   ");

    auto list_mv_show = new QListWidget();
    for(int i = 0; i < this->service->get_length(); ++i){
        auto for_show = this->service->get_movie_by_pos(i).get_title();
        auto for_show2 = QString::fromStdString(for_show);
        auto list_item = new QListWidgetItem();
        list_item->setText(for_show2);
        list_mv_show->addItem(list_item);
    }
    main->setLayout(hlay);
    main->show();

    hlay->addWidget(list_mv_show);

    auto add_widget = new QWidget();
    auto fl = new QFormLayout();
    add_widget->setLayout(fl);
    auto *lbl = new QLabel("ID:");
    auto *id = new QLineEdit();
    id->setPlaceholderText("ENTER ID");
    id->setValidator(new QIntValidator());
    fl->addRow(lbl, id);
    lbl = new QLabel("Title:");
    auto *title = new QLineEdit();
    title->setPlaceholderText("ENTER TITLE");
    fl->addRow(lbl, title);
    lbl = new QLabel("Type:");
    auto *type = new QLineEdit();
    type->setPlaceholderText("ENTER TYPE");
    fl->addRow(lbl, type);
    lbl = new QLabel("Year:");
    auto *year = new QLineEdit();
    year->setPlaceholderText("ENTER YEAR");
    year->setValidator(new QIntValidator());
    fl->addRow(lbl, year);
    lbl = new QLabel("Actor:");
    auto *actor = new QLineEdit();
    actor->setPlaceholderText("ENTER ACTOR");
    fl->addRow(lbl, actor);
    fl->addRow(buton_adauga);
    auto *buton_sterge = new QPushButton("Delete movie! ");
    fl->addRow(buton_sterge);
    auto *buton_modifica = new QPushButton("Modify movie!");
    fl->addRow(buton_modifica);
    auto generate_mov_buton = new QPushButton("Generate  ");
    fl->addRow(generate_mov_buton);
    auto bag = new QPushButton("Cart");
    fl->addRow(bag);
    hlay->addWidget(add_widget);
    auto buton_filter_title = new QPushButton("Filter Title ");
    auto fl2_filter = new QVBoxLayout();
    fl2_filter->addWidget(buton_filter_title);
    auto buton_filter_year = new QPushButton("Filter Year ");
    fl2_filter->addWidget(buton_filter_year);
    auto buton_undo = new QPushButton("Undo");
    fl2_filter->addWidget(buton_undo);
    auto fl2_sort = new QVBoxLayout();
    auto buton_sort_title_asc = new QPushButton("Sort Title^");
    fl2_sort->addWidget(buton_sort_title_asc);
    auto buton_sort_title_desc = new QPushButton("Sort Title⌄");
    fl2_sort->addWidget(buton_sort_title_desc);
    auto buton_sort_type_asc = new QPushButton("Sort Type^");
    fl2_sort->addWidget(buton_sort_type_asc);
    auto buton_sort_type_desc = new QPushButton("Sort Type⌄");
    fl2_sort->addWidget(buton_sort_type_desc);
    auto buton_sort_year_asc = new QPushButton("Sort Year^");
    fl2_sort->addWidget(buton_sort_year_asc);
    auto buton_sort_year_desc = new QPushButton("Sort Year⌄");
    fl2_sort->addWidget(buton_sort_year_desc);
    auto buton_sort_actor_asc = new QPushButton("Sort Actor^");
    fl2_sort->addWidget(buton_sort_actor_asc);
    auto buton_sort_actor_desc = new QPushButton("Sort Actor⌄");
    fl2_sort->addWidget(buton_sort_actor_desc);
    hlay->addLayout(fl2_filter);
    hlay->addLayout(fl2_sort);
    connect(buton_adauga, &QPushButton::released, main, [list_mv_show, id, title, type, year, actor, this]{add_movie(list_mv_show, id, title, type, year, actor);});
    connect(buton_sterge, &QPushButton::released, add_widget, [list_mv_show, id, this]{delete_movie(list_mv_show, id);});
    connect(list_mv_show, &QListWidget::itemClicked, main, [list_mv_show, id, title, type, year, actor, this]{show_item(list_mv_show, id, title, type, year, actor);});
    connect(buton_modifica, &QPushButton::released, main, [list_mv_show, id, title, type, year, actor, this]{modify_movie(list_mv_show, id, title, type, year, actor);});
    connect(buton_filter_title, &QPushButton::released, main, [title, this]{filter_movies_by_title(title);});
    connect(buton_filter_year, &QPushButton::released, main, [year, this]{filter_movies_by_year(year);});
    connect(buton_sort_title_asc, &QPushButton::released, main, [this]{sort_movies_by_title_asc();});
    connect(buton_sort_title_desc, &QPushButton::released, main, [this]{sort_movies_by_title_desc();});
    connect(generate_mov_buton, &QPushButton::released, main, [list_mv_show, this]{generate_movies(list_mv_show);});
    connect(buton_sort_type_asc, &QPushButton::released, main, [this]{sort_movies_by_type_asc();});
    connect(buton_sort_type_desc, &QPushButton::released, main, [this]{sort_movies_by_type_desc();});
    connect(buton_sort_year_asc, &QPushButton::released, main, [this]{sort_movies_by_year_asc();});
    connect(buton_sort_year_desc, &QPushButton::released, main, [this]{sort_movies_by_year_desc();});
    connect(buton_sort_actor_asc, &QPushButton::released, main, [this]{sort_movies_by_actor_asc();});
    connect(buton_sort_actor_desc, &QPushButton::released, main, [this]{sort_movies_by_actor_desc();});
    connect(bag, &QPushButton::released, main, [this]{generate_bag_window();});
    connect(buton_undo, &QPushButton::released, main, [list_mv_show, this]{undo_mv(list_mv_show);});
    hlay->addLayout(vlay);
}

void gui::add_movie(QListWidget *list_mv_show, QLineEdit *id, QLineEdit *title, QLineEdit *type, QLineEdit *year, QLineEdit *actor) {
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
        return;
    }
    auto list_item = new QListWidgetItem();
    list_item->setText("ID: " + id_string + " TITLE: " + title_string);
    list_mv_show->addItem(list_item);
}

void gui::delete_movie(QListWidget *list_mv_show, QLineEdit *id){
    QString id_string = id->text();
    std::ignore = id_string;
    std::string id_str = id_string.toStdString();
    if(!validate_id(id_str)){
        return;
    }
    int id_int = stoi(id_str);
    int pos = this->service->get_pos_by_id_s(id_int);
    list_mv_show->takeItem(pos);
    int ok = this->service->delete_movie(id_int);
    if(ok == -1){
        return;
    }
}

void gui::undo_mv(QListWidget *list_mv_show){
    this->service->undo();
    list_mv_show->clear();
    for(int i = 0; i < this->service->get_length(); ++i){
        auto for_show = this->service->get_movie_by_pos(i).get_title();
        auto for_show2 = QString::fromStdString(for_show);
        auto list_item = new QListWidgetItem();
        list_item->setText("ID: " + QString::fromStdString(std::to_string(this->service->get_movie_by_pos(i).get_id())) + " TITLE: " + for_show2);
        list_mv_show->addItem(list_item);
    }
}

void gui::modify_movie(QListWidget *list_mv_show, QLineEdit *id, QLineEdit *title, QLineEdit *type, QLineEdit *year, QLineEdit *actor){
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

    if(!validate_id(id_str)){
        return;
    }

    int id_int = stoi(id_str);
    int ok = this->service->modify_movie(id_int, title_str, type_str, year_str, actor_str);
    if(ok == -1){
        return;
    }
    Film mv = this->service->get_movie_by_id(id_int);
    for(int row = 0; row < list_mv_show->count(); ++row){
        QListWidgetItem *item = list_mv_show->item(row);
        QString item_string = item->text();
        QStringList item_string_list = item_string.split(" ");
        QString item_id = item_string_list[1];
        std::string item_id_str = item_id.toStdString();
        int item_id_int = stoi(item_id_str);
        if(item_id_int == id_int){
            item->setText("ID: " + item_id + " TITLE: " + QString::fromStdString(title_str));
            return;
        }
    }
}

void gui::create_new_window_bag(const vector<Film> &filtered_mvs){
    auto newWidget = new QWidget();
    newWidget->setBaseSize(500, 300);
    auto hlay = new QHBoxLayout();
    auto vlay = new QVBoxLayout();
    auto list_mv_show = new QListWidget();
    for(const auto & filtered_mv : filtered_mvs){
        auto for_show = filtered_mv.get_title();
        auto for_show2 = QString::fromStdString(for_show);
        auto list_item = new QListWidgetItem();
        list_item->setText("ID: " + QString::number(filtered_mv.get_id()) + " TITLE: " + for_show2);
        list_mv_show->addItem(list_item);
    }
    newWidget->setLayout(hlay);
    newWidget->show();

    hlay->addWidget(list_mv_show);

    auto add_widget = new QWidget();
    auto fl = new QFormLayout();
    add_widget->setLayout(fl);
    auto *lbl = new QLabel("ID:");
    auto *id = new QLineEdit();
    fl->addRow(lbl, id);
    lbl = new QLabel("Title:");
    auto *title_2 = new QLineEdit();
    fl->addRow(lbl, title_2);
    lbl = new QLabel("Type:");
    auto *type = new QLineEdit();
    fl->addRow(lbl, type);
    lbl = new QLabel("Year:");
    auto *year = new QLineEdit();
    fl->addRow(lbl, year);
    lbl = new QLabel("Actor:");
    auto *actor = new QLineEdit();
    fl->addRow(lbl, actor);
    lbl = new QLabel("File:");
    auto *file = new QLineEdit();
    fl->addRow(lbl, file);
    lbl = new QLabel("Num. Movies:");
    auto *num_movies = new QLineEdit();
    fl->addRow(lbl, num_movies);
    auto add_to_bag = new QPushButton("Add to cart!");
    fl->addRow(add_to_bag);
    auto clear_bag = new QPushButton("Clear cart!");
    fl->addRow(clear_bag);
    auto export_bag = new QPushButton("Export cart!");
    fl->addRow(export_bag);
    auto fill_bag = new QPushButton("Fill cart!");
    fl->addRow(fill_bag);
    hlay->addWidget(add_widget);
    connect(list_mv_show, &QListWidget::itemClicked, newWidget, [list_mv_show, id, title_2, type, year, actor, this]{show_item(list_mv_show, id, title_2, type, year, actor);});
    connect(add_to_bag, &QPushButton::released, newWidget, [list_mv_show, title_2, this]{add_movie_to_bag(list_mv_show, title_2);});
    connect(clear_bag, &QPushButton::released, newWidget, [list_mv_show, this]{clear_mv_bag(list_mv_show);});
    connect(export_bag, &QPushButton::released, newWidget, [file, this]{export_mv_bag(file);});
    connect(fill_bag, &QPushButton::released, newWidget, [list_mv_show, num_movies, this]{fill_mv_bag(list_mv_show, num_movies);});
    hlay->addLayout(vlay);
}

void gui::add_movie_to_bag(QListWidget *list_mv_show, QLineEdit *title_2){
    QString title_text = title_2->text();
    this->service->add_movie_bag_service(title_text.toStdString());
    Film added_mv = this->service->get_bag_service()[this->service->get_bag_size() - 1];
    std::cout << added_mv.get_id();
    std::string id_str = std::to_string(added_mv.get_id());
    QString id_string = QString::fromStdString(id_str);
    auto list_item = new QListWidgetItem();
    list_item->setText("ID: " + id_string + " TITLE: " + title_text);
    list_mv_show->addItem(list_item);
}

void gui::clear_mv_bag(QListWidget *list_mv_show){
    this->service->empty_bag_service();
    list_mv_show->clear();
}

void gui::export_mv_bag(QLineEdit *file){
    this->service->export_mvs(file->text().toStdString());
}

void gui::fill_mv_bag(QListWidget *list_mv_show, QLineEdit *mvs){
    std::string nr_mvs = mvs->text().toStdString();
    if(!validate_id(nr_mvs)){
        return;
    }
    int nr_mvs_int = stoi(nr_mvs);
    this->service->fill_the_bag(nr_mvs_int);
    list_mv_show->clear();
    vector<Film> filtered_mvs = this->service->get_bag_service();
    for(const auto & filtered_mv : filtered_mvs){
        auto for_show = filtered_mv.get_title();
        auto for_show2 = QString::fromStdString(for_show);
        auto list_item = new QListWidgetItem();
        list_item->setText("ID: " + QString::number(filtered_mv.get_id()) + " TITLE: " + for_show2);
        list_mv_show->addItem(list_item);
    }
}

void gui::create_new_window(const vector<Film> &filtered_mvs){
    auto newWidget = new QWidget();
    newWidget->setBaseSize(600, 300);
    auto hlay = new QHBoxLayout();
    auto vlay = new QVBoxLayout();
    auto list_mv_show = new QListWidget();
    for(const auto & filtered_mv : filtered_mvs){
        auto for_show = filtered_mv.get_title();
        auto for_show2 = QString::fromStdString(for_show);
        auto list_item = new QListWidgetItem();
        list_item->setText("ID: " + QString::number(filtered_mv.get_id()) + " TITLE: " + for_show2);
        list_mv_show->addItem(list_item);
    }
    newWidget->setLayout(hlay);
    newWidget->show();

    hlay->addWidget(list_mv_show);

    auto add_widget = new QWidget();
    auto fl = new QFormLayout();
    add_widget->setLayout(fl);
    auto *lbl = new QLabel("ID:");
    auto *id = new QLineEdit();
    fl->addRow(lbl, id);
    lbl = new QLabel("Title:");
    auto *title_2 = new QLineEdit();
    fl->addRow(lbl, title_2);
    lbl = new QLabel("Type:");
    auto *type = new QLineEdit();
    fl->addRow(lbl, type);
    lbl = new QLabel("Year:");
    auto *year = new QLineEdit();
    fl->addRow(lbl, year);
    lbl = new QLabel("Actor:");
    auto *actor = new QLineEdit();
    fl->addRow(lbl, actor);
    hlay->addWidget(add_widget);
    connect(list_mv_show, &QListWidget::itemClicked, newWidget, [list_mv_show, id, title_2, type, year, actor, this]{show_item(list_mv_show, id, title_2, type, year, actor);});
    hlay->addLayout(vlay);
}

void gui::filter_movies_by_title(QLineEdit *title){
    QString title_text = title->text();
    vector<Film> filtered_mvs = this->service->filter_movies_by_title_service(title_text.toStdString());
    this->create_new_window(filtered_mvs);
}

void gui::filter_movies_by_year(QLineEdit *year){
    QString year_text = year->text();
    vector<Film> filtered_mvs = this->service->filter_movies_by_year_service(year_text.toStdString());
    this->create_new_window(filtered_mvs);
}

void gui::sort_movies_by_title_asc(){
    vector<Film> sorted_mvs = this->service->sort_movies_by_title("asc");
    this->create_new_window(sorted_mvs);
}

void gui::sort_movies_by_title_desc(){
    vector<Film> sorted_mvs = this->service->sort_movies_by_title("desc");
    this->create_new_window(sorted_mvs);
}

void gui::sort_movies_by_type_asc(){
    vector<Film> sorted_mvs = this->service->sort_movies_by_type("asc");
    this->create_new_window(sorted_mvs);
}

void gui::sort_movies_by_type_desc(){
    vector<Film> sorted_mvs = this->service->sort_movies_by_type("desc");
    this->create_new_window(sorted_mvs);
}

void gui::sort_movies_by_year_asc(){
    vector<Film> sorted_mvs = this->service->sort_movies_by_year("asc");
    this->create_new_window(sorted_mvs);
}

void gui::sort_movies_by_year_desc(){
    vector<Film> sorted_mvs = this->service->sort_movies_by_year("desc");
    this->create_new_window(sorted_mvs);
}

void gui::sort_movies_by_actor_asc(){
    vector<Film> sorted_mvs = this->service->sort_movies_by_actor("asc");
    this->create_new_window(sorted_mvs);
}

void gui::sort_movies_by_actor_desc(){
    vector<Film> sorted_mvs = this->service->sort_movies_by_actor("desc");
    this->create_new_window(sorted_mvs);
}

void gui::generate_movies(QListWidget *list_mv_show){
    this->service->generate_movies_service();
    for(int i = 0; i < this->service->get_length(); ++i){
        auto for_show = this->service->get_movie_by_pos(i).get_title();
        auto for_show2 = QString::fromStdString(for_show);
        auto list_item = new QListWidgetItem();
        list_item->setText("ID: " + QString::number(this->service->get_movie_by_pos(i).get_id()) + " TITLE: " + for_show2);
        list_mv_show->addItem(list_item);
    }
}

void gui::generate_bag_window(){
    vector<Film> bag = this->service->get_bag_service();
    this->create_new_window_bag(bag);
}

void gui::show_item(QListWidget* lst_mv, QLineEdit* id, QLineEdit* title, QLineEdit* type, QLineEdit* year, QLineEdit* actor){
    QString selectedvalue= lst_mv->currentItem()->text();
    QStringList txt_list = selectedvalue.split(" ");
    QString id_txt = txt_list[1];
    std::string id_str = id_txt.toStdString();

    int id_int = stoi(id_str);
    Film mv = this->service->get_movie_by_id(id_int);
    id->setText(QString::number(mv.get_id()));
    title->setText(QString::fromStdString(mv.get_title()));
    type->setText(QString::fromStdString(mv.get_type()));
    year->setText(QString::fromStdString(mv.get_year()));
    actor->setText(QString::fromStdString(mv.get_actor()));
}
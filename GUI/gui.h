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
    void add_movie(QLineEdit *id, QLineEdit *title, QLineEdit *type, QLineEdit *year, QLineEdit *actor);

    ~gui() override = default;
};


#endif //LAB6_7_GUI_H

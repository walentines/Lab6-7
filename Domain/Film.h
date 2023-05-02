//
// Created by Valentin Serban on 29.03.2023.
//

#ifndef LAB6_7_FILM_H
#define LAB6_7_FILM_H

#include <string>
#include <utility>

class Film{
private:
    std::string title;
    std::string type;
    std::string year;
    std::string actor;
    int id{};
public:
      Film() = default;

      explicit Film(int id, std::string title, std::string type, std::string year, std::string actor){
          this->title = std::move(title);
          this->type = std::move(type);
          this->year = std::move(year);
          this->actor = std::move(actor);
          this->id = id;
      }

    [[nodiscard]] std::string get_title() const;

    [[nodiscard]] std::string get_type() const;

    [[nodiscard]] std::string get_year() const;

    [[nodiscard]] std::string get_actor() const;

    void set_title(std::string new_title);

    void set_type(std::string new_type);

    void set_actor(std::string new_actor);

    void set_year(std::string year);

    [[nodiscard]] int get_id() const;

    void set_id(int new_id);

    void show_movie() const;

    // deallocate memory here
    ~Film() = default;

    bool operator == (const Film &f1) const;
};

#endif //LAB6_7_FILM_H

//
// Created by Valentin Serban on 19.04.2023.
//

#ifndef LAB6_7_EXCEPTIONCLASS_H
#define LAB6_7_EXCEPTIONCLASS_H
#include <exception>
#include <string>

class InvalidID : public std::exception {
public:
    std::string what(){
        return "The ID you entered is invalid!";
    }
};

class InvalidTitle : public std::exception {
public:
    std::string what(){
        return "The Title you entered is invalid!";
    }
};

class InvalidType : public std::exception {
public:
    std::string what(){
        return "The Type you entered is invalid!";
    }
};

class InvalidYear : public std::exception {
public:
    std::string what(){
        return "The Year you entered is invalid!";
    }
};

class InvalidActor : public std::exception {
public:
    std::string what(){
        return "The Actor you entered is invalid!";
    }
};

class EmptyUndo: public std::exception {
public:
    std::string what(){
        return "You cannot undo anymore!";
    }
};

#endif //LAB6_7_EXCEPTIONCLASS_H

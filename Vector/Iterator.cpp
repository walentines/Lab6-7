//
// Created by Valentin Serban on 29.03.2023.
//

#include "Iterator.h"

template <typename Vector>
Iterator<Vector>::Iterator(const Vector&){
    this->curent = 0;
}

template <typename Vector>
int Iterator<Vector>::begin(){
    this->curent = 0;
    return this->curent;
}

template <typename Vector>
bool Iterator<Vector>::valid() const{
    return curent < v.size();
}

template <typename Vector>
Vector Iterator<Vector>::element() const{
    return v.get_element(this->curent);
}

template <typename Vector>
void Iterator<Vector>::next(){
    this->curent++;
}

template <typename Vector>
int Iterator<Vector>::end(){
    this->curent = v.get_length();
    return this->curent;
}
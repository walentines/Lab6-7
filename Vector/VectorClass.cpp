//
// Created by Valentin Serban on 29.03.2023.
//

#include "VectorClass.h"
#include <stdexcept>
#include <iostream>

template <class T>
int Vector<T>::size() const{
    return this->length;
}

template <class T>
Vector<T>::Vector(int len){
    try{
        if(len <= 0){
            throw std::invalid_argument("The length of the vector should be > 0");
        }
    }
    catch(std::invalid_argument& e){
        std::cerr << e.what() << std::endl;
        return;
    }
    this->max_length = len;
    this->length = 0;
    this->vector = new T[len];
}

template <class T>
T Vector<T>::get_element(int position) const{
    return this->vector[position];
}

template <class T>
void Vector<T>::redim(){
    int new_size = 2 * this->max_length;
    T* new_vector = new T[new_size];
    for(int i = 0; i < this->length; ++i){
        new_vector[i] = this->vector[i];
    }
    delete[] this->vector;
    this->vector = new_vector;
    this->max_length = new_size;
}

template<class T>
void Vector<T>::push_back(T elem) {
    if(this->length == this->max_length){
        redim();
    }
    this->vector[this->length] = elem;
    this->length++;
}

template<class T>
int Vector<T>::remove(T elem) {
    int pos = -1;

    for(int i = 0; i < this->length; ++i){
        if(this->vector[i] == elem){
            pos = i;
        }
    }
    if(this->length == 1){
        this->length--;
        return pos;
    }
    for(int i = pos; i < this->length - 1; ++i){
        this->vector[i] = this->vector[i + 1];
    }

    this->length--;

    return pos;
}

template <class T>
Iterator<Vector<T>> Vector<T>::iterator(){
    return Iterator(*this);
}

template <class T>
T& Vector<T>::operator[](int i) const{
    try{
        if(i >= this->length){
            throw std::out_of_range("Index is out of range!");
        }
    }
    catch(std::out_of_range& e){
        std::cerr << e.what() << std::endl;
        return this->vector[0];
    }

    return this->vector[i];
}

template<class T>
Vector<T>::~Vector(){
    delete[] this->vector;
}

template<class T>
void Vector<T>::sort(int (*func)(const T&, const T&)){
    std::sort(this->vector, this->vector + this->length, func);
}
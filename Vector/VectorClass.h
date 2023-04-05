//
// Created by Valentin Serban on 29.03.2023.
//

#ifndef LAB6_7_VECTORCLASS_H
#define LAB6_7_VECTORCLASS_H

#include "Iterator.h"

template <class T>
class Iterator;

template <class T>
class Vector{
private:
    T* vector;
    int length{};
    int max_length{};

    void redim();

public:
    friend class Iterator<T>;
    explicit Vector(int len);
    [[nodiscard]] int size() const;
    [[nodiscard]] T get_element(int position) const;
    void push_back(T elem);
    int remove(T elem);
    T &operator[](int i) const;
    ~Vector();
    Iterator<Vector> iterator();
    void sort(int (*func)(const T&, const T&));
};

#endif //LAB6_7_VECTORCLASS_H

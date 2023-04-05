//
// Created by Valentin Serban on 29.03.2023.
//

#ifndef LAB6_7_ITERATOR_H
#define LAB6_7_ITERATOR_H

#include "VectorClass.h"

template <typename Vector>
class Iterator{
private:
    const Vector &v;
    int curent{};
public:
    explicit Iterator(const Vector&);
    int begin();
    [[nodiscard]] bool valid() const;
    Vector element() const;
    void next();
    int end();
};

#endif //LAB6_7_ITERATOR_H

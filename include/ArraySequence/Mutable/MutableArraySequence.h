#pragma once
#include "ArraySequence/ArraySequence.h"

template <typename T>
class MutableArraySequence final : public ArraySequence<T> {
public:
    MutableArraySequence() : ArraySequence<T>() {}
    MutableArraySequence(T* items, int count) : ArraySequence<T>(items, count) {}
    MutableArraySequence(const MutableArraySequence<T>& other) : ArraySequence<T>(other) {}

    Sequence<T>* Clone() override {
        return new MutableArraySequence<T>(*this);
    }
};

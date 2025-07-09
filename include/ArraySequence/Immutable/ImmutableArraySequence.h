#pragma once
#include "ArraySequence/ArraySequence.h"

template <typename T>
class ImmutableArraySequence final : public ArraySequence<T> {
public:
    ImmutableArraySequence() : ArraySequence<T>() {}
    ImmutableArraySequence(T* items, int count) : ArraySequence<T>(items, count) {}
    ImmutableArraySequence(const ImmutableArraySequence<T>& other) : ArraySequence<T>(other) {}

    Sequence<T>* Instance() override {
        return this->Clone();
    }

    Sequence<T>* Clone() override {
        return new ImmutableArraySequence<T>(*this);
    }
};

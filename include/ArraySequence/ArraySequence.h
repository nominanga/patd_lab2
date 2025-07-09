#pragma once
#include "DynamicArray.h"
#include "SequenceInterface/Sequence.h"

template <typename T>
class ArraySequence : Sequence<T> {

    DynamicArray<T>* data = nullptr;

public:
    ArraySequence() {
        data = new DynamicArray<T>(0);
    }

    ArraySequence(T* items, int count) {
        data = new DynamicArray<T>(items, count);
    }

    ArraySequence(const ArraySequence<T>& other) {
        int newSize = other.GetSize();
        data = new DynamicArray<T>(newSize);

        for (int i = 0; i < newSize; i++) {
            data->Set(i, other.Get(i));
        }
    }

    ~ArraySequence() override {
        delete data;
    }

    virtual Sequence<T>* Instance() = 0;

    T Get(int index) const override {
        return data->Get(index);
    }



    T GetFirst() const override {
        return data->Get(0);
    }

    T GetLast() const override {
        return data->Get(data->GetSize() - 1);
    }

    T GetLength() const override {
        return data->GetSize();
    }

    ArraySequence<T>* AppendInternal(T item) override {
        int size = data->GetSize();
        data->Resize(size + 1);
        data->Set(size, item);
        return this;
    }

    ArraySequence<T>* PrependInternal(T item) override {
        InsertAtInternal(0, item);
        return this;
    }

    ArraySequence<T>* InsertAtInternal(int index, T item) override {
        int size = data->GetSize();
        data->Resize(++size);

        for (int i = index + 1; i < size; i++) {
            data->Set(i, data->Get(i - 1));
        }

        data->Set(index, item);
        return this;
    }

    ArraySequence<T>* Append(T item) override {
        return Instance()->AppendInternal(item);
    }

    ArraySequence<T>* Prepend(T item) override {
        return Instance()->PrependInternal(item);
    }

    ArraySequence<T>* InsertAt(T index, T item) override {
        return Instance()->InsertAtInternal(index, item);
    }

    ArraySequence<T>* GetSubsequence(int startindex, int endindex) override {
    }

    ArraySequence<T>* Concat(Sequence<T>* other) override {

    }
};

#include <iostream>
#include "../include/ArraySequence/Immutable/ImmutableArraySequence.h"
#include "../include/ArraySequence/Mutable/MutableArraySequence.h"
#include "../include/ListSequence/Immutable/ImmutableListSequence.h"
#include "../include/ListSequence/Mutable/MutableListSequence.h"

template<typename T>
void printSequence(const Sequence<T>& seq) {
    for (int i = 0; i < seq.GetLength(); ++i) {
        std::cout << seq.Get(i) << " ";
    }
    std::cout << "\n";
}

int main() {
    std::cout << "Testing MutableArraySequence:\n";
    MutableArraySequence<int> mas;
    mas.Append(1);
    mas.Append(2);
    mas.Append(3);
    printSequence(mas);


    std::cout << "Testing MutableListSequence:\n";
    MutableListSequence<int> mls;
    mls.Append(10);
    mls.Append(20);
    mls.Append(30);
    printSequence(mls);

    return 0;
}

#include <iostream>
#include <string>
#include "../include/ArraySequence/Immutable/ImmutableArraySequence.h"
#include "../include/ArraySequence/Mutable/MutableArraySequence.h"
#include "../include/ListSequence/Immutable/ImmutableListSequence.h"
#include "../include/ListSequence/Mutable/MutableListSequence.h"

template<typename T>
void printSequence(const Sequence<T>* seq) {
    std::cout << "Значения Sequence" << std::endl;
    for (int i = 0; i < seq->GetLength(); ++i) {
        std::cout << seq->Get(i) << " ";
    }
    std::cout << "\n";
}

template<typename T>
void inputSequence(Sequence<T>* seq, int size) {
    std::cout << "Введите значения(через пробел)";
    for (int i = 0; i < size; ++i) {
        T item;
        std::cin >> item;
        seq->Append(item);
    }
    std::cout << "\n";
}





int main() {
    std::string command;
    while (command != "exit") {
    }

    return 0;
}

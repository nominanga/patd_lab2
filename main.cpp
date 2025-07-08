#include <iostream>
#include "include/core/LinkedList.h"

int main() {

    auto arr = new int[10];
    for (int i = 0; i < 10; i++) {
        arr[i] = i + 1;
    }
    auto list = new LinkedList<int>(arr, 10);
    delete arr;

    std::cout << list->GetFirst() <<  " " << list->Get(5) << " " << list->GetLast() << std::endl;

    LinkedList<int>* subList = list->GetSubList(3, 9);
    for (int i = 0; i < subList->GetLength(); i++) {
        std::cout << subList->Get(i) << " ";
    }
    std::cout << "\n";

    LinkedList<int>* newList = list->Concat(subList);
    for (int i = 0; i < newList->GetLength(); i++) {
        std::cout << newList->Get(i) << " ";
    }
    std::cout << "\n";

    delete list;
    delete subList;
    delete newList;

    return 0;
}
#include <iostream>
#include "BiList.h"

int main() {
    size_t n = 5;
    int* arr = nullptr;
    
    try {
        arr = new int[5]{10, 20, 30, 40, 50};
    }
    catch (const std::bad_alloc& e) {
        std::cerr << "Not enough memory";
        return 1;
    }
    
    BiList<int>* fake = nullptr;
    try {
        fake = array_to_list(arr, n);
    }
    catch (...) {
        std::cerr << "Not enough memory";
        delete[] arr;
        return 1;
    }
    
    // Вывод списка
    BiList<int>* curr = fake->next;
    while (curr != fake) {
        std::cout << curr->val << " ";
        curr = curr->next;
    }
    std::cout << std::endl;
    
    // Освобождение памяти
    clear_list(fake);
    delete fake;
    delete[] arr;
    
    return 0;
}

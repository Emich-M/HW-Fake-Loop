#ifndef BILIST_H
#define BILIST_H

#include <cstddef>
#include <iostream>

template <class T>
struct BiList {
    T val;
    BiList<T>* next;
    BiList<T>* prev;
    
    BiList() : next(nullptr), prev(nullptr) {}
    BiList(const T& value) : val(value), next(nullptr), prev(nullptr) {}
};

// Создаем новый fake-узел (пустой закольцованный список)
template <class T>
BiList<T>* create_fake() {
    BiList<T>* fake = new BiList<T>();
    fake->next = fake;
    fake->prev = fake;
    return fake;
}

// Добавляем элемент после узла h
template <class T>
BiList<T>* add_after(BiList<T>* h, const T& value) {
    BiList<T>* node = new BiList<T>(value);
    node->next = h->next;
    node->prev = h;
    h->next->prev = node;
    h->next = node;
    return node;
}

// Добавляем элемент перед узлом h
template <class T>
BiList<T>* add_before(BiList<T>* h, const T& value) {
    BiList<T>* node = new BiList<T>(value);
    node->prev = h->prev;
    node->next = h;
    h->prev->next = node;
    h->prev = node;
    return node;
}

// Удаляем узел h
template <class T>
BiList<T>* remove_node(BiList<T>* h) {
    BiList<T>* next_node = h->next;
    h->prev->next = h->next;
    h->next->prev = h->prev;
    delete h;
    return next_node;
}

// Очищаем список (удалить все элементы, кроме fake)
template <class T>
void clear_list(BiList<T>* fake) {
    BiList<T>* curr = fake->next;
    while (curr != fake) {
        BiList<T>* next = curr->next;
        delete curr;
        curr = next;
    }
    fake->next = fake;
    fake->prev = fake;
}

// Удаляем весь список (с fake)
template <class T>
void delete_list(BiList<T>* fake) {
    clear_list(fake);
    delete fake;
}

// Конвертируем массив в список
template <class T>
BiList<T>* array_to_list(const T* arr, size_t size) {
    BiList<T>* fake = create_fake<T>();
    BiList<T>* curr = fake;
    
    for (size_t i = 0; i < size; i++) {
        curr = add_after(curr, arr[i]);
    }
    
    return fake;
}

// Выводим список
template <class T>
void print_list(BiList<T>* fake) {
    BiList<T>* curr = fake->next;
    std::cout << "[";
    while (curr != fake) {
        std::cout << curr->val;
        if (curr->next != fake)
            std::cout << " <-> ";
        curr = curr->next;
    }
    std::cout << "]" << std::endl;
}

// Получаем размер списка
template <class T>
size_t list_size(BiList<T>* fake) {
    size_t count = 0;
    BiList<T>* curr = fake->next;
    while (curr != fake) {
        count++;
        curr = curr->next;
    }
    return count;
}

#endif // BILIST_H

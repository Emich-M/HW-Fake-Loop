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

template <class T>
void delete_list(BiList<T>* fake) {
    clear_list(fake);
    delete fake;
}

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

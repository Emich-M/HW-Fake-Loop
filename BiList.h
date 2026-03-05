template <class T>
BiList<T>* create_fake() {
    BiList<T>* fake = new BiList<T>();
    fake->next = fake;
    fake->prev = fake;
    return fake;
}

template <class T>
BiList<T>* add_after(BiList<T>* h, const T& value) {
    BiList<T>* node = new BiList<T>(value);
    node->next = h->next;
    node->prev = h;
    h->next->prev = node;
    h->next = node;
    return node;
}

template <class T>
BiList<T>* add_before(BiList<T>* h, const T& value) {
    BiList<T>* node = new BiList<T>(value);
    node->prev = h->prev;
    node->next = h;
    h->prev->next = node;
    h->prev = node;
    return node;
}

template <class T>
BiList<T>* remove_node(BiList<T>* h) {
    BiList<T>* next_node = h->next;
    h->prev->next = h->next;
    h->next->prev = h->prev;
    delete h;
    return next_node;
}

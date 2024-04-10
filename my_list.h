#ifndef FARMACIE_MY_LIST_H
#define FARMACIE_MY_LIST_H

#include <iostream>

template<typename type>
class My_list {
private:
    type * list;
    size_t size;
    size_t capacity;

    void resize() {
        capacity *= 2;

        type *newList = new type[capacity];

        for (size_t i = 0; i < size; ++i) {
            newList[i] = list[i];
        }

        delete[] list;

        list = newList;
    }
public:
    My_list(){
        size = 0;
        capacity = 1;
        list = new type[capacity];
    }
    My_list(std::initializer_list<type> initList) : My_list() {
        for (const auto& item : initList) {
            if (size >= capacity) {
                resize(); // Resize if needed
            }
            list[size++] = item;
        }
    }

    ~My_list() {
        delete[] list;
    }

    type& operator[](size_t index) {
        if (index >= size) {
            throw std::out_of_range("Index out of range");
        }
        return list[index];
    }
    bool operator==(const My_list<type>& other)const {
        if (size != other.size) {
            return false;
        }
        for (size_t i = 0; i < size; ++i) {
            if (list[i] != other.list[i]) {
                return false;
            }
        }
        return true;
    }

    My_list(const My_list& other) : size(other.size), capacity(other.capacity) {
        list = new type[other.capacity];
        for (size_t i = 0; i < size; ++i) {
            list[i] = other.list[i];
        }
    }

    My_list& operator=(const My_list& other) {
        if (this != &other) {
            size = other.size;
            capacity = other.capacity;
            delete[] list;
            list = new type[other.capacity];
            for (size_t i = 0; i < size; ++i) {
                list[i] = other.list[i];
            }
        }
        return *this;
    }

    size_t getSize() {
        return size;
    }

    void add(type element) {
        if(size == capacity)
            resize();
        list[size++] = element;
    }
    void remove(type element) {
        size_t i = 0;
        while(i < size and list[i] != element) {
            ++i;
        }

        if(i == size)
            return;

        for(;i < size - 1; ++i) {
            list[i] = list[i+1];
        }
        --size;
    }

    type& get(size_t index) {
        if(index >= size) {
            throw "ACCESARE POZITIE INVALIDA\n";
        }
        return list[index];
    }

    [[nodiscard]] bool empty() const {
        return size == 0;
    }
};

#endif //FARMACIE_MY_LIST_H

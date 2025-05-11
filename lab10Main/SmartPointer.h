#pragma once

template <typename T>
class SmartPointer {
private:
    T* ptr;
public:
    explicit SmartPointer(T* p = nullptr) : ptr(p) {}

    ~SmartPointer() {
        delete ptr;
    }

    // Запрет копирования
    SmartPointer(const SmartPointer&) = delete;
    SmartPointer& operator=(const SmartPointer&) = delete;

    // Перемещение
    SmartPointer(SmartPointer&& other) noexcept : ptr(other.ptr) {
        other.ptr = nullptr;
    } 

    // Проверка на самоприсваивание
    SmartPointer& operator=(SmartPointer&& other) {
        if (this != &other) {
            delete ptr;
            ptr = other.ptr;
            other.ptr = nullptr;
        }
        return *this;
    }

    // Операторы доступа
    T& operator*() const { return *ptr; }
    T* operator->() const { return ptr; }
    T* get() const { return ptr; }

    // Проверка на валидность
    explicit operator bool() const { return ptr != nullptr; }

    // Освобождение ресурса
    void reset(T* p = nullptr) {
        delete ptr;
        ptr = p;
    }
};
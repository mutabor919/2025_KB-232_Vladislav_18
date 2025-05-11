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

    
    SmartPointer(const SmartPointer&) = delete;
    SmartPointer& operator=(const SmartPointer&) = delete;

    
    SmartPointer(SmartPointer&& other) noexcept : ptr(other.ptr) {
        other.ptr = nullptr;
    } 

    
    SmartPointer& operator=(SmartPointer&& other) {
        if (this != &other) {
            delete ptr;
            ptr = other.ptr;
            other.ptr = nullptr;
        }
        return *this;
    }

    
    T& operator*() const { return *ptr; }
    T* operator->() const { return ptr; }
    T* get() const { return ptr; }

    
    explicit operator bool() const { return ptr != nullptr; }

    
    void reset(T* p = nullptr) {
        delete ptr;
        ptr = p;
    }
};

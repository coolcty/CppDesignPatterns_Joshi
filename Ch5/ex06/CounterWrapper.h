#pragma once

class Counter {
public:
    Counter() :m_counter(0) {}

    Counter(const Counter&) = delete;

    Counter& operator=(const Counter&) = delete;

    unsigned int get()
    {
        return m_counter;
    }

    ~Counter() {}

    void operator++() {
        m_counter++;
    }

    void operator--() {
        m_coutner--;
    }
private:
    unsigned int m_counter;
};

template<class T>
class CounterWrapper {
public:
    Wrapper() { innerPtr = 0;m_counterPtr = 0; }

    CounterWrapper(const T& inner) {
        m_counterPtr = new Counter();
        innerPtr = new T(inner);
        (*m_counter)++;
    }



    ~CounterWrapper() {
        if (innerPtr) {
            (*m_counterPtr)--;
        }
        if (m_counterPtr->get() == 0) {
            delete innerPtr;
            delete m_counterPtr;
        }
    }
    CounterWrapper(const CounterWrapper<T>& original) {
        if (original.innerPtr != 0) {
            innerPtr = original.innerPtr;
            (*m_counterPtr)++;
        }
        else
            innerPtr = 0;

    }

    CounterWrapper& operator=(const CounterWrapper<T>& original) {
        if (this != &original) {

            if (innerPtr != 0) {
                ~CounterWrapper();
            }
            innerPtr = original.innerPtr;
            m_counterPtr = original.m_counterPtr;
            if (m_counterPtr)(*m_counterPtr)++;
        }
        return *this;
    }

    T& operator*() {
        return *innerPtr;
    }

    const T& operator*()const {
        return *innerPtr;
    }

    T* operator->() {
        return innerPtr;
    }

    const T* const operator->()const {
        return innerPtr;
    }

private:
    T* innerPtr;
    Counter* m_counterPtr;

};
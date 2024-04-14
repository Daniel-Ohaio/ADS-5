// Copyright 2021 NNTU-CS
#ifndef INCLUDE_TSTACK_H_
#define INCLUDE_TSTACK_H_

template<typename T, int size>
class TStack {
private:
    T* StArr;
    int StTop;

public:
    TStack() : StArr(new T[size]), StTop(-1) {}

    void Push(T dvalue) {
        if (StTop != size - 1) {
            StArr[++StTop] = dvalue;
        }
    }

    T pop() {
        if (StTop != -1) {
            return StArr[StTop--];
        } else {
            return T();
        }
    }

    T get() {
        return (StTop == -1) ? T() : StArr[StTop];
    }

    bool IsEmptyy() {
        return StTop == -1;
    }
};

#endif

//
// Created by karta on 12.02.2024.
//

#ifndef DOWNLOADS_STACKLST_H
#define DOWNLOADS_STACKLST_H

#include <cstddef>

class StackLst {
public:
    typedef int T;
private:
    struct Node{
        T v;
        Node* next = nullptr;
    };
    Node* head_ = nullptr;
public:
    StackLst() = default;
    StackLst(const StackLst&);
    ~StackLst() = default;

    StackLst& operator=(const StackLst&) = default;
    bool IsEmpty() noexcept;
    void Push(const T& c);
    void Pop();

};

inline
Stack::~StackLst(){
    while (!IsEmty()){
        Pop();
    }
}

#endif //DOWNLOADS_STACKLST_H

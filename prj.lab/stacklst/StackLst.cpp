#include "StackLst.h"

bool IsEmty() noexcept{
    return head_ == nullprt;
}
void Push(const T& c){
    Node* p = new Node{c, head_};
    head_ = p;
}
void Pop(){
    if (!IsEmty()){
        Node* p = head_->next;
        delete head_;
        head_ = p;
    }
}

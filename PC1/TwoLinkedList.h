#ifndef PC1_TWOLINKEDLIST_H
#define PC1_TWOLINKEDLIST_H

#include <string>
#include <fstream>

struct Node {
    int value;
    Node* next;
    Node(int value): value{value}, next{nullptr} {}
};

class TwoLinkedList {
    Node* head1;
    Node* head2;
    Node* tail1;
    Node* tail2;
    Node* tail;
public:
    TwoLinkedList(): head1{nullptr}, head2{nullptr}, tail1{nullptr}, tail2{nullptr}, tail{nullptr} {}
    ~TwoLinkedList();
    void push_back1(int value);
    void push_back2(int value);
    std::string merge(int value);
    bool is_merged();
    std::string getlist(int lista);
    Node* search(int valor);
    void save(std::string archivo);
    void load(std::string archivo);
};


#endif //PC1_TWOLINKEDLIST_H

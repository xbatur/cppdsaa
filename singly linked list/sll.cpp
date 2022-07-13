#include "sll.h"
#include <iostream>
INTSLList::~INTSLList(){
    for(INTSLNode *p; !isEmpty(); ){
        p = head->next;
        delete head;
        head = p;
    }
}

void INTSLList::addToHead(int data){
    head = new INTSLNode(data,head);
    if(tail == nullptr)
        tail = head;
    std::cout << "Head " << data << " added.\n";
}

void INTSLList::addToTail(int data){
    if(tail != nullptr){
        tail->next = new INTSLNode(data);
        tail = tail->next;
    }
    else head = tail = new INTSLNode(data);
    std::cout << "Tail " << data << " added.\n";
}

int INTSLList::deleteFromHead(){
    int tempData = head->data;
    INTSLNode* temp = head;
    if(head == tail){
        head = tail = nullptr;
    }
    else{
        head = head->next;
    }
    delete temp;
    std::cout << "Head removed\n";
    return tempData;
}

int INTSLList::deleteFromTail(){
    int tempData= tail->data;
    if(tail == head){
        delete head;
        tail = head = nullptr;
    }
    else{
        INTSLNode* temp;
        for(temp = head; temp->next != tail; temp = temp->next);
        delete tail;
        tail = temp;
        tail->next = nullptr;
    }
    std::cout << "Tail removed.\n";
    return tempData;
}
void INTSLList::deleteNode(int data){
    if(head != nullptr){
        if(head == tail && data == head->data){
            delete head;
            head = tail = nullptr;
        }
        else if(data = head->data){
            INTSLNode* temp = head;
            head = head->next;
            delete temp;
        }
        else{
            INTSLNode *pre, *temp;
            for(pre = head, temp = head->next; temp != nullptr && !(temp->data == data); pre = pre->next, temp = temp->next);
            if(temp != nullptr){
                pre->next; temp->next;
                if(temp == tail){
                    tail = pre;
                }
                delete temp;
            }
            else{
                std::cout << "Node delete error. There is no value like that. " << data << std::endl;
            }
        }
        std::cout << "Node deleted.\n";
    }
}
bool INTSLList::isInList(int data) const{
    INTSLNode* temp;
    for(temp = head; temp != nullptr && temp->data != data; temp = temp->next);
    return temp != nullptr;
}
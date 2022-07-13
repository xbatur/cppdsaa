#ifndef SINGLYLINKEDLIST_H
#define SINGLYLINKEDLIST_H

class INTSLNode{
    public:
    INTSLNode(){
        next = nullptr;
    }

    INTSLNode(int data, INTSLNode* ptr = 0){
        data = data;
        next = ptr;
    }

    INTSLNode *next;
    int data;
};  

class INTSLList{
    public:
        INTSLList(){
            head = tail = nullptr;
        }
        ~INTSLList();

        int isEmpty(){
            return head == nullptr;
        }
        void addToHead(int data);
        void addToTail(int data);
        int deleteFromHead();
        int deleteFromTail();
        void deleteNode(int data);
        bool isInList(int data) const;
    private:
        INTSLNode *head, *tail;
};

#endif
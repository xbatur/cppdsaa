#ifndef DBLL_H
#define DBLL_H
#include <iostream>
class DLLNode {
public:
	DLLNode() {
		pre = next = nullptr;
	}
	DLLNode(int data, DLLNode* pre = 0, DLLNode* next = 0) {
		this->data = data;
		this->pre = pre;
		this->next = next;
	}
protected:
	DLLNode* pre, *next;
	friend class DLList;
	int data;
};

class DLList {
public:
	DLList() {
		head = tail = nullptr;
	}
	void addToHead(int data);
	void addToTail(int data);
	int isEmpty() {
		return head == 0;
	}
	int deleteFromHead();
	int deleteFromTail();
	int deleteNode(int data);
	bool isInList(int data); 

private:
	DLLNode* head, *tail;
};

#endif
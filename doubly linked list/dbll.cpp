#include "dbll.h"

void DLList::addToHead(int data) {
	if (head != nullptr) {
		head = new DLLNode(data, nullptr, head);
		head->next->pre = head;
		std::cout << "Node added to head: " << data << " \n";
	}
	else {
		head = new DLLNode(data);
		if (tail == nullptr) {
			tail = head;
		}
		std::cout << "There was no head node. Head node " << data << " added.\n";
	}
}

void DLList::addToTail(int data) {
	if (tail != nullptr) {
		tail->next = new DLLNode(data, tail);
		tail = tail->next;
	}
	else {
		head = tail = new DLLNode(data);
	}
	std::cout << "Node added to tail: " << data << "\n";
}

int DLList::deleteFromHead() {
	if (head != nullptr && tail != head) {
		DLLNode* temp = head;
		int tempData = temp->data;
		head = head->next;
		head->pre = nullptr;
		delete temp;
		std::cout << "Node " << tempData << " removed from head.\n";
		return tempData;
	}
	else if (head != nullptr && tail == head) {
		int tempData = head->data;
		delete head;
		std::cout << "Single node " << tempData << " removed from head.\n";
		head = tail = nullptr;
		return tempData;
	}
	else {
		std::cout << "There is already no nodes in list.\n";
	}
	return 0;
}

int DLList::deleteFromTail() {
	if (!isEmpty() && tail != head) {
		DLLNode* temp = tail;
		int tempData = temp->data;
		tail = temp->pre;
		tail->next = nullptr;
		delete temp;
		std::cout << "Node " << tempData << " removed from tail.\n";
		return tempData;
	}
	else if (!isEmpty() && tail == head) {
		int tempData = head->data;
		delete head;
		std::cout << "Single node " << tempData << " removed from tail.\n";
		return tempData;
	}
	else {
		std::cout << "There is already no nodes in list.\n";
	}
	return 0;
}

int DLList::deleteNode(int data) {
	if (head != nullptr) {
		if (head->data == data && head == tail) {
			int tempData = head->data;
			delete head;
			head = tail = nullptr;
			std::cout << "Single node " << tempData << " removed.\n";
			return tempData;
		}
		else if (head->data == data) {
			DLLNode* temp = head;
			int tempData = head->data;
			head->next->pre = nullptr;
			head = temp->next;
			delete temp;
			std::cout << "Node " << tempData << " removed.\n";
			return tempData;
		}
		else {
			DLLNode* it = head;
			for (; it != nullptr && it->data != data; it = it->next);
				if (it != nullptr && it->data == data) {
					int tempData = it->data;
					if (it == tail) {
						it->pre->next = nullptr;
						tail = it->pre;
						delete it;
					}
					else {
						it->pre->next = it->next;
						it->next->pre = it->pre;
						delete it;
					}
					std::cout << "Node " << tempData << " removed.\n";
					return tempData;
				}
				else {
					std::cout << "Node " << data << " didn't exist\n";
				}
		}

	}
}
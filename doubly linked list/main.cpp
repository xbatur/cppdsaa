#include "dbll.h"
#include <iostream>

int main() {
	DLList l;
	l.addToHead(5);
	l.addToTail(6);
	l.deleteFromHead();
	l.deleteFromTail();
	l.addToHead(8);
	l.deleteNode(8);
	l.addToHead(1);
	l.addToHead(2);
	l.addToHead(3);
	l.addToTail(4);
	l.addToTail(5);
	l.addToTail(6);
	l.deleteNode(9);
}
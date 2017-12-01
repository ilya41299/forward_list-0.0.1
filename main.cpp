#include "stdafx.h"
#include <iostream>
#include <sstream>
using namespace std;

struct node {
	int val;
	node * next;
};

void add(node * & head) {
	string chislo;
	getline(cin, chislo);
	istringstream stream(chislo);
	int value;
	stream >> value;
	node * time = new node;
	time->val = value;
	time->next = nullptr;
	if (head == NULL) {
		head = time;
	}
	else {
		node * last = head;
		while (last->next) {
			last = last->next;
		}
		last->next = time;
	}
}

void sub(node * & head) {
	node * time = head;
	head = head->next;
	delete time;
}

void reverse(node * & head) {
	node * new_head = nullptr;
	for (node * node_t = head; node_t; )
	{
		node * node_next = node_t->next;
		node_t->next = new_head;
		new_head = node_t;
		node_t = node_next;
	}
	head = new_head;
}

void output(node * head) {
	node * time;
	time = head;
	while (time != NULL) {
		cout << "+---+    ";
		time = time->next;
	}
	time = head;
	cout << endl;
	while (time != NULL) {
		cout << "| " << time->val << " |";
		time = time->next;
		if (time != NULL) {
			cout << "--->";
		}
	}
	time = head;
	cout << endl;
	while (time != NULL) {
		cout << "+---+    ";
		time = time->next;
	}
	cout << endl;
}

int main() {
	char op;
	node * head = new node;
	head = nullptr;
	while (cin >> op) {
		switch (op) {
		case '+': {
			add(head);
			break;
		}
		case '-': {
			sub(head);
			break; 
		}
		case '/': {
			reverse(head);
			break;
		}
		case '=': {
			output(head);
			break;
		}
		case 'q': {
			return -1;
			}
		}
	}
	return 0;
}

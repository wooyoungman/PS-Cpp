#include <iostream>

using namespace std;

// 커서는 맨 앞에서 시작

struct Node {
	char a;
	Node* prev;
	Node* next;
};

int node_count;
Node node_pool[1000001];

Node* newNode(char a) {
	node_pool[node_count].a = a;
	node_pool[node_count].next = nullptr;
	node_pool[node_count].prev = nullptr;
	return &node_pool[node_count++];
}

class LinkedList {
	Node* head;
	Node* tail;
	Node* cur;

public:
	LinkedList() = default;

	void init() {
		node_count = 0;
		head = newNode('1');
		cur = head;
		tail = cur;
	}

	void addNode(char a) {
		Node* node = newNode(a);
		
		if (cur == tail) {
			cur->next = node;
			node->prev = cur;
			tail = node;
			cur = tail;
		}
		else {
			node->next = cur->next;
			node->prev = cur;
			cur->next->prev = node;
			cur->next = node;
			cur = node;
		}
	}

	void moveLeft() {
		if (cur != head)cur = cur->prev;
	}

	void moveRight() {
		if (cur != tail)cur = cur->next;
	}

	void deleteNode() {
		if (cur == head)return;

		if (cur == tail) {
			tail = cur->prev;
			tail->next = nullptr;
			cur = tail;
		}
		else {
			cur->prev->next = cur->next;
			cur->next->prev = cur->prev;
			cur = cur->prev;
		}
	}

	void print() {
		Node* temp = head;
		while (temp->next != nullptr) {
			temp = temp->next;
			cout << temp->a;
		}
	}

};

int main() {
	
	int t;
	cin >> t;
	for (int i = 0; i < t; i++) {
		string s;
		cin >> s;
		LinkedList llist;
		llist.init();
		for (int j = 0; j < s.length(); j++) {
			switch (s[j]) {
			case '<':
				llist.moveLeft();
				break;
			case'>':
				llist.moveRight();
				break;
			case'-':
				llist.deleteNode();
				break;
			default:
				llist.addNode(s[j]);
				break;
			}
		}
		llist.print();
		cout << "\n";
	}
	
	return 0;
}
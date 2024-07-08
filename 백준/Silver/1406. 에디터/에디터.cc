#include<iostream>

using namespace std;

struct Node {
	char a;
	Node* prev;
	Node* next;
};

int node_count = 0;
Node node_pool[600001];

Node* new_node(char a) {
	node_pool[node_count].a = a;
	node_pool[node_count].next = nullptr;
	node_pool[node_count].prev = nullptr;
	return &node_pool[node_count++];
}


class LinkedList {


	// 현재 커서, 헤드, 테일 위치
	Node* cur;
	Node* head;
	Node* tail;
public:

	LinkedList() = default;
	
	// 입력 문자열 링크드리스트 연결
	void init(string s) {
		head = new_node('1');
		cur = head;
		for (int i = 0; i < s.length(); i++) {
			Node* node = new_node(s[i]);
			cur->next = node;
			node->prev = cur;
			cur = node;
		}
		tail = cur;
	}

	// L : 커서 왼쪽 이동
	void moveLeft() {
		if (cur != head)cur = cur->prev;
	}
	

	// D : 커서 오른쪽 이동
	void moveRight() {
		if (cur != tail)cur = cur->next;
	}


	// B : 커서 왼쪽의 문자를 삭제 (맨 앞인 경우 무시)
	void deleteChar() {
		// 커서가 헤드인경우
		if (cur == head)return;
		
		// 커서가 테일인경우
		if (cur == tail) {
			tail = cur->prev;
			tail->next = nullptr;
			cur = tail;
		}
		// 그 외 사이인 경우
		else {
			cur->prev->next = cur->next;
			cur->next->prev = cur->prev;
			cur = cur->prev;
		}
	}


	// P $ : $라는 문자를 커서 왼쪽에 추가
	void addChar(char a) {
		Node* node = new_node(a);
		
		if (cur == tail) {
			cur->next = node;
			node->prev = cur;
			tail = node;
			cur = tail;
		}
		// 
		else {
			node->next = cur->next;
			node->prev = cur;
			cur->next->prev = node;
			cur->next = node;
			cur = node;
		}
	}

	void print() {
		Node* cur = head;
		while (cur->next != nullptr) {
			cur = cur->next;
			cout << cur->a;
		}
	}

};

int main() {

	string s;
	cin >> s;
	int n;
	cin >> n;
	LinkedList llist;
	llist.init(s);
	for (int i = 0; i < n; i++) {
		char a, b;
		cin >> a;
		switch (a) {
		case 'L':
			llist.moveLeft();
			break;
		case 'D':
			llist.moveRight();
			break;
		case 'B':
			llist.deleteChar();
			break;
		case 'P':
			cin >> b;
			llist.addChar(b);
			break;
		default:break;
		}
	}
	llist.print();
	return 0;
}

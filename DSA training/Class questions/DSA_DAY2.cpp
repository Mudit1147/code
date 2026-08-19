#include <iostream>
#include <string>
#include <algorithm>    
#include <sstream>
using namespace std;

struct Node {
	int digit;
	Node* next;
	Node(int d): digit(d), next(nullptr) {}
};

// Create a linked list from a numeric string. The list stores digits
// in least-significant-digit-first order (head = units digit).
Node* createListFromString(const string &s) {
	Node* head = nullptr;
	Node* tail = nullptr;
	for (int i = (int)s.size() - 1; i >= 0; --i) {
		if (!isdigit((unsigned char)s[i])) continue;
		int d = s[i] - '0';
		Node* node = new Node(d);
		if (!head) head = tail = node;
		else { tail->next = node; tail = node; }
	}
	if (!head) return new Node(0);
	return head;
}

// Add two numbers represented by linked lists (LSD-first) and
// return a new list (also LSD-first).
Node* addLists(Node* a, Node* b) {
	Node* head = nullptr;
	Node* tail = nullptr;
	int carry = 0;
	while (a || b || carry) {
		int sum = carry;
		if (a) { sum += a->digit; a = a->next; }
		if (b) { sum += b->digit; b = b->next; }
		int d = sum % 10;
		carry = sum / 10;
		Node* node = new Node(d);
		if (!head) head = tail = node; else { tail->next = node; tail = node; }
	}
	return head;
}

// Convert list (LSD-first) to string in normal most-significant-first order.
string listToString(Node* head) {
	if (!head) return "0";
	string out;
	for (Node* cur = head; cur; cur = cur->next) out.push_back(char('0' + cur->digit));
	reverse(out.begin(), out.end());
	// strip leading zeros (but leave a single '0')
	size_t pos = out.find_first_not_of('0');
	if (pos == string::npos) return "0";
	return out.substr(pos);
}

// Free list memory
void freeList(Node* head) {
	while (head) {
		Node* t = head->next;
		delete head;
		head = t;
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	string A, B;
	// Read two numbers (allow spaces/newlines). Prefer full-line input.
	if (!getline(cin, A)) return 0;
	if (!getline(cin, B)) {
		// maybe input was given as two tokens on one line
		stringstream ss(A);
		if (!(ss >> A >> B)) {
			// nothing more to do
			return 0;
		}
	}

	Node* listA = createListFromString(A);
	Node* listB = createListFromString(B);

	Node* sum = addLists(listA, listB);
	cout << listToString(sum) << '\n';

	freeList(listA);
	freeList(listB);
	freeList(sum);
	return 0;
}
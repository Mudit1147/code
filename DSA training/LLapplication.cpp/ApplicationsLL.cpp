// Application of singly linked list to perform set operations

#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;

    Node(int value) : data(value), next(nullptr) {}
};

// Display all elements of the set
void displaySet(Node* head) {
    if (head == nullptr) {
        cout << "{}";
        return;
    }

    cout << "{";
    Node* temp = head;
    while (temp != nullptr) {
        cout << temp->data;
        if (temp->next != nullptr) {
            cout << ", ";
        }
        temp = temp->next;
    }
    cout << "}";
}

// Check whether a value already exists in the set
bool contains(Node* head, int value) {
    Node* temp = head;
    while (temp != nullptr) {
        if (temp->data == value) {
            return true;
        }
        temp = temp->next;
    }
    return false;
}

// Add a value to the set only if it is not already present
void addElement(Node*& head, int value) {
    if (contains(head, value)) {
        return; // set does not allow duplicate values
    }

    // Insert at the front for simplicity
    Node* newNode = new Node(value);
    newNode->next = head;
    head = newNode;
}

// Take input from the user and build a set
Node* createSet(int n) {
    Node* head = nullptr;

    for (int i = 0; i < n; i++) {
        int value;
        cout << "Enter value " << i + 1 << ": ";
        cin >> value;
        addElement(head, value);
    }

    return head;
}

// Union of two sets: all elements present in either set
Node* unionSets(Node* first, Node* second) {
    Node* result = nullptr;

    Node* temp = first;
    while (temp != nullptr) {
        addElement(result, temp->data);
        temp = temp->next;
    }

    temp = second;
    while (temp != nullptr) {
        addElement(result, temp->data);
        temp = temp->next;
    }

    return result;
}

// Intersection of two sets: common elements only
Node* intersectionSets(Node* first, Node* second) {
    Node* result = nullptr;

    Node* temp = first;
    while (temp != nullptr) {
        if (contains(second, temp->data)) {
            addElement(result, temp->data);
        }
        temp = temp->next;
    }

    return result;
}

// Difference of two sets: elements in first but not in second
Node* differenceSets(Node* first, Node* second) {
    Node* result = nullptr;

    Node* temp = first;
    while (temp != nullptr) {
        if (!contains(second, temp->data)) {
            addElement(result, temp->data);
        }
        temp = temp->next;
    }

    return result;
}

// Symmetric difference: elements present in one set or the other, but not both
Node* symmetricDifferenceSets(Node* first, Node* second) {
    Node* result = nullptr;

    Node* temp = first;
    while (temp != nullptr) {
        if (!contains(second, temp->data)) {
            addElement(result, temp->data);
        }
        temp = temp->next;
    }

    temp = second;
    while (temp != nullptr) {
        if (!contains(first, temp->data)) {
            addElement(result, temp->data);
        }
        temp = temp->next;
    }

    return result;
}

// Free memory used by the linked list
void freeList(Node* head) {
    while (head != nullptr) {
        Node* temp = head;
        head = head->next;
        delete temp;
    }
}

int main() {
    int sizeA, sizeB;

    cout << "Enter size of Set A: ";
    cin >> sizeA;
    Node* setA = createSet(sizeA);

    cout << "Enter size of Set B: ";
    cin >> sizeB;
    Node* setB = createSet(sizeB);

    cout << "\nSet A: ";
    displaySet(setA);
    cout << "\nSet B: ";
    displaySet(setB);

    cout << "\n\nPerforming set operations..." << endl;

    Node* resultUnion = unionSets(setA, setB);
    Node* resultIntersection = intersectionSets(setA, setB);
    Node* resultDifferenceAB = differenceSets(setA, setB);
    Node* resultDifferenceBA = differenceSets(setB, setA);
    Node* resultSymmetric = symmetricDifferenceSets(setA, setB);

    cout << "\nUnion: ";
    displaySet(resultUnion);

    cout << "\nIntersection: ";
    displaySet(resultIntersection);

    cout << "\nA - B: ";
    displaySet(resultDifferenceAB);

    cout << "\nB - A: ";
    displaySet(resultDifferenceBA);

    cout << "\nSymmetric Difference: ";
    displaySet(resultSymmetric);

    cout << "\n\nAdd one more element to Set A" << endl;
    int newValue;
    cout << "Enter value to add: ";
    cin >> newValue;
    addElement(setA, newValue);

    cout << "Updated Set A: ";
    displaySet(setA);

    // Clean up memory
    freeList(setA);
    freeList(setB);
    freeList(resultUnion);
    freeList(resultIntersection);
    freeList(resultDifferenceAB);
    freeList(resultDifferenceBA);
    freeList(resultSymmetric);

    return 0;
}


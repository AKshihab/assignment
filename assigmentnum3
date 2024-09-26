#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;
};

Node* reverseList(Node* head) {
    Node* prev = NULL;
    Node* current = head;
    Node* next = NULL;

    while (current != NULL) {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }

    return prev;
}

void printList(Node* head) {
    Node* temp = head;
    while (temp != NULL) {
        cout << temp->data << "  ";
        temp = temp->next;
    }
    cout << endl;
}

int main() {
    int n;
    cin >> n;

    Node* head = NULL;
    Node* temp = NULL;

    for (int i = 0; i < n; i++) {
        if (head == NULL) {
            head = new Node();
            cin >> head->data;
            head->next = NULL;
            temp = head;
        } else {
            Node* newItem = new Node();
            cin >> newItem->data;
            newItem->next = NULL;
            temp->next = newItem;
            temp = newItem;
        }
    }

    cout << "Original List: ";
    printList(head);

    head = reverseList(head);

    cout << "Reversed List: ";
    printList(head);

    return 0;
}

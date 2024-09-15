#include <iostream>

class Node {
public:
    Node(int curNum) { n = curNum; }

    int n;
    Node* next;
    Node* prev;
};

class SpecialList {
private:
    int sizeCurrent;
    Node* first;
    Node* last;
    Node* current;

public:
    SpecialList() {
        first = new Node(0);
        first->next = NULL;
        first->prev = NULL;
        last = first;
    }

    void add() {
        Node* node = new Node(last->n);
        last->next = node;
        node->prev = last;
        node->next = NULL;
        node->n++;
        last = node;

        sizeCurrent++;
    }

    void deleteFirst() {
        first = first->next;
        delete first->prev;
        first->prev = NULL;
        sizeCurrent--;
    }

    void deleteLast() {
        last = last->prev;
        delete last->next;
        last->next = NULL;
        sizeCurrent--;
    }

    void goForward() {
        current = first;
        while (current->next != NULL) {
            std::cout << "Current node: " << current->n << std::endl;
            current = current->next;
        }
    }

    void goBackwards() {
        current = last;
        while (current->prev != NULL) {
            std::cout << "Current node: " << current->n << std::endl;
            current = current->prev;
        }
    }

    Node* getFirst() { return first; }
    Node* getLast() { return last; }
    Node* getCurrent() { return current; }
};

int main() {
    SpecialList list;

    int listSize = 10;
    for (int i = 0; i < listSize - 1; i++) { // 10 элементов делаем
        list.add();
    }

    std::cout << " >_< Hello, Kotik! ^_^ " << std::endl;
    list.goForward();
    std::cout << "_^ " << std::endl;
    list.goBackwards();
    std::cout << "_^ " << std::endl;
    list.goForward();
    std::cout << "_^ " << std::endl;
    list.goBackwards();
    std::cout << "_^ " << std::endl;

}
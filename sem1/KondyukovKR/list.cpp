#include <iostream>

class ListNode {
public:
    ListNode(int curNum) { n = curNum; }

    int n;
    ListNode* next;
    ListNode* prev;
    ListNode* rand;
};

class List {
public:
    List() {
        first = new ListNode(0);
        first->next = NULL;
        first->prev = NULL;
        last = first;
    }

    ListNode* add() {
        ListNode* node = new ListNode(last->n);
        last->next = node;
        node->prev = last;
        node->next = NULL;
        node->n++;
        last = node;
        return node;
    }

    void goForward() {
        while (first != NULL){
            std::cout << "Current number: " << first->n << std::endl;
            first = first->next;
        }
    }

    void goBackwards() {
        while (last != NULL) {
            std::cout << "Current number: " << last->n << std::endl;
            last = last->prev;
        }
    }

private:
    ListNode* first;
    ListNode* last;
};

int main() {
    List list;

    int listSize = 10;
    for (int i = 0; i < listSize - 1; i++) { // 10 элементов делаем
        list.add();
    }

    list.goBackwards();
}
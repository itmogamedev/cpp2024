#include <iostream>

class StackNode {
public:
    StackNode(int curNum) { n = curNum; }

    int n;
    StackNode* next;
    StackNode* prev;
};

class Stack {
public:
    Stack(int maxSize) {
        sizeMax = maxSize;

        last = new StackNode(0);
        last->next = NULL;
        last->prev = NULL;
    }

    void push() {
        if (sizeCurrent >= sizeMax) {
            std::cout << "Stack overflow!" << std::endl;
            return;
        }

        StackNode* node = new StackNode(last->n);
        last->next = node;
        node->prev = last;
        node->next = NULL;
        node->n++;
        last = node;

        sizeCurrent++;
    }

    void pop() {
        last = last->prev;
        delete last->next;
        last->next = NULL;
        sizeCurrent--;
    }

    StackNode* peek() {
        return last;
    }

private:
    int sizeMax;
    int sizeCurrent;
    StackNode* last;
};

int main() {
    Stack stack(10);

    int listSize = 10;
    for (int i = 0; i < listSize - 1; i++) { // 10 элементов делаем
        stack.push();
    }

    std::cout << "Current n: " << stack.peek()->n << std::endl;
    stack.pop();
    std::cout << "Current n: " << stack.peek()->n << std::endl;

}
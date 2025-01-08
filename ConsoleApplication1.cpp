#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <thread>
#include <chrono>
#include <list>
#include <string>
class Customer {
public:
    int id;
    int items;

    Customer(int id) : id(id) {
        items = rand() % 15 + 1; // Случайное количество товаров от 1 до 15
    }
};

class DoublyLinkedList {
public:
    struct Node {
        Customer* customer;
        Node* prev;
        Node* next;
    };

    Node* head;
    Node* tail;

    DoublyLinkedList() : head(nullptr), tail(nullptr) {}

    void addCustomer(Customer* customer) {
        Node* newNode = new Node{customer, tail, nullptr};
        if (tail) {
            tail->next = newNode;
        } else {
            head = newNode;
        }
        tail = newNode;
    }

    Customer* removeCustomer() {
        if (!head) return nullptr;

        Node* temp = head;
        Customer* customer = temp->customer;
        head = head->next;
        if (head) {
            head->prev = nullptr;
        } else {
            tail = nullptr;
        }
        delete temp;
        return customer;
    }

    bool isEmpty() const {
        return head == nullptr;
    }
};

class CashRegister {
public:
    int id;
    DoublyLinkedList queue;

    CashRegister(int id) : id(id) {}

    void processCustomers() {
        while (!queue.isEmpty()) {
            Customer* customer = queue.removeCustomer();
            std::cout << "Cassa " << id << " serves the client " << customer->id << " with " << customer->items << " product.\n";
            int delay = rand() % 3 + 1; // Случайная задержка от 1 до 3 секунд
            std::this_thread::sleep_for(std::chrono::seconds(delay));
            std::cout << "Cassa " << id << " completed customer service " << customer->id << ".\n";
            delete customer;
        }
    }
};

int main() {
    setlocale(LC_ALL, "Russian");
    srand(time(nullptr));

    int numCustomers, numCashRegisters;
    std::string input;

    std::cout << "Enter the number of customers (or 'r' for a random value from 5 to 15): ";
    std::cin >> input;
    if (input == "r") {
        numCustomers = rand() % 11 + 5;
    } else {
        numCustomers = std::stoi(input);
    }

    std::cout << "Enter the number of cash registers (or 'r' for a random value from 1 to 5): ";
    std::cin >> input;
    if (input == "r") {
        numCashRegisters = rand() % 5 + 1;
    } else {
        numCashRegisters = std::stoi(input);
    }

    std::list<CashRegister> cashRegisters;
    for (int i = 0; i < numCashRegisters; ++i) {
        cashRegisters.emplace_back(i + 1);
    }

    for (int i = 0; i < numCustomers; ++i) {
        Customer* customer = new Customer(i + 1);
        int cashRegisterIndex = rand() % numCashRegisters;
        auto it = cashRegisters.begin();
        std::advance(it, cashRegisterIndex);
        it->queue.addCustomer(customer);
        std::cout << "Client " << customer->id << " added to the checkout queue " << it->id << ".\n";
    }

    for (auto& cashRegister : cashRegisters) {
        std::thread(&CashRegister::processCustomers, &cashRegister).detach();
    }

    while (true) {
        std::cout << "Enter '+1' to add a checkout, '-1' to restart the purchase, or ' ' to continue: ";
        std::cin >> input;
        if (input == "+1") {
            cashRegisters.emplace_back(cashRegisters.size() + 1);
            std::cout << "A new sales register has been added " << cashRegisters.size() << ".\n";
        } else if (input == "-1") {
            std::cout << "Restarting a purchase.\n";
            // Здесь можно добавить логику для перезапуска покупки
        } else if (input == " ") {
            break;
        }
    }

    return 0;
}


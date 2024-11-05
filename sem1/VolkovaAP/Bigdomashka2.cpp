#include <iostream>
#include <string>
#include <ctime>
#include <windows.h>

class Client
{
public:
    std::string name;
    int items;

public:
    Client* prev, * next;

    Client (std::string name, int items) {
        this->name = name;
        this->items = items;
        this->prev = this->next = NULL;
    }
};

class Queue
{
public:
    Client* head, * tail;

    Queue()
    {
        head = tail = NULL;
    }

    ~Queue()
    {
        while (head != NULL)
            pop_front();
    }

    Client* push_back(std::string name, int items)
    {
        Client* ptr = new Client(name, items);
        ptr->prev = tail;
        if (tail != NULL)
            tail->next = ptr;
        if (head == NULL)
            head = ptr;
        tail = ptr;

        return ptr;
    }

    void pop_front()
    {
        if (head == NULL) return;

        Client* ptr = head->next;
        if (ptr != NULL)
            ptr->prev = NULL;
        else
            head = NULL;

        delete head;
        head = ptr;
    }
};

class Cash_desk
{
public:
    Queue client;

    void Queue()
    {
        std::string arr_names[]{ "Anna", "Aleksey", "Aleksandr", "Ekaterina", "Elizaveta", "Maria", "Natalia", "Stepan", "Sergey", "Anastasia", "Maksim", "Andrey", "Pavel", "Arina", "Oleg", "Artem", "Svetlana", "Yulia", "Victoria", "Ivan" };

        int client_name = rand() % 20;
        int client_items = rand() % 15 + 1;

        client.push_back(arr_names[client_name], client_items);
    }

    void Print()
    {
        for (Client* ptr = client.head; ptr != NULL; ptr = ptr->next)
            std::cout << "Клиент " << ptr->name << " добавлен(а) в очередь" << "\tКол-во предметов клиента: " << ptr->items << std::endl;
    }

    void Service()
    {
        int delay = rand() % 3;
        int arr_delay[]{ 1000, 2000, 3000 };
        Sleep(arr_delay[delay]);

        Client* ptr = client.head;
        std::cout << "Касса обслужила клиента " << ptr->name << " за " << arr_delay[delay] / 1000;
        if (arr_delay[delay] / 1000 == 1)
        {
            std::cout << " секунду" << std::endl << std::endl;
        }

        if (arr_delay[delay] / 1000 == 2 or arr_delay[delay] / 1000 == 3)
        {
            std::cout << " секунды" << std::endl << std::endl;
        }

        client.pop_front();
    }
};



int main()
{
    srand(time(0));

    setlocale(LC_ALL, "Rus");

    std::cout << "Выберите соответствующий номер способа определения кол-ва клиентов и касс:" << std::endl;
    std::cout << "1. Определить рандомно" << std::endl;
    std::cout << "2. Определить самостоятельно" << std::endl << std::endl;

    int number;
    std::cin >> number;
    std::cout << std::endl;

    Cash_desk service;

    if (number == 1)
    {
        int ran_num_of_clients = rand() % 11 + 5;
        int ran_num_of_cash_desks = rand() % 3 + 1;
        int ran_num_of_clients2 = ran_num_of_clients;

        std::cout << "Кол-во клиентов: " << ran_num_of_clients << std::endl;
        std::cout << "Кол-во касс: " << ran_num_of_cash_desks << std::endl << std::endl;

        for (ran_num_of_clients; ran_num_of_clients > 0; ran_num_of_clients--)
        {
            service.Queue();
        }

        service.Print();
        std::cout << std::endl;

        for (ran_num_of_clients2; ran_num_of_clients2 > 0; ran_num_of_clients2--)
        {
            service.Service();
        }
    }

    else if (number == 2)
    {
        int num_of_clients;
        int num_of_cash_desks;

        std::cout << "Введите кол-во клиентов (от 5 до 15): ";
        std::cin >> num_of_clients;

        std::cout << "Введите кол-во касс (от 1 до 3): ";
        std::cin >> num_of_cash_desks;
        std::cout << std::endl;

        int num_of_clients2 = num_of_clients;

        for (num_of_clients; num_of_clients > 0; num_of_clients--)
        {
            service.Queue();
        }

        service.Print();
        std::cout << std::endl;

        for (num_of_clients2; num_of_clients2 > 0; num_of_clients2--)
        {
            service.Service();
        }
    }

    else
    {
        std::cout << "Неверный выбор! Повторите попытку" << std::endl;
    }

}
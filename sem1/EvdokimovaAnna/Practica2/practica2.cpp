#include <iostream>
#include <cstdlib>
#include <ctime>
#include <thread>
#include <chrono>
#include <vector>

using std::cout;
using std::cin;
using std::vector;
using std::thread;
using std::string;
using std::endl;

class Client
{
public:
	int num;
	int items;

	Client(int num, int items) :num(num), items(items) {}
};

class Node
{
public:
	Client* client;
	Node* next;
	Node* prev;

	Node(Client* client) : client(client), next(nullptr), prev(nullptr) {}
};

class List
{
private:
	Node* head;
	Node* tail;

public:
	List() : head(nullptr), tail(nullptr) {}

	void push(Client* client)
	{
		Node* newNode = new Node(client);

		if (!head)
		{
			head = tail = newNode;
		}

		else
		{
			tail->next = newNode;
			newNode->prev = tail;
			tail = newNode;
		}
	}

	Client* pop()
	{
		if (!head) return nullptr;
		Node* temp = head;
		Client* client = head->client;
		head = head->next;
		if (head) head->prev = nullptr;
		delete temp;
		return client;
	}

	bool isEmpty()
	{
		return head == nullptr;
	}

	~List()
	{
		while (!isEmpty())
		{
			pop();
		}
	}
};

class Till
{
private:
	List list;
	int time;
	int alltill;

public:
	Till(int registers) : alltill(registers)
	{
		std::srand(std::time(0));
	};


	void servis()
	{
		while (!list.isEmpty())
		{
			for (int i = 0; i < alltill && !list.isEmpty(); i++)
			{
				Client* client = list.pop();
				processClient(client);
				delete client;
			}
		}
	}

	void addclient(Client* client)
	{
		list.push(client);
	}

	void processClient(Client* client)
	{
		time = rand() % 3 + 1;
		int itemsprocess = rand() % 15 + 1;
		cout << "Serving client " << client->num << " with " << itemsprocess << " items.\n";
		std::this_thread::sleep_for(std::chrono::seconds(time));
		cout << "Client " << client->num << " served.\n";
	}

	void restlist()
	{
		while (!list.isEmpty())
		{
			Client* client = list.pop();
			cout << "Cancelled service for client " << client->num << ".\n";
			delete client;
		}
	}

	void changetill(int newcount)
	{
		alltill = newcount;
		cout << "Number of registers changed to: " << alltill << "\n";
	}
};


int main()
{
	int clientcount, tillcount;
	cout << "Enter number of clients (5 to 15): ";
	cin >> clientcount;
	cout << "Enter number of tilles: ";
	cin >> tillcount;

	Till till(tillcount);

	vector <Client*> clients;
	for (int i = 1; i <= clientcount; i++)
	{
		int items = rand() % 15 + 1;
		Client* client = new Client(i, items);
		clients.push_back(client);
	}

	char changetill;
	cout << "Would you like to change the number of registers? (y / n) :  ";
	cin >> changetill;

	if (changetill == 'y')
	{
		cout << "Enter new number of tilles: ";
		cin >> tillcount;
		till.changetill(tillcount);
	}

	cout << " Are you sure you want to proceed ? (y / n) : ";
	char confir;
	cin >> confir;

	if (confir == 'n')
	{
		for (auto client : clients)
		{
			cout << "Cancelled purchase for client " << client->num << ".\n";
			delete client;
		}
		return 0;
	}

	for (auto client : clients)
	{
		till.addclient(client);
	}

	till.servis();

	return 0;

}
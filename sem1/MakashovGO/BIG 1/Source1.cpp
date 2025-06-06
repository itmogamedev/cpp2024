#include <iostream>
#include <string>
#include <fstream>
#include <vector> 


class Studens
{
private:
	std::string name, surname, patronymic, work, line, new_student = "";
	int id, for_del; // int потому что нужно провер€ть что это число а не строка
	float md_mark = -1.0;
	std::vector <std::string> Slist;
	std::string f = "C:/Users/Makas/OneDrive/–абочий стол/список студентов итмо.txt";
	std::fstream base;

	bool check_id(int n)
	{
		for (std::string x : get_list())
		{
			if (x.substr(0, 6) == std::to_string(n))
			{
				return true;
			}
		}
		return false;
	}

public:
	std::vector <std::string> get_list()
	{
		base.open(f, std::ios::in);
		while (std::getline(base, line))
		{
			Slist.push_back(line);
		}
		base.close();
		return Slist;
	}

	void add()
	{
		do
		{
			std::cout << "enter correct form of id: ";
			std::cin >> id;
		} while (std::to_string(id).length() != 6 or check_id(id));
		new_student += std::to_string(id) + ' ';
		std::cout << "Full name: ";
		std::cin >> name >> surname >> patronymic;
		new_student += name + ' ' + surname + ' ' + patronymic + ' ';
		do
		{
			std::cout << "enter correct form of average mark: ";
			std::cin >> md_mark;
		} while ((0 >= md_mark) or (md_mark > 5));
		new_student += std::to_string(round(md_mark * 10) / 10).substr(0, 3) + ' ';
		std::cout << "enter specialization: ";
		std::cin >> work;
		new_student += work;
		base.open(f, std::ios::app);
		base << std::endl << new_student;
		base.close();
	}

	void search(std::string look, bool not_found = false)
	{
		for (std::string z : get_list())
		{
			if (z.find(look) != std::string::npos)
			{
				not_found = true;
				std::cout << z << std::endl;
			}
		}
		if (!not_found)
		{
			std::cout << "Not found";
		}
	}

	void delite()
	{
		auto g = get_list();
		do
		{
			std::cout << "enter correct form of id: ";
			std::cin >> for_del;
		} while (std::to_string(for_del).length() != 6);
		for (int i = 0; i < g.size(); ++i)
		{
			if (g[i].substr(0, 6) == std::to_string(for_del))
			{
				g.erase(g.cbegin() + i);
			}
		}
		base.open(f, std::ios::trunc | std::ios::out);
		for (std::string s : g)
		{
			base << s << std::endl;
		}
		base.close();
	}
};


int main()
{
	Studens itmo;
	bool flag = true;
	std::string for_search;
	do
	{
		printf("funcshion:\n"
			"0. exit\n"
			"1. add\n"
			"2. view\n"
			"3. search\n"
			"4. delite\n");
		std::cout << "Enter the number of funcshion: ";
		int n, cont;
		std::cin >> n;
		switch (n)
		{
		case (0):
			flag = false;
			break;
		case (1):
			itmo.add();
			std::cout << "if you want to continue, enter 1 else whatever: ";
			std::cin >> cont;
			if (cont == 1) { break; }
			else { flag = false; break; }
		case (2):
			for (std::string x : itmo.get_list())
			{
				std::cout << x << std::endl;
			}
			std::cout << "\nif you want to continue, enter 1 else whatever: ";
			std::cin >> cont;
			if (cont == 1) { break; }
			else { flag = false; break; }
		case (3):
			std::cout << "enter what you want to find: ";
			std::cin >> for_search;
			itmo.search(for_search);
			std::cout << "\nif you want to continue, enter 1 else whatever: ";
			std::cin >> cont;
			if (cont == 1) { break; }
			else { flag = false; break; }
		case (4):
			itmo.delite();
			std::cout << "\nif you want to continue, enter 1 else whatever: ";
			std::cin >> cont;
			if (cont == 1) { break; }
			else { flag = false; break; }
		default:
			std::cout << "\nyou entered the wrong number, try again\n\n";
			break;
		}
	} while (flag);
}
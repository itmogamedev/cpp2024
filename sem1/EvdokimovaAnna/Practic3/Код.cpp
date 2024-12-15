#include <iostream>
#include <string>
#include <vector>
#include <memory>
#include <cstdlib>
#include <ctime>
#include <fstream>
#include <sstream>

using std::string;
using std::cout;
using std::cin;
using std::endl;
using std::vector;
using std::ofstream;
using std::ifstream;
using std::unique_ptr; //указатель динамического ресурса
using std::make_unique; //создание unique_ptr

class Fossil
{
public:
    string name;
    int quantity;
    int price; // Цена за единицу ископаемого

    Fossil(const string& n, int q, int p) : name(n), quantity(q), price(p)
    { // проверка диапозон цены
        if (price < 50 || price > 120) 
        {
            throw std::invalid_argument("Price must be between 50 and 120.");
        }
    }
};

class Excavation
{
protected:
    string name;
    string terrainType;
    int cost;
    vector<Fossil> fossils;

public:
    Excavation(const string& n, const string& t, int c)
        : name(n), terrainType(t), cost(c) {}

    virtual ~Excavation() {}

    virtual void excavate() = 0;
    virtual void effect() = 0;
    virtual void printText() = 0;

    string getTerrainType() const { return terrainType; }
    int getCost() const { return cost; }
    const vector<Fossil>& getFossils() const { return fossils; }

    void addFossil(const string& name, int quantity, int price)
    {
        fossils.emplace_back(name, quantity, price);
    }
};

class ArcticExcavation : public Excavation
{
public:
    ArcticExcavation() : Excavation("Arctic Excavation", "Arctic", 150)
    {
        addFossil("Mammoth Bone", rand() % 5 + 1, 80); // Фиксированная цена 80
        addFossil("Woolly Rhino Horn", rand() % 3 + 1, 120); // Фиксированная цена 120
    }

    void excavate() override
    {
        cout << "You have started excavating in the Arctic!" << endl;
    }

    void effect() override
    {
        cout << "You found fossils!" << endl;
    }

    void printText() override
    {
        cout << "While you were working, the penguins made you something to eat ;)" << endl;
    }
};

class MarianaTrenchExcavation : public Excavation
{
public:
    MarianaTrenchExcavation() : Excavation("Mariana Trench Excavation", "Mariana Trench", 300)
    {
        addFossil("Ammonite", rand() % 5 + 1, 60); 
        addFossil("Nautilus Shell", rand() % 3 + 1, 70);
    }

    void excavate() override
    {
        cout << "You have started excavating in the Mariana Trench!" << endl;
    }

    void effect() override
    {
        cout << "You found fossils!" << endl;
    }

    void printText() override
    {
        cout << "After so many underwater, you began to understand the fish language :)" << endl;
    }
};

class AfricaExcavation : public Excavation
{
public:
    AfricaExcavation() : Excavation("Africa Excavation", "Africa", 70)
    {
        addFossil("Dinosaur Bone", rand() % 5 + 1, 90);
        addFossil("Prehistoric Plant", rand() % 3 + 1, 50); 
    }

    void excavate() override
    {
        cout << "You have started excavating in Africa!" << endl;
    }

    void effect() override
    {
        cout << "You found fossils." << endl;
    }

    void printText() override
    {
        cout << "The heat has made you lose a lot of weight, but you've become very beautiful." << endl;
    }
};

class Player
{
private:
    int money;
    int food;
    vector<string> loot;
    vector<Fossil> fossils;
    int kirk;
    int shovel;
    int brush;

public:
    Player(int m, int f) : money(m), food(f), kirk(0), shovel(0), brush(0) {}

    void buyinstruments(int cost, const string& item)
    {
        if (money >= cost)
        {
            money -= cost;
            if (item == "kirk") kirk++;
            if (item == "shovel") shovel++;
            if (item == "brush") brush++;
            cout << "You bought " << item << " for " << cost << " money.\n";
            printStatus();
        }
        else
        {
            cout << "Not enough money to buy!\n";
        }
    }

    void eat()
    {
        if (food > 0)
        {
            food--;
            cout << "\nYou ate food. Remaining food: " << food << "\n";
        }
        else
        {
            cout << "You ran out of food!\n";
        }
    }

    void spendmoney(int amount)
    {
        if (money >= amount)
        {
            money -= amount;
        }
        else
        {
            cout << "Not enough money!\n";
        }
    }

    bool canafford(int amount)
    {
        return money >= amount;
    }

    void addloot(const string& item)
    {
        loot.push_back(item); // в конец векотра 
    }

    void addFossil(const string& name, int quantity, int price)
    {
        bool found = false;
        for (auto& fossil : fossils)
        {
            if (fossil.name == name)
            {
                fossil.quantity += quantity;
                found = true;
                break;
            }
        }
        if (!found)
        {
            fossils.emplace_back(name, quantity, price); // в конец контенера
        }
    }

    void sellFossil(int index, int quantity) 
    {
        if (index < 0 || index >= fossils.size())
        {
            cout << "Invalid fossil index!\n";
            return;
        }

        Fossil& fossil = fossils[index];
        if (fossil.quantity >= quantity)
        {
            fossil.quantity -= quantity;
            money += quantity * fossil.price; // цена  за 1 товра
            cout << "You sold " << quantity << " of " << fossil.name << " for " << quantity * fossil.price << " money.\n";
            if (fossil.quantity == 0)
            {
                fossils.erase(fossils.begin() + index);
            }
        }
        else
        {
            cout << "You don't have enough " << fossil.name << " to sell!\n";
        }
    }

    void showloot()
    {
        cout << "Collected fossils:" << endl;
        for (size_t i = 0; i < fossils.size(); ++i) //size_t i = 0 счетчик i
        {
            cout << i + 1 << ". " << fossils[i].name << ": " << fossils[i].quantity << " (Price: " << fossils[i].price << " each)" << endl;
        }
    }

    void printStatus()
    {
        cout << "Money: " << money << "\n" << "Food: " << food << endl;
        cout << "Kirk: " << kirk << "\nShovel: " << shovel << "\nBrush: " << brush << endl;
    }

    int getMoney() const { return money; }
    int getFood() const { return food; }
    bool outoffood() const { return food <= 0; }
    int getKirk() const { return kirk; }
    int getShovel() const { return shovel; }
    int getBrush() const { return brush; }
    const vector<Fossil>& getFossils() const { return fossils; }
};

void saveGame(const Player& player)
{
    ofstream ofs("progress.txt");
    if (ofs.is_open())
    {
        ofs << "Money:" << player.getMoney() << "\n";
        ofs << "Food:" << player.getFood() << "\n";
        for (const auto& fossil : player.getFossils())
        {
            ofs << fossil.name << ":" << fossil.quantity << ":" << fossil.price << "\n"; // Сохраняем цену
        }
        ofs.close();
    }
}

void loadGame(Player& player)
{
    ifstream ifs("progress.txt");
    if (ifs.is_open())
    {
        string line;
        while (getline(ifs, line))
        {
            std::istringstream iss(line); // считывания данных из строки
            string key; // для хранения части строки
            getline(iss, key, ':');
            if (key == "Money")
            {
                int money;
                iss >> money;
                player = Player(money, player.getFood()); // Сохраняем только деньги
            }
            else if (key == "Food")
            {
                int food;
                iss >> food;
                player = Player(player.getMoney(), food); // Сохраняем только еду
            }
            else
            {
                string fossilName = key;
                int quantity, price;
                iss >> quantity;
                iss.ignore(); // Игнорируем двоеточие
                iss >> price;
                player.addFossil(fossilName, quantity, price); // Сохраняем количество и цену
            }
        }
        ifs.close();
        cout << "-------BASA-------\n";
    }
}

class Game
{
private:
    Player player;

public:
    Game() : player(500, 6)
    {
        loadGame(player); // Загружаем игру при старте
    }

    void startExcavation(unique_ptr<Excavation> excavation, int attempts, bool useKirk, bool useShovel)
    {
        player.spendmoney(excavation->getCost());
        cout << "You have set off for the " << excavation->getTerrainType() << endl;

        excavation->excavate();
        excavation->printText();

        int totalFossilsFound = 0;

        for (int i = 0; i < attempts && player.getFood() > 0; ++i)
        {
            cout << "\nAttempt " << (i + 1) << ":" << endl;
            player.eat();
            excavation->effect();

            int foundFossils = 1; // Минимум 1 ископаемое
            if (useKirk) foundFossils += 1; // +1 при использовании кирки
            if (useShovel) foundFossils += 1; // +1 при использовании лопаты

            // Добываем ископаемые
            for (int j = 0; j < foundFossils; ++j)
            {
                int fossilIndex = rand() % excavation->getFossils().size();
                const Fossil& fossil = excavation->getFossils()[fossilIndex];
                player.addFossil(fossil.name, 1, fossil.price); // Добавляем цену
                totalFossilsFound++;
            }

            player.printStatus();
        }

        cout << "You found a total of " << totalFossilsFound << " fossils during this expedition." << endl;

        if (player.outoffood())
        {
            cout << "You ran out of food! The expedition is over." << endl;
        }
        else
        {
            cout << "You finished all attempts! The expedition is over." << endl;
        }

        saveGame(player);
    }

    void visitShop()
    {
        cout << "\n-------SHOP-------" << endl;
        cout << "\nYou have " << player.getMoney() << " money and " << player.getFood() << " food.\n";
        cout << "1. Buy Food (10 money each)" << endl;
        cout << "2. Buy Kirk (60 money)" << endl;
        cout << "3. Buy Shovel (50 money)" << endl;
        cout << "4. Buy Brush (20 money)" << endl;
        cout << "5. Sell Fossils" << endl; 
        cout << "6. Exit Shop" << endl;

        int choice;
        cin >> choice;
        switch (choice)
        {
        case 1:
            if (player.canafford(10))
            {
                player.spendmoney(10);
                cout << "You bought food!" << endl;
            }
            else
            {
                cout << "Not enough money!" << endl;
            }
            break;

        case 2:
            player.buyinstruments(60, "kirk");
            break;

        case 3:
            player.buyinstruments(50, "shovel");
            break;

        case 4:
            player.buyinstruments(20, "brush");
            break;

        case 5: // Продажа ископаемых
        {
            cout << "Which fossil would you like to sell?\n";
            player.showloot();
            int fossilIndex, quantity;
            cout << "Enter fossil number: ";
            cin >> fossilIndex;
            cout << "Enter quantity to sell: ";
            cin >> quantity;
            player.sellFossil(fossilIndex - 1, quantity); // Уменьшаем на 1 для индексации
            break;
        }

        case 6:
            cout << "Exiting shop." << endl;
            break;

        default:
            cout << "Invalid choice!" << endl;
        }
    }

    void visitMuseum()
    {
        player.showloot();
    }

    void displayResources()
    {
        cout << "Current Resources:\n";
        cout << "Money: " << player.getMoney() << endl;
        cout << "Food: " << player.getFood() << endl;
        cout << "Kirk: " << player.getKirk() << endl;
        cout << "Shovel: " << player.getShovel() << endl;
        cout << "Brush: " << player.getBrush() << endl;
    }

    void menu()
    {
        int choice;
        do
        {
            displayResources(); // Отображаем ресурсы перед выбором
            cout << "\n1. Start Expedition" << endl;
            cout << "2. Visit Shop" << endl;
            cout << "3. Visit Museum" << endl;
            cout << "4. Exit Game" << endl;
            cout << "Choose an option: ";
            cin >> choice;

            switch (choice)
            {
            case 1:
            {
                cout << "\n-------Excavation-------\n1. Arctic - 150\n2. Mariana Trench - 300\n3. Africa - 70\n";
                int type;
                cin >> type;

                unique_ptr<Excavation> excavation; //unique_ptr - умный указатель, который управляет динамически выделенной памятью и автоматически освобождает память, когда указатель выходит из области видимости.
                if (type == 1) {
                    excavation = make_unique<ArcticExcavation>(); //make_unique<ArcticExcavation>() — функция, которая выделяет память для нового объекта ArcticExcavation и возвращает unique_ptr на этот объект.
                }
                else if (type == 2) {
                    excavation = make_unique<MarianaTrenchExcavation>();
                }
                else if (type == 3) {
                    excavation = make_unique<AfricaExcavation>();
                }
                else {
                    cout << "Invalid choice!" << endl;
                    continue;
                }

                cout << "How many attempts would you like to make? ";
                int attempts;
                cin >> attempts;

                // Выбор оборудования
                bool useKirk = player.getKirk() > 0;
                bool useShovel = player.getShovel() > 0;

                cout << "You have the following equipment:\n";
                if (useKirk) cout << "1. Kirk\n";
                if (useShovel) cout << "2. Shovel\n";
                cout << "Would you like to use:\n";
                cout << "1. Kirk\n2. Shovel\n3. Both\n4. None\n";
                int equipmentChoice;
                cin >> equipmentChoice;

                if (equipmentChoice == 1) {
                    useKirk = true;
                    useShovel = false;
                }
                else if (equipmentChoice == 2) {
                    useKirk = false;
                    useShovel = true;
                }
                else if (equipmentChoice == 3) {
                    useKirk = true;
                    useShovel = true;
                }
                else {
                    useKirk = false;
                    useShovel = false;
                }

                startExcavation(std::move(excavation), attempts, useKirk, useShovel); 
                break;
            }

            case 2:
                visitShop();
                break;

            case 3:
                visitMuseum();
                break;

            case 4:
                cout << "Exiting game." << endl;
                break;

            default:
                cout << "Invalid choice!" << endl;
                break;
            }

        } while (choice != 4);
    }
};

int main()
{
    srand(static_cast<unsigned int>(time(0))); //srand - генератор случайных; чисел time(0) - текущее время

    Game game;
    game.menu();

    return 0;
}

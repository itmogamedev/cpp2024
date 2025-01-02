#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <cstdlib>
#include <ctime>
#include <fstream>
// Класс для предметов
class Item {
public:
    std::string name;
    int value;

    Item(std::string n, int v) : name(n), value(v) {}
};

// Класс для игрока
class Player {
public:
    int money;
    std::vector<Item> equipment;
    std::vector<Item> loot;
    int food;

    Player(int m, int f) : money(m), food(f) {}

    void addEquipment(Item item) {
        equipment.push_back(item);
    }

    void addLoot(Item item) {
        loot.push_back(item);
    }

    void useFood() {
        food--;
    }

    bool hasFood() {
        return food > 0;
    }
};

// Абстрактный класс для мест раскопок
class ExcavationSite {
public:
    virtual Item excavate(std::string tool) = 0;
    virtual ~ExcavationSite() {}
};

// Конкретные классы для мест раскопок
class DesertSite : public ExcavationSite {
public:
    Item excavate(std::string tool) override {
        if (tool == "brush") {
            return Item("sand", 0);
        } else if (tool == "shovel") {
            return Item("bone", 50);
        } else if (tool == "kirk") {
            return Item("stone", 10);
        }
        return Item("none", 0);
    }
};

class ForestSite : public ExcavationSite {
public:
    Item excavate(std::string tool) override {
        if (tool == "brush") {
            return Item("foliage", 0);
        } else if (tool == "shovel") {
            return Item("ammonite", 100);
        } else if (tool == "kirk") {
            return Item("root", 20);
        }
        return Item("none", 0);
    }
};

class MountainSite : public ExcavationSite {
public:
    Item excavate(std::string tool) override {
        if (tool == "brush") {
            return Item("dust", 0);
        } else if (tool == "shovel") {
            return Item("fossil", 150);
        } else if (tool == "kirk") {
            return Item("ore", 30);
        }
        return Item("none", 0);
    }
};

// Класс для базы
class Base {
public:
    std::map<std::string, int> shop;

    Base() {
        shop["brush"] = 10;
        shop["shovel"] = 50;
        shop["kirk"] = 100;
        shop["eat"] = 5;
    }

    void visitShop(Player& player) {
        std::cout << "Shop:\n";
        for (auto& item : shop) {
            std::cout << item.first << " - " << item.second << " coins\n";
        }
        std::string choice;
        std::cout << "What do you want to buy? (write 'exit' to exit)\n";
        while (std::cin >> choice && choice != "quit") {
            if (shop.find(choice) != shop.end()) {
                if (player.money >= shop[choice]) {
                    player.money -= shop[choice];
                    player.addEquipment(Item(choice, shop[choice]));
                    std::cout << "You bought " << choice << ".\n";
                } else {
                    std::cout << "Not enough money.\n";
                }
            } else {
                std::cout << "There is no such product.\n";
            }
        }
    }

    void visitMuseum(Player& player) {
        std::cout << "Museum:\n";
        for (auto& item : player.loot) {
            std::cout << item.name << " - " << item.value << " coins\n";
        }
    }

    void sellLoot(Player& player) {
        std::cout << "Sale of loot:\n";
        for (auto& item : player.loot) {
            player.money += item.value;
            std::cout << "You have sold " << item.name << " for " << item.value << " coins.\n";
        }
        player.loot.clear();
    }
};

// Функция для сохранения прогресса
void saveProgress(Player& player) {
    std::ofstream file("save.txt");
    file << player.money << " " << player.food << "\n";
    for (auto& item : player.equipment) {
        file << item.name << " " << item.value << "\n";
    }
    for (auto& item : player.loot) {
        file << item.name << " " << item.value << "\n";
    }
    file.close();
}

// Функция для загрузки прогресса
void loadProgress(Player& player) {
    std::ifstream file("save.txt");
    if (file.is_open()) {
        file >> player.money >> player.food;
        std::string name;
        int value;
        while (file >> name >> value) {
            player.addEquipment(Item(name, value));
        }
        file.close();
    }
}

// Основная функция игры
int main() {
    srand(time(0));
    Player player(100, 10);
    Base base;
    loadProgress(player);

    while (true) {
        std::cout << "Base. Your money: " << player.money << ", eat: " << player.food << "\n";
        std::cout << "1. Shop\n2. Museum\n3. Sell loot\n4. The expedition\n5. Exit\n";
        int choice;
        std::cin >> choice;

        if (choice == 1) {
            base.visitShop(player);
        } else if (choice == 2) {
            base.visitMuseum(player);
        } else if (choice == 3) {
            base.sellLoot(player);
        } else if (choice == 4) {
            if (player.money < 10) {
                std::cout << "Not enough money for the expedition!\n";
                continue;
            }
            player.money -= 10;
            std::cout << "You went on an expedition.\n";
            ExcavationSite* site;
            int siteChoice = rand() % 3;
            if (siteChoice == 0) {
                site = new DesertSite();
                std::cout << "You have arrived in the desert.\n";
            } else if (siteChoice == 1) {
                site = new ForestSite();
                std::cout << "You have arrived in the forest.\n";
            } else {
                site = new MountainSite();
                std::cout << "You have arrived in the mountains.\n";
            }

            while (player.hasFood()) {
                std::cout << "Choose a tool (brush, shovel, kirk):\n";
                std::string tool;
                std::cin >> tool;
                Item found = site->excavate(tool);
                if (found.name != "none") {
                    player.addLoot(found);
                    std::cout << "You have found " << found.name << "!\n";
                } else {
                    std::cout << "You haven't found anything.\n";
                }
                player.useFood();
                std::cout << "There's food left: " << player.food << "\n";
                std::cout << "1. Continue the excavation\n2. Return to base\n";
                int expeditionChoice;
                std::cin >> expeditionChoice;
                if (expeditionChoice == 2) {
                    break;
                }
            }
            delete site;
        } else if (choice == 5) {
            saveProgress(player);
            break;
        }
    }

    return 0;
}
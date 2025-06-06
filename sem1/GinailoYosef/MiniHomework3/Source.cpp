#include <iostream>
#include <fstream>
#include <vector>
#include <string>

class itemBase{
public:
    std::string name;
    int cost, weight;

    itemBase(std::string _name, int _cost, int _weight){
        this->name = _name;
        this->cost = _cost;
        this->weight = _weight;
    };
};

class item : public itemBase{
public:
    std::string type;

    std::string fps;
    int amount;
    bool looksCool;

    item(std::string _name, int _cost, int _weight, int _amount) : itemBase(_name, _cost, _weight) { this->amount = _amount; this->type = "atableProduct"; };
    item(std::string _name, int _cost, int _weight, std::string _fps) : itemBase(_name, _cost, _weight) { this->fps = _fps; this->type = "pcPart"; };
    item(std::string _name, int _cost, int _weight, bool _looksCool) : itemBase(_name, _cost, _weight) { this->looksCool = _looksCool; this->type = "pieceOfClothing"; };

    void printContent(){
        std::cout << "NAME: " << name << "\n";
        std::cout << "COST: " << cost << "\n";
        std::cout << "WEIGHT: " << weight << "\n";
        
        if (type == "pcPart"){std::cout << "FPS: " << fps << "\n";};
        if (type == "atableProduct"){std::cout << "AMOUNT: " << amount << "\n";};
        if (type == "pieceOfClothing"){
            std::string result;
            if (looksCool){
                result = "YES";
            } else {
                result = "NO";
            };
            std::cout << "LOOKS COOL?: " << result << "\n";
        };
    };
};

class shop{
public:
    std::string name;
    std::vector<item> content;

    shop(std::string _name, std::vector<item> _content){
        this -> name = _name;
        this -> content = _content;
    };

    void printContent(){
        std::cout << "Shop with " << name << ":\n\n";
        for (int i = 0; i < content.size(); i++){
            content[i].printContent();
            std::cout << "\n";
        };
        std::cout << "\n";
    };

    float getAverageWeight(){
        int sum{0};
        for (int i = 0; i < content.size(); i++){
            sum += content[i].weight;
        };
        return (float) sum/content.size();
    };

    void printAverageWeight(){
        std::cout << "AVERAGE WEIGHT FOR A SHOP WITH " << name << " IS: " << getAverageWeight() << "\n\n";
    }

    float getAveragePrice(){
        int sum{0};
        for (int i = 0; i < content.size(); i++){
            sum += content[i].cost;
        }
        return (float) sum/content.size();
    };

    void printAveragePrice(){
        std::cout << "AVERAGE PRICE FOR A SHOP WITH " << name << " IS: " << getAveragePrice() << "\n\n";;
    }
};

class fileReader{
public:
    std::vector<shop> shops;

    void loadContent(){
        std::string line, shopName;
        std::vector<item> content;
        std::string itemData[4]{"","","",""};
        int itemsAmount;

        std::ifstream in("ShopData.txt");
        if (in.is_open()){
            while (std::getline(in, line)){
                //Название магазина
                shopName = line.substr(5); //Чтение строки с n-ного символа

                //Кол-во предметов
                std::getline(in, line);
                itemsAmount = std::stoi(line.substr(6)); //Перевод string в int
            
                for (int i=0; i < itemsAmount; i++){
                    std::getline(in,line);

                    int currentSlot{0};
                    std::string temp{""};

                    for (int i = 0; i < line.length(); i++){
                        if (currentSlot < 3){
                            if (line[i] == ' '){
                                itemData[currentSlot] = temp;
                                currentSlot += 1;
                                temp = "";
                            } else {
                                temp += line[i];
                            }
                        } else {
                            temp += line[i];
                        }
                    }

                    itemData[3] = temp;

                    if (shopName == "Products"){
                        item newItem(itemData[0], std::stoi(itemData[1]), std::stoi(itemData[2]), std::stoi(itemData[3]));
                        content.push_back(newItem);

                    } else if (shopName == "PcParts"){
                        item newItem(itemData[0], std::stoi(itemData[1]), std::stoi(itemData[2]), itemData[3]);
                        content.push_back(newItem);

                    } else if (shopName == "Clothes"){
                        bool thirdParam;

                        if (itemData[3] == "true"){
                            thirdParam = true;
                        } else {
                            thirdParam = false;
                        }

                        item newItem(itemData[0], std::stoi(itemData[1]), std::stoi(itemData[2]), thirdParam);
                        content.push_back(newItem);
                    }
                };

                shop newShop(shopName, content);
                content.clear();
                shops.push_back(newShop);
            };
        };

        in.close();
    };

    fileReader(){
        loadContent();
    }

    void printContent(){
        for (int i = 0; i < shops.size(); i++){
            shops[i].printContent();
        };
    };

    void printAveragePrices(){
        for (int i = 0; i < shops.size(); i++){
            shops[i].printAveragePrice();
        };
    };

    void printAverageWeights(){
        for (int i = 0; i < shops.size(); i++){
            shops[i].printAverageWeight();
        };
    };
};

int main(){
    fileReader reader;
    int userInput;

    std::cout << "CHOOSE AN OPTION:\n";
    std::cout << "1) PRINT AVERAGE PRICES\n";
    std::cout << "2) PRINT AVERAGE WEIGHTS\n";
    std::cout << "3) PRINT ALL THE CONTENT\n";

    while (std::cin >> userInput){
        if (userInput == 1){
            reader.printAveragePrices();
        } else if (userInput == 2){
            reader.printAverageWeights();
        } else if (userInput == 3){
            reader.printContent();
        } else {
            std::cout << "NOT AN OPTION\n";
        };
    };
}
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <sstream>

class Product {
public:
    std::string name;
    double price;
    double weight;

    Product(const std::string& name, double price, double weight)
        : name(name), price(price), weight(weight) {}

    virtual void display() const {
        std::cout << "Product: " << name << ", Price: $" << price
            << ", Weight: " << weight << " kg\n";
    }

    virtual ~Product() = default;
};

class Shop {
public:
    std::string shopName;
    std::vector<Product*> products;

    ~Shop() {
        for (Product* product : products) {
            delete product;
        }
    }

    void addProduct(Product* product) {
        products.push_back(product);
    }

    double calculateAveragePrice() const {
        if (products.empty()) return 0.0;

        double total = 0.0;
        for (const Product* product : products) {
            total += product->price;
        }
        return total / products.size();
    }

    double calculateAverageWeight() const {
        if (products.empty()) return 0.0;

        double totalWeight = 0.0;
        for (const Product* product : products) {
            totalWeight += product->weight;
        }
        return totalWeight / products.size();
    }

    void displayAll() const {
        std::cout << "Shop: " << shopName << "\n";
        for (const Product* product : products) {
            product->display();
        }
        std::cout << "Average Price: $" << calculateAveragePrice() << "\n";
        std::cout << "Average Weight: " << calculateAverageWeight() << " kg\n";
    }
};

class Fruit : public Product {
public:
    std::string origin;

    Fruit(const std::string& name, double price, double weight, const std::string& origin)
        : Product(name, price, weight), origin(origin) {}

    void display() const override {
        std::cout << "Fruit: " << name << ", Price: $" << price
            << ", Weight: " << weight << " kg, Origin: " << origin << "\n";
    }
};

void loadShopsFromFile(const std::string& filename, std::vector<Shop*>& shops) {
    std::ifstream file(filename);
    if (!file.is_open()) {
        std::cerr << "Error: Could not open file.\n";
        return;
    }

    std::string line;
    while (std::getline(file, line)) {
        std::istringstream iss(line);
        std::string shopType;
        iss >> shopType;

        Shop* shop = new Shop();
        shop->shopName = line;

        int itemCount = 0;
        if (std::getline(file, line)) {
            std::istringstream issCount(line);
            std::string itemsLabel;
            issCount >> itemsLabel >> itemCount;
        }
        else {
            std::cerr << "Error: Unable to read item count for " << shop->shopName << ".\n";
            delete shop;
            continue;
        }

        for (int i = 0; i < itemCount; ++i) {
            if (std::getline(file, line)) {
                std::istringstream issProduct(line);
                std::string name;
                double price, weight;

                if (issProduct >> name >> price >> weight) {
                    if (shopType == "ShopFruits") {
                        std::string origin;
                        issProduct >> origin;
                        shop->addProduct(new Fruit(name, price, weight, origin));
                    }
                    else {
                        shop->addProduct(new Product(name, price, weight));
                    }
                }
                else {
                    std::cerr << "Error reading product data: " << line << "\n";
                }
            }
            else {
                std::cerr << "Error: Not enough lines to read products for " << shop->shopName << ".\n";
                break;
            }
        }
        shops.push_back(shop);
    }

    file.close();
}

int main() {
    setlocale(LC_ALL, "RUS");
    std::vector<Shop*> shops;
    loadShopsFromFile("shop_data.txt", shops);
    for (const auto& shop : shops) {
        shop->displayAll();
        std::cout << "\n";
    }
    for (auto shop : shops) {
        delete shop;
    }
    return 0;
}
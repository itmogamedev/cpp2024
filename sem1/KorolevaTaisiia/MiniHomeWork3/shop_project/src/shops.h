#include <utility>
#include <vector>
#include "products.h"

static float get_middle_cost(std::vector<product *> const &products) {
    float x = 0;
    for (auto p: products) {
        x += p->get_cost();
    }
    return x / products.size();
}

static float get_middle_weight(std::vector<product *> const &products) {
    float x = 0;
    for (auto p: products) {
        x += p->get_weight();
    }
    return x / products.size();
}

template<typename T>
class shop_base {
private:
    std::string name;
protected:
    std::vector<T> products;
    std::vector<product *> pointers;
public:
    shop_base() = delete;
    explicit shop_base(std::string name) : name(std::move(name)) {}

    virtual std::string present_itself() = 0;

    std::string get_product_presentation() {
        std::string ans;
        ans = " " + name + "\nItems " + std::to_string(products.size()) + "\n";
        for (const auto &p: products) {
            ans += p.present_itself();
            ans += "\n";
        }
        return ans;
    };

    virtual void add_product(T product) = 0;

    float middle_cost() const {
        return get_middle_cost(pointers);
    }

    float middle_weight() const {
        return get_middle_weight(pointers);
    }

};

class basic_shop : public shop_base<product> {
public:
    basic_shop (std::string name): shop_base<product>(std::move(name)){};
    static std::string class_name() {
        return "basic_shop";
    }

    virtual void add_product(product pr) override {
        products.push_back(pr);
        pointers.push_back(&pr);
    }


    virtual std::string present_itself() override {
        return class_name() + get_product_presentation();

    }
};

class shop_with_sales : public shop_base<sales_product> {
public:
    shop_with_sales (std::string name): shop_base<sales_product>(std::move(name)){};
    static std::string class_name() {
        return "shop_with_sales";
    }


    std::string present_itself() override {
        return class_name() + get_product_presentation();
    }

    void add_product(sales_product product) override {
        products.push_back(product);
        pointers.push_back(&product);
    }


};

class heavy_package_shop : shop_base<heavy_package_product> {
public:
    heavy_package_shop (std::string name): shop_base<heavy_package_product>(std::move(name)){};
    static std::string class_name() {
        return "shop_with_packages";
    }

    std::string present_itself() override {
        return class_name() + get_product_presentation();
    }

    void add_product(heavy_package_product product) override {
        products.push_back(product);
        pointers.push_back(&product);
    }


};
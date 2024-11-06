#include <string>
#include <utility>

class product {
protected:
    std::string name;
    float cost;
    float weight;
public:
    product(std::string name, float cost, float weight) : name(std::move(name)), cost(cost), weight(weight) {

    }

    virtual float get_cost() const {
        return cost;
    }

    virtual float get_weight() const {
        return weight;
    }

    virtual std::string present_itself() const {
        return name + " " + std::to_string(get_cost()) + " " + std::to_string(get_weight());
    }
};

class sales_product : public product {
private:
    float sale;
public:
    sales_product(std::string name, float cost, float weight, float sale) : product(std::move(name), cost, weight),
                                                                            sale(sale) {
    }

    float get_cost() const override {
        return cost * sale;
    }

    std::string present_itself() const override {
        return name + " " + std::to_string(get_true_cost())
               + " " + std::to_string(get_weight()) + " " + std::to_string(get_sale());
    }

    float get_sale() const {
        return sale;
    }

    float get_true_cost() const {
        return cost;
    }
};

class heavy_package_product : public product {
private:
    float package_weight;
public:
    heavy_package_product(std::string &name, float cost, float weight, float package_weight) :
            product(name, cost, weight), package_weight(package_weight) {}

    float get_weight() const override {
        return weight + package_weight;
    }

    float get_package_weight() const {
        return package_weight;
    }

    std::string present_itself() const override {
        return name + " " + std::to_string(get_cost()) +
               +" " + std::to_string(get_weight() - get_package_weight())
               + " " + std::to_string(get_package_weight());
    }


};
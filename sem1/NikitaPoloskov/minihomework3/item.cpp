#include "item.h"


befry::Item::Item(std::string n, double c, double w)
{
    name = n;
    cost = c;
    weight = w;
}

std::string befry::Item::GetName() { return name; }
double befry::Item::GetCost() { return cost; }
double befry::Item::GetWeight() { return weight; }

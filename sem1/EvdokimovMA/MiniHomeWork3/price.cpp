//
// Created by Maksim Evdokimov on 01.11.2024.
//

#pragma once

#include "string"
#include "sstream"

struct Price {
    unsigned long long int rubles;
    unsigned char kopecks;

    Price() {
        rubles = 0;
        kopecks = 0;
    }
    Price(unsigned long long int rubles, unsigned char kopecks) {
        this->rubles = rubles;
        this->kopecks = kopecks;
    }

    explicit operator double() const {
        return static_cast<double>(rubles) + kopecks / 100.0;
    }

    static Price parseFromString(std::string& str) {
        std::istringstream stream(str);
        unsigned long long int rubles;
        unsigned short int kopecks;

        stream >> rubles;
        stream >> kopecks;

        return Price(rubles, kopecks);
    }

    Price operator+(Price other) {
        Price result;
        result.rubles = rubles + other.rubles;
        result.kopecks = kopecks + other.kopecks;
        if (result.kopecks >= 100) {
            result.rubles++;
            result.kopecks -= 100;
        }
        return result;
    }
    Price operator-(Price other) {
        Price result;
        result.rubles = rubles - other.rubles;
        result.kopecks = kopecks - other.kopecks;
        if (result.kopecks < 0) {
            result.rubles--;
            result.kopecks += 100;
        }
        return result;
    }
    Price operator*(unsigned long long int multiplier) {
        Price result;
        result.rubles = rubles * multiplier;
        result.kopecks = kopecks * multiplier;
        result.rubles += result.kopecks / 100;
        result.kopecks %= 100;
        return result;
    }
    Price operator/(unsigned long long int divider) {
        Price result;
        result.rubles = rubles / divider;
        result.kopecks = kopecks / divider;
        return result;
    }

    bool operator>(Price other) {
        return rubles > other.rubles || (rubles == other.rubles && kopecks > other.kopecks);
    }
    bool operator<(Price other) {
        return rubles < other.rubles || (rubles == other.rubles && kopecks < other.kopecks);
    }
    bool operator>=(Price other) {
        return rubles > other.rubles || (rubles == other.rubles && kopecks >= other.kopecks);
    }
    bool operator<=(Price other) {
        return rubles < other.rubles || (rubles == other.rubles && kopecks <= other.kopecks);
    }
    bool operator==(Price other) {
        return rubles == other.rubles && kopecks == other.kopecks;
    }
    bool operator!=(Price other) {
        return rubles != other.rubles || kopecks != other.kopecks;
    }

    std::string toString() {
        return std::to_string(rubles) + "." + (kopecks < 10 ? "0" : "") + std::to_string(kopecks);
    }
};
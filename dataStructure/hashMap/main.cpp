//
// Created by Luzh on 2019-07-16.
//
#include <string>
#include <vector>
#include "hash.h"

int main() {
    Hash hashy;
    hashy.addItem("Paul", "Locha");
    hashy.addItem("Kim", "Iced Mocha");
    hashy.addItem("Anni", "Strawberry Smoothy");
    hashy.addItem("Sara", "Passion Tea");
    hashy.addItem("Mike", "Tea");
    hashy.addItem("steve", "Apple cider");
    hashy.addItem("Sill", "Root beer");
    hashy.addItem("Bill", "Lochs");
    hashy.addItem("Susan", "Cola");
    hashy.addItem("Joe", "Green Tea");


    std::string name;
    while(name != "exit") {
        std::cout << "search for: \n";
        std::cin >> name;
        if(name != "exit") {
            hashy.findDrink(name);
        }
    }

    return 0;
}

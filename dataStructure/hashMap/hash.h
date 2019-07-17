//
// Created by Luzh on 2019-07-17.
//

#ifndef HASMAP_HASH_H
#define HASMAP_HASH_H

#include <iostream>
#include <string>

struct Item {
    std::string name;
    std::string drink;
    Item* next;
};

class Hash {
public:
    Hash();

    void addItem(std::string name, std::string drink);
    int numberOfItemsInIndex(int index);
    void printTable();
    void printItemsInIndex(int index);
    void findDrink(std::string name);
    void removeItem(std::string name);

private:
    int hashFunction(std::string name);
    static const int tableSize = 10;
    Item* hashTable[tableSize];
};


#endif //HASMAP_HASH_H

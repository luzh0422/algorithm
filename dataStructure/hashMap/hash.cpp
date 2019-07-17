//
// Created by Luzh on 2019-07-17.
//

#include "hash.h"

Hash::Hash() {
    for (int i = 0; i < tableSize; i++) {
        this->hashTable[i] = new Item();
        this->hashTable[i]->name = "empty";
        this->hashTable[i]->drink = "empty";
        this->hashTable[i]->next = NULL;
    }
}

/**
 * hash函数,根据字符串计算出对应的hash值.
 */
int Hash::hashFunction(std::string name) {
    int sum = 0;
    int index = 0;
    index = name.length();
    for (int i = 0; i < index; i++) {
        sum += static_cast<int>(name[i]);
    }

    index = sum % this->tableSize;
    return index;
}

/**
 * 首先根据字符串计算hash值,然后根据数组的长度计算位置,然后添加;
 */
void Hash::addItem(std::string name, std::string drink) {
    int index = hashFunction(name);

    if (this->hashTable[index]->name == "empty") {
        this->hashTable[index]->name = name;
        this->hashTable[index]->drink = drink;
    } else {
        Item* ptr = hashTable[index];
        Item* n = new Item();
        n->name = name;
        n->drink = drink;
        n->next = NULL;

        while (ptr->next != NULL) {
            ptr = ptr->next;
        }
        ptr->next = n;
    }
}

int Hash::numberOfItemsInIndex(int index) {
    int count = 0;
    if (hashTable[index]->name == "empty") {
        return count;
    } else {
        count++;
        Item* ptr = hashTable[index];
        while (ptr->next != NULL) {
            count++;
            ptr = ptr->next;
        }
    }
}

void Hash::printTable() {
    int number;
    for (int i = 0; i < tableSize; i++) {
        std::cout << "i = " << i << ": " << std::endl;
        number = numberOfItemsInIndex(i);
        std::cout << "--------------\n";
        std::cout << "index = " << i << ": " << std::endl;
        std::cout << hashTable[i]->name << std::endl;
        std::cout << hashTable[i]->drink << std::endl;
        std::cout << "# of items = " << number << std::endl;
        std::cout << "--------------\n";
    }
}

void Hash::printItemsInIndex(int index) {
    Item* ptr = hashTable[index];
    if (ptr->name == "empty") {
        std::cout << "index = " << index << "is empty" << std::endl;
    } else {
        std::cout << "index " << index << " contains the following items: \n";
        while(ptr != nullptr) {
            std::cout << "--------------\n";
            std::cout << ptr->name << std::endl;
            std::cout << ptr->drink << std::endl;
            std::cout << "--------------\n";
            ptr = ptr->next;
        }
    }
}

/**
 * 首先根据字符串计算hash值,然后根据数组长度计算位置,最后通过链表一个个查找;
 */
void Hash::findDrink(std::string name) {
    int index = hashFunction(name);
    bool FoundName = false;

    std::string drink;
    Item* ptr = hashTable[index];
    while (ptr != nullptr) {
        if (ptr -> name == name) {
            FoundName = true;
            drink = ptr->drink;
        }
        ptr = ptr->next;
    }

    if (FoundName) {
        std::cout << "Favorite drink = " << drink << std::endl;
    } else {
        std::cout << name << "'s info was not found in the hashTable" << std::endl;
    }
}

/**
 * 根据字符串计算hash值,根据长度计算位置;
 * 然后根据链表判断字符串是否符合,最后修改链表的指向即可.
 */
void Hash::removeItem(std::string name) {
    int index = hashFunction(name);

    Item* delPtr;

    if (hashTable[index]->name == "empty" && hashTable[index]->drink == "empty") {
        std::cout << name << "'s not found in the hash table \n";
    } else if (hashTable[index]->name == name && hashTable[index]->next == NULL){
        hashTable[index]->name = "empty";
        hashTable[index]->drink = "empty";
        std::cout << name << " was removed from the hash table. \n";
    } else if (hashTable[index]->name == name) {
        delPtr = hashTable[index];
        hashTable[index] = hashTable[index]->next;
        delete delPtr;
        std::cout << name << " was removed from the hash table \n";
    } else {
        Item* p1 = hashTable[index]->next;
        Item* p2 = hashTable[index];
        while (p1 != nullptr && p1->name != name) {
            p2 = p1;
            p1 = p1->next;
        }
        if (p1 == nullptr) {
            std::cout << name << " was not found in the hash table \n";
        } else {
            p2->next = p1->next;
            delete p1;
            std::cout << name << " was removed from the hash table. \n";
        }
    }
}
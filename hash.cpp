// hash.cpp

#include <sstream>

#include "hash.hpp"

using std::stringstream;

// Initializes the Hash Table under the class requirements
HashTable::HashTable(int initialCapacity) {
    capacity = initialCapacity; //how many slots are available in the table
    size = 0; // starts it empty

    // create array of the size capacity that will serve as storage for the string values input in the HT
    storage = new string[capacity]; 
}

//this function is the hash logic of the system
int HashTable::hash(string value) {
    // start variable that will store the ASCII sum result
    int result = 0;

    // Iterates through all characters of the inserted value 
    for (char c : value) {
        result += (int)c; // adds the ASCII (int) value of all characters in the string
    }

    // take the modulus of the result with the capacity of the hash table
    result %= capacity; // this step ensures that the hash value falls within the range of the hash table's capacity.

    // returns the hash index
    return result;
}

// this function adds a value to the hash table at its correct hash index location
int HashTable::add(string value) {

    // calculate the hash index of the inserted value
    int hash_index = hash(value);

    // CHECK FOR COLLISION
    // normally I would do it here but this program is simple and if there is a collision 
    // it simply replaces the value in the collision index, which is the same operation if there is not collision
    // in other words, for now checking for collision is not necessary.

    // place in hash_index
    storage[hash_index] = value;

    return hash_index;
}

bool HashTable::search(string value) {

    // initializes the boolean
    bool result = false;

    // calculate the hash index of the inserted value
    int hash_index = hash(value);

    // check if value there is the same as our value
    if (storage[hash_index] == value) {
        result = true; // if it is equal then return true
    }

    return result; // if is not equal return false
}

// this function turns the hash table into a displayable string
string HashTable::toString() {

    // string that can be altered
    stringstream result;

    // iterates through the entire storage array printing out the value at each one of its indexes
    // and separating them with commas
    for (int i = 0; i < capacity; ++i) {
        result << storage[i] << ", ";

    }

    // stringstream can't be returned out of a function, so much turn it into a normal string before returning.
    return result.str();
}
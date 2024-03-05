// hash.hpp

#ifndef HASH_HPP
#define HASH_HPP

#include <string>

using std::string;

class HashTable {
public:
    HashTable(int initialCapacity); // creates the initial HashTable with the capacity of elements that it can take.
    int hash(string key); // this is the hash function, it will take an input string key and output the integer value of the hash index of the key
    int add(string key); // adds a new string value to the hash table
    bool search(string key); // search if a value is in the hash table, if it is then return true, if it is not then return false 
    string toString(); // turn the hash table into a string with all the values in it


private:
    int capacity = 10; // sets the capacity of the hash table to be 10 elements
    int size = 0; // initiates the hash table with 0 elements
    string *storage = nullptr; //there will be a storage array, but at this point the storage hasn't been created yet, so currently the pointer string points at nullptr but later that will be the storage of the storage
};

#endif // HASH_HPP
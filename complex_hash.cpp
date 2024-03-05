#include <sstream>
#include <functional>

#include "hash.hpp"

using std::stringstream;

// Initializes the Hash Table under the class requirements
HashTable::HashTable(int initialCapacity) {
    capacity = initialCapacity; //how many slots are available in the table
    size = 0; // starts it empty

    // create array of the size capacity that will serve as storage for the string values input in the HT
    storage = new string[capacity]; 
}

//this function is the primary hash logic of the system
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

//this function is the secondary hash logic of the system
// this function will be used once collision happens and there needs to be a change on the hex index of a certain key
int HashTable::hash2(string value) {

    // start variable that will store the ASCII sum result
    int result = 0;

    // Iterates through all characters of the inserted value 
    for (char c : value) {
        result += (int)c; // adds the ASCII (int) value of all characters in the string
    }

    // take the modulus of the result with the capacity of the hash table
    result %= (capacity); 

    // add 1 to ensure that the second hash value is never 0
    return result+1; // if the result was 0 there could be certain cases where the hashing would be stuck in an infinite loop since you can't alter the number 0
}

// this function adds a value to the hash table at its correct hash index location
int HashTable::add(string value) {

    bool collision = false;

    // calculate the hash index of the inserted value
    int hash_index = hash(value);

    // CHECK FOR COLLISION
    if (storage[hash_index] != value && storage[hash_index] != "") { // checks if the slot in the storage array is not empty or if the value that is already stored is not the same as the one we are trying to add.
        collision = true;
    }

    if (collision == true) {
        // Resolve collision using double hashing
        // In my version of double hashing both index values obtained from hash1 and hash2 are added together and the sum modules with the capacity so that it stays withing range
        hash_index = (hash_index + hash2(value)) % capacity;
    }

    // place in hash_index
    storage[hash_index] = value;

    return hash_index;
}

bool HashTable::search(string value) {

    // calculate the hash index of the inserted value
    int hash_index = hash(value);

    // check if value there is the same as our value
    while (storage[hash_index] != "") {
        if (storage[hash_index] == value) {
            return true; // if it is equal then return true
        }
        // Resolve collision using double hashing
        hash_index = (hash_index + hash2(value)) % capacity;
    }

    return false; // if value not found
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
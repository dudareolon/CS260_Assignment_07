#include <iostream>

#include "hash.hpp"
#include "hash.cpp"

using std::cout;
using std::endl;

// Added collaboration with ChatGPT for resize and collision count behavior.

int main() {

    // Create an empty Hash Table
    HashTable ht(10);
    cout << "Create an empty Hash table." << endl;
    cout << "table contents (empty table): " << ht.toString() << endl;
    cout << endl;

    // Add a string to the hash table in its correct hash index
    int result = ht.add("Duda");
    cout << "Add Duda (in the index " << result << ")." << endl;
    cout << "table contents (one entry): " << ht.toString() << endl;
    // For 'D': result += (int)'D' = 68.
    // For 'u': result += (int)'u' = 117.
    // For 'd': result += (int)'d' = 100.
    // For 'a': result += (int)'a' = 97.
    // After the loop, result is 68 + 117 + 100 + 97 = 382.
    // Take the modulus of result with the capacity of the hash table (let's assume it's 10): 382 % 10 = 2.
    cout << endl;

    // Add a second string to the hash table in its correct hash index
    result = ht.add("Friend");
    cout << "Add Friend (in the index " << result << ")." << endl;
    cout << "table contents (two entries): " << ht.toString() << endl;
    // For 'F': result += (int)'F' = 70.
    // For 'r': result += (int)'r' = 114.
    // For 'i': result += (int)'i' = 105.
    // For 'e': result += (int)'e' = 101.
    // For 'n': result += (int)'n' = 110.
    // For 'd': result += (int)'d' = 100.
    // After the loop, result is 70 + 114 + 105 + 101 + 110 + 100 = 590.
    // Take the modulus of result with the capacity of the hash table (let's assume it's 10): 590 % 10 = 0.
    cout << endl;

    // Prove case sensitivity
    result = ht.add("duda");
    cout << "Add duda (in the index " << result << ")." << endl;
    cout << "table contents (three entries): " << ht.toString() << endl;
    // For 'd': result += (int)'d' = 100.
    // For 'u': result += (int)'u' = 117.
    // For 'd': result += (int)'d' = 100.
    // For 'a': result += (int)'a' = 97.
    // After the loop, result is 100 + 117 + 100 + 97 = 414.
    // Take the modulus of result with the capacity of the hash table (let's assume it's 10): 414 % 10 = 4.
    cout << endl;

    //Search for a string that is in the hash table
    bool result_boolean = ht.search("duda");
    cout << "Is 'duda' a string in the hash table?" << endl;
    cout << "Result of the search (1=True and 0=False): " << result_boolean << endl;
    cout << endl;

    // Search for a string that is not in the hash table
    result_boolean = ht.search("dudas");
    cout << "Is 'dudas' a string in the hash table?" << endl;
    cout << "Result of the search (1=True and 0=False): " << result_boolean << endl;
    cout << endl;

    // Collision: when a string is added in an index that already has a string
    result = ht.add("dadu");
    cout << "Add dadu (in the index " << result << ")." << endl;
    cout << "table contents (three entries): " << ht.toString() << endl;
    // For 'd': result += (int)'d' = 100.
    // For 'a': result += (int)'a' = 97.    
    // For 'd': result += (int)'d' = 100.
    // For 'u': result += (int)'u' = 117.
    // After the loop, result is 100 + 117 + 100 + 97 = 414.
    // Take the modulus of result with the capacity of the hash table (let's assume it's 10): 414 % 10 = 4.
    cout << endl;

    return 0;
}
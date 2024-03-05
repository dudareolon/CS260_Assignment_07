# CS260_Assignment_07
Hashtable
Eduarda (Duda) Reolon
CS260

----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

The goal of this assignment is to create a hashtable that resolves collisions by simply overwriting the old value with the new value, including at least:

- Description of the way that you decide on hashing a value
- An insert function that places the value at the appropriate location based on its hash value
- A contains function that returns whether the value is already in the hashtable

The second goal of this assignment is to also create a smarter hashtable (double hashing or chaining) including at least the same functions as the simple hashtable.

----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

Design: 

First, what is a hashtable?

Hash is a data structure that stores data in an orderly manner. An array, for an example, has the same purpose, but a Hash was designed so that it can store data much more efficiently and retrieving that data can be much faster.  

There are three main parts of the process of hashing:

- Key: The key element can be any data structure (integer, string, etc) taht is fed as an input to the hash function

- Hash Function: The hash function determines the location in which the key will be stored, it is what determines the order of the hashmap. The function receives the input key and returns the index of an element in an array called a hash table. 

- Hash Table: Hash table is a data structure that maps keys to values. Hash stores the data in a way that each one of them has its own unique index.


  ![image](https://github.com/dudareolon/CS260_Assignment_07/assets/102680672/b2950b41-5db5-4922-bff9-4930c534be2a)

Image retrieved from: https://www.geeksforgeeks.org/what-is-hashing/


Second, what is a collision?

The hashing process goal is to generate a smaller number for the hash index compared to the big key that is inputed in the hash function. For example, all numbers that have two digits and start with them will be stored in the hash index 1. It is very possible that 2 different values might be assigned to the same hash index, and that is defines as collision. In my program, I will be dealing with collision by simply overwriting the old value with the new value.


![image](https://github.com/dudareolon/CS260_Assignment_07/assets/102680672/a77fe1d3-2fd8-4509-bec6-ef0dccf02e26)

Image retrieved from: https://www.geeksforgeeks.org/what-is-hashing/

My program was created using 4 different files: main.cpp, hash.cpp, hash.hpp, complex_hash.cpp. Here is what each one of the files do:

...........................................

Hash.hpp:

This file will define the class HashTable. The public elements of the class will be:

    - HashTable(int initialCapacity); // creates the initial HashTable with the capacity of elements that it can take.
    
    - int hash(string key); // this is the hash function, it will take an input string key and output the integer value of the hash index of the key
    
    - int add(string key); // adds a new string value to the hash table
    
    - bool search(string key); // search if a value is in the hash table, if it is then return true, if it is not then return false 
    
    - string toString(); // turn the hash table into a string with all the values in it
    
and the private elements will be:

    - int capacity = 10; // sets the capacity of the hash table to be 10 elements
    
    - int size = 0; // initiates the hash table with 0 elements
    
    - string *storage = nullptr; //there will be a storage array, but at this point the storage hasn't been created yet, so currently the pointer string points at nullptr but later that will be the storage of the storage


...........................................

Hash.cpp:

The first step is initializes the Hash Table under the class requirements.
The capacity is how many slots are available in the table and is set to whatever the user wants. This way the same code can be reused for different amounts of data. The Hash Table starts empty. Then create an array called storage of the size capacity that will serve as storage for the string values input in the HT


Next step is to define what the hash function is. It start variable that will store the ASCII sum result. Then it iterates through all characters of the inserted value, adding the ASCII (int) value of all characters in the string. Takes the modulus of the result with the capacity of the hash table, which ensures that the hash value falls within the range of the hash table's capacity. Lastly, return the hash index.


The add function will start by finding the hash index value of the string value inserted. It will check in the storage array for the slot of hash index if that spot is not empty or if that value in that spot is not the same the add function is trying to input. If both of these are true, then collision has happened. The collision is not important for the program yet, since we are simply replace the value in the collision, but it will be important later. Independently of the collision, it will store the value at the storage[hash_index] location. 


The search function also finds the has index of the value inserted. Then it goes to that index location of the array storage and compares if the string there is the same as the input string. If it is then it returns true, if it is not equal then it returns false. 


toString is a function that turns the hash table into a displayable string. It does it by using the stringstream data structure which is a string that can be altered. But a stringstream can't be returned out of a function, so much turn it into a normal string before returning. The function iterates through the entire storage array printing out the value at each one of its indexes and separating them with commas


...........................................

Main.cpp:


...........................................

Complex_hash.cpp:



----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

Complexity Analysis:

Though storing in Array takes O(1) time, searching in it takes at least O(log n) time. This time appears to be small, but for a large data set, it can cause a lot of problems and this, in turn, makes the Array data structure inefficient.

----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

Requirements:

- Hashtable that resolves collisions by simply overwriting the old value with the new value:

- Describe the way that you decide on hashing a value: The hash value is calculated by iterating through all the characters in a string and adding their ASCII integer value. Each character in the ASCII table as you can see below is equivalent to an integer number.

  ![image](https://github.com/dudareolon/CS260_Assignment_07/assets/102680672/f36c354b-1454-47a8-bde6-b3fd49df6590)

It is important to notice that lower case and upper case of the same letter have different ASCII values, so for example, imputting the string "Cats" will have a different hash value compared to inputting "cats".

After completing the sum of all characters' ASCII vlaues, the result is divided by 10 (the capacity of my hash table), and the remainder of this division is the hash value of that string input. This operation of finding the remainder after dividing by 10 can be done very easily by using the modules operation, which is "ASCII sum % 10"

Here is a worked out example. I want to insert the word "cactus":

Iterate over each character in the string using a loop:

For 'c': result += (int)'c' = 99.

For 'a': result += (int)'a' = 97.

For 'c': result += (int)'c' = 99.

For 't': result += (int)'t' = 116.

For 'u': result += (int)'u' = 117.

For 's': result += (int)'s' = 115.

After the loop, result is 99 + 97 + 99 + 116 + 117 + 115 = 643.

Take the modulus of result with the capacity of the hash table (10): 643 % 10 = 3. So, the hash value for the string "cactus" would be 3 in this case.


- An insert function that places the value at the appropriate location based on its hash value:

- A contains function that returns whether the value is already in the hashtable:

- Smarter hashtable (double hashing or chaining) including at least the same functions as the simple hashtable:


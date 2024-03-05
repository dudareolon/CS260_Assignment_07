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

My program was created using 4 different files: main.cpp, hash.cpp, hash.h, complex_hash.cpp. Here is what each one of the files do:

...........................................

Hash.h:


...........................................

Hash.cpp:


...........................................

Main.cpp:


...........................................

Complex_hash.cpp:



----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

Complexity Analysis:

Now the question arises if Array was already there, what was the need for a new data structure! The answer to this is in the word “efficiency“. Though storing in Array takes O(1) time, searching in it takes at least O(log n) time. This time appears to be small, but for a large data set, it can cause a lot of problems and this, in turn, makes the Array data structure inefficient.

----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

Requirements:


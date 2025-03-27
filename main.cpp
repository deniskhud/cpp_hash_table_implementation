#include "hashtable.h"
#include<cassert>


int main() {

	HashTable<std::string, int> map;

	// Test insert() and find()
	map.insert("apple", 10);
	map.insert("banana", 20);

	int value;
	assert(map.find("apple", value) && value == 10);  // Check if "apple" was inserted correctly
	assert(map.find("banana", value) && value == 20); // Check if "banana" was inserted correctly
	assert(!map.find("cherry", value));  // "cherry" should not exist in the hash table

	// Test overwriting an existing value
	map.insert("apple", 30);
	assert(map.find("apple", value) && value == 30); // The value of "apple" should be updated to 30

	// Test remove()
	map.remove("banana");
	assert(!map.find("banana", value));  // "banana" should be removed

	// Test rehashing by inserting multiple elements
	for (int i = 0; i < 20; i++) {
		map.insert("key" + std::to_string(i), i);
	}

	for (int i = 0; i < 20; i++) {
		assert(map.find("key" + std::to_string(i), value) && value == i);
	}

	// Test clearing the hash table
	map.clear();
	assert(map.Size() == 0);  // The hash table should now be empty
	assert(!map.find("apple", value));  // "apple" should no longer exist

	std::cout << "All tests passed successfully!\n";

	return 0;
}



# Hash Table Implementation

This project is a simple implementation of a hash table in C++ using separate chaining for collision handling.

## Features
- Insert key-value pairs into the hash table.
- Find values by key.
- Remove key-value pairs.
- Automatically rehash when the load factor is exceeded.
- Clear all elements from the table.
- Print the current state of the table.

## Methods

### `void insert(const key& k, const value& v)`
Inserts a key-value pair into the hash table. If the key already exists, its value is updated.

### `bool find(const key& k, value& v)`
Finds a value associated with the given key. Returns `true` if the key exists, otherwise `false`.

### `void remove(const key& k)`
Removes a key-value pair from the table.

### `void rehash(size_t newSize)`
Resizes the hash table and rehashes all elements.

### `void print_table()`
Prints the current contents of the hash table.

### `void clear()`
Clears all elements from the hash table.

### `size_t Size()`
Returns the number of elements in the hash table.

## Testing
The implementation includes basic tests to verify functionality:
- Inserting and retrieving values.
- Updating values.
- Removing keys.
- Rehashing the table when necessary.
- Clearing the table.

The tests use assertions to verify expected behavior. If all assertions pass, a success message is printed.
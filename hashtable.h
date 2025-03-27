#ifndef HASH_TABLE
#define HASH_TABLE

#include<iostream>
#include<vector>
#include <string>
#include<list>
using namespace std;


template<typename key, typename value>
class HashTable {
private:
	vector<list<pair<key, value>>> table;
	size_t size;
	float load_factor;
	size_t num_elements;
	size_t hash(const key& k) const {
		return std::hash<key>()(k) % size;
	}

	void rehash(size_t newSize);

public:

	HashTable(int size = 10, float load_factor = 0.70) : size(size), load_factor(load_factor)
	{
		table.resize(size);
		num_elements = 0;
	}
	void print_table();
	void insert(const key& k, const value& v);
	void remove(const key& k);
	size_t Size() { return num_elements; }
	bool find(const key& k, value& v);

	value& operator [](const key& k);

	void clear();

};

//private method to rehash the hash table
template<typename key, typename value>
void HashTable<key, value>::rehash(size_t newSize)
{
	vector<list<pair<key, value>>> newTable(newSize);

	for (auto& bucket : table) {
		for (auto& pair : bucket) {
			size_t new_index = std::hash<key>()(pair.first) % newSize;
			newTable[new_index].push_back(pair);
		}
	}
	size = newSize;
	table = move(newTable);
}



//print hash table
template<typename key, typename value>
void HashTable<key, value>::print_table()
{
	for (int i = 0; i < size; ++i) {
		if (table[i].empty()) {		//if chain is empty
			cout << i << " <---->\n";
		}
		else {
			cout << "index " << i << ": ";
			for (auto& pair : table[i]) {
				cout << "(" << pair.first << ", " << pair.second << ")" << " -> ";
			}
			cout << endl;

		}
	}
}

//insert the pair (key, value) in hash table
template<typename key, typename value>
void HashTable<key, value>::insert(const key& k, const value& v)
{
	if (num_elements > size * load_factor) {
		rehash(size * 2);
	}
	size_t index = hash(k);			//hash key
	for (auto& current : table[index]) {
		if (current.first == k) {
			current.second = v;		//overwriting the value
			return;
		}
	}
	table[index].emplace_back(k, v);	//insert the value
	++num_elements;
}

//remove the pair 
template<typename key, typename value>
void HashTable<key, value>::remove(const key& k)
{
	size_t index = hash(k);
	auto& chain = table[index];
	for (auto pair = chain.begin(); pair != chain.end(); ++pair) {
		if (pair->first == k) {
			chain.erase(pair);
			--num_elements;
			return;
		}
	}
	return;
}

//find a pair and write down the value
template<typename key, typename value>
bool HashTable<key, value>::find(const key& k, value& v)
{
	int index = hash(k);
	if (table[index].empty()) {
		return false;			//if chain is empty
	}
	else {
		for (const auto& pair : table[index]) {
			if (pair.first == k) {
				v = pair.second;		//save the value
				return true;
			}
		}
	}
	return false;
}

template<typename key, typename value>
value& HashTable<key, value>::operator[](const key& k)
{
	int index = hash(k);
	for (auto& pair : table[index]) {
		if (pair.first == k) {
			return pair.second;
		}
	}
	table[index].emplace_back(k, value());
	return table[index].back().second;
}

template<typename key, typename value>
void HashTable<key, value>::clear()
{
	for (auto& temp : table) {
		temp.clear();
	}
	num_elements = 0;
}

#endif // !HASH_TABLE

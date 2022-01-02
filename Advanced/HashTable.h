#pragma once
#include<iostream>
#include<list>
#include<vector>
using namespace std;

class HashEntry
{
public:
	int key;
	int value;
	HashEntry()
	{
		this->key = -1;
		this->value = NULL;
	}
	HashEntry(int k,int v)
	{
		this->key = k;
		this->value = v;
	}
	~HashEntry()
	{
	}
};

#define SIZE 20
class HashTable
{
public:
	HashEntry entries[SIZE];
	//TO DO HANDLE WHEN THE TABLE IS FULL
	HashTable()
	{
		for (int i = 0; i < SIZE; i++)
			this->entries[i] = HashEntry();
	}

	//using linear proble to handle collision
	HashEntry Search(int key)
	{
		int hashIndex = HashCode(key);
		while (this->entries[hashIndex].key != -1)//occupied so there 's data in this cell
		{
			if (this->entries[hashIndex].key == key)
				return this->entries[hashIndex];

			hashIndex = (hashIndex + 1) % SIZE;//to get to the idx=0 to keep searching
		}
		return HashEntry();//key =-1 la ko tim thay
	}

	void Insert(int k, int v)
	{
		HashEntry entry = HashEntry(k, v);
		int hashIndex = HashCode(entry.key);
		while (this->entries[hashIndex].key != -1)
			hashIndex = (hashIndex + 1) % SIZE;

		this->entries[hashIndex] = entry;
	}

	void Delete(int k)
	{
		int hashIndex = HashCode(k);
		while (this->entries[hashIndex].key != -1)
		{
			if (this->entries[hashIndex].key == k)
			{
				this->entries[hashIndex] = HashEntry();
				return;
			}

			//neu ko nhay tim tiep
			hashIndex = (hashIndex + 1) % SIZE;
		}

		//not found to delete
		return;
	}


private:
	int HashCode(int key)
	{
		return key%SIZE;
	}

};
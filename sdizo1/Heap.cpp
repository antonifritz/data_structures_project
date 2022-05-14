#include "Heap.h"
#include <iostream>

Heap::Heap(int value)
{
	this->array = new int[1];
	this->array[0] = value;									//konstruktor
	this->size++;
}

int Heap::left(int i)
{
	return 2 * i + 1;										//zwraca indeks lewego syna
}

int Heap::right(int i)
{
	return 2 * i + 2;										//zwraca indeks prawego syna
}

int Heap::parent(int i)
{
	return (i - 1) / 2;										//zwraca indeks rodzica
}

void Heap::insertHeap(int key)								//wstawia nowy element do kopca			
{
	int* newArray = new int[this->size + 1];				
	int* oldArray = this->array;							//tworzenie tablicy o 1 wiêkszej

	for (int i = 0; i < this->size; i++)
	{
		newArray[i] = this->array[i];						//przypisanie elementów ze starej tablicy do nowej
	}

	this->array = newArray;									
	int i = this->size;
	this->size++;

	while (i > 0 && this->array[parent(i)] < key)			//algorytm wstawiania	
	{
		this->array[i] = this->array[parent(i)];
		i = parent(i);
	}

	this->array[i] = key;

	delete oldArray;
}

void Heap::deleteRootHeap()									//algorytm usuwania korzenia	
{
	if (this->size == 0)
	{
		std::cout << "Kopiec jest pusty!" << std::endl;
		return;
	}


	int* newArray = new int[this->size - 1];
	int* oldArray = this->array;

	this->size--;
	int key = this->array[size];

	int i = 0;
	int j = 1;

	while (j < this->size)
	{
		if (j + 1 < this->size && (this->array[j + 1] > this->array[j]))
		{
			j++;
		}
		if (key >= this->array[j])
			break;
		this->array[i] = this->array[j];
		i = j;
		j = left(j);
	}
	this->array[i] = key;

	for (int i = 0; i < this->size; i++)
	{
		newArray[i] = this->array[i];
	}

	this->array = newArray;
	delete oldArray;
}

int Heap::searchHeap(int key)							   //przeszukuje tablice kopca				
{
	for (int i = 0; i < this->size; i++)
	{
		if (this->array[i] == key)
		{
			return i;
		}
	}
	return -1;
}

void Heap::showData()									   //wyswietla dane
{
	for (int i = 0; i < this->size; i++)
	{
		std::cout << i << ": " << this->array[i] << std::endl;
	}
}

int* Heap::getArrayPointerHeap()						  //zwraca wskaznik na tablice
{
	return this->array;
}

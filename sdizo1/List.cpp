#include <iostream>
#include "List.h"

List::List(ListElement* head)
{
	this->head = head;
}

ListElement List::getHead()
{
	return *this->head;
}

int List::getSize()
{
	return this->size;
}

void List::setHead(ListElement* head)
{
	this->head = head;
}

void List::setSize(int size)
{
	this->size = size;
}

void List::insertListBeginning(ListElement* newElement)
{
	if (this->size == 0)
	{
		this->head = newElement;
		this->head->setKey(newElement->getKey());
		this->size++;
		return;
	}
	newElement->setNext(this->head);
	this->head->setPrev(newElement);
	this->head = newElement;

	this->size++;
}

void List::insertListCustom(ListElement* newElement, int index)
{
	if (index == 0)
	{
		insertListBeginning(newElement);
		return;
	}

	if (index == this->size)
	{
		insertListEnd(newElement);
		return;
	}

	ListElement* iterator = this->head;

	for (int i = 0; i < index - 1; i++)
	{
		iterator = iterator->getNext();
	}

	newElement->setNext(iterator->getNext());
	newElement->setPrev(iterator);
	iterator->getNext()->setPrev(newElement);
	iterator->setNext(newElement);

	this->size++;
}

void List::insertListEnd(ListElement* newElement)
{
	if (this->size == 0)
	{
		this->head = newElement;
		this->size++;
		return;
	}

	ListElement* iterator = this->head;

	for (int i = 0; i < this->size - 1; i++)
	{
		iterator = iterator->getNext();
	}

	iterator->setNext(newElement);
	newElement->setPrev(iterator);

	this->size++;
}

void List::deleteListBeginning()
{
	if (this->size == 0)
	{
		return;
	}
	if (this->size == 1)
	{
		this->head == nullptr;
		this->size--;
		return;
	}
	ListElement* iterator = this->head;
	this->head = this->head->getNext();
	this->head->setPrev(nullptr);

	this->size--;
}

void List::deleteListCustom(int index)
{
	if (index == 0)
	{
		deleteListBeginning();
		return;
	}

	if (index == this->size - 1)
	{
		deleteListEnd();
		return;
	}

	ListElement* iterator = this->head;

	for (int i = 0; i < index; i++)
	{
		iterator = iterator->getNext();
	}

	iterator->getNext()->setPrev(iterator->getPrev());
	iterator->getPrev()->setNext(iterator->getNext());

	this->size--;
}

void List::deleteListEnd()
{
	if (this->size == 0)
	{
		return;
	}
	if (this->size == 1)
	{
		this->head == nullptr;
		this->size--;
		return;
	}
	ListElement* iterator = this->head;

	for (int i = 0; i < size - 1; i++)
	{
		iterator = iterator->getNext();
	}

	iterator->getPrev()->setNext(nullptr);

	this->size--;
}

int List::searchElement(int key)
{
	if (this->size == 0)
	{
		std::cout <<std::endl<<"Lista pusta";
		return -1;
	}
	int i = 0;
	ListElement* iterator = this->head;

	while (iterator->getKey() != key && iterator->getNext() != nullptr)
	{
		iterator = iterator->getNext();
		i++;
	}
	if (iterator->getNext() == nullptr && iterator->getKey() != key)
		return -1;
	else
		return i;
}

void List::showData()
{
	if (this->size == 0)
		std::cout << "Lista pusta!" << std::endl;

	else {
	ListElement* iterator = this->head;

	for (int i = 0; iterator != nullptr; i++)
	{
		std::cout << i << ": " << iterator->getKey() << std::endl;
		iterator = iterator->getNext();
	}
	}
}

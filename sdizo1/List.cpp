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
	newElement->setNext(this->head);
	this->head->setPrev(newElement);
	this->head = newElement;

	this->size++;
}

void List::insertListCustom(ListElement* newElement, int index)
{
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
	ListElement* iterator = this->head;
	this->head = this->head->getNext();
	this->head->setPrev(nullptr);

	this->size--;
}

void List::deleteListCustom(int index)
{
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
	ListElement* iterator = this->head;

	for (int i = 0; i < size - 1; i++)
	{
		iterator = iterator->getNext();
	}

	iterator->getPrev()->setNext(nullptr);

	this->size--;
}

void List::searchElement(int key)
{
	ListElement* iterator = this->head;

	while (iterator->getKey() != key && iterator->getNext() != nullptr)
	{
		iterator = iterator->getNext();
	}
}

void List::showData()
{
	ListElement* iterator = this->head;

	for (int i = 0; iterator != nullptr; i++)
	{
		std::cout << i << ": " << iterator->getKey() << std::endl;
		iterator = iterator->getNext();
	}
}

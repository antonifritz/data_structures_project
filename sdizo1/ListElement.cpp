#include <iostream>
#include "ListElement.h"

ListElement::ListElement()
{
	this->key = 0;
	this->next = nullptr;
	this->prev = nullptr;
}

ListElement::ListElement(int key)
{
	this->key = key;
}

ListElement::ListElement(int key, ListElement* next, ListElement* prev)
{
	this->key = key;
	this->next = next;
	this->prev = prev;
}

int ListElement::getKey()
{
	return this->key;
}

ListElement* ListElement::getNext()
{
	return this->next;
}

ListElement* ListElement::getPrev()
{
	return this->prev;
}

void ListElement::setKey(int key)
{
	this->key = key;
}

void ListElement::setNext(ListElement* next)
{
	this->next = next;
}

void ListElement::setPrev(ListElement* prev)
{
	this->prev = prev;
}

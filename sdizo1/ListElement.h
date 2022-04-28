#pragma once
class ListElement
{
public:

	ListElement();
	ListElement(int key);
	ListElement(int key, ListElement* next, ListElement* prev);

	int getKey();
	ListElement* getNext();
	ListElement* getPrev();

	void setKey(int key);
	void setNext(ListElement* next);
	void setPrev(ListElement* prev);

private:

	int key;
	ListElement* next = nullptr;
	ListElement* prev = nullptr;
};


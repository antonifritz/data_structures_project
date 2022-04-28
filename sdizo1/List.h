#pragma once
#include "ListElement.h"

class List
{
public:

	List(ListElement* head);

	ListElement getHead();
	int getSize();

	void setHead(ListElement* head);
	void setSize(int size);

	void insertListBeginning(ListElement* newElement);
	void insertListCustom(ListElement* newElement, int index);
	void insertListEnd(ListElement* newElement);

	void deleteListBeginning();
	void deleteListCustom(int index);
	void deleteListEnd();

	void searchElement(int key);

	void showData();

private:
	ListElement* head;
	int size = 1;
};

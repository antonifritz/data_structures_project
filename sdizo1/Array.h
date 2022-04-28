#pragma once
class Array
{
public:

	Array(int size);

	int getArray(int index);
	int* getArrayPointer();
	int getSize();

	void setArray(int index, int num);
	void setSize(int size);

	void insertArrayBeginning(int newElement);
	void insertArrayCustom(int index, int newElement);
	void insertArrayEnd(int newElement);

	void deleteArrayBeginning();
	void deleteArrayCustom(int index);
	void deleteArrayEnd();

	int searchArray(int key);

	void showData();

private:

	int size;
	int* array;
};
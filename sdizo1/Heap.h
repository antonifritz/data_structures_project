#pragma once
class Heap
{
public:
	Heap(int value);

	int left(int i);
	int right(int i);
	int parent(int i);

	void insertHeap(int key);
	void deleteRootHeap();
	int searchHeap(int key);

	void showData();

	int* getArrayPointerHeap();

private:
	int* array;
	int size = 0;
};


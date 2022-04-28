// main.cpp : Ten plik zawiera funkcję „main”. W nim rozpoczyna się i kończy wykonywanie programu.
//

#include <iostream>
#include <fstream>
#include <string>
#include <windows.h>
#include "Array.h"
#include "ListElement.h"
#include "List.h"
#include "Heap.h"

using namespace std;

int main()
{
	LARGE_INTEGER frequency;
	LARGE_INTEGER start;
	LARGE_INTEGER end;
	fstream inputDataFile;
	string line;
	int number1, number2, number3, number4, number5;
	double sum = 0;
	Array* mainArray;
	int size;

	std::cout << "Tworzenie tablicy z danymi z pliku..." << endl;

	inputDataFile.open("inputData.csv", ios::out | ios::in);								//otwarcie pliku z danymi
	
	if(inputDataFile.is_open())
	{
		getline(inputDataFile, line);															//pierwsza linia zawiera rozmiar struktury
		size = atoi(line.c_str());

		std::cout << "Rozmiar tablicy wynosi: " << size << endl;
		std::cout << "Tworzenie tablicy z pliku..." << endl;
	 
		mainArray = new Array(size);														 //utworzenie tablicy o rozmiarze zadeklarowanym w pliku

	for (int i = 0; i < size; i++)
	{
		getline(inputDataFile, line);
		mainArray->setArray(i, atoi(line.c_str()));										     //zczytywanie linia po linii pliku 
	}																						 //i przypisywanie danych do tablicy
	
	inputDataFile.close();

	std::cout << "Zakonczono proces tworzenia tablicy." << endl << endl;
	}
	else {
		std::cout << "Plik nie zostal otwarty, utworz recznie dane wejsciowe. " << endl;
		std::cout << "Podaj rozmiar instancji: "<< endl;
		cin >> size;
		mainArray = new Array(size);
		std::cout << "Wprowadzaj dane: "<< endl;
		for (int i = 0; i < size; i++)
		{
			int input;
			cin >> input;
			mainArray->setArray(i, input);
		}
	}
	mainArray->showData();																	  //wyswietlenie głównej tablicy

	std::cout << endl;

	while (true)
	{
		sum = 0;

		std::cout << "MENU" << endl;
		std::cout << "Wybierz rodzaj struktury:" << endl;
		std::cout << "1. Tablica" << endl;
		std::cout << "2. Lista" << endl;
		std::cout << "3. Kopiec binarny (maksimum)" << endl;
		std::cout << "4. Wyswietl glowna tablice" << endl;

		std::cin >> number1;

		if (number1 == 1)
		{
			std::cout << endl;
			std::cout << "Wybierz operacje ktora chcesz przeprowadzic na tablicy:" << endl;
			std::cout << "1. Wstaw na poczatek" << endl;
			std::cout << "2. Wstaw w dowolne miejsce" << endl;
			std::cout << "3. Wstaw na koniec" << endl;
			std::cout << "4. Usun z poczatku" << endl;
			std::cout << "5. Usum z dowolnego miejsca" << endl;
			std::cout << "6. Usun z konca" << endl;
			std::cout << "7. Wyszukaj element" << endl;

			std::cin >> number2;

			if (number2 == 1)
			{
				int value;
				std::cout << "Wybrano operacje wstaw na poczatek" << endl;
				std::cout << "Podaj wartosc wstawianego elementu" << endl;
				std::cin >> value;
				std::cout << "Obliczanie usrednionego czasu operacji..." << endl;

				for (int i = 0; i < 100; i++)												 //przeprowadzanych jest 100 pomiarów 
				{
					Array* array = new Array(size);											 //utworzenie nowej tablicy

					for (int j = 0; j < size; j++)
					{
						array->setArray(j, mainArray->getArray(j));							 //przypisanie elementów z tablicy tworzonej z pliku
					}

					double interval = 0;
					QueryPerformanceFrequency(&frequency);
					QueryPerformanceCounter(&start);

					array->insertArrayBeginning(value);

					QueryPerformanceCounter(&end);
					interval = (double)(end.QuadPart - start.QuadPart) / frequency.QuadPart; //pomiar czasu metody

					sum = sum + interval;													 //zwiększenie sumy czasów o dany czas

					if (i == 0)
					{
						array->showData();													 //jednokrotne wyświetlenie tablicy
					}

					delete[] array->getArrayPointer();
					delete array;															 //usunięcie tablicy	
				}

				double result = sum * 100.0;
				std::cout << "Czas wyniosl: " << result << " * 10^-4 [s]" << endl;			 //uśredniony czas 100 pomiarów
			}

			else if (number2 == 2)
			{
				int value;
				int index;
				std::cout << "Wybrano operacje wstaw na dowolne miejsce" << endl;
				std::cout << "Podaj wartosc wstawianego elementu" << endl;
				std::cin >> value;
				std::cout << "Podaj indeks wstawianego elementu" << endl;
				std::cin >> index;
				std::cout << "Obliczanie usrednionego czasu operacji..." << endl;

				for (int i = 0; i < 100; i++)												//wykonywanych jest 100 pomiarów
				{
					Array* array = new Array(size);											//utworzenie nowej tablicy

					for (int j = 0; j < size; j++)
					{
						array->setArray(j, mainArray->getArray(j));							//przypisanie elementów z tablicy tworzonej z pliku
					}

					double interval = 0;
					QueryPerformanceFrequency(&frequency);
					QueryPerformanceCounter(&start);

					array->insertArrayCustom(index, value);									//pomiar czasu metody		

					QueryPerformanceCounter(&end);
					interval = (double)(end.QuadPart - start.QuadPart) / frequency.QuadPart;

					sum = sum + interval;													//zwiększenie sumy czasów o czas danego pomiaru

					if (i == 0)
					{
						array->showData();													//jednokrotne wyświetlenie tablicy
					}

					delete[] array->getArrayPointer();
					delete array;															//usunięcie tablicy
				}

				double result = sum * 100.0;
				std::cout << "Czas wyniosl: " << result << " * 10^-4 [s]" << endl;
			}

			else if (number2 == 3)
			{
				int value;
				std::cout << "Wybrano operacje wstaw na koniec" << endl;
				std::cout << "Podaj wartosc wstawianego elementu" << endl;
				std::cin >> value;
				std::cout << "Obliczanie usrednionego czasu operacji..." << endl;

				for (int i = 0; i < 100; i++)
				{
					Array* array = new Array(size);											//utworzenie nowej tablicy

					for (int j = 0; j < size; j++)
					{
						array->setArray(j, mainArray->getArray(j));							//przypisanie wartości z tablicy tworzonej z pliku
					}

					double interval = 0;
					QueryPerformanceFrequency(&frequency);
					QueryPerformanceCounter(&start);

					array->insertArrayEnd(value);											//pomiar czasu metody

					QueryPerformanceCounter(&end);
					interval = (double)(end.QuadPart - start.QuadPart) / frequency.QuadPart;

					sum = sum + interval;													//zwiększenie sumy czasów o czas danego pomiaru

					if (i == 0)
					{
						array->showData();													//jednokrotne wyświetlenie tablicy
					}

					delete[] array->getArrayPointer();
					delete array;															//usunięcie tablicy
				}

				double result = sum * 100;

				std::cout << "Czas wyniosl: " << result << " * 10^-4 [s]" << endl;
			}

			else if (number2 == 4)
			{
				std::cout << "Wybrano operacje usun z poczatku" << endl;
				std::cout << "Obliczanie usrednionego czasu operacji..." << endl;

				for (int i = 0; i < 100; i++)												//wykonywanych jest 100 pomiarów
				{
					Array* array = new Array(size);											//tworzenie nowej tablicy
					for (int j = 0; j < size; j++)
					{
						array->setArray(j, mainArray->getArray(j));							//przypisanie wartości z tablicy tworzonej z pliku
					}

					double interval = 0;
					QueryPerformanceFrequency(&frequency);
					QueryPerformanceCounter(&start);

					array->deleteArrayBeginning();											//pomiar czasu metody

					QueryPerformanceCounter(&end);
					interval = (double)(end.QuadPart - start.QuadPart) / frequency.QuadPart;

					sum = sum + interval;													//zwiększenie sumy czasów o czas danego pomiaru	

					if (i == 0)
					{
						array->showData();													//jednokrotne wyświetlenie tablicy
					}

					delete array->getArrayPointer();
					delete array;															//usunięcie tablicy
				}

				double result = sum * 100.0;
				std::cout << "Czas wyniosl: " << result << " * 10^-4 [s]" << endl;

			}

			else if (number2 == 5)
			{
				std::cout << "Wybrano operacje usun z dowolnego miejsca" << endl;
				int index;
				std::cout << "Podaj indeks wstawianego elementu" << endl;
				std::cin >> index;
				std::cout << "Obliczanie usrednionego czasu operacji..." << endl;

				for (int i = 0; i < 100; i++)												//wykonywanych jest 100 pomiarów
				{
					Array* array = new Array(size);											//utworzenie nowej tablicy

					for (int j = 0; j < size; j++)
					{
						array->setArray(j, mainArray->getArray(j));							//przypisanie wartości z tablicy tworzonej z pliku
					}

					double interval = 0;
					QueryPerformanceFrequency(&frequency);
					QueryPerformanceCounter(&start);

					array->deleteArrayCustom(index);										//pomiar czasu metody

					QueryPerformanceCounter(&end);
					interval = (double)(end.QuadPart - start.QuadPart) / frequency.QuadPart;

					sum = sum + interval;													//zwiększenie sumy czasów o czas danego pomiaru

					if (i == 0)
					{
						array->showData();													//jednokrotne wyświetlenie tablicy
					}

					delete[] array->getArrayPointer();
					delete array;															//usunięcie tablicy
				}

				double result = sum * 100.0;
				std::cout << "Czas wyniosl: " << result << " * 10^-4 [s]" << endl;
			}

			else if (number2 == 6)
			{
				std::cout << "Wybrano operacje usun z konca" << endl;
				std::cout << "Obliczanie usrednionego czasu operacji..." << endl;

				for (int i = 0; i < 100; i++)												//wykonywanych jest 100 pomiarów	
				{
					Array* array = new Array(size);											//tworzona jest nowa tablica

					for (int j = 0; j < size; j++)
					{
						array->setArray(j, mainArray->getArray(j));							//przypisanie wartości z tablicy tworzonej z pliku
					}

					double interval = 0;
					QueryPerformanceFrequency(&frequency);
					QueryPerformanceCounter(&start);

					array->deleteArrayEnd();												//pomiar czasu metody

					QueryPerformanceCounter(&end);
					interval = (double)(end.QuadPart - start.QuadPart) / frequency.QuadPart;

					sum = sum + interval;													//zwiększenie sumy czasów o czas danego pomiaru

					if (i == 0)
					{
						array->showData();													//jednokrotne wyświetlenie tablicy
					}

					delete[] array->getArrayPointer();
					delete array;															//usunięcie tablicy
				}

				double result = sum * 100.0;
				std::cout << "Czas wyniosl: " << result << " * 10^-4 [s]" << endl;
			}

			else if (number2 == 7)
			{
				std::cout << "Wybrano operacje wyszukaj element" << endl;
				int value;
				std::cout << "Podaj wartosc elementu" << endl;
				std::cin >> value;
				std::cout << "Obliczanie usrednionego czasu operacji..." << endl;

				Array* array = new Array(size);												//tworzona jest nowa tablica

				for (int j = 0; j < size; j++)
				{
					array->setArray(j, mainArray->getArray(j));								//przypisanie wartości z tablicy tworzonej z pliku
				}

				for (int i = 0; i < 100; i++)
				{
					double interval = 0;
					QueryPerformanceFrequency(&frequency);
					QueryPerformanceCounter(&start);

					array->searchArray(value);						  //pomiar czasu metody

					QueryPerformanceCounter(&end);
					interval = (double)(end.QuadPart - start.QuadPart) / frequency.QuadPart;

					sum = sum + interval;							  //zwiększenie sumy czasów o czas danego pomiaru

					if (i == 0)
					{
						array->showData();							  //jednokrotne wyświetlenie tablicy
					}
				}

				delete[] array->getArrayPointer();
				delete array;																//usunięcie tablicy

				double result = sum * 100.0;
				std::cout << "Czas wyniosl: " << result << " * 10^-4 [s]" << endl;
			}

			else
			{
				std::cout << "Wprowadz prawidlowy numer" << endl;
			}

		}

		else if (number1 == 2)
		{
			std::cout << "Wybrano strukture lista" << endl;
			std::cout << "Rozmiar listy wynosi: " << size << endl;
			std::cout << "Tworzenie listy..." << endl;

			ListElement* head = new ListElement(mainArray->getArray(0));
			List* list = new List(head);
			for (int i = 1; i < size; i++)
			{
				ListElement* newElement = new ListElement(mainArray->getArray(i));			//tworzone są elementy listy a następnie są
				list->insertListEnd(newElement);											//wstawiane na koniec 
			}
			list->showData();																//wyświetlenie listy

			std::cout << endl;
			std::cout << "Wybierz operacje ktora chcesz przeprowadzic na liscie:" << endl;
			std::cout << "1. Wstaw na poczatek" << endl;
			std::cout << "2. Wstaw w dowolne miejsce" << endl;
			std::cout << "3. Wstaw na koniec" << endl;
			std::cout << "4. Usun z poczatku" << endl;
			std::cout << "5. Usum z dowolnego miejsca" << endl;
			std::cout << "6. Usun z konca" << endl;
			std::cout << "7. Wyszukaj element" << endl;

			std::cin >> number2;

			if (number2 == 1)
			{
				int value;
				std::cout << "Wybrano operacje wstaw na poczatek" << endl;
				std::cout << "Podaj wartosc wstawianego elementu" << endl;
				std::cin >> value;
				std::cout << "Obliczanie usrednionego czasu operacji..." << endl;

				ListElement* newElement = new ListElement(value);

				for (int i = 0; i < 100; i++)												//przeprowadzanych jest 100 pomiarów 
				{

					double interval = 0;
					QueryPerformanceFrequency(&frequency);
					QueryPerformanceCounter(&start);

					list->insertListBeginning(newElement);

					QueryPerformanceCounter(&end);
					interval = (double)(end.QuadPart - start.QuadPart) / frequency.QuadPart; //pomiar czasu metody

					sum = sum + interval;													 //zwiększenie sumy czasów o dany czas

					if (i == 0)
					{
						list->showData();													 //jednokrotne wyświetlenie listy
					}

					list->deleteListBeginning();										     //przywrócenie stanu sprzed wstawienia elementu
				}

				delete list;

				double result = sum * 100.0;
				std::cout << "Czas wyniosl: " << result << " * 10^-4 [s]" << endl;			 //uśredniony czas 100 pomiarów
			}

			else if (number2 == 2)
			{
				int value, index;
				std::cout << "Wybrano operacje wstaw w dowolne miejsce" << endl;
				std::cout << "Podaj indeks wstawianego elementu" << endl;
				std::cin >> index;
				std::cout << "Podaj wartosc wstawianego elementu" << endl;
				std::cin >> value;
				std::cout << "Obliczanie usrednionego czasu operacji..." << endl;

				ListElement* newElement = new ListElement(value);

				for (int i = 0; i < 100; i++)
				{
					double interval = 0;
					QueryPerformanceFrequency(&frequency);
					QueryPerformanceCounter(&start);

					list->insertListCustom(newElement, index);

					QueryPerformanceCounter(&end);
					interval = (double)(end.QuadPart - start.QuadPart) / frequency.QuadPart; //pomiar czasu metody

					sum = sum + interval;												     //zwiększenie sumy czasów o dany czas

					if (i == 0)
					{
						list->showData();													 //jednokrotne wyświetlenie listy
					}

					list->deleteListCustom(index);											//przywrócenie stanu sprzed wstawienia elementu

					if (i == 0)
					{
						list->showData();												    //wyswietlenie listy
					}
				}

				delete list;																//usunięcie listy

				double result = sum * 100.0;
				std::cout << "Czas wyniosl: " << result << " * 10^-4 [s]" << endl;			//uśredniony czas 100 pomiarów
			}

			else if (number2 == 3)
			{
				int value;
				std::cout << "Wybrano operacje wstaw na koniec" << endl;
				std::cout << "Podaj wartosc wstawianego elementu" << endl;
				std::cin >> value;
				std::cout << "Obliczanie usrednionego czasu operacji..." << endl;

				ListElement* newElement = new ListElement(value);

				for (int i = 0; i < 100; i++)        //przeprowadzanych jest 100 pomiarów 
				{

					double interval = 0;
					QueryPerformanceFrequency(&frequency);
					QueryPerformanceCounter(&start);

					list->insertListEnd(newElement);

					QueryPerformanceCounter(&end);
					interval = (double)(end.QuadPart - start.QuadPart) / frequency.QuadPart; //pomiar czasu metody

					sum = sum + interval;								 //zwiększenie sumy czasów o dany czas

					if (i == 0)
					{
						list->showData();						 //jednokrotne wyświetlenie listy
					}

					list->deleteListEnd();						 //przywrócenie stanu sprzed wstawienia elementu
				}

				delete list;									 //usunięcie listy

				double result = sum * 100.0;
				std::cout << "Czas wyniosl: " << result << " * 10^-4 [s]" << endl;			 //uśredniony czas 100 pomiarów
			}

			else if (number2 == 4)
			{
				std::cout << "Wybrano operacje usun z poczatku" << endl;
				std::cout << "Podaj indeks usuwanego elementu" << endl;
				std::cout << "Obliczanie usrednionego czasu operacji..." << endl;

				ListElement deleted = list->getHead();

				for (int i = 0; i < 100; i++)												//przeprowadzanych jest 100 pomiarów 
				{

					double interval = 0;
					QueryPerformanceFrequency(&frequency);
					QueryPerformanceCounter(&start);

					list->deleteListBeginning();

					QueryPerformanceCounter(&end);
					interval = (double)(end.QuadPart - start.QuadPart) / frequency.QuadPart; //pomiar czasu metody

					sum = sum + interval;													 //zwiększenie sumy czasów o dany czas

					if (i == 0)
					{
						list->showData();													 //jednokrotne wyświetlenie listy
					}

					list->insertListBeginning(&deleted);									 //przywrócenie stanu sprzed wstawienia elementu

				}

				delete list;																 //usunięcie listy

				double result = sum * 100.0;
				std::cout << "Czas wyniosl: " << result << " * 10^-4 [s]" << endl;			 //uśredniony czas 100 pomiarów
			}

			else if (number2 == 5)
			{
				int index;
				std::cout << "Wybrano operacje usun z dowolnego miejsca" << endl;
				std::cout << "Podaj indeks usuwanego elementu" << endl;
				std::cin >> index;
				std::cout << "Obliczanie usrednionego czasu operacji..." << endl;

				ListElement deleted = list->getHead();
				for (int i = 0; i < index; i++)
				{
					deleted = *deleted.getNext();											//pobranie usuwanego elementu
				}

				for (int i = 0; i < 100; i++)												//przeprowadzanych jest 100 pomiarów 
				{

					double interval = 0;
					QueryPerformanceFrequency(&frequency);
					QueryPerformanceCounter(&start);

					list->deleteListCustom(index);

					QueryPerformanceCounter(&end);
					interval = (double)(end.QuadPart - start.QuadPart) / frequency.QuadPart; //pomiar czasu metody

					sum = sum + interval;													 //zwiększenie sumy czasów o dany czas

					if (i == 0)
					{
						list->showData();													 //jednokrotne wyświetlenie listy
					}

					list->insertListCustom(&deleted, index);							     //przywrócenie stanu sprzed wstawienia elementu

					if (i == 0)
					{
						list->showData();
					}
				}

				delete list;																  //usunięcie listy

				double result = sum * 100.0;
				std::cout << "Czas wyniosl: " << result << " * 10^-4 [s]" << endl;			  //uśredniony czas 100 pomiarów
			}

			else if (number2 == 6)
			{
				std::cout << "Wybrano operacje usun z konca" << endl;
				std::cout << "Obliczanie usrednionego czasu operacji..." << endl;

				ListElement deleted = list->getHead();
				for (int i = 1; i < size; i++)
				{
					deleted = *deleted.getNext();
				}

				for (int i = 0; i < 100; i++)        //przeprowadzanych jest 100 pomiarów 
				{

					double interval = 0;
					QueryPerformanceFrequency(&frequency);
					QueryPerformanceCounter(&start);

					list->deleteListEnd();

					QueryPerformanceCounter(&end);
					interval = (double)(end.QuadPart - start.QuadPart) / frequency.QuadPart; //pomiar czasu metody

					sum = sum + interval;													 //zwiększenie sumy czasów o dany czas

					if (i == 0)
					{
						list->showData();													 //jednokrotne wyświetlenie listy
					}

					list->insertListEnd(&deleted);							 //przywrócenie stanu sprzed wstawienia elementu

				}

				delete list;																//usunięcie listy

				double result = sum * 100.0;
				std::cout << "Czas wyniosl: " << result << " * 10^-4 [s]" << endl;			//uśredniony czas 100 pomiarów
			}

			else if (number2 == 7)
			{
				int input;
				std::cout << "Wybrano operacje wyszukaj element" << endl;
				std::cout << "Podaj wartosc elementu" << endl;
				std::cin >> input;
				std::cout << "Obliczanie usrednionego czasu operacji..." << endl;

				for (int i = 0; i < 100; i++)												 //przeprowadzanych jest 100 pomiarów 
				{

					double interval = 0;
					QueryPerformanceFrequency(&frequency);
					QueryPerformanceCounter(&start);

					list->searchElement(input);

					QueryPerformanceCounter(&end);
					interval = (double)(end.QuadPart - start.QuadPart) / frequency.QuadPart; //pomiar czasu metody

					sum = sum + interval;													 //zwiększenie sumy czasów o dany czas
				}

				delete list;																 //usunięcie listy

				double result = sum * 100.0;
				std::cout << "Czas wyniosl: " << result << " * 10^-4 [s]" << endl;			 //uśredniony czas 100 pomiarów
			}
		}

		else if (number1 == 3)
		{
			std::cout << "Wybrano strukture kopiec binarny" << endl;
			std::cout << "Rozmiar kopca wynosi: " << size << endl;
			std::cout << endl;
			std::cout << "Wybierz operacje ktora chcesz przeprowadzic na kopcu:" << endl;
			std::cout << "1. Wstaw nowy element" << endl;
			std::cout << "2. Usun korzen" << endl;
			std::cout << "3. Wyszukaj element" << endl;

			std::cin >> number2;

			if (number2 == 1)
			{
				int value;
				std::cout << "Wybrano operacje wstaw element" << endl;
				std::cout << "Podaj wartosc nowego elementu: ";
				std::cin >> value;
				std::cout << "Obliczanie usrednionego czasu operacji..." << endl;
				for (int j = 0; j < 100; j++)
				{
					Heap* heap = new Heap(mainArray->getArray(0));			

					for (int i = 1; i < size; i++)
					{
						heap->insertHeap(mainArray->getArray(i));								//tworzenie kopca i wstawianie nowego elementu
					}																			

					if (j == 0)
					{
						heap->showData();														//wyswietlenie kopca
						std::cout << endl;
					}
					

					double interval = 0;
					QueryPerformanceFrequency(&frequency);
					QueryPerformanceCounter(&start);

					heap->insertHeap(value);													//pomiar czasu metody		

					QueryPerformanceCounter(&end);
					interval = (double)(end.QuadPart - start.QuadPart) / frequency.QuadPart;

					sum = sum + interval;														//zwiększenie sumy czasów o czas danego pomiaru

					if (j == 0)
					{
						heap->showData();
					}

					delete heap->getArrayPointerHeap();
					delete heap;
				}
				
				double result = sum * 100.0;
				std::cout << "Czas wyniosl: " << result << " * 10^-4 [s]" << endl;				//uśredniony czas 100 pomiarów
			}
			else if (number2 == 2)
			{
				std::cout << "Wybrano operacje usun korzen kopca" << endl;	
				std::cout << "Obliczanie usrednionego czasu operacji..." << endl;

				for (int j = 0; j < 100; j++)
				{
					Heap* heap = new Heap(mainArray->getArray(0));

					for (int i = 1; i < size; i++)
					{
						heap->insertHeap(mainArray->getArray(i));								//tworzenie kopca i wstawianie nowego elementu
					}

					if (j == 0)
					{
						heap->showData();														//wyswietlenie danych
						std::cout << endl;
					}


					double interval = 0;
					QueryPerformanceFrequency(&frequency);
					QueryPerformanceCounter(&start);

					heap->deleteRootHeap();														//pomiar czasu metody		

					QueryPerformanceCounter(&end);
					interval = (double)(end.QuadPart - start.QuadPart) / frequency.QuadPart;

					sum = sum + interval;														//zwiększenie sumy czasów o czas danego pomiaru

					if (j == 0)
					{
						heap->showData();														//wyswietlenie danych
					}

					delete heap->getArrayPointerHeap();
					delete heap;
				}

				double result = sum * 100.0;
				std::cout << "Czas wyniosl: " << result << " * 10^-4 [s]" << endl;				//uśredniony czas 100 pomiarów
			}
			else if (number2 == 3)
			{
				int input;
				std::cout << "Wybrano operacje wyszukaj element" << endl;
				std::cout << "Podaj wartosc elementu:" << endl;
				std::cin >> input;
				std::cout << "Obliczanie usrednionego czasu operacji..." << endl;

				Heap* heap = new Heap(mainArray->getArray(0));

				for (int i = 1; i < size; i++)
				{
					heap->insertHeap(mainArray->getArray(i));									//tworzenie kopca i wstawianie nowych elementów
				}

				heap->showData();
				std::cout << endl;

				for (int j = 0; j < 100; j++)
				{

					double interval = 0;
					QueryPerformanceFrequency(&frequency);
					QueryPerformanceCounter(&start);

					heap->searchHeap(input);													//pomiar czasu metody		

					QueryPerformanceCounter(&end);
					interval = (double)(end.QuadPart - start.QuadPart) / frequency.QuadPart;

					sum = sum + interval;														//zwiększenie sumy czasów o czas danego pomiaru
				}

				delete heap->getArrayPointerHeap();
				delete heap;

				double result = sum * 100.0;
				std::cout << "Czas wyniosl: " << result << " * 10^-4 [s]" << endl;				//uśredniony czas 100 pomiarów
			}
			else
			{
			std::cout << "Wprowadz prawidlowy numer" << endl;
			}
		}

		else if (number1 == 4)
		{
			mainArray->showData();																//wyświetlenie tablicy
		}

		else
		{
			std::cout << "Wprowadź poprawny numer";
		}

		std::cout << endl;
	}

	return 0;
}


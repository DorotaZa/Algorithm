#pragma once

class Vector
{
private:
	int* _data;
	unsigned int _capacity;
	unsigned int _size;

public:
	Vector(); //konstruktor domyslny tworzy pusty wektor
	Vector(unsigned int capacity); //rezeruwje miejsce na podana liczbe elementow
	Vector(const Vector& old); //konstruktor kopiujacy
	virtual ~Vector();

	void reserve(unsigned int _capacity); //zwieksza rozmiar zarezerwowanej pamieci vectora, ale nie mozna zmienjszyc
	//void resize(unsigned int _size);//pozwala zmniejszyc i zwiekszyc rozmiar wektora

	//gettery
	unsigned int capacity() const;//const = obietnica nie zmieniania pol
	unsigned int size() const;
	bool empty() const; //"wygodniej" sprawdzamy size; zwaraca prawde kiedy wektor jest pusty (czyli kiedy size jest pusty) 

	void push_back(const int& value); //odklada element na ostatnie wolne miejsce 
	void insert(int value, unsigned int index);//pozwala wstawic wartosc do wektora na dana pozycje
	void remove(unsigned int index); //usuwa dany index
	void clear(); //usuwa wszytskie elementy z wektora jednak nie zmniejsza zarezerwowanej pamieci
	void remove(unsigned int from, unsigned int to); //usuwa wiele wartosci z wektora from to
	void bubble_sort(); //sortowanie za pomoca algorytmu sortowania babelkowego
	void pop_back(); //usuwa ostani elelement
	//void copyTo(Vector& other, unsigned int index); //skopiuj zawartosc wektora other w podane miejsce 

	int& operator[](unsigned int index); //operator dostepu do danych na podanej pozycji
	Vector& operator=(const Vector& other); //to samo co konstruktor kopiujacy

};


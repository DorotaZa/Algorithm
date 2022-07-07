#pragma once
class Vector
{
private:
	int* data;
	unsigned int capacity;
	unsigned int size;

public:
	Vector(); //konstruktor domyslny, tworzy vector na 1 element i korzyta z konstruktora od capacity
	Vector(unsigned int _capacity); //rezeruwje miejsce na podana liczbe elementow
	Vector(const Vector& old); //konstruktor kopiujacy
	virtual ~Vector();

	void reserve(unsigned int _capacity); //zwieksza rozmiar zarezerwowanej pamieci vectora, ale nie mozna zmienjszyc
	void resize(unsigned int _size);//pozwala zmniejszyc i zwiekszyc rozmiar wektora

	//gettery
	unsigned int capacity() const;//obietnica nie zmiany pol
	unsigned int size() const;//obietnica nie zmiany pol
	bool empty() const; //"wygodniej" sprawdzamy size; 

	void push_back(); //odklada element na ostatnie wolne miejsce 
	void insert(int value, unsigned int position);//pozwala wstawic wartosc do wektora na dana pozycje
	void remove();//usuwa element z wektora
	void clear(); //

	int& operator[](unsigned int position); //operator dostepu do danych na podanej pozycji
	Vector& operator=(const Vector&); //to samo co konstruktor kopijacy

};


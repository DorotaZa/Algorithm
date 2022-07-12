#pragma once

class DoublyLinkedList
{
private:
	struct Node //struktura, bo defaultowo public
	{
		int data;
		Node* next; //wskaznik na elementy next i prev, bo dwukierunkowa
		Node* prev;
	};
	Node* _head; //wskazniki poczatkowy i koncowy naszej listy
	Node* _tail;

	
	//DoublyLinkedList(const DoublyLinkedList& other); //zabrania uzycia, bo nie bedziemy wywolywac, bo duzo pamieci zajmuje; przenosimy do private, zeby nikt z dostepem do klasy nie wywolal; zabronienie kompilatorowi kopiowania c-tora w starym c++ (przed 11)
	//DoublyLinkedList& operator=(DoublyLinkedList& other); kopiujacy konstruktor przypisania
public:
	//konstruujemy te elementy zgodnie z rule of 3
	DoublyLinkedList();
	virtual ~DoublyLinkedList();
	DoublyLinkedList(const DoublyLinkedList& other) = delete; // = linijka 16; // linijka 22 to nowszy standard, dlatego lepiej go uzywac

	unsigned int size() const; //policz ilosc elementow
	//bool empty() const; //true, gdy head lub tail wskazuje na nullptr //DOM
	void print() const;

	void insertFront(int value); //wstaw wartosc na poczatku
	void insertBack(int value); //wstaw wartosc na koncu DOM
	void insertAfter(int value, const unsigned int index);//wstaw wartosc w dowolnym miejscu

	//void removeValue(int value); //dom
	//void remove(const unsigned int index); //dom
	void clear();

	int& operator[](const unsigned int index) const; //dostep do danych na danej pozycji w liscie
	DoublyLinkedList& operator=(const DoublyLinkedList& other);

	//praca domowa
	//merge
	//splice //splot

};
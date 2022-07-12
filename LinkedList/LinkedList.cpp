#include "LinkedList.hpp"
#include <iostream>

DoublyLinkedList::DoublyLinkedList() : _tail(nullptr), _head(nullptr) {}

DoublyLinkedList::~DoublyLinkedList()
{
	clear();
}


void DoublyLinkedList::clear()
{
	Node* temp = nullptr;

	while (temp != nullptr)
	{
		temp = _head->next; //z wezla wskazywanego przez ten wskaznik wez nastepny element
		delete _head;
		_head = temp;
	}
	//bez linijki 42 ryzyko, ze tail bedzie wskazywal na pusty element
	_tail = nullptr; //ostatni element tez ma wskazywac na nullptr
}

void DoublyLinkedList::insertFront(int value)
{
	//utworzenie nowego wezla, ustawiamy prev na nullptr poniewaz 1szy elelemnt listy nie ma poprzednika
	Node* newNode = new Node(); //utworzenie tymczasowego elementu
	newNode->data = value; //przypisujemy wartosc
	newNode->prev = nullptr;

	//kopiujemy wksaznik na pierwszy element(ten, na ktory wskazuje _head), robimy to najpierw, zeby nie stracic uchwytu do listy
	newNode->next = _head;

	//ustawiamy wskaznik poczatku listy na nasz 
	_head = newNode;

}

void DoublyLinkedList::insertBack(int value)
{
	Node* newNode = new Node();
	newNode->data = value;
	newNode->next = nullptr;
	newNode->prev = _tail;
	_tail = newNode;
}

void DoublyLinkedList::insertAfter(int value, const unsigned int index)
{
	Node* temp = _head;
	unsigned int currentIndex = 0;

	while (temp != nullptr && currentIndex != index) //przechodzenie przez wszytskie elementy
	{
		++currentIndex;
		temp = temp->next;
	}

	if (temp != nullptr && temp->next != nullptr) //sprawdzenie czy mamy min 2 elementy w liscie, zeby moc wstawic pomiedzy
	{
		Node* newNode = new Node();
		newNode->data = value;

		//Node* nodeAfterNewOne = temp->next; //element ktory znajdduje sie na naszym nowo-wtsawionym elementem
		//nodeAfterNewOne->next = newNode;

		temp->next->prev = newNode; //to zalatwia linijki 61 i 62; ; kolokwialnie - wez element na ktory wksauzje next z temp i uzyj jego wskaznika prev 
		newNode->next = temp->next; //next naszego newNOde'a
		//strzalka(dzida) na starcie kompilatora nam to wyluskuje 
		temp->next = newNode; //element za ktorym wstawiamy ma wskzywac na nowy element
		newNode->prev = temp; //nowy element wskazuje na ten za ktorym sie wstawiamy

		//Tak sie nie robi, ale zostawiam jako pokaz co robi operator ->
		//tmp->next->prev = newNode;
		//(*(*tmp).next).prev = newNode;
		//Node* next = (*tmp).next;
		//next->prev = newNode;
	}
}

//void DoublyLinkedList::remove(const unsigned int index)
//{
//	{
//		Node* tmp = _head;
//		unsigned int currentIndex = 0;
//
//		while (tmp != nullptr && currentIndex != index) //przechodzenie listy - odwiedzanie wszytkich wezłów (ang. traverse)
//		{
//			++currentIndex;
//			tmp = tmp->next;
//		}
//
//		if (tmp->prev == nullptr && tmp->next != nullptr) //usuwamy pierwszy element
//		{
//			_head = tmp->next;
//			tmp->next->prev = nullptr;
//			delete tmp;
//		}
//		else if (tmp->next == nullptr && tmp->prev != nullptr) //usuwamy ostatni element
//		{
//			_tail = tmp->prev;
//			tmp->prev->next = nullptr;
//			delete tmp;
//		}
//		else if (tmp->next != nullptr && tmp->prev != nullptr) //usuwamy jedyny element w liscie
//		{
//			//TUTAJ JEST BLAD GDZIES
//			_head = nullptr;
//			_tail = nullptr;
//			delete tmp;
//		}
//		else //usuwamy element w srodku 
//		{
//			tmp->prev->next = tmp->next;
//			tmp->next->prev = tmp->prev;
//			delete tmp;
//		}
//
//	}
//}


unsigned int DoublyLinkedList::size() const
{
	unsigned int size = 0;
	Node* temp = _head; //alternatywa od tylu _tail

	while (temp != nullptr)
	{
		temp = temp->next; //zamiana next na prev w przypadku uzycia _tail
		++size;
	}
	std::cout << "nullptr";
	return 0;
}

void DoublyLinkedList::print() const
{
	//utworzyc pomocniczy wskaznik, ktory bedzie wskazywal na to co head
	/*Node* tempNode = new Node();
	tempNode = _head;*/

	Node* temp = _head;

	while (temp != nullptr) // przechodzenie przez liste - odwiedzanie wszystkch wezlow (ang. traverse)
	{
		std::cout << temp->data << "<->";
		temp = temp->next;
	}
	std::cout << "nullptr";
}

int& DoublyLinkedList::operator[](const unsigned int index) const
{
	Node* temp = _head;
	unsigned int currentIndex = 0;

	while (temp != nullptr && currentIndex != index)
	{
		++currentIndex;
		temp = temp->next;
	}
	if (temp == nullptr)
	{
		//todo exception21
	}
	return temp->data;
}

DoublyLinkedList& DoublyLinkedList::operator=(const DoublyLinkedList& other)
{
	return *this;
}

#include "Vector.hpp"

Vector::Vector() //pusty wektor
	: _size(0) //to samo co _size = 0; przypisanie wartosci poczatkowej
	, _capacity(0)
	, _data(nullptr) //nullptr, bo data to pole dynamiczne (wskaznik)
{
	//this-> _capacity = 0;
	//this-> _size = 0;
	//this-> _data = nullptr;
}

Vector::Vector(unsigned int capacity) //wektor o podanej capacity
	: _size(0)
	, _capacity(capacity)
{
	_data = new int[_capacity]; //alokacja pamieci!
}

Vector::Vector(const Vector& old)
{
	_capacity = old._capacity;
	_size = old._size;

	_data = new int[_capacity]; //musimy utworzy new dla naszego wektora, bo ktos moze usunac nasz wskaznik
	for (unsigned int i = 0; i < old._size; ++i) //kopiowanie zawartosci z drugiego wektora
	{
		_data[i] = old._data[i];
	}
}

Vector::~Vector()
{
	//usuniecie nullptr jest legalne, ale w rmach dobrych praktyk zapamietujemy, ze jakikolwiek dostep do wskaznika powiniene byc poprzedzony sprawdzeniem czy wskazuje na cokolwiek
	if (_data != nullptr) //warunek sprawdzajacy czy wektor jest pusty
	{
		delete[] _data; //usuwamy tablice, na ktora wskazuje wskaznik _data
		_data = nullptr; //PAMIETAC MEGA WAZNE !!! po usunieciu wskanzika (zwolnieniu pamieci) ustawiamy zawsze nullptr, aby dwa razy nie usunac tej amieci albo zeby przez przypadek nie probowac sie do niej dobrac
	}
	
}

unsigned int Vector::capacity() const
{
	return _capacity;
}

unsigned int Vector::size() const
{
	return _size;
}

bool Vector::empty() const
{
	return _size == 0; //upraszczanie kodu

	/*if (_size == 0) to jest ok ale znaczy "jak prawda to prawda"
	{
		return true;
	}
	else
	{
		return false;
	}*/
}

void Vector::reserve(unsigned int capacity)
{
	//todo::exception if cap=0
	int* data = new int[capacity];
	for (int i = 0; i < _size; ++i)
	{
		data[i] = _data[i];
	}
	_capacity = capacity;
	delete[] _data; //zwolnij stara pamiec
	_data = data; //nsdpisz wskaznik tak, zeby wektor przechowywal juz nowa wieksza
}

void Vector::push_back(const int& value)
{
	if (_size >= _capacity) //jesli potrzeba to zwieksz pamiec
	{
		reserve((_capacity+1) * 2);// alokujemy wiecej pamieci; +1 zabezpiecza przed mnozeniem 0 *
	}
	_data[_size++] = value; //wez rozmiar, zwieksz go i przypsiz do wartosci
}

void Vector::insert(int value, unsigned int index)
{
	if (index > _size)
	{
		//todo exception
	}
	if (_size >= _capacity)
	{
		reserve((_capacity + 1) * 2);
	}
	for (unsigned int i = _size; i > index; --i) //petla robiaca miejsce dla danego elementu w petli
	{
		_data[i] = _data[i-1];
	}
	_data[index] = value;
	++_size;
}

void Vector::clear()
{
	_size = 0;
}

void Vector::remove(unsigned int index)
{
	if (index > _size)
	{
		//todo exception
	}
	for (unsigned int i = index; i < _size; ++i)
	{
		_data[i] = _data[i + 1]; //usuwa index, ale uwzglednia jako pusty element (liczy sie w capacity)
	}
	--_size;
}

void Vector::remove(unsigned int from, unsigned int to)
{
	unsigned int length = to - from;

	for (unsigned int i = from; i < to; ++i)
	{
		_data[i] = _data[i + length]; //zachowuwjemy capacity; TUTAJ MI SIE WYSYPUJE; POWTARZA WARTOSCI LENGTH ON REPEAT
		--_size;
	}
	
}

void Vector::bubble_sort()
{
	int temp;
	bool swapped = false;

	do
	{
		swapped = false;

		for (unsigned int i = 0; i < _size - 1; ++i)
		{

			if (_data[i] > _data[i + 1])
			{
				int temp = _data[i];
				_data[i] = _data[i + 1];
				_data[i + 1] = temp;
				swapped = true;
			}
		}

	} while (swapped); //until true
}

void Vector::pop_back()
{
	for (unsigned int i = _size-1; i < _size; ++i)
	{
		_data[i] = _data[i+1];
	}
	--_size;
}

void Vector::copyTo(Vector& other, unsigned int index)
{
}

int& Vector::operator[](unsigned int index) //
{
	if (index > _size)
	{
		//todo exception
	}
	return _data[index];
}

Vector& Vector::operator=(const Vector& other) //chcemy nadpisac w nowym obiekcie wszystkie wartosci z istniejacego 
{
	return *this; //wyluskanie sie tutaj odbywa na aktualnym obiekcie; wskaznik na obiekt na rzecz ktorego wykonala sie metoda
}

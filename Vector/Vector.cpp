#include "Vector.hpp"

Vector::Vector()
{
}

Vector::Vector(unsigned int _capacity) : capacity(_capacity){}

Vector::Vector(const Vector& old)
{
}

Vector::~Vector()
{
}

void Vector::reserve(unsigned int capacity)
{
}

void Vector::resize(unsigned int size)
{
}

unsigned int Vector::capacity() const
{
	return 0;
}

unsigned int Vector::size() const
{
	return 0;
}

bool Vector::empty() const
{
	return false;
}

void Vector::push_back()
{
}

void Vector::insert(int value, unsigned int position)
{
}

void Vector::remove()
{
}

void Vector::clear()
{
}

int& Vector::operator[](unsigned int position)
{
	// // O: insert return statement here
}

Vector& Vector::operator=(const Vector&)
{
	// // O: insert return statement here
}

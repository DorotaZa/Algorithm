// Vector

#include <iostream>
#include "Vector.hpp"

int main()
{
    Vector vector(10);
    std::cout << "Capacity = " << vector.capacity() << std::endl;
    std::cout << "Size = " << vector.size() << std::endl;
    std::cout << "If empty = " << std::boolalpha << vector.empty() << std::endl;

    vector.push_back(1);
    std::cout << "Capacity = " << vector.capacity() << std::endl;
    std::cout << "Size = " << vector.size() << std::endl;
    std::cout << "If empty = " << std::boolalpha << vector.empty() << std::endl;

    vector.push_back(6);
    vector.push_back(2);
    vector.push_back(11);
    vector.push_back(23);
    vector.push_back(0);
    std::cout << "Capacity = " << vector.capacity() << std::endl;
    std::cout << "Size = " << vector.size() << std::endl;
    std::cout << "If empty = " << std::boolalpha << vector.empty() << std::endl;

    //printing our vector
    for (unsigned int i = 0; i < vector.size(); ++i)
    {
        std::cout << "[" << i << "] = " << vector[i] << std::endl;
    }
    std::cout << "Capacity = " << vector.capacity() << std::endl;
    std::cout << "Size = " << vector.size() << std::endl;
    std::cout << "If empty = " << std::boolalpha << vector.empty() << std::endl;

    std::cout << std::endl;


    //insert
    vector.insert(333, 4);
    std::cout << "Insert function:" << std::endl;
    for (unsigned int i = 0; i < vector.size(); ++i)
    {
        
        std::cout << "[" << i << "] = " << vector[i] << std::endl;
    }
    std::cout << "Capacity = " << vector.capacity() << std::endl;
    std::cout << "Size = " << vector.size() << std::endl;
    std::cout << "If empty = " << std::boolalpha << vector.empty() << std::endl;

    std::cout << std::endl;

    //remove
    vector.remove(0);
    std::cout << "Remove function:" << std::endl;
    for (unsigned int i = 0; i < vector.size(); ++i)
    {
       
        std::cout << "[" << i << "] = " << vector[i] << std::endl;
    }
    std::cout << std::endl;

    //bubble sort
    vector.bubble_sort();
    std::cout << "Bubble_sort function:" << std::endl;
    for (unsigned int i = 0; i < vector.size(); ++i)
    {
        
        std::cout << "[" << i << "] = " << vector[i] << std::endl;
    }
    std::cout << std::endl;

    //remove overloaded
    vector.remove(1, 3);
    std::cout << "Remove overloaded 'from_to' function:" << std::endl;
    for (unsigned int i = 0; i < vector.size(); ++i)
    {
       
        std::cout <<"[" << i << "] = " << vector[i] << std::endl;
    }
    std::cout << "Capacity = " << vector.capacity() << std::endl;
    std::cout << "Size = " << vector.size() << std::endl;
    std::cout << "If empty = " << std::boolalpha << vector.empty() << std::endl;

    std::cout << std::endl;

    std::cout << "Two different ways to display overloaded operator '[]': " << vector[2] << " ; " << vector.operator[](2) << std::endl;

    std::cout << std::endl;

    //pop_back
    vector.pop_back();
    std::cout << "Pop_back function:" << std::endl;
    for (unsigned int i = 0; i < vector.size(); ++i)
    {
        
        std::cout << "[" << i << "] = " << vector[i] << std::endl;
    }
    std::cout << std::endl;

    
}
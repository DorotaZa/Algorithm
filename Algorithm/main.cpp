// Minimum

#include <iostream>

void readValues(int* arr, const unsigned int size)
{
    for (int i = 0; i < size; ++i)
    {
        std::cout << "Enter "  << i << " number: ";
        std::cin >> arr[i];
    }
}


int minNumber(int* arr, const unsigned int size)
{
    int min = 0;

    if (size > 0 && arr != nullptr)
    {
        min = arr[0];
        int i = 1;
        while (i<size-1)
        {
            if (arr[i] < min)
            {
                min = arr[i];
            }
            ++i;
        }
    }
    return min;

}

int main()
{
    unsigned int count = 0;
    std::cout << "Enter the amount of numbers:  " << std::endl;
    std::cin >> count;

    if (count > 0)
    {
        int* arr = new int [count];
        readValues(arr, count);
        int min = minNumber(arr, count);
        std::cout << "The minimum number you put is: " << min << std::endl;

        delete[] arr;
    }
}


// 
//int main()
//{
//
//    const int size = 10;
//    int numbers[size] = {};
//    int num = 0;
//    int min = 0;
//    for (int i = 1; i < size; ++i)
//    {
//        std::cout << "Enter the number: " << std::endl;
//        std::cin >> num;
//        if (numbers[i] < min)
//        {
//            min = numbers[i];
//        }
//    }
//    std::cout << "Min number is: " << min;
//
//}
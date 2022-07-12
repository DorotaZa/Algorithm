// BubbleSort 

#include <iostream>

void bubbleSort1(int* tab, const unsigned int size)
{
    int temp;
    bool swapped = false;

    do
    {
        swapped = false;

        for (unsigned int i = 0; i < size - 1; ++i)
        {
            for (unsigned int j = 0; j < size - 1 - i; ++j)
            {
                if (tab[j] > tab[j + 1])
                {
                    int temp = tab[j];
                    tab[j] = tab[j + 1];
                    tab[j + 1] = temp;
                    swapped = true;
                }
            }
            
        }

    } while (swapped); //until true
}


void bubbleSort2(int* tab, const unsigned int size)
{
    int temp;
    bool swapped = false;

    do
    {
        swapped = false;

        for (unsigned int i = 0; i < size - 1; ++i)
        {
            if (tab[i] > tab[i + 1])
            {
                int temp = tab[i];
                tab[i] = tab[i + 1];
                tab[i + 1] = temp;
                swapped = true;
            }
        }

    } while (swapped); //until true
}

int main()
{
    const int size = 10;
    int tab[size] = { 8,3,5,0,2,9,1,7,6,4 }; //spr rand tutaj

    for (int i = 0; i < size; ++i)
    {
        std::cout << "[" << i << "]" << tab[i] << std::endl;
    }
    std::cout << std::endl;

    bubbleSort1(tab, size);

    for (int i = 0; i < size; ++i)
    {
        std::cout << "[" << i << "]= " << tab[i] << std::endl;
    }
    std::cout << std::endl;

    const int size2 = 10;
    int tab2[size] = { 8,3,5,0,2,9,1,7,6,4 }; //spr rand tutaj

    for (int i = 0; i < size; ++i)
    {
        std::cout << "[" << i << "]" << tab2[i] << std::endl;
    }
    std::cout << std::endl;

    bubbleSort2(tab2, size2);

    for (int i = 0; i < size; ++i)
    {
        std::cout << "[" << i << "]= " << tab[i] << std::endl;
    }
    std::cout << std::endl;


}
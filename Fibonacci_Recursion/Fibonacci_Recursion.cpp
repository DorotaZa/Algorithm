// Fibonacci_Recursion


#include <iostream>

class Fibonacci
{

public:
    int generate(int n)
    {
        if (n <= 2)
        {
            return 1;
        }
        else
        {
            return generate(n - 2) + generate(n - 1);
        }
    }
};

class FibonacciLoop
{
private:
    int sum = 0;
    int a = 0;
    int b = 1;

public:
    int generateLoop(int n)
    {
        for (int i = 1; i <= n; ++i) 
        {
            if (i == 1)
            {
               // std::cout << a << ", ";
            }
            else if (i == 2)
            {
               // std::cout << b << ", ";
            }
            else
            {
                sum = a + b;
                a = b;
                b = sum;

                std::cout << sum << ", ";
            }
           
        }
        return sum;
    }
};



int main()
{
    /*Fibonacci fib;
    std::cout << fib.generate(5) << std::endl;*/

    FibonacciLoop fibLoop;
    std::cout << fibLoop.generateLoop(5) << std::endl;

}

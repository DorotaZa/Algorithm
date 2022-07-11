// Fibonacci_Recursion


#include <iostream>

class Fibonacci 
{

public:
    int generate(int n) //funkcja rekurencyjna
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
    int a = 0;
    int b = 1;
    int sum;
    
public:
    int generateLoop(int n)
    {
        for (int i = 1; i <= n; ++i) 
        {
            if (i == 1)
            {
               std::cout << a << ", ";
            }
            else if (i == 2)
            {
               std::cout << b << ", ";
            }
            else
            {
                sum = a + b;
                std::cout << a << "-> " << sum <<std::endl;
                a = b;
                b = sum;

               //std::cout << sum << ", ";
            //}
           
        }
        
           /* while ( n >= a)
            {
                sum = a + b;
                std::cout << "Number " << a << " = " << sum << std::endl;
                a = b;
                b = sum;
            }*/

            return sum;
    }
};


void fibonacci(int n)
{
    int a = 0;
    int b = 1;
    int s;

    while (n >= a)
    {
        s = a + b;
        std::cout << a << "->" << s<< std::endl;
        a = b;
        b = s;
    }
}



int main()
{
    /* Fibonacci fib;
    std::cout << fib.generate(5) << std::endl;*/

    FibonacciLoop fibLoop;
    std::cout << fibLoop.generateLoop(5);
    fibonacci(5);
}
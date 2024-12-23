#include <iostream>
#include "Array.hpp"
#include <ctime>

#define MAX_VAL 750
int main(int, char**)
{
    Array<int> numbers(MAX_VAL);
    int* mirror = new int[MAX_VAL];
    srand(time(NULL));
    for (int i = 0; i < MAX_VAL; i++)
    {
        const int value = rand();
        numbers[i] = value;
        mirror[i] = value;
    }
    std::cout << "Array (numbers): " << numbers << std::endl;
    //SCOPE
    {
        Array<int> tmp = numbers;
        Array<int> test(tmp);
        std::cout << "Temporary array (tmp): " << tmp << std::endl;
        std::cout << "Copied array (test): " << test << std::endl;
    }

    for (int i = 0; i < MAX_VAL; i++)
    {
        if (mirror[i] != numbers[i])
        {
            std::cerr << "didn't save the same value!!" << std::endl;
            return 1;
        }
    }
    try
    {
        numbers[-2] = 0;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    try
    {
        numbers[MAX_VAL] = 0;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }

    try
    {
        numbers[MAX_VAL - 1] = 0;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    std::cout << "Array (numbers) with modified 0 to an end: " << numbers << std::endl;
    for (int i = 0; i < MAX_VAL; i++)
    {
        numbers[i] = rand();
    }
    std::cout << "Modified array (numbers): " << numbers << std::endl;
    delete [] mirror;
    return 0;
}
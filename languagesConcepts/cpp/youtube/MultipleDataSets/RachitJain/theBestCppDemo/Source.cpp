#include <iostream>
#include <vector>

int main()
{
    // Declaring a vector
    std::vector<int> v = { 1, 2, 3 };

    // Declaring an iterator
    std::vector<int>::iterator i;

    int j;

    std::cout << "Without iterators = ";

    // Accessing the elements without using iterators
    for (j = 0; j < 3; ++j)
    {
        std::cout << v[j] << " ";
    }

    std::cout << "\nWith iterators = ";

    // Accessing the elements using iterators
    for (i = v.begin(); i != v.end(); ++i)
    {
        std::cout << *i << " ";
    }

    // Adding one more element to vector
    v.push_back(4);

    std::cout << "\nWithout iterators = ";

    // Accessing the elements without using iterators
    for (j = 0; j < 4; ++j)
    {
        std::cout << v[j] << " ";
    }

    std::cout << "\nWith iterators = ";

    // Accessing the elements using iterators
    for (i = v.begin(); i != v.end(); ++i)
    {
        std::cout << *i << " ";
    }

	return 0;
}
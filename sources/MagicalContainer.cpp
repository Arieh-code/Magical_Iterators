#include "MagicalContainer.hpp"

using namespace ariel;
using namespace std;

bool MagicalContainer::in(int number)
{
    return std::find(elements.begin(), elements.end(), number) != elements.end();
}

MagicalContainer::addElement(int number)
{
    element.push_back(number);
    std::sort(elements.begin(), elements.end);
    primeNumberVector.clear();
    for (int &num : elements)
    {
        if (isPrime(num))
        {
            int *ptr = new int(num);
            primeNumberVector.push_back(ptr);
        }
    }
}

bool MagicalContainer::isPrime(int number)
{
    if (number < 2)
    {
        return false;
    }
    for (int i = 2; i <= sqrt(number); i++)
    {
        if (number % i == 0)
        {
            return false;
        }
    }
    return true;
}

MagicalContainer::removeElement(int number)
{
    if (!in(element))
    {
        throw std::runtime_error("Element not found in container");
    }
    // remove all occurrences of the desired number
    elements.erase(std::remove(elements.begin(), elements.end(), element), elements.end());
    // check if the number was prime.
    if (isPrime(number))
    {
        // find the position of the element in the prime pointer number vector
        auto it = std::find(primeNumberVector.begin(), primeNumberVector.end(), &number);
        if (it != primeNumberVector.end())
        {
            primeNumberVector.erase(it);
        }
    }
}

size_t MagicalContainer::size() const
{
    // return the size of the container
    return elements.size();
}

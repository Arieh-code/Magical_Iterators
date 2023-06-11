#include "MagicalContainer.hpp"

using namespace ariel;
using namespace std;

bool MagicalContainer::in(int number) const
{
    return std::find(elements.begin(), elements.end(), number) != elements.end();
}

void MagicalContainer::addElement(int number)
{
    elements.push_back(number);
    std::sort(elements.begin(), elements.end());
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

void MagicalContainer::removeElement(int number)
{
    if (!in(number))
    {
        throw std::runtime_error("Element not found in container");
    }
    // remove all occurrences of the desired number
    elements.erase(std::remove(elements.begin(), elements.end(), number), elements.end());
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

// ************************** Ascending Iterator implementation ************************
// default constructor
MagicalContainer::AscendingIterator::AscendingIterator(MagicalContainer &container)
    : index(0),
      container(container)
{
}

// copy constructor
MagicalContainer::AscendingIterator::AscendingIterator(const AscendingIterator &other)
    : index(other.index), container(other.container)
{
}

// Assignment operator
MagicalContainer::AscendingIterator &MagicalContainer::AscendingIterator::operator=(const AscendingIterator &other)
{
    // first check if the iterators are of the same type.
    if (&container != &other.container)
    {
        throw std::runtime_error("Can't assign to a different Iterator");
    }
    container = other.container;
    index = other.index;
    return *this;
}

// bool operands

bool MagicalContainer::AscendingIterator::operator==(const AscendingIterator &other) const
{
    return index == other.index;
}

bool MagicalContainer::AscendingIterator::operator!=(const AscendingIterator &other) const
{
    return index != other.index;
}

bool MagicalContainer::AscendingIterator::operator<(const AscendingIterator &other) const
{
    return index < other.index;
}

bool MagicalContainer::AscendingIterator::operator>(const AscendingIterator &other) const
{
    return index > other.index;
}

int MagicalContainer::AscendingIterator::operator*() const
{
    return container.elements[index];
}

MagicalContainer::AscendingIterator &MagicalContainer::AscendingIterator::operator++()
{
    // check that index is not out of bounds
    if (index > container.size() - 1)
    {
        throw std::runtime_error("interator is out of bounds");
    }
    ++index;
    return *this;
}

MagicalContainer::AscendingIterator MagicalContainer::AscendingIterator::begin()
{
    // return a new iterator pointing to the beginning of the container
    return AscendingIterator(container);
}

MagicalContainer::AscendingIterator MagicalContainer::AscendingIterator::end()
{
    // Create a new iterator pointing to the end of the container
    AscendingIterator it(container);
    // Set the index to the end position by using the container's size
    it.index = container.size();
    return it;
}

// adding code to satisfy tidy requirements
// Move constructor
MagicalContainer::AscendingIterator::AscendingIterator(AscendingIterator &&other) noexcept
    : container(other.container), index(other.index)
{
    other.index = 0;
}

// adding code to satisfy tidy requirements
// Move assignment operator
MagicalContainer::AscendingIterator &MagicalContainer::AscendingIterator::operator=(AscendingIterator &&other) noexcept
{
    container = other.container;
    index = other.index;
    return *this;
}


// *********************** SideCross Iterator ***********************
// default constructor
MagicalContainer::SideCrossIterator::SideCrossIterator(MagicalContainer &container)
: container(container), frontIndex(0), backIndex(container.size()-1), AtFront(true)
{

}

// copy constructor


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
            int *ptr = &num;
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
    : container(container), frontIndex(0), backIndex(container.size() - 1), AtFront(true)
{
}

// copy constructor
MagicalContainer::SideCrossIterator::SideCrossIterator(const SideCrossIterator &other)
    : container(other.container), frontIndex(other.frontIndex), backIndex(other.backIndex), AtFront(other.AtFront)
{
}

MagicalContainer::SideCrossIterator &MagicalContainer::SideCrossIterator::operator=(const SideCrossIterator &other)
{
    // check if the iterator are the same type
    if (&container != &other.container)
    {
        throw std::runtime_error("Can't assign to a different iterator");
    }
    container = other.container;
    frontIndex = other.frontIndex;
    backIndex = other.backIndex;
    AtFront = other.AtFront;

    return *this;
}

bool MagicalContainer::SideCrossIterator::operator==(const SideCrossIterator &other) const
{
    // check that both front and back indexes are pointing to the same index
    return frontIndex == other.frontIndex && backIndex == other.backIndex;
}

bool MagicalContainer::SideCrossIterator::operator!=(const SideCrossIterator &other) const
{
    // using the == operator to check that they are not equal
    return !(*this == other);
}

bool MagicalContainer::SideCrossIterator::operator>(const SideCrossIterator &other) const
{
    // checking all options of the indexes
    return ((frontIndex > other.frontIndex && backIndex > other.backIndex) || (frontIndex > other.frontIndex && other.AtFront) || (AtFront && backIndex > other.backIndex));
}

bool MagicalContainer::SideCrossIterator::operator<(const SideCrossIterator &other) const
{
    // using already implemented code check that is isn't bigger and not equal there fore smaller
    return (!(*this > other) && (*this != other));
}

int MagicalContainer::SideCrossIterator::operator*() const
{
    // if I am in front return the front index else return the back index
    if (AtFront)
    {
        return container.elements[frontIndex];
    }
    else
    {
        return container.elements[backIndex];
    }
}

MagicalContainer::SideCrossIterator &MagicalContainer::SideCrossIterator::operator++()
{
    // check both cases of even and odd lengths of container
    if ((container.size() % 2 == 0 && frontIndex == container.size() / 2 && backIndex == container.size() / 2 - 1) || container.size() % 2 == 1 && frontIndex == container.size() / 2 + 1 && backIndex == container.size() / 2)
    {
        throw std::runtime_error("interator is out of bounds");
    }
    // if we are in bounds check if we are at front of back.
    if (AtFront)
    {
        ++frontIndex;
    }
    else
    {
        --backIndex;
    }
    // change state of AtFront
    AtFront = !AtFront;
    return *this;
}

MagicalContainer::SideCrossIterator MagicalContainer::SideCrossIterator::begin()
{
    // return iterator with container
    return SideCrossIterator(container);
}

MagicalContainer::SideCrossIterator MagicalContainer::SideCrossIterator::end()
{
    // create new container and set indexes at the end.
    SideCrossIterator it(container);
    if (container.size() % 2 == 0)
    {
        it.frontIndex = container.size() / 2;
        it.backIndex = container.size() / 2 - 1;
    }
    else
    {
        it.frontIndex = container.size() / 2 + 1;
        it.backIndex = container.size() / 2;
    }
    return it;
}

// implementing move copy to make tidy happy
MagicalContainer::SideCrossIterator::SideCrossIterator(SideCrossIterator &&other) noexcept
    : container(other.container), frontIndex(other.frontIndex), backIndex(other.backIndex), AtFront(other.AtFront)
{
    other.frontIndex = 0;
    other.backIndex = 0;
}

MagicalContainer::SideCrossIterator &MagicalContainer::SideCrossIterator::operator=(SideCrossIterator &&other) noexcept
{
    container = other.container;
    frontIndex = other.frontIndex;
    backIndex = other.backIndex;
    AtFront = other.AtFront;
    return *this;
}

// ************************************* PrimeIterator ***************************
// default constructor
MagicalContainer::PrimeIterator::PrimeIterator(MagicalContainer &container)
    : container(container), index(0)
{
}

// copy constructor

MagicalContainer::PrimeIterator::PrimeIterator(const PrimeIterator &other)
    : container(other.container), index(other.index)
{
}

// assignment operator
MagicalContainer::PrimeIterator &MagicalContainer::PrimeIterator::operator=(const PrimeIterator &other)
{
    if (&container != &other.container)
    {
        throw std::runtime_error("Can't assign to a different Iterator");
    }
    container = other.container;
    index = other.index;
    return *this;
}

// boolean operator

bool MagicalContainer::PrimeIterator::operator==(const PrimeIterator &other) const
{
    return (index == other.index);
}

bool MagicalContainer::PrimeIterator::operator!=(const PrimeIterator &other) const
{
    return !(*this == other);
}

bool MagicalContainer::PrimeIterator::operator<(const PrimeIterator &other) const
{
    return (index < other.index);
}

bool MagicalContainer::PrimeIterator::operator>(const PrimeIterator &other) const
{
    return (!(index < other.index) && (index != other.index));
}

// dereference operator
int MagicalContainer::PrimeIterator::operator*() const
{
    return *container.primeNumberVector[index];
}

MagicalContainer::PrimeIterator &MagicalContainer::PrimeIterator::operator++()
{
    // check if we are in bounds
    if (index == container.primeNumberVector.size())
    {
        throw std::runtime_error("Iterator out of bounds");
    }
    ++index;
    return *this;
}

MagicalContainer::PrimeIterator MagicalContainer::PrimeIterator::begin()
{
    // return a new iterator pointing to the beginning of the container
    return PrimeIterator(container);
}

MagicalContainer::PrimeIterator MagicalContainer::PrimeIterator::end()
{
    // return a new iterator pointing to the end of the container
    PrimeIterator it(container);
    it.index = container.primeNumberVector.size();
    return it;
}

#include "MagicalContainer.hpp"
#include <cmath>
#include <algorithm>
#include <iostream>

using namespace ariel;

   MagicalContainer::MagicalContainer() : elements_vector(std::vector<int>{}) {
}
    void MagicalContainer::assignedTo(bool b)
    {
        
    }

    // Core function - add, remove and size
    void MagicalContainer::addElement(int element)
    {
        
    }

    void MagicalContainer::removeElement(int element)
    {
       
    }

    size_t MagicalContainer::size() const
    {
        return 0;
    }

    // Constructors
    ariel::MagicalContainer::AscendingIterator::AscendingIterator()
        : iterator_container(), currentIndex(0) {}

    MagicalContainer::AscendingIterator::AscendingIterator(MagicalContainer &container)
        : iterator_container(), currentIndex(0)
    {
        sortAscending();
    }

    MagicalContainer::AscendingIterator::AscendingIterator(MagicalContainer &container, size_t currentIndex)
        : iterator_container(), currentIndex() {}

    MagicalContainer::AscendingIterator::AscendingIterator(const AscendingIterator &other)
        : iterator_container(), currentIndex() {}

    // Destructor
    MagicalContainer::AscendingIterator::~AscendingIterator() {}

    void MagicalContainer::AscendingIterator::sortAscending()
    {
        
    }

    MagicalContainer::AscendingIterator &ariel::MagicalContainer::AscendingIterator::operator=(const AscendingIterator &other)
     {
        return *this;
    }

    MagicalContainer::AscendingIterator &MagicalContainer::AscendingIterator::operator++()
    {
        return *this;
    }
    int MagicalContainer::AscendingIterator::operator*() const
    {
        return 0;
    }

    bool MagicalContainer::AscendingIterator::operator==(const AscendingIterator &other) const
    {
        return false;
    }

    bool MagicalContainer::AscendingIterator::operator!=(const AscendingIterator &other) const
    {
        return false;
    }

    bool MagicalContainer::AscendingIterator::operator>(const AscendingIterator &other) const
    {
        return false;
    }

    bool MagicalContainer::AscendingIterator::operator<(const AscendingIterator &other) const
    {
        return false;
    }

    MagicalContainer::AscendingIterator MagicalContainer::AscendingIterator::begin()
    {
        return AscendingIterator();
    }

    MagicalContainer::AscendingIterator MagicalContainer::AscendingIterator::end()
    {
        return AscendingIterator();
    }
   
    // Constructors
    MagicalContainer::SideCrossIterator::SideCrossIterator()
        : iterator_container(*(new MagicalContainer())), startIndex(0), endIndex(0), isAtFront(true) {}

  MagicalContainer::SideCrossIterator::SideCrossIterator(MagicalContainer &container)
    : iterator_container(*new MagicalContainer())
{
    
}


    MagicalContainer::SideCrossIterator::SideCrossIterator(const SideCrossIterator &other)
        : iterator_container(other.iterator_container),
          startIndex(other.startIndex),
          endIndex(other.endIndex),
          isAtFront(other.isAtFront) {}
    // Destructor
    MagicalContainer::SideCrossIterator::~SideCrossIterator() {}

    void MagicalContainer::SideCrossIterator::arrangeSideCross(MagicalContainer &container)
    {
       
    }

    MagicalContainer::SideCrossIterator &ariel::MagicalContainer::SideCrossIterator::operator=(const SideCrossIterator &other)
    {
       
        return *this;
    }
    MagicalContainer::SideCrossIterator::SideCrossIterator(MagicalContainer &container, size_t startIndex, size_t endIndex, bool isFront)
        : iterator_container(container), startIndex(startIndex), endIndex(endIndex), isAtFront(isFront) {}

    int MagicalContainer::SideCrossIterator::operator*() const
    {
        return 0;
    }

    MagicalContainer::SideCrossIterator &MagicalContainer::SideCrossIterator::operator++()
    {
        return *this;
    }

    bool MagicalContainer::SideCrossIterator::operator==(const SideCrossIterator &other) const
    {
        return false;
    }

    bool MagicalContainer::SideCrossIterator::operator!=(const SideCrossIterator &other) const
    {
        return false;
    }

    bool MagicalContainer::SideCrossIterator::operator>(const SideCrossIterator &other) const
    {
        return false;
    }

    bool MagicalContainer::SideCrossIterator::operator<(const SideCrossIterator &other) const
    {
        return false;
    }

    MagicalContainer::SideCrossIterator MagicalContainer::SideCrossIterator::begin()
    {
        return SideCrossIterator();
    }

    MagicalContainer::SideCrossIterator MagicalContainer::SideCrossIterator::end()
    {
        return SideCrossIterator();
    }

    
    // Constructors
    MagicalContainer::PrimeIterator::PrimeIterator()
        : iterator_container(*(new MagicalContainer())), currentIndex(0) {}

    MagicalContainer::PrimeIterator::PrimeIterator(const MagicalContainer &container, size_t currentIndex)
        : iterator_container(container), currentIndex(currentIndex) {}

    MagicalContainer::PrimeIterator::PrimeIterator(const PrimeIterator &other)
        : iterator_container(other.iterator_container),
          currentIndex(other.currentIndex) {}

    MagicalContainer::PrimeIterator &ariel::MagicalContainer::PrimeIterator::operator=(const PrimeIterator &other)
    {
        return *this;
    }

    MagicalContainer::PrimeIterator::PrimeIterator(const MagicalContainer &container)
        : iterator_container(container) {
           
        }

    // Destructor
    MagicalContainer::PrimeIterator::~PrimeIterator() {}

    bool MagicalContainer::PrimeIterator::isPrime(int number) const
    {
        return false;
    }

    int MagicalContainer::PrimeIterator::operator*() const
    {
        
        return 0;
    }

    MagicalContainer::PrimeIterator &MagicalContainer::PrimeIterator::operator++()
    {
         return *this;
    }

    bool MagicalContainer::PrimeIterator::operator==(const PrimeIterator &other) const
    {
        return false;
    }

    bool MagicalContainer::PrimeIterator::operator!=(const PrimeIterator &other) const
    {
        return false;
    }

    bool MagicalContainer::PrimeIterator::operator>(const PrimeIterator &other) const
    {
        return false;
    }

    bool MagicalContainer::PrimeIterator::operator<(const PrimeIterator &other) const
    {
        return false;
    }

    MagicalContainer::PrimeIterator MagicalContainer::PrimeIterator::begin()
    {
        return PrimeIterator();
    }

    MagicalContainer::PrimeIterator MagicalContainer::PrimeIterator::end()
    {
        return PrimeIterator();
    }

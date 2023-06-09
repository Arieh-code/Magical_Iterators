#pragma once
#include <vector>
namespace ariel
{
    class MagicalContainer
    {
    private:
        // element vector
        std::vector<int> elements;
        // prime numbers pointer to element vector
        std::vector<int*> primeNumberVector;

    public:
        // check if the element is already in the container
        bool in(int number) const;
        // add a new element to the container
        void addElement(int element);
        // remove the element from the container
        void removeElement(int element);
        // check the size of the container
        size_t size() const;

        class AscendingIterator
        {
        private:
            MagicalContainer &container;
            size_t index;

        public:
            // constructor
            AscendingIterator(MagicalContainer &container);
            // copy constructor
            AscendingIterator(AscendingIterator &other);
            // destructor
            ~AscendingIterator() = default;
            // assignment operator
            AscendingIterator &operator=(const AscendingIterator &other);

            // bool operands
            bool operator==(const AscendingIterator &other) const;

            bool operator!=(const AscendingIterator &other) const;

            bool operator<(const AscendingIterator &other) const;

            bool operator>(const AscendingIterator &other) const;

            int operator*() const;

            // pre-increment operator 
            AscendingIterator& operator++();

            AscendingIterator begin();

            AscendingIterator end();

        };

        class SideCrossIterator{
            private:
                MagicalContainer &container;
                size_t frontIndex;
                size_t backIndex;
                bool AtFront;
            
            public:
                // default constructor
                SideCrossIterator(MagicalContainer &container);
                // copy constructor
                SideCrossIterator(SideCrossIterator& other);
                // destructor
                ~SideCrossIterator() = default;
                // assignment operator
                SideCrossIterator& operator=(const SideCrossIterator& other);
                // bool operators
                bool operator==(const SideCrossIterator& other) const;

                bool operator!=(const SideCrossIterator& other) const;

                bool operator>(const SideCrossIterator& other) const;
                
                bool operator<(const SideCrossIterator& other) const;

                int operator*() const;

                SideCrossIterator& operator++();

                SideCrossIterator begin();
            
                SideCrossIterator end();
        };

        class PrimeIterator{
            private:
                MagicalContainer &container;
                size_t index;
            public:
                // is prime function 
                static bool isPrime(int number);
                // default constructor
                PrimeIterator(MagicalContainer &container);
                // copy constructor
                PrimeIterator(PrimeIterator& other);
                // destructor
                ~PrimeIterator() = default;
                // assignment operator
                PrimeIterator& operator=(const PrimeIterator& other);
                // bool operands
                bool operator==(const PrimeIterator& other) const;

                bool operator!=(const PrimeIterator& other) const;
                
                bool operator<(const PrimeIterator& other) const;

                bool operator>(const PrimeIterator& other) const;

                // dereference operator
                int operator*() const;

                PrimeIterator& operator++();

                PrimeIterator being();

                PrimeIterator end();
        };
    };

}

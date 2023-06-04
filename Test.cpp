#include "doctest.h"
#include "MagicalContainer.hpp"
#include <chrono>
#include <iostream>

using namespace ariel;
using namespace std;

TEST_SUITE("Test 1 - container checks")
{
    MagicalContainer mc;

    TEST_CASE("Ascending Iterator")
    {
        MagicalContainer mc;
        mc.addElement(5);
        mc.addElement(2);
        mc.addElement(7);
        mc.addElement(1);

        MagicalContainer::AscendingIterator ascIter(mc);
        auto it = ascIter.begin();

        CHECK(*it == 1);
        ++it;
        CHECK(*it == 2);
        ++it;
        CHECK(*it == 5);
        ++it;
        CHECK(*it == 7);
        ++it;
        CHECK(it == ascIter.end());
    }

    TEST_CASE("Side Cross Iterator")
    {
        MagicalContainer mc;
        mc.addElement(5);
        mc.addElement(2);
        mc.addElement(7);
        mc.addElement(1);

        MagicalContainer::SideCrossIterator crossIter(mc);
        auto it = crossIter.begin();

        CHECK(*it == 5);
        ++it;
        CHECK(*it == 1);
        ++it;
        CHECK(*it == 2);
        ++it;
        CHECK(*it == 7);
        ++it;
        CHECK(it == crossIter.end());
    }

        TEST_CASE("Prime Iterator")
    {
        MagicalContainer mc;
        mc.addElement(5);
        mc.addElement(2);
        mc.addElement(7);
        mc.addElement(1);
        mc.addElement(3);
        mc.addElement(11);

        MagicalContainer::PrimeIterator primeIter(mc);
        auto it = primeIter.begin();

        CHECK(*it == 2);
        ++it;
        CHECK(*it == 3);
        ++it;
        CHECK(*it == 5);
        ++it;
        CHECK(*it == 7);
        ++it;
        CHECK(*it == 11);
        ++it;
        CHECK(it == primeIter.end());
    }


    TEST_CASE("One element only in the container")
    {
        MagicalContainer mc;
        mc.addElement(2);
        MagicalContainer::AscendingIterator ascIter(mc);
        for (auto it = ascIter.begin(); it != ascIter.end(); ++it)
        {
            CHECK((*it) == 2);
        }
    }

    TEST_CASE("Changing container and iterator check")
    {
        MagicalContainer mc;
        mc.addElement(1);
        MagicalContainer::AscendingIterator ascIter(mc);
        for (auto it = ascIter.begin(); it != ascIter.end(); ++it)
        {
            CHECK((*it) == 1);
        }
        mc.removeElement(1);
        CHECK(mc.size() == 0);
        CHECK_THROWS(ascIter.begin());
        mc.addElement(2);
        CHECK(mc.size() == 1);
        for (auto it = ascIter.begin(); it != ascIter.end(); ++it)
        {
            CHECK((*it) == 2);
        }
    }


TEST_CASE("Removing non-existent elements from container")
{
    MagicalContainer mc;
    mc.addElement(1);
    mc.addElement(2);
    mc.addElement(3);
    mc.removeElement(4);   // Trying to remove an element that doesn't exist
    CHECK(mc.size() == 3); // Size should remain unchanged
}

TEST_CASE("Iterating over an empty container")
{
    MagicalContainer mc;
    MagicalContainer::AscendingIterator ascIter(mc);
    CHECK(ascIter.begin() == ascIter.end()); // Iterator range should be empty
}

TEST_CASE("Iterating over a container with duplicate elements")
{
    MagicalContainer mc;
    mc.addElement(1);
    mc.addElement(2);
    mc.addElement(1);
    mc.addElement(3);
    mc.addElement(2);
    mc.addElement(1);
    MagicalContainer::AscendingIterator ascIter(mc);
    vector<int> expectedValues = {1, 1, 1, 2, 2, 3};
    size_t index = 0;
    for (auto it = ascIter.begin(); it != ascIter.end(); ++it)
    {
        CHECK((*it) == expectedValues[index]);
        index++;
    }
}

TEST_CASE("Removing elements during iteration")
{
    MagicalContainer mc;
    mc.addElement(1);
    mc.addElement(2);
    mc.addElement(3);
    mc.addElement(4);
    mc.addElement(5);
    MagicalContainer::AscendingIterator ascIter(mc);
    auto it = ascIter.begin();
    mc.removeElement(2);
    CHECK((*it) == 1); // Iterator should still point to the first element
    ++it;
    CHECK((*it) == 3); // Second element should be skipped due to removal
}

TEST_CASE("Stress Test - Adding a large number of elements")
{
    MagicalContainer mc;
    const int numElements = 1000;
    for (int i = 1; i <= numElements; ++i)
    {
        mc.addElement(i);
        CHECK(mc.size() == i);
    }
}

TEST_CASE("Stress Test - Removing elements from a large container")
{
    MagicalContainer mc;
    const int numElements = 1000;
    for (int i = 1; i <= numElements; ++i)
    {
        mc.addElement(i);
    }
    for (int i = numElements; i >= 1; --i)
    {
        mc.removeElement(i);
        CHECK(mc.size() == (i - 1));
    }
}

TEST_CASE("Performance Test - Iterating over a large container")
{
    MagicalContainer mc;
    const int numElements = 1000;
    for (int i = 1; i <= numElements; ++i)
    {
        mc.addElement(i);
    }
    MagicalContainer::AscendingIterator ascIter(mc);

    auto startTime = chrono::steady_clock::now();

    int count = 0;
    for (auto it = ascIter.begin(); it != ascIter.end(); ++it)
    {
        ++count;
    }

    auto endTime = chrono::steady_clock::now();
    auto duration = chrono::duration_cast<chrono::milliseconds>(endTime - startTime).count();

    CHECK(count == numElements);
    cout << "Time taken for iteration: " << duration << " milliseconds." << endl;
}

}
#include <stdexcept>

#include "doctest.h"
#include "sources/MagicalContainer.hpp"

using namespace ariel;

TEST_CASE("MagicalContainer Tests") {
    SUBCASE("Adding Elements") {
        MagicalContainer container;

        SUBCASE("Adding one element") {
            CHECK(container.size() == 0);
            container.addElement(1);
            CHECK(container.size() == 1);
        }

        SUBCASE("Adding more than one element") {
            container.addElement(1);
            container.addElement(-1);
            container.addElement(2);

            CHECK(container.size() == 3);
        }
    }

    SUBCASE("Remove Elements") {
        MagicalContainer container;

        container.addElement(1);
        container.addElement(-1);
        container.addElement(2);

        SUBCASE("Remove first element") {
            container.removeElement(1);
            CHECK(container.size() == 2);
        }

        SUBCASE("Remove element not in boundaries") {
            container.removeElement(-1);
            CHECK(container.size() == 2);
        }

        SUBCASE("Remove last element") {
            container.removeElement(2);
            CHECK(container.size() == 2);
        }

        SUBCASE("Remove all elements") {
            container.removeElement(2);
            container.removeElement(1);
            container.removeElement(-1);
            CHECK(container.size() == 0);
        }
    }
}

TEST_CASE("AscendingIterator Tests") {
    MagicalContainer container;

    SUBCASE("Iterator with no elements test") {
        MagicalContainer::AscendingIterator iter(container);
        CHECK(iter == iter.end());
    }

    SUBCASE("Iterator with one element test") {
        container.addElement(1);

        MagicalContainer::AscendingIterator iter(container);
        CHECK(*iter == 1);
        ++iter;
        CHECK(iter == iter.end());
    }

    SUBCASE("Iterator with elements test") {
        container.addElement(1);
        container.addElement(5);
        container.addElement(10);
        container.addElement(2);
        container.addElement(7);

        MagicalContainer::AscendingIterator iter(container);

        std::vector<int> expected_order = {1, 2, 5, 7, 10};
        std::size_t index = 0;

        for (auto it = iter.begin(); it != iter.end(); ++it) {
            CHECK(*it == expected_order[index]);
            index++;
        }
    }
}

TEST_CASE("SideCrossIterator Tests") {
    MagicalContainer container;

    SUBCASE("Iterator with no elements test") {
        MagicalContainer::SideCrossIterator iter(container);
        CHECK(iter == iter.end());
    }

    SUBCASE("Iterator with one element test") {
        container.addElement(1);

        MagicalContainer::SideCrossIterator iter(container);
        CHECK(*iter == 1);
        ++iter;
        CHECK(iter == iter.end());
    }

    SUBCASE("Iterator with elements test") {
        container.addElement(1);
        container.addElement(5);
        container.addElement(10);
        container.addElement(2);
        container.addElement(7);

        MagicalContainer::SideCrossIterator iter(container);

        std::vector<int> expected_order = {1, 8, 5, 2, 10};
        std::size_t index = 0;

        for (auto it = iter.begin(); it != iter.end(); ++it) {
            CHECK(*it == expected_order[index]);
            index++;
        }
    }
}

TEST_CASE("PrimeIterator Tests") {
    MagicalContainer container;

    SUBCASE("Iterator with no elements test") {
        MagicalContainer::PrimeIterator iter(container);
        CHECK(iter == iter.end());
    }

    SUBCASE("Iterator with one prime element test") {
        container.addElement(2);

        MagicalContainer::PrimeIterator iter(container);
        CHECK(*iter == 2);
        ++iter;
        CHECK(iter == iter.end());
    }

    SUBCASE("Iterator with elements test") {
        container.addElement(1);
        container.addElement(5);
        container.addElement(10);
        container.addElement(2);
        container.addElement(7);

        MagicalContainer::PrimeIterator iter(container);

        std::vector<int> expected_order = {2, 5, 7};
        std::size_t index = 0;

        for (auto it = iter.begin(); it != iter.end(); ++it) {
            CHECK(*it == expected_order[index]);
            index++;
        }
    }
}

TEST_CASE("Exceptions Test") {
    SUBCASE("Removing Elements") {
        MagicalContainer container;

        container.addElement(1);
        container.addElement(5);
        container.addElement(10);
        container.addElement(2);
        container.addElement(7);

        CHECK_NOTHROW(container.removeElement(1));
        CHECK(container.size() == 4);
        CHECK_NOTHROW(container.removeElement(5));
        CHECK(container.size() == 3);
        CHECK_NOTHROW(container.removeElement(2));
        CHECK(container.size() == 2);
        CHECK_NOTHROW(container.removeElement(7));
        CHECK(container.size() == 1);

        CHECK_THROWS_AS(container.removeElement(0), std::runtime_error);
        CHECK(container.size() == 1);
        CHECK_NOTHROW(container.removeElement(10));
        CHECK(container.size() == 1);

        // removing empty container
        CHECK_NOTHROW(container.removeElement(10));
        CHECK(container.size() == 0);
        CHECK_THROWS_AS(container.removeElement(10), std::runtime_error);
        CHECK(container.size() == 0);
    }

    SUBCASE("AscendingIterator") {
        MagicalContainer container;

        container.addElement(2);

        MagicalContainer::AscendingIterator iter(container);
        CHECK_NOTHROW(++iter);
        CHECK_THROWS_AS(++iter, std::runtime_error);
    }

    SUBCASE("SideCrossIterator") {
        MagicalContainer container;

        container.addElement(2);

        MagicalContainer::SideCrossIterator iter(container);
        CHECK_NOTHROW(++iter);
        CHECK_THROWS_AS(++iter, std::runtime_error);
    }

    SUBCASE("PrimeIterator") {
        MagicalContainer container;

        container.addElement(2);

        MagicalContainer::PrimeIterator iter(container);
        CHECK_NOTHROW(++iter);
        CHECK_THROWS_AS(++iter, std::runtime_error);
    }
}
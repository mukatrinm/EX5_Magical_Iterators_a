#pragma once

#include <iostream>
#include <vector>

namespace ariel {
class MagicalContainer {
   private:
    std::vector<int> _mystical_elements;

   public:
    MagicalContainer() {}

    void addElement(int element);
    void removeElement(int element);

    size_t size() const;

    class BaseIterator {
       protected:
        MagicalContainer *ptr_magical_containter = nullptr;
        size_t _index = 0;

       public:
        BaseIterator(MagicalContainer *container, size_t index = 0) : ptr_magical_containter(container), _index(index){};
        BaseIterator(const BaseIterator &other)
            : ptr_magical_containter(other.ptr_magical_containter), _index(other._index) {}

        BaseIterator(BaseIterator &&other)
            : ptr_magical_containter(other.ptr_magical_containter), _index(other._index) {
            other.ptr_magical_containter = nullptr;
            other._index = 0;
        }

        BaseIterator &operator=(BaseIterator &&other) noexcept {
            if (this != &other) {
                ptr_magical_containter = other.ptr_magical_containter;
                _index = other._index;
                other.ptr_magical_containter = nullptr;
                other._index = 0;
            }
            return *this;
        }

        virtual ~BaseIterator() = default;

        bool operator==(const BaseIterator &other) const;
        bool operator!=(const BaseIterator &other) const;
        bool operator<(const BaseIterator &other) const;
        bool operator>(const BaseIterator &other) const;
        BaseIterator &operator=(const BaseIterator &other);
        int operator*() const;
    };

    class AscendingIterator : public BaseIterator {
       public:
        AscendingIterator(MagicalContainer &ptr_magical_containter, size_t index = 0) : BaseIterator(&ptr_magical_containter, index) {}
        AscendingIterator(const AscendingIterator &other) : BaseIterator(other) {}
        AscendingIterator &operator++();

        AscendingIterator begin();
        AscendingIterator end();
    };

    class SideCrossIterator : public BaseIterator {
       public:
        SideCrossIterator(MagicalContainer &ptr_magical_containter, size_t index = 0) : BaseIterator(&ptr_magical_containter, index) {}
        SideCrossIterator(const SideCrossIterator &other) : BaseIterator(other) {}

        SideCrossIterator &operator++();

        SideCrossIterator begin();
        SideCrossIterator end();
    };

    class PrimeIterator : public BaseIterator {
       public:
        PrimeIterator(MagicalContainer &ptr_magical_containter, size_t index = 0) : BaseIterator(&ptr_magical_containter, index) {}
        PrimeIterator(const PrimeIterator &other) : BaseIterator(other) {}

        PrimeIterator &operator++();

        PrimeIterator begin();
        PrimeIterator end();
    };
};
}  // namespace ariel
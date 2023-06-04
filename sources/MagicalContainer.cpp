#include "MagicalContainer.hpp"

#include <algorithm>
#include <vector>

using namespace ariel;

/********************
 * MagicalContainer *
 *********************/

void MagicalContainer::addElement(int element) {
    _mystical_elements.push_back(element);
}

void MagicalContainer::removeElement(int element) {
    auto iter = std::find(_mystical_elements.begin(), _mystical_elements.end(), element);

    if (iter == _mystical_elements.end()) {
        throw std::runtime_error("Element doesn't exist.");
    }

    _mystical_elements.erase(iter);
}

size_t MagicalContainer::size() const {
    return _mystical_elements.size();
}

/******************
 * BaseIterator *
 *******************/

bool MagicalContainer::BaseIterator::operator==(const BaseIterator &other) const {
    return ptr_magical_containter == other.ptr_magical_containter && _index == other._index;
}

bool MagicalContainer::BaseIterator::operator!=(const BaseIterator &other) const {
    return !(*this == other);
}

bool MagicalContainer::BaseIterator::operator>(const BaseIterator &other) const {
    return ptr_magical_containter->_mystical_elements[_index] > other.ptr_magical_containter->_mystical_elements[_index];
}

bool MagicalContainer::BaseIterator::operator<(const BaseIterator &other) const {
    return ptr_magical_containter->_mystical_elements[_index] < other.ptr_magical_containter->_mystical_elements[_index];
}

MagicalContainer::BaseIterator &MagicalContainer::BaseIterator::operator=(const BaseIterator &other) {
    if (this != &other) {
        ptr_magical_containter = other.ptr_magical_containter;
        _index = other._index;
    }
    return *this;
}

int MagicalContainer::BaseIterator::operator*() const {
    if (ptr_magical_containter == nullptr) {
        throw std::runtime_error("Container is null.");
    }

    if (_index >= ptr_magical_containter->_mystical_elements.size()) {
        throw std::out_of_range("Index is out of range.");
    }

    return ptr_magical_containter->_mystical_elements[_index];
}

/*********************
 * AscendingIterator *
 **********************/

MagicalContainer::AscendingIterator &MagicalContainer::AscendingIterator::operator++() {
    ++_index;
    return *this;
}

MagicalContainer::AscendingIterator MagicalContainer::AscendingIterator::begin() {
    return AscendingIterator(*ptr_magical_containter);
}

MagicalContainer::AscendingIterator MagicalContainer::AscendingIterator::end() {
    AscendingIterator iter(*ptr_magical_containter);
    iter._index = ptr_magical_containter->_mystical_elements.size();
    return iter;
}

/*********************
 * SideCrossIterator *
 *********************/

MagicalContainer::SideCrossIterator &MagicalContainer::SideCrossIterator::operator++() {
    ++_index;
    return *this;
}

MagicalContainer::SideCrossIterator MagicalContainer::SideCrossIterator::begin() {
    return SideCrossIterator(*ptr_magical_containter);
}

MagicalContainer::SideCrossIterator MagicalContainer::SideCrossIterator::end() {
    SideCrossIterator iter(*ptr_magical_containter);
    iter._index = ptr_magical_containter->_mystical_elements.size();
    return iter;
}

/*****************
 * PrimeIterator *
 *****************/

MagicalContainer::PrimeIterator &MagicalContainer::PrimeIterator::operator++() {
    ++_index;
    return *this;
}

MagicalContainer::PrimeIterator MagicalContainer::PrimeIterator::begin() {
    return PrimeIterator(*ptr_magical_containter);
}

MagicalContainer::PrimeIterator MagicalContainer::PrimeIterator::end() {
    PrimeIterator iter(*ptr_magical_containter);
    iter._index = ptr_magical_containter->_mystical_elements.size();
    return iter;
}
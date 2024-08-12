#ifndef __SINGLELIST_CPP__
#define __SINGLELIST_CPP__

#include "../headers/SingleList.hpp"

#include <cassert>
#include <limits>
#include <cstring>

template <typename T>
std::ostream& operator<<(std::ostream& out, const SingleList<T>& rhv)
{
    typename SingleList<T>::Node* temp = rhv.begin_;
    while(temp != NULL) {
        out << temp->data_ << " ";
        temp = temp-> next_;
    }
    return out;
};

template <typename T>
SingleList<T>::Node::Node(const_reference d, Node* n)
    : data_(d)
    , next_(n)
{
}

template <typename T>
SingleList<T>::SingleList()
    : begin_(NULL)
    , end_(NULL)
{
}

template <typename T>
SingleList<T>::SingleList(const size_type n)
    : begin_(NULL)
    , end_(NULL)
{
    resize(n);
}

template <typename T>
SingleList<T>::SingleList(const size_type n, const_reference t)
    : begin_(NULL)
    , end_(NULL)
{
    resize(n, t);
}

template <typename T>
SingleList<T>::SingleList(const int n, const_reference t)
        : begin_(NULL)
        , end_(NULL)
{
    resize(n, t);
}

template <typename T>
SingleList<T>::SingleList(const SingleList<T>& rhv)
    : begin_(NULL)
    , end_(NULL)
{
    for (Node* temp = rhv.begin_; temp != NULL; temp = temp->next_) {
        push_back(temp->data_);
    }
}

template <typename T>
template <typename InputIterator>
SingleList<T>::SingleList(InputIterator f, InputIterator l)
{
    while (f != l) {
        push_back(*(f));
        ++f;
    }
}

template <typename T>
const SingleList<T>&
SingleList<T>::operator=(const SingleList<T>& rhv)
{
    if (this == &rhv) return *this;
    resize(rhv.size());
    Node* rhvTemp = rhv.begin_;
    Node* thisTemp = begin_;
    while (rhvTemp != NULL) {
        thisTemp->data_ = rhvTemp->data_;
        rhvTemp = rhvTemp->next_;
        thisTemp = thisTemp->next_;
    }

    return *this;
}

template <typename T>
void
SingleList<T>::swap(SingleList<T>& rhv)
{
    Node* thisTempBegin = begin_;
    begin_ = rhv.begin_;
    rhv.begin_ = thisTempBegin;

    Node* thisTempEnd = end_;
    end_ = rhv.end_;
    rhv.end_ = thisTempEnd;
}


template <typename T>
SingleList<T>::~SingleList()
{
    clear();
}

template <typename T>
typename SingleList<T>::size_type
SingleList<T>::size() const
{
    size_type count = 0;
    Node* temp = begin_;
    while (temp != NULL) {
	temp = temp->next_; 
        ++count;
    }
    return count;
}

template <typename T>
typename SingleList<T>::size_type
SingleList<T>::max_size() const
{
    return std::numeric_limits<size_type>::max();
}

template <typename T>
bool
SingleList<T>::empty() const
{
    return NULL == begin_;
}

template <typename T>
void
SingleList<T>::clear()
{
    while (begin_ != NULL) {
        Node* temp = begin_;
        begin_ = begin_->next_;
        delete temp;
    }
    begin_ = NULL;
    end_ = NULL;
}

template <typename T>
void
SingleList<T>::resize(const size_type n, const_reference t)
{
    const size_type oldSize = size();
    for (size_type i = oldSize; i < n; ++i) {
        push_back(t);
    }
    for (size_type i = n; i < oldSize; ++i) {
        pop_back();
    }
}

template <typename T>
typename SingleList<T>::reference
SingleList<T>::front()
{
    assert(begin_ != NULL);
    return begin_->data_;
}

template <typename T>
typename SingleList<T>::const_reference
SingleList<T>::front() const
{
    assert(begin_ != NULL);
    return begin_->data_;
}

template <typename T>
void
SingleList<T>::push_front(const T& e)
{
    begin_ = new Node(e, begin_);
    if (NULL == end_) end_ = begin_;
}

template <typename T>
void
SingleList<T>::pop_front()
{
    assert(NULL != begin_);
    Node* temp = begin_->next_;
    delete begin_;
    begin_ = temp;
}

template <typename T>
void
SingleList<T>::push_back(const T& e)
{
    end_ = new Node(e, end_);
    if (NULL == begin_) {
        begin_ = end_;
        return;
    }
    end_->next_->next_ = end_;
    end_->next_ = NULL;
}

template <typename T>
void
SingleList<T>::pop_back()
{
    assert(begin_ != NULL);
    if (NULL == begin_->next_) {
        pop_front();
        return;
    }

    Node* beforeLast;
    for (beforeLast = begin_; beforeLast->next_ != end_; beforeLast = beforeLast->next_);
    delete end_;
    end_ = beforeLast;
    end_->next_ = NULL;
}

template <typename T>
typename SingleList<T>::reference
SingleList<T>::back()
{
    assert(end_ != NULL);
    return end_->data_;
}

template <typename T>
typename SingleList<T>::const_reference
SingleList<T>::back() const
{
    assert(end_ != NULL);
    return end_->data_;
}

template <typename T>
bool
SingleList<T>::operator==(const SingleList<T>& rhv) const
{
    if (size() != rhv.size()) {
        return false;
    }
    const_iterator rhvIt = rhv.begin();
    for (const_iterator it = begin(); it != end() ; ++it, ++rhvIt) {
        if (*it != *rhvIt) {
            return false;
        }
    }
    return true;
}

template <typename T>
bool
SingleList<T>::operator!=(const SingleList<T>& rhv) const
{
    return !(*this == rhv);
}

template <typename T>
bool
SingleList<T>::operator<(const SingleList<T>& rhv) const
{
    if (this->operator==(rhv)) return false;
    if (this->size() > rhv.size()) return false;
    if (this->size() < rhv.size()) return true;
    const_iterator rhvIt = rhv.begin();
    for (const_iterator it = begin(); it != end() ; ++it, ++rhvIt) {
        if (*it > *rhvIt) return false;
    }
    return true;
}

template <typename T>
bool
SingleList<T>::operator<=(const SingleList<T>& rhv) const
{
    return !(rhv < *this);
}

template <typename T>
bool
SingleList<T>::operator>(const SingleList<T>& rhv) const
{
    return (rhv < *this);
}

template <typename T>
bool
SingleList<T>::operator>=(const SingleList<T>& rhv) const
{
    return !(*this < rhv);
}

template <typename T>
typename SingleList<T>::iterator
SingleList<T>::begin()
{
    return iterator(begin_);
}

template <typename T>
typename SingleList<T>::iterator
SingleList<T>::end()
{
    return iterator(NULL);
}

template <typename T>
typename SingleList<T>::const_iterator
SingleList<T>::begin() const
{
    return const_iterator(begin_);
}

template <typename T>
typename SingleList<T>::const_iterator
SingleList<T>::end() const
{
    return const_iterator(NULL);
}

template <typename T>
typename SingleList<T>::iterator
SingleList<T>::insert(iterator pos, const_reference x)
{
    if (pos.ptr_ == begin_) {
        push_front(x);
        return pos;
    }
    if (pos == end()) {
        push_back(x);
        return pos;
    }
    insert_after(pos, x);

    Node* temp = pos.ptr_;
    std::swap(temp->data_, temp->next_->data_);
    return pos;
}

template <typename T>
void
SingleList<T>::insert(iterator pos, const size_type n, const_reference x)
{
    for (size_type i = 0; i < n; ++i) {
        pos = insert(pos, x);
    }
}

template <typename T>
void
SingleList<T>::insert(iterator pos, const int n, const_reference x)
{
    for (int i = 0; i < n; ++i) {
        pos = insert(pos, x);
    }
}


template <typename T>
template <typename InputIterator>
void
SingleList<T>::insert(iterator pos, InputIterator f, InputIterator l)
{
    iterator posTemp = pos;
    while (f != l) {
        insert(posTemp, *(f));
        ++f;
        ++posTemp;
    }
}

template <typename T>
typename SingleList<T>::iterator
SingleList<T>::insert_after(iterator pos)
{
    if (pos == end()) {
        push_back(T());
        return pos;
    }
    pos.ptr_->next_ = new Node(T(), pos.ptr_->next_);
    return pos.ptr_->next_;
}

template <typename T>
typename SingleList<T>::iterator
SingleList<T>::insert_after(iterator pos, const_reference x)
{
    if (pos == end()) {
        push_back(x);
        return pos;
    }
    pos.ptr_->next_ = new Node(x, pos.ptr_->next_);
    return pos.ptr_->next_;
}

template <typename T>
void
SingleList<T>::insert_after(iterator pos, size_type n, const_reference x)
{
    for (size_type i = 0; i < n; ++i) {
        pos = insert_after(pos, x);
    }
}

template <typename T>
void
SingleList<T>::insert_after(iterator pos, int n, const_reference x)
{
    for (int i = 0; i < n; ++i) {
        pos = insert_after(pos, x);
    }
}

template <typename T>
template <typename InputIterator>
void
SingleList<T>::insert_after(iterator pos, InputIterator f, InputIterator l)
{
    iterator posTemp = pos;
    while (f != l) {
        insert_after(posTemp, *f);
        ++f;
        ++posTemp;
    }
}

template <typename T>
typename SingleList<T>::iterator
SingleList<T>::erase(iterator pos)
{
    if (pos.ptr_ == begin_) {
        pop_front();
        return begin();
    }

    if (pos == end()) {
        pop_back();
        return end();
    }
    Node* beforePos;
    for (beforePos = begin_; beforePos->next_ != pos.ptr_; beforePos = beforePos->next_);

    beforePos->next_ = pos.ptr_->next_;
    delete pos.ptr_;
    return beforePos->next_;
}

template <typename T>
typename SingleList<T>::iterator
SingleList<T>::erase(iterator f, iterator l)
{
    while (f != l) {
       f = erase(f);
    }
    return l;
}

template <typename T>
typename SingleList<T>::iterator
SingleList<T>::erase_after(iterator pos)
{
    Node* nextNext = pos.ptr_->next_->next_;
    delete pos.ptr_->next_;
    pos.ptr_->next_ = nextNext;
    return pos;
}

template <typename T>
SingleList<T>::const_iterator::const_iterator()
    : ptr_(NULL)
{
}

template <typename T>
SingleList<T>::const_iterator::const_iterator(const const_iterator& rhv)
        : ptr_(rhv.ptr_)
{
}

template <typename T>
SingleList<T>::const_iterator::~const_iterator()
{
    if (ptr_ != NULL) {
        ptr_ = NULL;
    }
}

template <typename T>
const typename SingleList<T>::const_iterator&
SingleList<T>::const_iterator::operator=(const const_iterator& rhv)
{
    ptr_ = rhv.ptr_;
    return *this;
}

template <typename T>
typename SingleList<T>::const_reference
SingleList<T>::const_iterator::operator*() const
{
    return ptr_->data_;
}

template <typename T>
const typename SingleList<T>::value_type*
SingleList<T>::const_iterator::operator->() const
{
    return ptr_;
}

template <typename T>
const typename SingleList<T>::const_iterator&
SingleList<T>::const_iterator::operator++()
{
    ptr_ = ptr_->next_;
    return *this;
}


template <typename T>
const typename SingleList<T>::const_iterator
SingleList<T>::const_iterator::operator++(int)
{
    const_iterator temp = *this;
    ptr_ = ptr_->next_;
    return temp;
}

template <typename T>
bool
SingleList<T>::const_iterator::operator==(const const_iterator& rhv) const
{
    return ptr_ == rhv.ptr_;
}

template <typename T>
bool
SingleList<T>::const_iterator::operator!=(const const_iterator& rhv) const
{
    return !(*this == rhv);
}

template <typename T>
SingleList<T>::const_iterator::const_iterator(Node* rhv)
    : ptr_(rhv)
{
}

template <typename T>
typename SingleList<T>::Node*
SingleList<T>::const_iterator::getPtr()
{
    return ptr_;
}

template <typename T>
typename SingleList<T>::Node*
SingleList<T>::const_iterator::getPtr() const
{
    return ptr_;
}

template <typename T>
void
SingleList<T>::const_iterator::setPtr(Node* ptr)
{
    ptr_ = ptr;
}

template <typename T>
SingleList<T>::iterator::iterator()
    : const_iterator()
{
}

template <typename T>
SingleList<T>::iterator::iterator(const iterator& rhv)
        : const_iterator(rhv)
{
}

template <typename T>
SingleList<T>::iterator::~iterator()
{
    if (const_iterator::ptr_ != NULL) {
        const_iterator::ptr_ = NULL;
    }
}

template <typename T>
typename SingleList<T>::reference
SingleList<T>::iterator::operator*()
{
    return const_iterator::ptr_->data_;
}

template <typename T>
typename SingleList<T>::const_reference
SingleList<T>::iterator::operator->()
{
    return const_iterator::ptr_->data_;
}

template <typename T>
typename SingleList<T>::iterator&
SingleList<T>::iterator::operator++()
{
    const_iterator::setPtr(const_iterator::getPtr()->next_);
//    ptr_ = ptr_->next_;
    return *this;
}


template <typename T>
typename SingleList<T>::iterator
SingleList<T>::iterator::operator++(int)
{
    iterator temp = *this;
    const_iterator::setPtr(const_iterator::getPtr()->next_);
    return temp;
}


template <typename T>
typename SingleList<T>::iterator&
SingleList<T>::iterator::operator=(const iterator& rhv)
{
    const_iterator::setPtr(rhv.getPtr());
    return *this;
}

template <typename T>
typename SingleList<T>::iterator&
SingleList<T>::iterator::operator=(const_iterator& rhv)
{
    const_iterator::ptr_ = rhv.getPtr();
    return *this;
}

template <typename T>
bool
SingleList<T>::iterator::operator==(const iterator& rhv) const
{
    return const_iterator::ptr_ == rhv.getPtr();
}

template <typename T>
bool
SingleList<T>::iterator::operator!=(const iterator& rhv) const
{
    return const_iterator::ptr_ != rhv.getPtr();
}

template <typename T>
SingleList<T>::iterator::iterator(Node* rhv)
{
    const_iterator::setPtr(rhv);
}

#endif

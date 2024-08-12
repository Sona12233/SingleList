#ifndef __SINGLELIST_HPP__
#define __SINGLELIST_HPP__

#include <iostream>

template <typename T> class SingleList;
template <typename T> std::ostream& operator<<(std::ostream& out, const SingleList<T>& singleList);

template <typename T>
class SingleList
{
public:
    template <typename U>
    friend std::ostream& operator<<(std::ostream& out, const SingleList<U>& rhv);
    typedef T value_type;
    typedef value_type& reference;
    typedef const value_type& const_reference;
    typedef value_type* pointer;
    typedef std::ptrdiff_t difference_type;
    typedef std::size_t size_type;

private:
    struct Node {
        Node(const_reference d, Node* n = NULL);
        value_type data_;
        Node* next_;
    };

public:
    class const_iterator { /// ForwardIterator
        friend class SingleList<T>;
    public:
        const_iterator(); /// trivial
        const_iterator(const const_iterator& rhv);
        ~const_iterator();
        const const_iterator& operator=(const const_iterator& rhv); /// trivial
        const_reference operator*() const;
        const value_type* operator->() const;
        const const_iterator& operator++();
        const const_iterator operator++(int);
        bool operator==(const const_iterator& rhv) const;
        bool operator!=(const const_iterator& rhv) const;
    protected:
        const_iterator(Node* rhv);
        Node* getPtr() const;
        Node* getPtr();
        void setPtr(Node* ptr);
    private:
        Node* ptr_;
    };

    class iterator : public const_iterator
    {
        friend class SingleList<T>;
    public:
        iterator();
        iterator(const iterator& rhv);
        ~iterator();
        reference operator*();
        const_reference operator->();
        iterator& operator++();
        iterator operator++(int);
        iterator& operator=(const iterator& rhv);
        iterator& operator=(const_iterator& rhv);
        bool operator==(const iterator& rhv) const;
        bool operator!=(const iterator& rhv) const;
    protected:
        iterator(Node* rhv);
    };

    SingleList();
    SingleList(const size_type n); /// Sequence
    SingleList(const size_type n, const_reference t); /// Seq
    SingleList(const int n, const_reference t); /// Seq
    SingleList(const SingleList& rhv); /// Container
    template <typename InputIterator>
    SingleList(InputIterator f, InputIterator l); /// Seq
    ~SingleList();
    const SingleList& operator=(const SingleList&);
    void swap(SingleList& rhv);
    size_type size() const; /// Container
    size_type max_size() const; /// Container
    bool empty() const; /// Container
    void clear();
    void resize(const size_type n, const_reference t = T());
    reference front(); /// Front Insertion Sequence
    const_reference front() const; /// Front Insertion
    void push_front(const T& e); /// Front Insertion
    void pop_front(); /// Front Insertion
    void push_back(const T& e); /// Back Insertion
    void pop_back();
    reference back(); /// Back Insertion Sequence
    const_reference back() const; /// Back Insertion
    bool operator==(const SingleList& rhv) const;
    bool operator!=(const SingleList& rhv) const;
    bool operator<(const SingleList& rhv) const;
    bool operator<=(const SingleList& rhv) const;
    bool operator>(const SingleList& rhv) const;
    bool operator>=(const SingleList& rhv) const;
    iterator begin();
    iterator end();
    const_iterator begin() const;
    const_iterator end() const;
    iterator insert(iterator pos, const T& x);
    void insert(iterator pos, const size_type n, const_reference x);
    void insert(iterator pos, const int n, const_reference x);
    template <typename InputIterator>
    void insert(iterator pos, InputIterator f, InputIterator l);
    iterator insert_after(iterator pos);
    iterator insert_after(iterator pos, const_reference x);
    void insert_after(iterator pos, size_type n, const_reference x);
    void insert_after(iterator pos, int n, const_reference x);
    template <typename InputIterator>
    void insert_after(iterator pos, InputIterator f, InputIterator l);
    iterator erase(iterator pos);
    iterator erase(iterator f, iterator l);
    iterator erase_after(iterator pos);

private:
    Node* begin_;
    Node* end_;
};

#include "../templates/SingleList.cpp"

#endif /// __SINGLELIST_HPP__

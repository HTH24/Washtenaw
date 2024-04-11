//
//  minivector.hpp
//  cps272MP1
//
//  Created by TianHang Hu on 1/21/24.
//

#ifndef minivector_hpp
#define minivector_hpp

#include <stdio.h>

#include <iostream>
#include <fstream>
#include <sstream>
#include <tuple>
using namespace std;

template <typename T>

class miniVector
{
private:
    T *ptr;
    size_t vSize;
    size_t capacity;
public:
    // Default Constructor, initial value of no size
    miniVector(size_t = 0);
    // Copy Constructor, assign a vector to another vector
    miniVector(const miniVector<T>&);
    // Destructor
    ~miniVector();
    
    // add elements
    void push_back(const T&);
    // remove last element
    void pop_back();
    // sort the miniVector according to the total number of Votes
    void sort();
    T& back();
    
    size_t size() const;
    bool empty() const;
    miniVector& operator= (const miniVector<T>&);
    T& operator[] (size_t);
    
    // read the input file into the program
    void readFromFile(const string& filename);
};

template <typename T1, typename T2>
istream& operator>>(istream& is, pair<T1, T2>& pair)
{
    is >> pair.first >> pair.second;
    return is;
}

template <typename T>
miniVector<T>::miniVector(size_t size) : vSize(0), capacity(0), ptr(NULL)
{
    if (size == 0)
        return ;
    ptr = new T[size];
    vSize = size;
    for (size_t i = 0; i < vSize; i++)
        ptr[i] = T();
}

template <typename T>
miniVector<T>::miniVector(const miniVector<T>& obj)
{
    ptr = new T[obj.size];
    this->vSize = obj.vSize;
    for (size_t i = 0; i < obj.size(); i++)
        ptr[i] = obj.ptr[i];
}

template <typename T>
miniVector<T>::~miniVector()
{
    if (ptr != NULL)
    {
        delete [] ptr;
    }
}

template <typename T>
miniVector<T>& miniVector<T>::operator= (const miniVector<T>& rhs)
{
    this->vSize = rhs.vSize;
    for (size_t i = 0; i < vSize; ++i)
        ptr[i] = rhs.ptr[i];
    return *this;
}

template <typename T>
T& miniVector<T>::operator[] (size_t i)
{
    if (i < 0 || i >= vSize) {
        throw out_of_range("Index out of range");
    }
    return ptr[i];
}

template <typename T>
void miniVector<T>::push_back(const T& obj)
{
    if (vSize == capacity)
    {
        if(capacity == 0)
        {
            capacity = 1;
            ptr = new T[1];
        }
        else
        {
            T *temp;
            temp = new T[2 * capacity];
            for (size_t i = 0; i < vSize; i++)
                temp[i] = ptr[i];
            capacity *= 2;
            if (ptr != NULL)
                delete [] ptr;
            ptr = temp;
        }
    }
    ptr[vSize] = obj;
    vSize++;
}

template <typename T>
void miniVector<T>::pop_back()
{
    if (vSize == 0) {
        throw out_of_range("Vector is empty");
    }
    vSize--;
}

template <typename T>
T& miniVector<T>::back()
{
    if (vSize == 0) {
        throw out_of_range("Vector is empty");
    }
    return ptr[vSize - 1];
}

template <typename T>
size_t miniVector<T>::size() const
{
    return vSize;
}

template <typename T>
bool miniVector<T>::empty() const
{
    return (vSize == 0);
}

template <typename T>
void miniVector<T>::readFromFile(const string& filename) {
    // when we provide a filename, open is called automatically
    ifstream in(filename);
    string name;
    int num;
    
    if (!in.is_open()) {
        throw runtime_error("Unable to open this file.");
    }
    
    // total number of votes for all those 5 people
    int totalVotes = 0;
    
    while (in >> name >> num) {
        // getline reads a whole line, not appropraite here. Here elements are read separately
        T contents;
        get<0>(contents) = name;
        get<1>(contents) = num;
        push_back(contents);
        
        totalVotes += num;
    }
    
    for (auto i = 0; i < size(); ++i) {
        get<2>((*this)[i]) = double(get<1>((*this)[i])) / double(totalVotes) * 100.0;
    }
    
    in.close();
}

// compare a miniVector's total number of votes
template <typename T>
int compare(const T &m1, const T &m2)
{
    if (get<1>(m1) < get<1>(m2)) {
        return 1;
    }
                                  
    if (get<1>(m2) < get<1>(m1)) {
        return -1;
    }
    return 0;
}

template <typename T>
void miniVector<T>::sort() {
    for (size_t i = 0; i < vSize - 1; ++i) {
        for (size_t j = 0; j < vSize - i - 1; ++j) {
            // if the second element read is less than the first element read
            if (compare(ptr[j], ptr[j + 1]) == 1) {
                // Swap elements if they are in the wrong order
                T temp = ptr[j];
                ptr[j] = ptr[j + 1];
                ptr[j + 1] = temp;
            }
        }
    }
}


#endif /* minivector_hpp */

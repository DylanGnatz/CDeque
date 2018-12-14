#include "cdeque.h"
#include <iostream>
#include <cmath>
using namespace std;

CDeque::CDeque(){
    _capacity = DEFAULT_CAPACITY;
    _deque = new string[_capacity];
    _back = 0;
    _front = -1;
    _size = 0;
}

CDeque::CDeque(int capacity){
    if (capacity < 0)
        throw string("Invalid deque capacity.");
    _capacity = capacity;
    _deque = new string[_capacity];
    _back = 0;
    _front = -1;
}

bool CDeque::empty() const {
    return (_front == -1);
}

bool CDeque::full() const{
    if (_front == 0 && _back == _capacity - 1)
        return true;
    return _front == _back + 1;
}

bool CDeque::insertBegin(string str){
    if (full()){
        return false;
    }
    if (_front == -1) {
        _front = 0;
        _back = 0;
    }
    else if (_front == 0)
        _front = _capacity - 1;
    else
        _front--;
    _deque[_front] = str;
    _size++;
    return true;
}

bool CDeque::insertEnd(string str) {
    if (full())
        return false;
    if (_front == -1) {
        _front = 0;
        _back = 0;
    }
    else if (_back == _capacity - 1)
        _back = 0;
    else
        _back++;
    _deque[_back] = str;
    _size++;
    return true;
}

string CDeque::removeBegin() {
    string removed;
    if (empty())
        throw (string) "Deque underflow.";
    removed = _deque[_front];
    if (_front == _back) {
        _front = -1;
        _back = -1;
    }
    else if (_front == _capacity - 1)
        _front = 0;
    else
        _front++;
    _size--;
    return removed;
}

string CDeque::removeEnd() {
    string removed;
    if (empty())
        throw (string) "Deque underflow.";
    removed = _deque[_back];
    if (_front == _back) {
        _front = -1;
        _back = -1;
    }
    else if (_back == 0)
        _back = _capacity - 1;
    else
        _back--;
    _size--;
    return removed;
}

string CDeque::first() const{
    if (empty())
        throw (string) "CDeque is empty.";
    return _deque[_front];
}

string CDeque::last() const{
    if (empty())
        throw (string) "CDeque is empty.";
    return _deque[_back];
}

int CDeque::size() const{
    return _size;
}

bool CDeque::isFull() const {
    return full();
}

bool CDeque::isEmpty() const {
    return empty();
}

int CDeque::capacity() const {
    return _capacity;
}

CDeque::~CDeque() {
    delete [] _deque;
}

ostream &operator<< (ostream& o, const CDeque& d){
   o << "First: " << d.first() << " Last: " << d.last();
   return o;
};
#ifndef CDEQUE_H_
#define CDEQUE_H_
#include <string>
using namespace std;

class CDeque {
private:
    static const int DEFAULT_CAPACITY = 10;
    int _capacity;
    int _front;
    int _back;
    int _size;
    string* _deque;
    bool full() const;
    bool empty() const;


public:
    // Create CDeque with default capacity
    CDeque();

    // Create CDeque with specified capacity (must be >= 0)
    CDeque(const int);

    // Insert at beginning -- boolean false indicates failure
    bool insertBegin(string);

    // Insert at end -- boolean false indicates failure
    bool insertEnd(string);

    // Remove from beginning -- throws a string if unsuccessful
    string removeBegin();

    // Remove from end -- throws a string if unsuccessful
    string removeEnd();

    // Standard container methods
    string first() const;
    string last() const;
    int size() const;
    bool isFull() const;
    bool isEmpty() const;
    int capacity() const;

    // Destructor is mandatory -- must deallocate any array space
    ~CDeque();
};

ostream &operator<< (ostream&, const CDeque&);
#endif /* CDEQUE_H_ */

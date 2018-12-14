#include <iostream>
#include "cdeque.h"
using namespace std;

int main() {
    cout << "start" << endl;
    CDeque cst(3);
    //cout << "*** " << cst << endl;
    cout << "Insert begin " << cst.insertBegin("two") << endl;
    cout << "*** " << cst << endl;
    cout << "Size: " << cst.size() << endl;
    cout << "Insert begin " << cst.insertBegin("one") << endl;
    cout << "*** " << cst << endl;
    cout << "Size: " << cst.size() << endl;
    cout << "Insert end " << cst.insertEnd("three") << endl;
    cout << "*** " << cst << endl;
    cout << "Size: " << cst.size() << endl;
    cout << "After inserts: ";
    cout << "first " << cst.first() << " last " << cst.last() << endl;
    cout << "Try to insert to full" << endl;
    cout << "Insert begin " << cst.insertBegin("four") << endl;


    cout << "remove end " << cst.removeEnd() << endl;
    cout << "*** " << cst << endl;
    cout << "Size: " << cst.size() << endl;
    cout << "remove begin" << cst.removeBegin() << endl;
    cout << "*** " << cst << endl;
    cout << "Size: " << cst.size() << endl;
    cout << "remove end " << cst.removeEnd() << endl;
    cout << "Size: " << cst.size() << endl;
   // cout << "*** " << cst << endl;
    cout << "Try to remove from empty" << endl;
    try {
        cst.removeEnd();
    } catch (string &s) {
        cout << "Remove threw exception: " << s << endl;
    }
    cout << "About to kill the CDeque" << endl;

    cout << "done" << endl;
}
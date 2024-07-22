#include "IntCell.h"

// 构造函数
IntCell::IntCell(int initialValue){storedValue = new int(initialValue);}
IntCell::IntCell(const IntCell & rhs){storedValue = new int(*rhs.storedValue);}

// 析构函数
IntCell::~IntCell(){delete storedValue;}

// operator=
const IntCell & IntCell::operator=(const IntCell & rhs){
    if (this != &rhs)
        storedValue = new int(*rhs.storedValue);
    return *this;
}

int IntCell::read() const {return *storedValue;}
void IntCell::write(int x) {*storedValue = x;}
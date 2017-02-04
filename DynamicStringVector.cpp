/* 
 * File:   DynamicStringVector.cpp
 * Author: Aziz OKAY
 * 
 * Created on December 1, 2016, 3:25 PM
 */

#include <iostream>
#include "GPUString.h"
#include "GPUStringVector.h"
using namespace std;
/*
GPUStringVector::~GPUStringVector() {
    delete [] allLine;
}*/

int GPUStringVector::push_back(const GPUString &obj) {
    if(getSize() >= getCapacity()) {
        GPUString *temp = (GPUString*)new GPUString[getSize()];
        for(int i = 0; i < getSize(); i++)
            temp[i] = allLine[i];
        
        delete [] allLine;
        capacity = getCapacity() + 10;
        size++;
        allLine = (GPUString*)new GPUString[getCapacity()];
        for(int i = 0; i < getSize()-1; i++)
            allLine[i] = temp[i];

        allLine[size-1] = obj;
        delete [] temp;
    }else {
        allLine[size] = obj;
        size++;
    }
    return 1;
}

int GPUStringVector::pop_back() {
    delete [] &allLine[getSize() - 1];
    size--;
    return 1;
}


GPUString& GPUStringVector::operator[](const int index) {
    if(index < getSize())
        return allLine[index];
    else {
        cerr << "Out of size." << endl;
        return allLine[getSize()-1];
    }	
}

GPUStringVector& GPUStringVector::operator =(const GPUStringVector& other) {
    if(getSize() != 0)
        delete [] allLine;
    setSize(other.getSize());
    capacity = other.getCapacity();
    allLine = (GPUString*)new GPUString[getCapacity()];
    for(int i = 0; i < other.getSize(); i++)
        allLine[i] = other.getAllLine()[i];
        
    return *this;    
}

void GPUStringVector::print() {
    for(int i = 0; i < getSize(); i++)
        cout << allLine[i] << endl;
}

ostream& operator << (ostream& out, GPUStringVector& other) {
   for (int i = 0 ; i < other.getSize() ; i++)
      out << other.getAllLine()[i];
   return out;
}

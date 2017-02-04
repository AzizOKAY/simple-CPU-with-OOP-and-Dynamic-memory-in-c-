/*
 * File:   DynamicString.h
 * Author: Aziz OKAY
 *
 * Created on December 1, 2016, 3:18 PM
 */

#ifndef GPUSTRING_H
#define GPUSTRING_H
#include <iostream>
#include <fstream>
#include <string.h>

using namespace std;

class  GPUString {
    public :
        GPUString() : str(NULL), length(0) {}
        GPUString(int lnhgt);
        GPUString(const char  *aStr);
        GPUString(const  GPUString &other);

        ~GPUString();
        GPUString& operator =(const GPUString &other);
        GPUString& operator =(const char* other);
        GPUString& operator +=(const char ch);
        char * getStr()const {return str;}
        int  getLength() const{return length;}
        int setLength(const int nl) {length = nl;}
        int find(const char ch) const;

        char& operator[](const int index);
        bool operator==(const char*);
        friend ostream& operator<<(ostream& out, const GPUString& other);
    private :
        char  *str;
        int  length;
};


#endif /* GPUSTRING_H */

/*
 * File:   DynamicString.cpp
 * Author: Aziz OKAY
 *
 * Created on December 1, 2016, 3:18 PM
 */

#include "GPUString.h"

GPUString::GPUString(int lnhgt) {
    str = new char[lnhgt];
    length = lnhgt;
}


GPUString::GPUString(const char *aStr ) {
   if(aStr) {
      length = strlen(aStr);
      str = new char[length+1];
      strcpy(str,aStr);
   } else {
      str = NULL;
      length = 0;
   }
}


GPUString::GPUString(const GPUString &other) {
    if(other.length == 0) {
        length=0;
        str = NULL;
    }else {
        length = other.getLength();
        str = new char[length];
        for (int i = 0 ; i < length ; i++)
            str[i] = other.str[i];

   }
}


GPUString::~GPUString() {
    if(getLength() > 0)
        delete [] str;
}

GPUString& GPUString::operator =(const GPUString &other) {
   if (getLength() != 0)
      delete [] str;

   length = other.getLength();
   str = new char[getLength()];
   for (int i = 0 ; i < getLength() ; i++)
      str[i] = other.getStr()[i];
   return *this;
}


GPUString& GPUString::operator =(const char* other) {
   if(strlen(other) > 0) {
      length = strlen(other);
      char *temp = new char[getLength()+1];
      strcat(temp, other);

      if(str)
         delete [] str;

      str = temp;
   } else {
      length = 0;
      if(str)
         delete [] str;
      str = NULL;
   }
   return *this;
}

GPUString& GPUString::operator +=(const char ch) {

    length = length+1;
    char *temp = new char[getLength()];
    strcat(temp, str);
    temp[getLength() - 1] = ch;
    if(str)
        delete [] str;
    str = temp;

   return *this;
}

ostream& operator << (ostream& out, const GPUString& other) {
   for (int i = 0 ; i < other.getLength() ; i++)
      out << other.str[i];
   return out;
}

bool GPUString::operator==(const char *chstr)
{
   bool equal = true;
   int stlen = 0;
   while (chstr[stlen] != '\0')
      stlen++;

    for (int i = 0 ; i < stlen ; i++) {
	    if (getStr()[i] != chstr[i])
	        equal = false;
    }
  return equal;
}

char& GPUString::operator[](const int index){
    if(index >= 0 && index <= getLength())
        return str[index];
    else {
        cerr << "The index is out of size!!!!!\n";
        return str[getLength()];
    }
}
int GPUString::find(const char ch) const {
    for(int i = 0; i < getLength(); i++)
        if(ch == str[i])
            return i;
return -1;
}

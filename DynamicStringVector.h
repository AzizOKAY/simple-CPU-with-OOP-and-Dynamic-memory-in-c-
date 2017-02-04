/* 
 * File:   DynamicStringVector.h
 * Author: Aziz OKAY
 *
 * Created on December 1, 2016, 3:25 PM
 */

#ifndef GPUSTRINGVECTOR_H
#define GPUSTRINGVECTOR_H

class GPUStringVector {
    public:
        GPUStringVector(): size(0), capacity(10) { allLine = (GPUString*)new GPUString[10];}
        //~GPUStringVector();
        GPUStringVector& operator =(const GPUStringVector& other);
        
        int getSize() const { return size;}
        GPUString* getAllLine() const { return allLine; }
        int getCapacity() const { return capacity; }
        void setSize(const int n_size) {size = n_size; }
        void print();

        int push_back(const GPUString &obj);
        int pop_back();

        GPUString& operator[](const int index);
        friend ostream& operator<<(ostream& out, GPUStringVector& other);
    private:
        GPUString *allLine;
        int size;
        int capacity;
};


#endif /* GPUSTRINGVECTOR_H */

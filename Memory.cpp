/*
 * File:   Memory.cpp
 * Author: Aziz OKAY
 * Created on 29 Ekim 2016 Cumartesi, 18:39
 */

#include "Memory.h"
#include "CPU.h"
#include "CPUProgram.h"

/**
 * No parameter constructor
 */
Memory::Memory() {
    for(int i = 0; i < 50; i++)
        setMem(i, 0);
}

/**
 * Constructor that take option
 * @param opt option for class
 */
Memory::Memory(const int opt) {
    for(int i = 0; i < 50; i++)
        setMem(i, 0);
    if(opt == 0 || opt == 1 || opt == 2)
        option = opt;
    else {
        cerr << "option value must be 0, 1 or 2"
                "(Program will processes with default option(0))" << endl;
        option = 0;
    }
}

/**
 * getter function that get a special index of memory
 * @param index to point memory element
 * @return unsiged int that index pointed
 */
unsigned int Memory::getMem(const int index) const {
    if(index >= 0 && index < 50)
        return memArr[index];
    else {
        cerr << "Out of range for memory" << endl;
        exit (EXIT_FAILURE);
    }

}
/**
 * setter function for memory
 * @param index of memory cell
 * @param value that saved in index
 */
void Memory::setMem(const int index, const unsigned int value) {
    if(index >= 0 && index < 50)
        memArr[index] = value;
    else {
        cerr << "Out of range for memory" << endl;
        exit (EXIT_FAILURE);
    }
}

/**
 * The function that print all memory content to screen
 * @param memoryArray array that hold memory
 */
void Memory::printAll() const{
    cout << "Memory Values:" << endl;
    for(int i = 0; i < 50; i++)
        cout << "[" << i << "]" << " -> " << getMem(i) << endl;
}

/*
 * File:   Memory.h
 * Author: Aziz OKAY
 * Created on 29 Ekim 2016 Cumartesi, 18:39
 */

#ifndef MEMORY_H
#define MEMORY_H

class Memory {
public:
    Memory();
    Memory(const int opt);

    /*** Getter Function ***/
    int getOption() const {return option;}
    unsigned int getMem(const int index) const;

    /*** Setter Function ***/
    void setOption(const int opt) { option = opt;}
    void setMem(const int index, const unsigned int value);

    void printAll() const;

private:
    int option;
    unsigned int memArr[50];
};

#endif /* MEMORY_H */

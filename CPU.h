/*
 * File:   CPU.h
 * Author: Aziz OKAY
 * Created on 29 Ekim 2016 Çarşamba, 00:27
 */

#ifndef CPU_H
#define CPU_H

#include <iostream>
#include "Memory.h"
#include "GPUString.h"
using namespace std;

class CPU {
public:
    /*** CONSTRUCTORS ***/
    CPU();
    CPU(int op);
    CPU(GPUString inst);

    /***** Getter function *****/
    int getPC() const;
    int getOption() const;
    GPUString getInstruction() const;
    int getNthRegister(int nth) const;

    /***** Setter function *****/
    void setPC(const int newPC);
    void setOption(const int newOp);
    void setInstruction(const GPUString& newString);
    void setNthRegister(const int newR1, const int nth);

    void print() const;
    bool halted() const;
    void gtuToLower(GPUString &line);
    int execute(GPUString line, Memory &memObj);

private:
    int PC;
    int option;
    int regArr[5];
    GPUString instruction;

    int gtuAtoi(const char *str) const;
    bool isNumber(const char isNum) const;
    bool isEndOfLine(const char isEnd) const;
    int numOfSpace(GPUString line);

    int jmpInstruction(GPUString& line);
    int jpnInstruction(GPUString& line);
    int addInstruction(GPUString& line, Memory &memObj);
    int subInstruction(GPUString& line, Memory &memObj);
    int movInstruction(GPUString& line, Memory &memObj);
    void dropAllSpace(GPUString& line, GPUString &newLine);
    int prnInstruction(GPUString& line, Memory &memObj);
    int movToReg(GPUString& line, int regNum, Memory &memObj);
    int movToMem(GPUString& line, int memNum, Memory &memObj);

};

#endif /* CPU_H */

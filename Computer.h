/*
 * File:   Computer.h
 * Author: Aziz OKAY
 * Created on 03 Kasım 2016 Perşembe, 23:48
 */

#ifndef COMPUTER_H
#define COMPUTER_H

#include "CPU.h"
#include "Memory.h"
#include "CPUProgram.h"

class Computer {
public:
    Computer(const int option);
    Computer(CPU myCPU, CPUProgram myCPUProgram, Memory myMemory, const int option);

    CPU getCPU() const;
    Memory getMemory() const;
    CPUProgram getCPUProgram() const;

    void setCPU(const CPU myCPU);
    void setMemory(const Memory myMemory);
    void setCPUProgram(const CPUProgram myCPUProgram);

    int execute();

private:
    CPU comCPU;
    CPUProgram comCPUProgram;
    Memory comMemory;

};

#endif /* COMPUTER_H */

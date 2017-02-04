/*
 * File:   Computer.cpp
 * Author: Aziz OKAY
 * Created on 03 Kasım 2016 Perşembe, 23:48
 */

#include "Computer.h"
#include <iostream>
using namespace std;

/**
 * Constructor taht take a option
 * @param option option for class
 */
Computer::Computer(const int option) {
    comCPU.setPC(1);
    comCPU.setOption(option);
}

/**
 * Constructor that take CPU, CPUProgram, Memory, option
 * @param myCPU a CPU class object
 * @param myCPUProgram CPUProgram class object
 * @param myMemory Memory class object
 * @param option for class
 */
Computer::Computer(CPU myCPU, CPUProgram myCPUProgram, Memory myMemory, const int option){
    comCPU.setPC(1);
    comCPU.setOption(option);
    comCPU.setInstruction(myCPU.getInstruction());
    for(int i = 0; i < 5; i++)
        comCPU.setNthRegister(0, i);
    setMemory(myMemory);
    setCPUProgram(myCPUProgram);
}
/*** getter function for computer class ***/
CPU Computer::getCPU() const { return comCPU;}
Memory Computer::getMemory() const {return comMemory;}
CPUProgram Computer::getCPUProgram() const {return comCPUProgram;}

/*** Setter function for computer class*/
void Computer::setCPU(const CPU myCPU) {
    comCPU.setInstruction(myCPU.getInstruction());
    comCPU.setOption(myCPU.getOption());
    comCPU.setPC(myCPU.getPC());
    for(int i = 0; i < 5; i++)
        comCPU.setNthRegister(myCPU.getNthRegister(i), i);
}

/*** Setter function for computer class*/
void Computer::setMemory(const Memory myMemory){
    for(int i = 0; i < 50; i++)
        comMemory.setMem(i, myMemory.getMem(i));
}

/*** Setter function for computer class*/
void Computer::setCPUProgram(const CPUProgram myCPUProgram) {
    comCPUProgram.setAllLine(myCPUProgram.getAllLine());
}

/**
 * Execute function for computer class
 * @return return -1 if there is problem 0 otherwise
 */
int Computer::execute() {
    GPUString instruction;
    comCPU.setInstruction(comCPUProgram.getLine(0));
    instruction = comCPUProgram.getLine(comCPU.getPC()-1);

    while(!comCPU.halted()) {
        if(comCPU.execute(instruction, comMemory) == -1) {
            cerr << "There is a problem at " << comCPU.getPC() << endl;
            exit (EXIT_FAILURE);
        }
        instruction = comCPUProgram.getLine(comCPU.getPC()-1);
        comCPU.gtuToLower(instruction);
        comCPU.setInstruction(instruction);
    }
    comCPU.print();
    return 0;
}

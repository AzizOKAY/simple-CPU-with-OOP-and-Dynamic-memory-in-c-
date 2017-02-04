/* 
 * File:   CPUProgram.h
 * Author: jan
 *
 * Created on December 1, 2016, 3:33 PM
 */

#ifndef CPUPROGRAM_H
#define CPUPROGRAM_H
#include <iostream>
#include "GPUString.h"
#include "GPUStringVector.h"
using namespace std;

class CPUProgram {
    public:
        CPUProgram(){option = 0;};
        CPUProgram(const int opt);
        CPUProgram(char *fileName);


        int size() const;
        GPUStringVector getAllLine() const;
        int ReadFile(const char *fileName);
        GPUString getLine(const int lineNum) const;
        int getOption() const { return option; }
        void setAllLine(GPUStringVector all);
        void setOption(const int opt) { option = opt;}
        void setLine(const GPUString _instr) {allLine.push_back(_instr);}

        /*** OPERATOR OVERLOADIG ***/
        GPUString operator[](const int index);
        CPUProgram operator ()(int index1, int index2);
        CPUProgram& operator --();
        CPUProgram operator --(int);
        CPUProgram& operator +=(const GPUString _instr);
        
        friend ostream& operator<<(ostream& out, const CPUProgram& obj);
        friend CPUProgram operator +(const CPUProgram obj, const char* _instr);
        friend bool operator<(const CPUProgram& left, const CPUProgram& right);
        friend bool operator>(const CPUProgram& left, const CPUProgram& right);
        friend bool operator==(const CPUProgram& left, const CPUProgram& right);
        friend bool operator!=(const CPUProgram& left, const CPUProgram& right);
        friend bool operator<=(const CPUProgram& left, const CPUProgram& right);
        friend bool operator>=(const CPUProgram& left, const CPUProgram& right);
        friend CPUProgram operator +(const CPUProgram first, const CPUProgram second);

    private:
        int option;
        GPUStringVector allLine;
};

#endif /* CPUPROGRAM_H */

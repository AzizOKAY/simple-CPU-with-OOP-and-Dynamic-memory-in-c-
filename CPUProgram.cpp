/*
 * File:   CPUProgram.cpp
 * Author: Aziz OKAY
 *
 * Created on December 1, 2016, 3:33 PM
 */

#include "CPUProgram.h"


/**
 * constructor that take a string as a parameter
 * @param fileName name of file
 */
CPUProgram::CPUProgram(char *fileName) {
    ReadFile(fileName);
}

CPUProgram::CPUProgram(const int opt) {
    if(opt == 0 || opt == 1 || opt == 2)
        option = opt;
    else {
        cerr << "option value must be 0, 1 or 2"
                "(Program will processes with default option(0))" << endl;
        option = 0;
    }
}

/**
 * the function return number that line of program
 * @return number of program
 */
int CPUProgram::size() const {
    return getAllLine().getSize();
}

/**
 * the function that return all program line
 * @return string vector of all program
 */
GPUStringVector CPUProgram::getAllLine() const{
    return allLine;
}

void CPUProgram::setAllLine(GPUStringVector all) {
    allLine = all;
}

/**
 * function that returned special line of program
 * @param lineNum line number of bonded program counter
 * @return line that indicated program counter
 */
GPUString CPUProgram::getLine(const int lineNum) const{
    if(lineNum >= 0 && lineNum <= size())
        return getAllLine()[lineNum];
    else {
        cerr << "Out of size!!!" << endl;
        return getAllLine()[size()];
    }
}

/**
 * function that read all instructions in file
 * @param fileName name of file
 * @return 0 if there is a problem with file 1 otherwise
 */
int CPUProgram::ReadFile(const char *fileName) {
    ifstream inputStream;
    char* line = new char[256];
    inputStream.open(fileName);

    if(inputStream.is_open()){
        while(inputStream.getline(line, 256))
            allLine.push_back(line);
        return 1;
    }else{
        cerr << "Error opening file!!!" << endl;
        return 0;
    }
    delete [] line;
    inputStream.close();
}
/*** Overloading Operator [] ***/
GPUString CPUProgram::operator[](const int index) {
    if(index < 0 || index >= size()) {
        return "OUT OF RANGE(size)";
    }
    return getAllLine()[index];
}

/*** Overloading Operator ()  ***/
CPUProgram CPUProgram::operator ()(int index1, int index2) {
    CPUProgram result;

    if(index1 > index2 || index2 >= size()){
        result.setLine("FOR OPERATOR () OUT OF RANGE or index1 BIGGER than index2!");
        return result;
    }
    for (int i = index1; i <= index2; i++) {
        result.setLine(getLine(i));
    }

    return result;
}
/*** Overloading Operator (pre)-- ***/
CPUProgram& CPUProgram::operator --() {
    getAllLine().pop_back();
    return *this;
}
/*** Overloading Operator (post)-- ***/
CPUProgram CPUProgram::operator --(int) {

    CPUProgram before(getOption());
    before.setAllLine(getAllLine());
    getAllLine().pop_back();
    return before;
}
/*** Overloading Operator += ***/
CPUProgram& CPUProgram::operator +=(GPUString _instr) {
    setLine(_instr);
    return *this;
}

/*** Overloading Operator == ***/
bool operator ==(const CPUProgram& left, const CPUProgram& right) {
    return left.size() == right.size();
}

/*** Overloading Operator != ***/
bool operator !=(const CPUProgram& left, const CPUProgram& right) {
    return !(left == right);
}
/*** Overloading Operator < ***/
bool operator <(const CPUProgram& left, const CPUProgram& right) {
    return left.size() < right.size();
}
/*** Overloading Operator > ***/
bool operator >(const CPUProgram& left, const CPUProgram& right) {
    return left.size() > right.size();
}
/*** Overloading Operator <= ***/
bool operator <=(const CPUProgram& left, const CPUProgram& right) {
    return left.size() <= right.size();
}
/*** Overloading Operator >= ***/
bool operator >=(const CPUProgram& left, const CPUProgram& right) {
    return left.size() >= right.size();
}


/*** Overloading Operator << ***/
ostream& operator << (ostream& out, const CPUProgram& obj) {
    for(int i = 0; i < obj.size(); i++)
        out << obj.getAllLine()[i]<< endl;
    return out;
}
/*** Overloading Operator + ***/
CPUProgram operator +(const CPUProgram first, const CPUProgram second) {
    CPUProgram result;
    for(int i = 0; i < first.size(); i++)
        result.setLine(first.getLine(i));

    for(int i = 0; i < second.size(); i++)
        result.setLine(second.getLine(i));

    return result;
}
/*** Overloading Operator + ***/
CPUProgram operator +(const CPUProgram obj, const char* _instr) {
    CPUProgram result;
    for(int i = 0; i < obj.size(); i++)
        result.setLine(obj.getLine(i));
    result.setLine(_instr);
    return result;
}

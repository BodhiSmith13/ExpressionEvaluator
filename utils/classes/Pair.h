//
// Created by coops on 4/6/2026.
//

#ifndef CALCULATORY_PAIR_H
#define CALCULATORY_PAIR_H
#include <string>


class Pair {

    double operand1;
    double operand2;
    char op;

    public:

    Pair();

    Pair(double operand1, double operand2, char op);

    double getOperand1();

    double getOperand2();

    char getOp();

    std::string getPair();

    void setOperand1(double operand1);

    void setOperand2(double operand2);

    void setOp(char op);

    double simplify();

};


#endif //CALCULATORY_PAIR_H
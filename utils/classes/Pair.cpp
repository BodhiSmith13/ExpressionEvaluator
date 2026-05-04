//
// Created by coops on 4/6/2026.
//

#include "../classes/Pair.h"
#include "../functions/doubleToCleanString.h"

Pair::Pair() {

    operand1 = 0;
    operand2 = 0;
    op = '+';

} // end of default constructor Pair

Pair::Pair(double operand1, double operand2, char op) {

    this->operand1 = operand1;
    this->operand2 = operand2;
    this->op = op;

} // end of constructor Pair

double Pair::getOperand1() {return operand1;}

double Pair::getOperand2() {return operand1;}

char Pair::getOp() {return op;}

std::string Pair::getPair() {return doubleToCleanString(operand1) + op + doubleToCleanString(operand2);}

void Pair::setOperand1(double operand1) {this->operand1 = operand1;}

void Pair::setOperand2(double operand2) {this->operand2 = operand2;}

void Pair::setOp(char op) {this->op = op;}

double Pair::simplify() {

    if (op == '+') {return operand1 + operand2;}

    if (op == '-') {return operand1 - operand2;}

    if (op == '*') {return operand1 * operand2;}

    if (op == '/') {return operand1 / operand2;}

} // end of method simplify

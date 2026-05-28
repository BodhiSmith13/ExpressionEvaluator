ExpressionEvaluator is an expression parser coded in C++. The purpose of this program is to allow simple arithmetic expressions in the form of strings to be evaluated. Expressions can be copy-pasted directly into the terminal, or entered manually. The Shunting Yard Algorithm is not utilized. Instead, the program counts the number of operations based on the number of mathematical symbols within the inputted expression. Then, the program loops through the entire input using a for loop. The loop stops once it identifies a multiplication or division operator. If none of those operators can be found, another for loop searches the expression for addition or subtraction operators. By prioritizing multiplication/division over addition/subtraction, the order of operations is followed. Once an operator has been selected, a pair object is created. Pairs consist of two operands and an operator (called an op because operator is a reserved keyword). Once the pair has been identified, a method is called that finds the result of the pair. Then, the pair within the string is replaced with its final value. The process repeats itself until the input has been simplified. ExpressionEvaluator can evaluate decimals and negative numbers, but is unable to evaluate groupings and exponents. 

To build, open the project folder in CLion and run the default build configuration. CLion will automatically detect the CMakeLists.txt file.

Example Output:
```
Input: 1+2*3
Number of multiplication operators: 1
Number of division operators: 0
Number of addition operators: 1
Number of subtraction operators: 0
Number of negative numbers: 0
Total number of operators: 2
Multiplication detected.
Operator * found at index 3
Beginning search for operand1 at 2
Found  digit of operand1: 2
Found beginning of another operation, ending operand1: +
Beginning search for operand2 at 4
Found digit of operand2: 3
Operand1: 2
Operand2: 3
Input after replacement: 1+6
Addition detected.
Operator + found at index 1
Beginning search for operand1 at 0
Found  digit of operand1: 1
Beginning search for operand2 at 2
Found digit of operand2: 6
Operand1: 1
Operand2: 6
Input after replacement: 7
Result: 7
```

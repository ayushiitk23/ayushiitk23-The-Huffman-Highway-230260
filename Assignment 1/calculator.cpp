#include <iostream>
#include <cmath> 
#include <string>
using namespace std;

//  making functions for different operators

//Addition
double add(double a, double b) {
    return a + b;
}

//Subtraction
double subtract(double a, double b) {
    return a - b;
}

//Multiplication
double multiply(double a, double b) {
    return a * b;
}

//Division
double divide(double a, double b) {
    if (b == 0) {
        cout << "Error: Division by zero" << endl;
        exit(1);
    }
    return a / b;
}

//Modulus
double mod(double a, double b) {
    if (b == 0) {
        cout << "Error: Modulus by zero" << endl;
        exit(1);
    }
    return static_cast<int>(a) % static_cast<int>(b);
}
//log
double ln(double x) {
    if (x <= 0) {
        cout << "Error: Logarithm of non-positive number" << endl;
        exit(1);
    }
    return log(x);
}
//sin
double sinX(double x) {
    return sin(x);
}

double calculate(string op, double a, double b = 0) {
    

    if (op == "+") return add(a, b);
    if (op == "-") return subtract(a, b);
    if (op == "*") return multiply(a, b);
    if (op == "/") return divide(a, b);
    if (op == "%") return mod(a, b);
    if (op == "ln") return ln(a);
    if (op == "sin") return sinX(a);
    
    cout << "Error: Unknown operator " << op << endl;
    exit(1);
}

int main() {
 
    
    
    int n = 0;
    int numValues = 0;

    cout << "Enter the number of operators: ";
    cin >> n;
    string operators[n];//array containing all opeartors
    double values[n+1];//array containing all values 
    //taking the operators as input
    cout << "Enter operators (eg: + - * / % ln sin): ";
    for (int i = 0; i < n; ++i) {
        cin >> operators[i];
    }

    // taking the values for operation
    for (int i = 0; i < n; ++i) {
        if (operators[i] == "ln" || operators[i] == "sin") {
            cout << "Enter value for " << operators[i] << ": ";
            cin >> values[i];
            numValues++;
        } else {
            cout << "Enter the value for " << operators[i] << ": ";
            if (i == 0) {
                cin >> values[i];
                numValues++;
            }
            cin >> values[i + 1];
            numValues++;
        }
    }

    // Perform  the calculations 
    double result = values[0];
    int k = 1;
    for (int i = 0; i < n; ++i) {
        if (operators[i] == "ln" || operators[i] == "sin") {
            result = calculate(operators[i], result);
        } else {
            result = calculate(operators[i], result, values[k]);
            k++;
        }
    }

    //  result
    cout << "Output: " << result,"\n";

    return 0;
}

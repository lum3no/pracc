#include <iostream>
#include <stack>
#include <string>

using namespace std;

int calculate(string s) {
    stack<int> stack;
    int result = 0;
    int number = 0;
    int sign = 1;  // 1 means positive, -1 means negative

    for (int i = 0; i < s.length(); i++) {
        char c = s[i];
        if (isdigit(c)) {
            number = number * 10 + (c - '0');
        }
        else if (c == '+') {
            result += sign * number;
            number = 0;
            sign = 1;
        }
        else if (c == '-') {
            result += sign * number;
            number = 0;
            sign = -1;
        }
        else if (c == '(') {
            // Push the result and sign onto the stack, for later
            stack.push(result);
            stack.push(sign);
            // Reset the result and sign for the new sub-expression
            result = 0;
            sign = 1;
        }
        else if (c == ')') {
            result += sign * number;
            number = 0;
            result *= stack.top();  // this is the sign before the parenthesis
            stack.pop();
            result += stack.top();  // this is the result before the parenthesis
            stack.pop();
        }
    }
    // Add the last number in the expression
    result += sign * number;
    return result;
}

int main() {
    string expression1 = "1 + 1";
    string expression2 = " 2-1 + 2 ";
    string expression3 = "(1+(4+5+2)-3)+(6+8+9)";

    cout << "Result of expression1: " << calculate(expression1) << endl;
    cout << "Result of expression2: " << calculate(expression2) << endl;
    cout << "Result of expression3: " << calculate(expression3) << endl;

    return 0;
}

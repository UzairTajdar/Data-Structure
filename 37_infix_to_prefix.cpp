#include <iostream>
#include <stack>
#include <string>
using namespace std;

int precedence(char op) {
    if (op == '+' || op == '-')
        return 1;
    if (op == '*' || op == '/')
        return 2;
    return 0;
}

string infixToPrefix(const string &infix) {
    stack<char> operators;
    stack<string> operands;

    for (int i = 0; i < infix.length(); i++) {
        if (infix[i] == ' ')
            continue;

        if (isalnum(infix[i])) {
            string operand(1, infix[i]);
            operands.push(operand);
        } else if (infix[i] == '(') {
            operators.push(infix[i]);
        } else if (infix[i] == ')') {
            while (!operators.empty() && operators.top() != '(') {
                string operand2 = operands.top();
                operands.pop();
                string operand1 = operands.top();
                operands.pop();
                char op = operators.top();
                operators.pop();
                string newOperand = op + operand1 + operand2;
                operands.push(newOperand);
            }
            operators.pop(); // Pop the '('
        } else {
            while (!operators.empty() && precedence(operators.top()) >= precedence(infix[i])) {
                string operand2 = operands.top();
                operands.pop();
                string operand1 = operands.top();
                operands.pop();
                char op = operators.top();
                operators.pop();
                string newOperand = op + operand1 + operand2;
                operands.push(newOperand);
            }
            operators.push(infix[i]);
        }
    }

    while (!operators.empty()) {
        string operand2 = operands.top();
        operands.pop();
        string operand1 = operands.top();
        operands.pop();
        char op = operators.top();
        operators.pop();
        string newOperand = op + operand1 + operand2;
        operands.push(newOperand);
    }

    return operands.top();
}

int main() {
    string infix = "a+b*(c-d)/e";
    string prefix = infixToPrefix(infix);
    cout << "Infix Expression: " << infix << endl;
    cout << "Prefix Expression: " << prefix << endl;

    return 0;
}

#include<bits/stdc++.h>
using namespace std;

int precedence(char op) {
    if (op == '+' || op == '-') return 1;
    if (op == '*' || op == '/') return 2;
    if (op == '^') return 3;
    return 0;
}

string infixToPostfix(string exp) {
    stack<char> st;
    string result = "";

    for (int i = 0; i < exp.length(); i++) {
        char c = exp[i];

        if (isspace(c)) continue;

        if (isdigit(c)) {
            while (i < exp.length() && isdigit(exp[i])) {
                result += exp[i++];
            }
            result += ' ';
            i--;
        }
        else if (c == '(') {
            st.push('(');
        }
        else if (c == ')') {
            while (!st.empty() && st.top() != '(') {
                result += st.top();
                result += ' ';
                st.pop();
            }
            if (!st.empty()) st.pop();
        }
        else {
            while (!st.empty() && precedence(st.top()) >= precedence(c)) {
                result += st.top();
                result += ' ';
                st.pop();
            }
            st.push(c);
        }
    }

    while (!st.empty()) {
        result += st.top();
        result += ' ';
        st.pop();
    }
    return result;
}

double evaluatePostfix(string postfix) {
    stack<double> st;

    for (int i = 0; i < postfix.length(); i++) {
        if (isspace(postfix[i])) continue;

        if (isdigit(postfix[i])) {
            double num = 0;
            while (i < postfix.length() && isdigit(postfix[i])) {
                num = num * 10 + (postfix[i] - '0');
                i++;
            }
            st.push(num);
            i--;
        }
        else {
            double val2 = st.top(); st.pop();
            double val1 = st.top(); st.pop();

            switch (postfix[i]) {
                case '+': st.push(val1 + val2); break;
                case '-': st.push(val1 - val2); break;
                case '*': st.push(val1 * val2); break;
                case '/': st.push(val1 / val2); break;
                case '^': st.push(pow(val1, val2)); break;
            }
        }
    }
    return st.top();
}

int main() {
    string infix = "(12 + 34) * 56 - 78 / 9";

    string postfix = infixToPostfix(infix);
    cout << "Infix:   " << infix << endl;
    cout << "Postfix: " << postfix << endl;

    double result = evaluatePostfix(postfix);
    cout << "Result:  " << result << endl;

    return 0;
}

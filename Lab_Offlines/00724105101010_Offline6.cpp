#include <bits/stdc++.h>

using namespace std;

int priority(string s) {
  if (s == "^")
    return 3;
  if (s == "*" || s == "/")
    return 2;
  if (s == "+" || s == "-")
    return 1;
  return 0;
}

double applyOp(double a, double b, string op) {
  if (op == "+")
    return a + b;
  if (op == "-")
    return a - b;
  if (op == "*")
    return a * b;
  if (op == "/")
    return a / b;
  if (op == "^")
    return pow(a, b);
  return 0;
}

int main() {
  string infix;
  cout << "Enter Infix Expression: ";
  getline(cin, infix);

  vector<string> postfix;
  stack<string> s;

  for (int i = 0; i < infix.length(); i++) {
    if (isspace(infix[i]))
      continue;

    if (isdigit(infix[i])) {
      string num = "";
      while (i < infix.length() && isdigit(infix[i])) {
        num += infix[i++];
      }
      postfix.push_back(num);
      i--;
    } else if (infix[i] == '(') {
      s.push("(");
    } else if (infix[i] == ')') {
      while (!s.empty() && s.top() != "(") {
        postfix.push_back(s.top());
        s.pop();
      }
      s.pop();
    } else {
      string op(1, infix[i]);
      while (!s.empty() && priority(s.top()) >= priority(op)) {
        postfix.push_back(s.top());
        s.pop();
      }
      s.push(op);
    }
  }

  while (!s.empty()) {
    postfix.push_back(s.top());
    s.pop();
  }

  cout << "Postfix: ";
  for (string str : postfix)
    cout << str << " ";
  cout << endl;

  stack<double> evalStack;
  for (string token : postfix) {
    if (isdigit(token[0])) {
      evalStack.push(stod(token));
    } else {
      double val2 = evalStack.top();
      evalStack.pop();
      double val1 = evalStack.top();
      evalStack.pop();
      evalStack.push(applyOp(val1, val2, token));
    }
  }

  cout << "Result: " << evalStack.top() << endl;

  return 0;
}
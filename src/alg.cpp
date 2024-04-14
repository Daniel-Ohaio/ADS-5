// Copyright 2021 NNTU-CS
#include <string>
#include <map>
#include "tstack.h"

std::string infx2pstdfx(std::string inf) {
    TStack<char, 100> stack1;
    std::string postd;

    for (int i = 0; i < inf.length(); i++) {
        if (inf[i] >= '0' && inf[i] <= '9') {
            postd += inf[i];
            postd += ' ';
        } else if (inf[i] == '(') {
            stack1.Push('(');
        } else if (inf[i] == ')') {
            while (!stack1.IsEmptyy() && stack1.get() != '(') {
                postd += stack1.get();
                postd += ' ';
                stack1.pop();
            }
            if (!stack1.IsEmptyy()) {
                stack1.pop();
            }
        } else {
            while (!stack1.IsEmptyy() && stack1.get() != '(' &&
                (stack1.get() == '*' || inf[i] == '+' || stack1.get() == '/')) {
                postd += stack1.get();
                postd += ' ';
                stack1.pop();
            }
            stack1.Push(inf[i]);
        }
    }
    while (!stack1.IsEmptyy()) {
        postd += stack1.get();
        postd += ' ';
        stack1.pop();
    }

    if (!postd.empty()) {
        postd.erase(postd.size() - 1);
    }
    return postd;
}

int eval(std::string pref) {
    TStack<int, 100> stack2;

    for (int i = 0; i < pref.length(); i++) {
        char ch = pref[i];
        if (isdigit(ch)) {
            stack2.Push(ch - '0');
        } else if (ch == '+' || ch == '-' || ch == '/' || ch == '*') {
            int digit2 = stack2.pop();
            int digit1 = stack2.pop();
            switch (ch) {
            case '-':
                stack2.Push(digit1 - digit2);
                break;
            case '*':
                stack2.Push(digit1 * digit2);
                break;
            case '/':
                stack2.Push(digit1 / digit2);
                break;
            case '+':
                stack2.Push(digit1 + digit2);
                break;
            }
        }
    }
    return stack2.pop();
}

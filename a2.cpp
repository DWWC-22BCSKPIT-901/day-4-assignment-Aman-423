#include <iostream>
#include <vector>
#include <stack>
using namespace std;

int scoreOfParentheses(string s) {
    stack<int> stk;
    stk.push(0); // Start with a base score of 0

    for (char c : s) {
        if (c == '(') {
            stk.push(0); // Push a new score level for the new '(' context
        } else {
            int top = stk.top();
            stk.pop();
            int currentScore = max(2 * top, 1); // "()" gives 1, otherwise double the inner score
            stk.top() += currentScore; // Add to the previous level's score
        }
    }

    return stk.top();
}

int main() {
    string s = "(()(()))";
    cout << "Score of parentheses: " << scoreOfParentheses(s) << endl;
    return 0;
}
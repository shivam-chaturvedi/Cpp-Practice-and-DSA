#include <iostream>
#include <string>
#include <stack>
#include <algorithm>

using namespace std;

int main() {
    string s = "cabxbae";
    int x = 2890, y = 1643;

    int points = 0;
    stack<char> st;

    string first, second;
    int firstPoints, secondPoints;
    
    if (x > y) {
        first = "ab";
        firstPoints = x;
        second = "ba";
        secondPoints = y;
    } else {
        first = "ba";
        firstPoints = y;
        second = "ab";
        secondPoints = x;
    }

    for (char c : s) {
        if (!st.empty() && st.top() == first[0] && c == first[1]) {
            st.pop();
            points += firstPoints;
        } else {
            st.push(c);
        }
    }

    string remaining;
    while (!st.empty()) {
        remaining += st.top();
        st.pop();
    }
    reverse(remaining.begin(), remaining.end());

    for (char c : remaining) {
        if (!st.empty() && st.top() == second[0] && c == second[1]) {
            st.pop();
            points += secondPoints;
        } else {
            st.push(c);
        }
    }

    cout << points << endl;

    return 0;
}

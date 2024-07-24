#include <iostream>
#include <stack>
#include <unordered_map>
#include <string>
#include <cctype>
#include <vector>
#include <algorithm>

using namespace std;

string countOfAtoms(string formula) {
    stack<unordered_map<string, int>> stk;
    stk.push(unordered_map<string, int>());
    int n = formula.size();
    for (int i = 0; i < n; ) {
        if (formula[i] == '(') {
            stk.push(unordered_map<string, int>());
            i++;
        } else if (formula[i] == ')') {
            unordered_map<string, int> top = stk.top();
            stk.pop();
            int i_start = ++i, multiplier = 1;
            while (i < n && isdigit(formula[i])) i++;
            if (i > i_start) multiplier = stoi(formula.substr(i_start, i - i_start));
            for (auto &p : top) stk.top()[p.first] += p.second * multiplier;
        } else {
            int i_start = i++;
            while (i < n && islower(formula[i])) i++;
            string atom = formula.substr(i_start, i - i_start);
            i_start = i;
            while (i < n && isdigit(formula[i])) i++;
            int count = (i > i_start) ? stoi(formula.substr(i_start, i - i_start)) : 1;
            stk.top()[atom] += count;
        }
    }

    vector<pair<string, int>> counts(stk.top().begin(), stk.top().end());
    sort(counts.begin(), counts.end());
    string result;
    for (auto &p : counts) {
        result += p.first;
        if (p.second > 1) result += to_string(p.second);
    }
    return result;
}

int main() {
    string formula = "Mg(OH)2";

    cout << countOfAtoms(formula) << endl;  // Output: "K4N2O14S4"
    return 0;
}

#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>

using namespace std;

vector<int> survivedRobotsHealths(vector<int>& positions, vector<int>& healths, string directions) {
    vector<pair<int, int>> robots; 
    for (int i = 0; i < positions.size(); i++) {
        robots.push_back({positions[i], i});
    }

    sort(robots.begin(), robots.end());

    stack<int> s; 
    for (auto& robot : robots) {
        int index = robot.second;
        if (directions[index] == 'R') {
            s.push(index); 
        } else {
            while (!s.empty() && healths[s.top()] < healths[index]) {
                healths[s.top()] = 0; 
                healths[index]--;
                s.pop();
            }
            if (!s.empty() && healths[s.top()] == healths[index]) {
                healths[s.top()] = 0;
                healths[index] = 0;
                s.pop();
            } else if (!s.empty() && healths[s.top()] > healths[index]) {
                healths[s.top()]--;
                healths[index] = 0;
            }
        }
    }

    vector<int> final_healths;
    for (int h : healths) {
        if (h != 0) {
            final_healths.push_back(h);
        }
    }
    return final_healths;
}

int main() {
    vector<int> positions = {4, 37, 23};
    vector<int> healths = {50, 15, 49};
    string directions = "RLR";
    vector<int> result = survivedRobotsHealths(positions, healths, directions);

    for (auto health : result) {
        cout << health << " ";
    }

    return 0;
}

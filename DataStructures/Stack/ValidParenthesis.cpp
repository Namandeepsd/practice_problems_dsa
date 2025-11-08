
// Complexity: O(n) time | O(n) space

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        for (int i = 0; i < s.size(); i++) {
            if (s.at(i) == '(' || s.at(i) == '{' || s.at(i) == '[') {
                st.push(s[i]);
            }
            else {
                if (st.empty()) {
                    return false;
                }
                else if (s[i] == ')' && st.top() == '(') {
                    st.pop();
                }
                else if (s[i] == '}' && st.top() == '{') {
                    st.pop();
                }
                else if (s[i] == ']' && st.top() == '[') {
                    st.pop();
                }
                else {
                    return false;
                }
            }
        }
        return st.empty();
    }
};

// ------------------ Code Editor Test Program ------------------
void runTest(const string &s) {
    Solution sol;
    cout << "Input: \"" << s << "\"\n";
    cout << "Output: " << (sol.isValid(s) ? "true" : "false") << "\n\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cout << "=== Valid Parentheses Test Program ===\n\n";

    // Sample tests
    runTest("()");
    runTest("()[]{}");
    runTest("(]");
    runTest("([)]");
    runTest("{[]}");
    runTest("(((");
    runTest(")(");
    runTest(""); // empty string -> true

    // Optional: Uncomment to test custom input
    /*
    string input;
    cout << "Enter a string to test: ";
    cin >> input;
    cout << (Solution().isValid(input) ? "Valid\n" : "Invalid\n");
    */

    return 0;
}

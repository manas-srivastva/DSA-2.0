#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    string smallestSubsequence(string s) {
        // Step 1: Record the last occurrence index of each character
        vector<int> last(26, 0);
        for (int i = 0; i < s.length(); i++) {
            last[s[i] - 'a'] = i;
        }
        
        // Step 2: Track if a character is already in our result stack
        vector<bool> used(26, false);
        string st = ""; // Using a string directly as a monotonic stack
        
        // Step 3: Iterate through the string and maintain the monotonic property
        for (int i = 0; i < s.length(); i++) {
            char ch = s[i];
            
            // Skip if the character is already included in the stack
            if (used[ch - 'a']) continue;
            
            // Maintain lexicographical order by popping larger characters 
            // if they are guaranteed to appear later in the string
            while (!st.empty() && st.back() > ch && last[st.back() - 'a'] > i) {
                used[st.back() - 'a'] = false;
                st.pop_back();
            }
            
            st.push_back(ch);
            used[ch - 'a'] = true;
        }
        
        return st;
    }
};

int main() {
    Solution solver;

    // Test Case 1
    string s1 = "bcabc";
    cout << "Input:  " << s1 << "\n";
    cout << "Output: " << solver.smallestSubsequence(s1) << " (Expected: abc)\n\n";

    // Test Case 2
    string s2 = "cbacdcbc";
    cout << "Input:  " << s2 << "\n";
    cout << "Output: " << solver.smallestSubsequence(s2) << " (Expected: acdb)\n";

    return 0;
}
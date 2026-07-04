#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    int minOperations(string s1, string s2) {

        int n = s1.size();
        int ans = 0;

        vector<int> pos;

        for (int i = 0; i < n; i++) {

            // Need to create a 1
            if (s1[i] == '0' && s2[i] == '1')
                ans++;

            // Extra 1 that needs removal
            if (s1[i] == '1' && s2[i] == '0')
                pos.push_back(i);
        }

        for (int i = 0; i < pos.size(); i++) {

            // Two adjacent extra 1's
            if (i + 1 < pos.size() &&
                pos[i + 1] == pos[i] + 1) {

                ans++;
                i++;
            }
            else {
                ans += 2;
            }
        }

        return ans;
    }
};

int main() {

    string s1, s2;

    cin >> s1 >> s2;

    Solution obj;

    cout << obj.minOperations(s1, s2);

    return 0;
}
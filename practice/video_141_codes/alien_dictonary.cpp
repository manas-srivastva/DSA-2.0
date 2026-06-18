#include <iostream>
#include <vector>
#include <queue>
using namespace std;

string findOrder(vector<string> &words)
{
    int N = words.size();

    vector<int> adj[26];
    vector<int> InDeg(26, 0);
    vector<bool> present(26, false);

    // Mark characters present
    for(auto word : words)
    {
        for(char ch : word)
        {
            present[ch - 'a'] = true;
        }
    }

    // Build graph
    for(int i = 0; i < N - 1; i++)
    {
        string str1 = words[i];
        string str2 = words[i + 1];

        int j = 0, k = 0;

        while(j < str1.size() &&
              k < str2.size() &&
              str1[j] == str2[k])
        {
            j++;
            k++;
        }

        // Invalid case: ["abcd","ab"]
        if(k == str2.size() && j < str1.size())
            return "";

        if(j < str1.size() && k < str2.size())
        {
            adj[str1[j] - 'a'].push_back(str2[k] - 'a');
            InDeg[str2[k] - 'a']++;
        }
    }

    queue<int> q;

    for(int i = 0; i < 26; i++)
    {
        if(present[i] && InDeg[i] == 0)
            q.push(i);
    }

    string ans = "";

    while(!q.empty())
    {
        int node = q.front();
        q.pop();

        ans += char('a' + node);

        for(int neigh : adj[node])
        {
            InDeg[neigh]--;

            if(InDeg[neigh] == 0)
                q.push(neigh);
        }
    }

    int cnt = 0;

    for(int i = 0; i < 26; i++)
    {
        if(present[i])
            cnt++;
    }

    // Cycle check
    if(ans.size() != cnt)
        return "";

    return ans;
}

int main()
{
    vector<string> words = {
        "baa",
        "abcd",
        "abca",
        "cab",
        "cad"
    };

    string ans = findOrder(words);

    if(ans == "")
        cout << "Invalid Ordering\n";
    else
        cout << ans << endl;

    return 0;
}
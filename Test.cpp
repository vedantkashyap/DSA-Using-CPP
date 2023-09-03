#include <bits/stdc++.h>
#include <vector>
#include <string>

using namespace std;

struct TrieNode {
    TrieNode* children[26];
    bool isEnd;

    TrieNode() {
        for (int i = 0; i < 26; i++) {
            children[i] = nullptr;
        }
        isEnd = false;
    }
};

void insertWord(TrieNode* root, const string& word) {
    TrieNode* node = root;
    for (char c : word) {
        int index = c - 'a';
        if (!node->children[index]) {
            node->children[index] = new TrieNode();
        }
        node = node->children[index];
    }
    node->isEnd = true;
}

int minExtraCharacters(string s, const vector<string>& dictionary) {
    TrieNode* root = new TrieNode();

    for (const string& word : dictionary) {
        insertWord(root, word);
    }

    int n = s.length();
    vector<int> dp(n + 1, INT_MAX);
    dp[0] = 0;

    for (int i = 1; i <= n; i++) {
        TrieNode* node = root;
        for (int j = i; j >= 1; j--) {
            int index = s[j - 1] - 'a';
            if (!node->children[index]) {
                break;
            }
            node = node->children[index];
            if (node->isEnd) {
                dp[i] = min(dp[i], dp[j - 1] + (i - j + 1));
            }
        }
    }

    int result = n;
    for (int i = 1; i <= n; i++) {
        result = min(result, dp[i]);
    }

    return n - result;
}

int main() {
    string s = "leetscode";
    vector<string> dictionary = {"leet", "code"};

    int result = minExtraCharacters(s, dictionary);
    cout << "Minimum extra characters left over: " << result << endl;

    return 0;
}

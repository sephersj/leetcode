//============================================================================
// Word Ladder
// Given two words (start and end), and a dictionary, find the length of 
// shortest transformation sequence from start to end, such that:
//
// Only one letter can be changed at a time
// Each intermediate word must exist in the dictionary
// For example,
//
// Given:
// start = "hit"
// end = "cog"
// dict = ["hot","dot","dog","lot","log"]
// As one shortest transformation is "hit" -> "hot" -> "dot" -> "dog" -> "cog",
// return its length 5.
//============================================================================

#include <iostream>
#include <unordered_set>
#include <queue>
#include <string>

using namespace std;

class Solution {
public:
    int ladderLength(string start, string end, unordered_set<string> &dict) {
        queue<string> cq, nq;
        unordered_set<string> visit;
        cq.push(start), visit.insert(start);
        int level = 1;
        while (!cq.empty()) {
            while (!cq.empty()) {
                string cur = cq.front();
                cq.pop();
                for (int i = 0; i < cur.size(); i++) {
                    char t = cur[i];
                    for (char c = 'a'; c <= 'z'; c++) {
                        cur[i] = c;
                        if (cur == end) return level + 1;
                        if (dict.count(cur) && !visit.count(cur)) visit.insert(cur), nq.push(cur);
                    }
                    cur[i] = t;
                }
            }
            swap(cq, nq);
            level++;
        }
        return 0;
    }
};

int main() {
    Solution sol;
    {
        unordered_set<string> dict = { "hot", "dot", "dog", "lot", "log" };
        cout << sol.ladderLength("hit", "cog", dict) << endl;
    }

    {
        unordered_set<string> dict = { "a", "b", "c" };
        cout << sol.ladderLength("a", "c", dict) << endl;
    }

    return 0;
}
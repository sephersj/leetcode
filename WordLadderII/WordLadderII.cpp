//============================================================================
// Word Ladder II
// Given two words (start and end), and a dictionary, find all shortest 
// transformation sequence(s) from start to end, such that:
//
// Only one letter can be changed at a time
// Each intermediate word must exist in the dictionary
// For example,
//
// Given:
// start = "hit"
// end = "cog"
// dict = ["hot","dot","dog","lot","log"]
// Return
//   [
//       ["hit","hot","dot","dog","cog"],
//       ["hit","hot","lot","log","cog"]
//   ]
// Note:
//  All words have the same length.
//  All words contain only lowercase alphabetic characters.
//============================================================================

#include <iostream>
#include <string>
#include <unordered_set>
#include <unordered_map>

using namespace std;

class Solution {
public:
    vector<vector<string>> findLadders(string start, string end, unordered_set<string> &dict) {
        unordered_set<string> cq, nq, visit;
        unordered_map<string, vector<string> > froms;
        cq.insert(start);
        while (!cq.empty() && !cq.count(end)) {
            for (auto & cur : cq) visit.insert(cur);
            for (auto & cur : cq) {
                auto next = cur;
                for (int i = 0; i < next.size(); i++) {
                    char t = next[i];
                    for (char c = 'a'; c <= 'z'; c++) {
                        next[i] = c;
                        if (next == end || (dict.count(next) && !visit.count(next))) nq.insert(next), froms[next].push_back(cur);
                    }
                    next[i] = t;
                }
            }
            swap(cq, nq);
            nq.clear();
        }
        vector<string> path;
        vector<vector<string> > res;
        path.push_back(end);
        go(end, start, froms, path, res);
        return res;
    }

    void go(string & cur, string & end, unordered_map<string, vector<string> > & froms, vector<string> & path, vector<vector<string> > & res) {
        if (cur == end) {
            res.push_back(vector<string>(path.rbegin(), path.rend()));
            return;
        }
        for (auto & next : froms[cur]) {
            path.push_back(next);
            go(next, end, froms, path, res);
            path.pop_back();
        }
    }
};

int main() {
    Solution sol;
    {
        unordered_set<string> dict = { "hot", "dot", "dog", "lot", "log" };
        auto res = sol.findLadders("hit", "cog", dict);
        for (auto it1 : res) {
            for (auto it2 : it1) cout << it2 << " ";
            cout << endl;
        }
    }
    return 0;
}
//============================================================================
// Reverse Words in a String
// Given an input string, reverse the string word by word.
//
// For example,
// Given s = "the sky is blue",
// return "blue is sky the".
//
// click to show clarification.
//
// Clarification:
// What constitutes a word?
// A sequence of non-space characters constitutes a word.
// Could the input string contain leading or trailing spaces?
// Yes. However, your reversed string should not contain leading or trailing 
// spaces.
// How about multiple spaces between two words?
// Reduce them to a single space in the reversed string.
//============================================================================

#include <iostream>
#include <algorithm>

using namespace std;

class Solution {
public:
    void reverseWords(string &s) {
        removeSpaces(s);
        if (s.empty()) return;
        int N = s.size(), i = 0, j = 0;
        while (true) {
            i = j;
            while (j < N && !isspace(s[j])) j++;
            reverse(s.begin()+i, s.begin()+j);
            if (j == N) break;
            j++;
        }
        reverse(s.begin(), s.end());
    }

    void removeSpaces(string & s) {
        int N = s.size(), i = 0, j = 0;
        while (i < N) {
            while (i < N && isspace(s[i])) i++;
            if (i == N) break;
            if (j != 0) s[j++] = ' ';
            while (i < N && !isspace(s[i])) s[j++] = s[i++];
        }
        s.resize(j);
    }
};

int main() {
    Solution sol;
    string s = "  the  sky  is   blue  ";
    sol.reverseWords(s);
    cout << "[" << s << "]" << endl;
    return 0;
}

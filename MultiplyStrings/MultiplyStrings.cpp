//============================================================================
// Multiply Strings
//
// Given two numbers represented as strings, return multiplication of the
// numbers as a string.
//
// Note: The numbers can be arbitrarily large and are non-negative.
//============================================================================

#include <iostream>

using namespace std;

class Solution {
public:
    string multiply(string num1, string num2) {
        if (num1.empty() || num2.empty()) return "";
        int n1 = num1.size(), n2 = num2.size();
        string num3(n1 + n2, '0');
        for (int i = n1 - 1; i >= 0; i--) {
            int sum = 0, carry = 0;
            for (int j = n2 - 1; j >= 0; j--) {
                sum = carry + (num3[i + j + 1] - '0') + (num1[i] - '0') * (num2[j] - '0');
                num3[i + j + 1] = '0' + sum % 10;
                carry = sum / 10;
            }
            num3[i] = '0' + carry;
        }
        while (num3.size() > 1 && (*num3.begin()) == '0') num3.erase(num3.begin());
        return num3;
    }
};

int main() {
    return 0;
}
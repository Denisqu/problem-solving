/*
Given an integer x, return true if x is a
palindrome
, and false otherwise.



Example 1:

Input: x = 121
Output: true
Explanation: 121 reads as 121 from left to right and from right to left.
Example 2:

Input: x = -121
Output: false
Explanation: From left to right, it reads -121. From right to left, it becomes
121-. Therefore it is not a palindrome. Example 3:

Input: x = 10
Output: false
Explanation: Reads 01 from right to left. Therefore it is not a palindrome.


Constraints:

-231 <= x <= 231 - 1


Follow up: Could you solve it without converting the integer to a string?
*/

#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
  bool isPalindrome(int x) {
    const auto str = to_string(x);

    auto forwardIter = str.cbegin();
    auto reverseIter = --str.cend();
    // bool isEven = str.length() % 2;
    int len = str.length();
    int midLength = len / 2;
    int step = 0;

    while (forwardIter != reverseIter) {
      if (*forwardIter != *reverseIter && step < midLength)
        return false;

      --reverseIter;
      ++forwardIter;
      ++step;

      if (step > midLength)
        return true;
    }

    return true;
  }
};

int main() {

  Solution sol;
  cout << sol.isPalindrome(1221);

  return 0;
}
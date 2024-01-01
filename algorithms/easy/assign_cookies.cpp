/*
Assume you are an awesome parent and want to give your children some cookies. But, you should give each child at most one cookie.

Each child i has a greed factor g[i], which is the minimum size of a cookie that the child will be content with; and each cookie j has a size s[j]. If s[j] >= g[i], we can assign the cookie j to the child i, and the child i will be content. Your goal is to maximize the number of your content children and output the maximum number.

 

Example 1:

Input: g = [1,2,3], s = [1,1]
Output: 1
Explanation: You have 3 children and 2 cookies. The greed factors of 3 children are 1, 2, 3. 
And even though you have 2 cookies, since their size is both 1, you could only make the child whose greed factor is 1 content.
You need to output 1.
Example 2:

Input: g = [1,2], s = [1,2,3]
Output: 2
Explanation: You have 2 children and 3 cookies. The greed factors of 2 children are 1, 2. 
You have 3 cookies and their sizes are big enough to gratify all of the children, 
You need to output 2.
 

Constraints:

1 <= g.length <= 3 * 104
0 <= s.length <= 3 * 104
1 <= g[i], s[j] <= 231 - 1
*/

#include <vector>
#include <map>
#include <algorithm>
using namespace std;

class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        // Sort the arrays
        std::sort(g.begin(), g.end());
        std::sort(s.begin(), s.end());
        
        // Initialize count for tracking assignments of cookies
        int count = 0;
        // Initialize two pointers i and j to iterate on g and s
        int i = 0, j = 0;
        
        // Iterate through the arrays
        while (i < g.size() && j < s.size()) {
            // If the size of the cookie is greater than or equal to the child's greed,
            // assign the cookie to the child and move both pointers
            if (g[i] <= s[j]) {
                count++;
                i++;
            }
            // Move the cookie pointer to the next cookie, regardless of assignment
            j++;
        }
        
        return count;
    }
};
/*
LeetCode 60 - Permutation Sequence

Approach:
- Store numbers from 1 to n in a vector.
- Precompute factorials from 0! to n! to avoid repeated calculations.
- Convert k to 0-based indexing (k--).
- At every position:
    - The remaining permutations are divided into blocks of
      (remainingElements - 1)!.
    - Find which block the k-th permutation belongs to:
          index = k / blockSize
    - Pick the number at that index.
    - Remove it from the vector.
    - Update:
          k = k % blockSize
- Repeat until all numbers are used.

Time Complexity:
- O(n)  : Initialize numbers vector
- O(n)  : Precompute factorials
- O(n²) : Vector erase operation (O(n)) performed n times
- Overall: O(n²)

Space Complexity:
- O(n) : Numbers vector
- O(n) : Factorial array
- O(n) : Output string
- Overall: O(n)

Revision Keywords:
- Factorial Number System
- K-th Permutation
- Greedy
- Precomputed Factorial
- Block Size
- 0-Based Indexing
*/

class Solution {
public:

    string getPermutation(int n, int k) {

        vector<int> nums;

        for(int i = 1; i <= n; i++)
            nums.push_back(i);

        // Precompute factorials
        vector<int> fact(n + 1);
        fact[0] = 1;

        for(int i = 1; i <= n; i++)
            fact[i] = fact[i - 1] * i;

        string s;

        // Convert to 0-based indexing
        k--;

        while(!nums.empty()) {

            // Size of one permutation block
            int total = fact[nums.size() - 1];

            // Required block index
            int p = k / total;

            // Remaining permutation index
            k %= total;

            s += char(nums[p] + '0');

            nums.erase(nums.begin() + p);
        }

        return s;
    }
};

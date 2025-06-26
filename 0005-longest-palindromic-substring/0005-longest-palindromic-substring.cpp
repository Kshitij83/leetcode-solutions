class Solution {
public:
    string longestPalindrome(string s) {
        if (s.empty()) return "";

        int start = 0, maxLength = 1; // Variables to store the starting index and maximum length of palindrome found.

        for (int i = 0; i < s.length(); i++) {
            // Check for odd-length palindromes (single character center)
            int len1 = expandAroundCenter(s, i, i);
            // Check for even-length palindromes (two character center)
            int len2 = expandAroundCenter(s, i, i + 1);
            int len = max(len1, len2);

            // Update maximum length and starting index if a longer palindrome is found
            if (len > maxLength) {
                maxLength = len;
                start = i - (maxLength - 1) / 2; // Calculate the new starting index
            }
        }

        return s.substr(start, maxLength); // Return the longest palindromic substring
    }

private:
    int expandAroundCenter(const string &s, int left, int right) {
        while (left >= 0 && right < s.length() && s[left] == s[right]) {
            left--; // Expand left
            right++; // Expand right
        }
        return right - left - 1; // Return the length of the palindrome
    }
};
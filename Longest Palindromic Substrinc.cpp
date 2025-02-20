class Solution {
  public:
      string longestPalindrome(string s) {
          if (s.length() == 1){
              return s;
          }
  
          int maxLeftIndex = 0;
          int maxLength = 1;  // A single character is always a palindrome
  
          for (int i = 1; i < s.length(); i++){
              int length = 0;
              int leftIndex = i - 1;
              int rightIndex = i;
  
              // Case 1: Even-length palindrome
              if (s[i] == s[i - 1]) {
                  length = 2;
  
                  // Expand around center
                  while (leftIndex - 1 >= 0 && rightIndex + 1 < s.length() && s[leftIndex - 1] == s[rightIndex + 1]) {
                      leftIndex--;
                      rightIndex++;
                      length += 2;
                  }
  
                  // Update longest palindrome if needed
                  if (length > maxLength) {
                      maxLength = length;
                      maxLeftIndex = leftIndex;
                  }
              } 
  
              // Case 2: Odd-length palindrome
              if (i < s.length() - 1 && s[i - 1] == s[i + 1]) {
                  length = 3;
                  leftIndex = i - 1;
                  rightIndex = i + 1;
  
                  // Expand around center
                  while (leftIndex - 1 >= 0 && rightIndex + 1 < s.length() && s[leftIndex - 1] == s[rightIndex + 1]) {
                      leftIndex--;
                      rightIndex++;
                      length += 2;
                  }
  
                  // Update longest palindrome if needed
                  if (length > maxLength) {
                      maxLength = length;
                      maxLeftIndex = leftIndex;
                  }
              }            
          }
          return s.substr(maxLeftIndex, maxLength);
      }
  };
public class Solution
{
  public int LengthOfLongestSubstring(string s)
  {
    char[] charArray = s.ToCharArray();

    HashSet<int> charsInWindow = new HashSet<int>();

    int windowStart = 0;
    int windowEnd = 0;
    int maxLength = 0;

    while (windowEnd < charArray.Length)
    {
      char endChar = charArray[windowEnd];
      if (charsInWindow.Contains(endChar) && windowStart != windowEnd)
      {
        charsInWindow.Remove(charArray[windowStart]);
        windowStart++;
      }
      else
      {
        charsInWindow.Add(endChar);
        windowEnd++;
        int currentLength = windowEnd - windowStart;
        if (currentLength > maxLength)
        {
          maxLength = currentLength;
        }
      }
    }

    return maxLength;
  }
}
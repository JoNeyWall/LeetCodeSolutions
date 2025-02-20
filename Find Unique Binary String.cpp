class Solution
{
public:
  string findDifferentBinaryString(vector<string> &nums)
  {
    int digitCount = nums[0].length();
    int maxNum = pow(2, digitCount);
    unordered_set<int> numsInSet;

    for (string s : nums)
    {
      int value = 0;
      int power = digitCount - 1;
      for (int i = 0; i < digitCount; i++)
      {
        if (s[i] == '1')
        {
          value += pow(2, power);
        }
        power--;
      }
      numsInSet.insert(value);
      cout << value << endl;
    }

    string binary = "";
    for (int decimal = 0; decimal <= maxNum; decimal++)
    {
      if (!numsInSet.contains(decimal))
      {
        cout << "Not in set: " << decimal << endl;
        if (decimal == 0)
        {
          binary = "0";
        }
        else
        {
          while (decimal > 0)
          {
            binary += (decimal % 2) + '0';
            decimal /= 2;
          }
        }

        reverse(binary.begin(), binary.end());

        while (binary.length() < digitCount)
        {
          binary = "0" + binary;
        }

        break;
      }
    }

    return binary;
  }
};
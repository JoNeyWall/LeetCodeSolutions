public class Solution
{
    public int[] TwoSum(int[] nums, int target)
    {
        int[] returnNums = new int[2];
        for (int i = 0; i < nums.Length; i++)
        {
            int currentFirst = nums[i];
            int targetSecond = target - currentFirst;
            for (int j = i + 1; j < nums.Length; j++)
            {
                if (nums[j] == targetSecond)
                {
                    returnNums[0] = i;
                    returnNums[1] = j;
                    return returnNums;
                }
            }
        }
        return returnNums;
    }
}
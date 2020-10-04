/*
 * @lc app=leetcode.cn id=34 lang=cpp
 *
 * [34] 在排序数组中查找元素的第一个和最后一个位置
 */

// @lc code=start
class Solution
{
public:
    vector<int> searchRange(vector<int> &nums, int target)
    {
        vector<int> ans;
        if (!nums.size())
        {
            ans = {-1, -1};
            return ans;
        }

        int m = biSearch(0, nums.size() - 1, nums, target);
        int n = biSearch(0, nums.size() - 1, nums, target + 1);
        if (nums[m] == target)
        {
            if (nums[n] == target)
                ans = {m, n};
            else
            {
                ans = {m, n - 1};
            }
        }
        else
        {
            ans = {-1, -1};
        }
        return ans;
    }
    int biSearch(int left, int right, vector<int> &nums, int target)
    {
        while (right > left)
        {
            int mid = (left + right) / 2;
            if (nums[mid] >= target)
            {
                right = mid;
            }
            else if (nums[mid] < target)
            {
                left = mid + 1;
            }
        }
        return left;
    }
};
// @lc code=end

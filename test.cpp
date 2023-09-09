#include <bits/stdc++.h>
using namespace std;

int combinationSum4(vector<int> &nums, int target)
{
    vector<unsigned int> dp(target + 1, 0);
    dp[0] = 1;

    for (int i = 1; i <= target; ++i)
    {
        for (int num : nums)
        {
            if (i >= num)
            {
                dp[i] += dp[i - num];
            }
        }
    }
    for (int x : dp)
    {
        cout << x << " ";
    }
    cout << endl;
    return dp[target];
}

int main()
{
    vector<int> nums = {1, 2, 3, 4};
    int target = 6;
    int result = combinationSum4(nums, target);
    cout << "Number of combinations: " << result << endl;
    return 0;
}

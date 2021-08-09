#include<iostream>
#include <vector>

int maxSubArray(std::vector<int>& nums)
{
    // Case: Only 1 element
    if (nums.size() == 1)
    {
        return nums[0];
    }

    /*
     * Cases:   All positive    - return sum of entire vector
     *          All negative    - return negative number closest to zero
     *          Mixed numbers   - return largest contiguous sub array
     */

    // Variable for tracking current positive total
    int currTotal = 0;

    // Variable for tracking max value obtained so far
    int max = INT_MIN;

    // Loop over entire vector
    for (int i = 0; i < nums.size(); ++i)
    {
        // Add value at current index to running total
        currTotal += nums[i];

        // If that running total is greater than the current max obtained value
        // Then update the max value
        if (currTotal > max)
        {
            max = currTotal;
        }

        /* 
        * If our current total ends up a negative value then reset the current total back to zero
        * Why do need to do this?
        * 
        * ALL NEGATIVE ARRAY EXPLANATION:
        * We need to do this as in an array with all negative numbers the largest sub-array value
        * that could be returned is -1 if it exists in the array, as the current total continually
        * adds up the consecutive index values we would never find a negative value greater than
        * whatever is stored at index[0]
        * 
        * ALL POSITIVE ARRAY EXPLANATION:
        * This check is only relevant for arrays with negative numbers involved, either entirely
        * or partially, if you KNOW it is +ve array then this check is NOT necessary
         */ 
        if (currTotal < 0)
        {
            currTotal = 0;
        }
    }

    return max;
}

int main()
{
    // TEST CASES
    std::vector<int> test0{ -2, -3, -4, -1, -2, -1, -5, -3 };       // Should return -1
    std::vector<int> test1{ -7, -3, -4, -1, -2, -1, -5, 0 };        // Should return 0
    std::vector<int> test2{ -2, -3, -4, -1, -2, -1, -5, 0 };        // Should return 0
    std::vector<int> test3{ -2, -3, 4, -1, -2, 1, 5, -3 };          // Should return 7
    std::vector<int> test4{ 2, 3, 4, 1, 2, 1, 5, 3, 0 };            // Should return 21
    std::vector<int> test5{ 2 };                                    // Should return 2

    int ans = maxSubArray(test3);

    std::cout << "The max sub array is " << ans << '\n';

    return 0;
}
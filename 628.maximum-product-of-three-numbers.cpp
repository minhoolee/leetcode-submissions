/*
 * [628] Maximum Product of Three Numbers
 *
 * https://leetcode.com/problems/maximum-product-of-three-numbers/description/
 *
 * algorithms
 * Easy (44.75%)
 * Total Accepted:		41.6K
 * Total Submissions: 92.9K
 * Testcase Example:	'[1,2,3]'
 *
 * Given an integer array, find three numbers whose product is maximum and
 * output the maximum product.
 * 
 * Example 1:
 * 
 * Input: [1,2,3]
 * Output: 6
 * 
 * 
 * 
 * Example 2:
 * 
 * Input: [1,2,3,4]
 * Output: 24
 * 
 * 
 * 
 * Note:
 * 
 * The length of the given array will be in range [3,104] and all elements are
 * in the range [-1000, 1000].
 * Multiplication of any three numbers in the input won't exceed the range of
 * 32-bit signed integer.
 * 
 * 
 */
class Solution {
public:
	/**
	 * First approach
	 *
	 * Sort and compare top three max versus top two min * top max
	 *
	 * Time: O(nlogn)
	 * Space: O(nlogn)
	 */

	/**
	 * Better approach
	 *
	 * Save top three max and top two min, then
	 * compare top three max versus top two min * top max
	 *
	 * Using max and min is better than positive and negative because it still
	 * works regardless of the total number of pos/neg in the array
	 *
	 * Time: O(n)
	 * Space: O(1)
	 *
	 * Set min1, min2 to INT_MAX
	 * Set max1, max2, max3 to INT_MIN
	 * For i from start to end in nums
	 *   If nums[i] < min1 
	 *	   Set min2 to min1
	 *	   Set min1 to nums[i]
	 *   Else if nums[i] < min2
	 *	   Set min2 to nums[i]
	 *	 Else if nums[i] > max1
	 *	   Set max3 to max2
	 *	   Set max2 to max1
	 *	   Set max1 to nums[i]
	 *	 Else if nums[i] > max2
	 *	   Set max3 to max2
	 *	   Set max2 to nums[i]
	 *	 Else if nums[i] > max3
	 *	   Set max3 to nums[i]
	 * Return max of min1*min2*max1 and max1*max2*max3
	 */

	/**
	 * Test cases:
	 * [-1,2,3,-10] -> 30
	 * [-1,2,3,-10,3] -> 30
	 * [1,2,3,-10] -> 6
	 * [1,2,-7,-10,-12] -> 240
	 * [0,0,0] -> 0
	 * [-1,-2,-3] -> -6
	 */
	int maximumProduct(vector<int>& nums) {
		int min1 = INT_MAX, min2 = min1;
		int max1 = INT_MIN, max2 = max1, max3 = max1;

		for (vector<int>::iterator it = nums.begin(); it != nums.end(); ++it) {
			// For top 2 smallest (often negative) numbers
			if (*it < min1) {
				min2 = min1;
				min1 = *it;
			} else if (*it < min2) {
				min2 = *it;
			}

			// For top 3 largest (often positive) numbers
			if (*it > max1) {
				max3 = max2;
				max2 = max1;
				max1 = *it;
			} else if (*it > max2) {
				max3 = max2;
				max2 = *it;
			} else if (*it > max3) {
				max3 = *it;
			}
		}

		return max(min1*min2*max1, max1*max2*max3);
	}
};

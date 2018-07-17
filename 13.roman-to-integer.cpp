/*
 * [13] Roman to Integer
 *
 * https://leetcode.com/problems/roman-to-integer/description/
 *
 * algorithms
 * Easy (48.82%)
 * Total Accepted:    254.7K
 * Total Submissions: 521.7K
 * Testcase Example:  '"III"'
 *
 * Roman numerals are represented by seven different symbols: I, V, X, L, C, D
 * and M.
 * 
 * 
 * Symbol       Value
 * I             1
 * V             5
 * X             10
 * L             50
 * C             100
 * D             500
 * M             1000
 * 
 * For example, two is written as II in Roman numeral, just two one's added
 * together. Twelve is written as, XII, which is simply X + II. The number
 * twenty seven is written as XXVII, which is XX + V + II.
 * 
 * Roman numerals are usually written largest to smallest from left to right.
 * However, the numeral for four is not IIII. Instead, the number four is
 * written as IV. Because the one is before the five we subtract it making
 * four. The same principle applies to the number nine, which is written as IX.
 * There are six instances where subtraction is used:
 * 
 * 
 * I can be placed before V (5) and X (10) to make 4 and 9. 
 * X can be placed before L (50) and C (100) to make 40 and 90. 
 * C can be placed before D (500) and M (1000) to make 400 and 900.
 * 
 * 
 * Given a roman numeral, convert it to an integer. Input is guaranteed to be
 * within the range from 1 to 3999.
 * 
 * Example 1:
 * 
 * 
 * Input: "III"
 * Output: 3
 * 
 * Example 2:
 * 
 * 
 * Input: "IV"
 * Output: 4
 * 
 * Example 3:
 * 
 * 
 * Input: "IX"
 * Output: 9
 * 
 * Example 4:
 * 
 * 
 * Input: "LVIII"
 * Output: 58
 * Explanation: C = 100, L = 50, XXX = 30 and III = 3.
 * 
 * 
 * Example 5:
 * 
 * 
 * Input: "MCMXCIV"
 * Output: 1994
 * Explanation: M = 1000, CM = 900, XC = 90 and IV = 4.
 * 
 */
class Solution {
public:
  // Test cases:
  // III -> 3
  // IV -> 4
  // IX -> 9
  // LVIII -> 58
  // MCMXCIV -> 1994
  int romanToInt(string s) {
    // Set sum to 0
    int sum = 0;

    // Loop until end of s
    for (int i = 0; i < s.length(); ++i) {
      // If current letter is not last letter and current letter is exception
      if (i < s.length()-1 && 
          ((s.at(i) == 'I' && (s.at(i+1) == 'V' || s.at(i+1) == 'X')) ||
           (s.at(i) == 'X' && (s.at(i+1) == 'L' || s.at(i+1) == 'C')) ||
           (s.at(i) == 'C' && (s.at(i+1) == 'D' || s.at(i+1) == 'M')))) {

        // Add next letter - current letter to sum
        sum += romanNumToDec(s.at(i+1)) - romanNumToDec(s.at(i));

        // Increment loop counter an additional letter
        ++i;
      }
      else {
        // Else add s.at(i) to sum
        sum += romanNumToDec(s.at(i));
      }
    }

    // Return sum
    return sum;
  }

  int romanNumToDec(char c) {
    int num = -1;
    switch (c) {
      case 'I':
        num = 1;
        break;
      case 'V':
        num = 5;
        break;
      case 'X':
        num = 10;
        break;
      case 'L':
        num = 50;
        break;
      case 'C':
        num = 100;
        break;
      case 'D':
        num = 500;
        break;
      case 'M':
        num = 1000;
        break;
      default:
        std::cout << "Incorrect input" << std::endl;
    }
    return num;
  }
};

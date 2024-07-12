

class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
         int maxCount = 0;  // To keep track of the maximum count of consecutive ones
        int currentCount = 0;  // To keep track of the current count of consecutive ones

        for (int num : nums) {
            if (num == 1) {
                currentCount++;
                if (currentCount > maxCount) {
                    maxCount = currentCount;
                }
            } else {
                currentCount = 0;
            }
        }

        return maxCount;
    }
};
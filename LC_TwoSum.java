import java.io.*;
import java.util.*;
class Solution {
    int[] twoSum(int[] nums, int target) {
        int i = 0, index;
        Hashtable<Integer, Integer> ht = new Hashtable<>();
        for (i = 0; i < nums.length; i++)
        {
            ht.put(nums[i], i);
        }
        for (i = 0; i < nums.length; i++)
        {
            if (ht.containsKey(target - nums[i]))
            {
                index = ht.get(target - nums[i]);
                if (index != i)
                {
                    return new int[]{i, index};
                }
            }
        }
        return null;
    }
}
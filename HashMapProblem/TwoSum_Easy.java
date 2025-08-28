/* 1. Two Sum
Easy
Topics
premium lock icon
Companies
Hint
Given an array of integers nums and an integer target, return indices of the two numbers such that they add up to target.

You may assume that each input would have exactly one solution, and you may not use the same element twice.

You can return the answer in any order.

 

Example 1:

Input: nums = [2,7,11,15], target = 9
Output: [0,1]
Explanation: Because nums[0] + nums[1] == 9, we return [0, 1].
Example 2:

Input: nums = [3,2,4], target = 6
Output: [1,2]
Example 3:

Input: nums = [3,3], target = 6
Output: [0,1]
 

Constraints:

2 <= nums.length <= 104
-109 <= nums[i] <= 109
-109 <= target <= 109
Only one valid answer exists.
 

Follow-up: Can you come up with an algorithm that is less than O(n2) time complexity? */

import java.util.Arrays;
class TwoSum_Easy {
      public static int[] twoSum(int[] nums, int target) {
        //int arr[] = new int[2];
        if(nums.length<2 || nums.length> 10000){
            System.out.print("Beyond the constraint boundation 1");
        //    arr[0]=0;arr[1]=0;
            return new int []{0,0};
        }
         if(target< -1_000_000_000 || target>1_000_000_000){
                    System.out.print("Beyond the constraint boundation 2");
            //arr[0]=0;arr[1]=0;
            return  new int []{0,0};
            }
        //int arr[] = new int[2];
        //int sumCalc=0;
        for(int i=0;i<nums.length-1;i++){
            for(int j=i+1; j<nums.length;j++){
               // sumCalc = nums[i]+num[j];
                if(nums[j]< -1_000_000_000 || nums[j]>1_000_000_000){
                    System.out.print("Beyond the constraint boundation 3");
                     //arr[0]=0;arr[1]=0;
            return  new int []{0,0};
                }
                if ((nums[i]+nums[j]) == target){
                    // arr[0]=i;arr[1]=j;
                      return  new int []{i,j};
                }


            }

        }

       // arr[0]=0;arr[1]=0;
            return  new int []{0,0};

    }


    public static void main(String[] args){
        TwoSum_Easy obj = new TwoSum_Easy();
        int arr[] = {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,26,27,28,29,30,31,32,33,34,35,36,37,38,39,40,41,42,43,44,45,46,47,48,49,50,51,52,53,54,55,56,57,58,59,60,61,62,63,64,65,66,67,68,69,70,71,72,73,74,75,76,77,78,79,80,81,82,83,84,85,86,87,88,89,90,91,92,93,94,95,96,97,98,99,100,101,102,103,104,105,106,107,108,109,110,111,112,113,114,115,116,117,118,119,120,121,122,123,124,125,126,127,128,129,130,131,132,133,134,135,136,137,138,139,140,141,142,143,144,145,146,147,148,149,150,151,152,153,154,155,156,157,158,159,160,161,162,163,164,165,166,167,168,169,170,171,172,173,174,175,176,177,178,179,180,181,182,183,184,185,186,187,188,189,190,191,192,193,194,195,196,197,198,199,200,201,202,203,204,205,206,207,208,209,210,211,212,213,214,215,216,217,218,219,220,221,222,223,224,225,226,227,228,229,230,231,232,233,234,235,236,237,238,239,240,241,242,243,244,245,246,247,248,249,250,251,252,253,254,255,256,257,258,259,260,261,262};
        System.out.println(Arrays.toString(obj.twoSum(arr,266)));
    }
}


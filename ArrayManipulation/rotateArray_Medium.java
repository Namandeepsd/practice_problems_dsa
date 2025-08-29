/* 
Given an integer array nums, rotate the array to the right by k steps, where k is non-negative.

 

Example 1:

Input: nums = [1,2,3,4,5,6,7], k = 3
Output: [5,6,7,1,2,3,4]
Explanation:
rotate 1 steps to the right: [7,1,2,3,4,5,6]
rotate 2 steps to the right: [6,7,1,2,3,4,5]
rotate 3 steps to the right: [5,6,7,1,2,3,4]
Example 2:

Input: nums = [-1,-100,3,99], k = 2
Output: [3,99,-1,-100]
Explanation: 
rotate 1 steps to the right: [99,-1,-100,3]
rotate 2 steps to the right: [3,99,-1,-100]
 

Constraints:

1 <= nums.length <= 105
-231 <= nums[i] <= 231 - 1
0 <= k <= 105
 */

class rotateArray_Medium {
    public void rotate(int[] nums, int k) {
        int temp=0;
       for(int i=0;i<k;i++){
           temp=nums[nums.length-1];
            for(int j=nums.length-1;j>0;j--){
                nums[j]=nums[j-1];
            }
            nums[0]=temp;
       }

        for (int i = 0; i < nums.length; i++) {
            System.out.print(nums[i]+" ");
        }

    }

    public static void main(String[] args) {
        rotateArray_Medium obj = new rotateArray_Medium();
        int arr[] = {-1,-100,3,99};
        obj.rotate(arr, 2);
    }
}


// SUGGESTION Do with two pointer approach for better efficiency and optimal flow.
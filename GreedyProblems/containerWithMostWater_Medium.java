/* You are given an integer array height of length n. There are n vertical lines drawn such that the two endpoints of the ith line are (i, 0) and (i, height[i]).

Find two lines that together with the x-axis form a container, such that the container contains the most water.

Return the maximum amount of water a container can store.

Notice that you may not slant the container.

 

Example 1:


Input: height = [1,8,6,2,5,4,8,3,7]
Output: 49
Explanation: The above vertical lines are represented by array [1,8,6,2,5,4,8,3,7]. In this case, the max area of water (blue section) the container can contain is 49.
Example 2:

Input: height = [1,1]
Output: 1
 

Constraints:

n == height.length
2 <= n <= 105
0 <= height[i] <= 104 */

public class containerWithMostWater_Medium{

     public int maxArea(int[] height) {
        int areaBack = 0; int areaFront = 0;
        int areaMax=0;
        for(int pointer = 0; pointer<height.length; pointer++){

            //loop from back
            for(int i=height.length-1;i>pointer;i--){
                
                if(height[pointer]<=height[i]){ // agar back wala tower bada ho toh
                    areaBack = height[pointer]*(i-pointer);
                    break;
                }
                else{
                    areaBack = height[i]*(i-pointer);
                }
            }


            //loop from front

            for(int i=0;i<pointer;i++){
                if(height[pointer]<=height[i]){
                    areaFront= height[pointer] * (pointer-i);
                    break;
                }
                else{
                    areaFront= height[i] * (pointer-i);
                }
            }

            if (areaMax<(areaBack>areaFront?areaBack:areaFront)){
                areaMax = (areaBack>areaFront?areaBack:areaFront);
            }

        }

        return areaMax;
    }
    public static void main(String[] args) {
        containerWithMostWater_Medium obj = new containerWithMostWater_Medium();
        int arr[] = {1,1};
        System.out.println(obj.maxArea(arr));
    }
}

// Solve using two pointers as it is optimal approach provides better efficiency.
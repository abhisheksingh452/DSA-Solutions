// class Solution {
//     public int[] twoSum(int[] nums, int target) {
//         for(int i=0;i<nums.length;i++){
//         //     for(int j=i+1;j<nums.length;j++){
//         //         int c=nums[i]+nums[j];
//         //         if(c==target){
//         //             int []b={i,j};
//         //             return b;
//         //         }
//         //     }
//         // }
//         // return new int[] {};

//     }
// }
class Solution {
    public int[] twoSum(int[] nums, int target) {
        Map<Integer, Integer> numMap = new HashMap<>();
        for (int i = 0; i < nums.length; i++) {
            int complement = target - nums[i];
            if (numMap.containsKey(complement)) {
                return new int[]{numMap.get(complement), i};
            }
            numMap.put(nums[i], i);
        }
        return new int[]{}; 
    }
}
class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        if (nums.size()==2) return nums[0];

        int slow=nums[0], fast = nums[nums[0]];
        //nums[i] = j and nums[j]=k ==> i points to k

        //detecting cycle
        while (slow != fast){
            slow = nums[slow]; //next node after current node is pointed to nums[slow]th index
            fast = nums[nums[fast]];
        }

        /*acc to floyd, the distance b/w initial node and beginning of cycle is same as the distance
          from current detected node in the cycle and beginning of the cycle */
        fast = 0; //new slow pointer starting from beginning of array

        while(slow != fast){
            slow = nums[slow];
            fast = nums[fast];
        }

        return fast;
    }
};

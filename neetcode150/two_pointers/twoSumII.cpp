class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        vector<int> output;
        int j=numbers.size()-1, i=0, diff ;
        
        while(i<j){
            diff = target - numbers[i];
            if (diff> numbers[j]){
                i++;
            } else if (diff<numbers[j]){
                j--;
            } else {
                output.push_back(i+1);
                output.push_back(j+1);
                break;
            }        
        }

        return output;
    }
};

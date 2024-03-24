class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        vector<int> temp(nums1.begin(), nums1.begin()+m);
        nums1.clear();
        int i=0, j=0, count=0;
        while (i<m && j<n){
            if (temp[i]<nums2[j]){
                nums1.push_back(temp[i]);
                i++;
            }
            else{                                
                nums1.push_back(nums2[j]);
                j++;
            }
            count++;
        }
        if (i<m){
            nums1.insert(nums1.begin()+count,temp.begin()+i, temp.end());
            count += m-i;
        }
        if (j<n)
            nums1.insert(nums1.begin()+count,nums2.begin()+j, nums2.end()) ;
    }
};

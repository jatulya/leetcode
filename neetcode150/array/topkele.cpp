class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> count;
        vector <int> result; 

      //storing each element in a hash map
        for (int n: nums){
            count[n]++;
        }

      //turning the map into a vector so that we can compare and sort according to the frequency
        vector<pair<int, int>> vec(count.begin(), count.end());

      //setting the sorting rule
        auto compare = [](const auto& a, const auto& b){
            return a.second > b.second;
        };
        sort(vec.begin(), vec.end(), compare);

      //pushing the top k elements from the sorted frequency vector
        for (int i=0; i<k; i++){
            result.push_back(vec[i].first);
        }
        
        return result;
        
    }
};


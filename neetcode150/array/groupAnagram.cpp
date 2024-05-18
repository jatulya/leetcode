class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> output;
        unordered_map<string, vector<string>> sortedLetters;
        string key;

        for (string word: strs){
            key = word;
            sort(key.begin(), key.end());
            sortedLetters[key].push_back(word);
        }

        for(auto keys : sortedLetters){
            output.push_back(keys.second);
        }
        return output;
    }
};

class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        if (ransomNote.size() > magazine.size())
            return false;
        
        unordered_map<char, int> count;

        for (char c: magazine)
            if (count.find(c)!=count.end())
                count[c]++;
            else count[c]=1;
        
        for (char c: ransomNote)
            if (count.find(c)==count.end() || count[c]==0)
                return false;
            else count[c]--;
        
        return true;
    }
};

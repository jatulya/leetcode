class Solution:
    def wordPattern(self, pattern: str, s: str) -> bool:       
        words = list(s.split(' '))
        
        if len(pattern)!=len(words):
            return False
   
        map1 = {} #char -> word
        map2 = {} #word -> char

        for i,ch in enumerate(pattern):
            if ch in map1 and map1[ch] != words[i]:
                return False
            if words[i] in map2 and map2[words[i]] != ch:
                return False
            map1[ch] = words[i]
            map2[words[i]] = ch
        
        return True


        
        

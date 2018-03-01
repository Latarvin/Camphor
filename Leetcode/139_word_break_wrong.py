class Solution:
    def wordBreak(self, s, wordDict):
        """
        :type s: str
        :type wordDict: List[str]
        :rtype: bool
        """
        if s in wordDict:
            return True
        
        word_len_max = 0
        for word in wordDict:
            if len(word) > word_len_max:
                word_len_max = len(word)
            
        for i in range(word_len_max, 0, -1):
            if s[0:i] in wordDict:
                return self.wordBreak(s[i:], wordDict)
        
        return False
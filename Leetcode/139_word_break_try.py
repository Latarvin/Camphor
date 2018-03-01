class Solution:
    def wordBreak(self, s, wordDict):
        """
        :type s: str
        :type wordDict: List[str]
        :rtype: bool
        """
        
        if s in wordDict:
            return True

        word_len_min = 0
        for word in wordDict:
            if len(word) < word_len_min:
                word_len_min = len(word)

        for i in range(word_len_min:-word_len_min)
            return self.wordBreak(s[0:i+1]) and self.wordBreak(s[i+1:])
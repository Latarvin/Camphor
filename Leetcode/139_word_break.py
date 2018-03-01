class Solution:
    def wordBreak(self, s, wordDict):
        """
        :type s: str
        :type wordDict: List[str]
        :rtype: bool
        """
        
        len_break = [0]

        for i in range(1, len(s)+1):
            for k in len_breakable:
                if s[k+1:i] in wordDict:
                    len_break.append(i)
                    break
        
        if len(s) in len_break:
            return True
        else:
            return False
class Solution:
    """
    @param: n: An integer
    @return: true if this is a happy number or false
    """
    def isHappy(self, n):
        # write your code here
        if n == 1:
            return True

        while n > 1000:
            temp = 0
            while n:
                temp = temp + (n%10) * (n%10)
                n = n / 10
            
            n = temp
        
        candidate = [n]
        while n is not 1:
            temp = 0;
            while n > 0:
                temp = temp + (n%10) * (n%10)
                n = n / 10
            
            n = temp

            if n in candidate:
                return False
            else:
                candidate.append(n)

        return True


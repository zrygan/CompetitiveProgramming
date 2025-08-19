class Solution:
    def hammingWeight(self, n: int) -> int:
        ctr = 0 
        while n > 1:            
            if (n % 2 == 1):    
                ctr += 1        
            n = n // 2          
        return ctr + n
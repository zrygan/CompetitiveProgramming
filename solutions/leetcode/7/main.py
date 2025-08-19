class Solution(object):
    def reverse(self, x: int) -> int:

        negative = -1 if x < 0 else 1
        
        x *= negative
        
        x = int(str(x)[::-1])
        
        if x > 2147483647:
            return 0

        return x * negative
from math import floor

class Solution:
    def mySqrt(self, x: int) -> int:
        if x == 0 or x == 1:
            return x
        
        start = 1
        end = 2147483647
        mid = 0
        while start <= end:
            mid = (start + end) // 2
            if mid * mid < x:
                start = mid + 1
            elif mid * mid > x:
                end = mid - 1
            else:
                return floor(mid)
        
        return floor(end)
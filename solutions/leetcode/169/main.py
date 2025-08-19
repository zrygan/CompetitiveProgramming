from typing import List
class Solution:
    def majorityElement(self, nums: List[int]) -> int:
        ctr = 0             
        elem = -1           
        
        for i in nums:     
            if ctr == 0:   
                elem = i   
                ctr = 1    
            elif elem == i:
                ctr += 1   
            else:          
                ctr -= 1   

        return elem
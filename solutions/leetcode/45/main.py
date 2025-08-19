class Solution(object):
    def jump(self, nums):
        if len(nums) <= 1:
            return 0
        elif len(nums) == 2:
            return 1
        
        n_jumps = 0     
        curr = 0        
        farthest = 0    
        
        for i in range(len(nums) - 1):  
            farthest = max(farthest, i + nums[i])   
            if i == curr:                           
                n_jumps += 1                        
                curr = farthest                     
                if curr >= len(nums) - 1:           
                    break
        return n_jumps
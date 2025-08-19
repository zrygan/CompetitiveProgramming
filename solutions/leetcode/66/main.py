class Solution(object):
    def plusOne(self, digits):
        digits = digits[::-1]
        
        carry = 1
        
        for i in range(len(digits)):    
            sum = digits[i] + carry     
            digits[i] = sum % 10        
            carry = sum // 10           
            if not carry:               
                break                   

        digits = digits[::-1]
        
        if carry:                       
            digits.insert(0, carry)     
            
        return digits
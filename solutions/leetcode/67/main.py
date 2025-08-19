class Solution:
    def addBinary(self, a: str, b: str) -> str:
        if a == "0" and b == "0":
            return "0"
        elif a == "1" and b == "0" or a == "0" and b == "0":
            return "1"
        elif a == "1" and b == "1":
            return "10"

        res = []
        car = 0

        a, b = a[::-1], b[::-1]
        
        max_len = len(a) if len(a) > len(b) else len(b)

        for i in range(max_len):

            bit_a = int(a[i]) if i < len(a) else 0
            bit_b = int(b[i]) if i < len(b) else 0

            sum = bit_a + bit_b + car
            
            res.append(str(sum % 2))

            car = sum >> 1
        
        if car:
            res.append(str(car))
        
        return "".join(res[::-1])
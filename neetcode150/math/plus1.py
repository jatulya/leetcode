class Solution:
    def plusOne(self, digits: List[int]) -> List[int]:
        plus1 = []
        carry = 1
        i = -1

        while i>= -len(digits):
            if digits[i] +  carry == 10:
                plus1.append(0)
                carry = 1
            else:
                plus1.append(digits[i] + carry)
                carry = 0
            i -= 1
        
        if carry:
            plus1.append(1)
            
        return plus1[::-1]
        

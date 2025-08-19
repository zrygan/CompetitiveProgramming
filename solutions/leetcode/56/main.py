class Solution(object):
    def lengthOfLastWord(self, s):
        return len([word for word in s.split(' ') if word != ''][-1])
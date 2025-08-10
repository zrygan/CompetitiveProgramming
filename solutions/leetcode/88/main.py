from typing import List

class Solution:
    def merge(self, nums1: List[int], m: int, nums2: List[int], n: int) -> None:
        """
        Do not return anything, modify nums1 in-place instead.
        """
        end1 = m - 1        
        end2 = n - 1        

        while end1 >= 0 and end2 >= 0:
            if nums1[end1] > nums2[end2]:
                nums1[avail] = nums1[end1]
                end1 -= 1
            else:
                nums1[avail] = nums2[end2]
                end2 -= 1
            avail -= 1

        while end2 >= 0:
            nums1[avail] = nums2[end2]
            end2 -= 1
            avail -= 1
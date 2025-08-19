from typing import Optional
from collections import deque

class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

class Solution:
  def isSymmetric(self, root: Optional[TreeNode]) -> bool:
    if root is None:
       return False
    
    if not root:
      return True
    
    queue = deque([(root.left, root.right)])
    
    while queue:
      left, right = queue.popleft()
      
      if not left and not right:
        continue
      if not left or not right or left.val != right.val:
        return False
      
      queue.append((left.left, right.right))
      queue.append((left.right, right.left))
    
    return True

class RecursiveSolution:
  def isSymmetric(self, root: Optional[TreeNode]) -> bool:
    if not root:
        return True
      
    def isMirror(t1: Optional[TreeNode], t2: Optional[TreeNode]) -> bool:
        if not t1 and not t2:
          return True
        if not t1 or not t2:
          return False
        return (t1.val == t2.val and
            isMirror(t1.left, t2.right) and
            isMirror(t1.right, t2.left))
    
    return isMirror(root.left, root.right)
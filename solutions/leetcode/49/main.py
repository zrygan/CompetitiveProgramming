from typing import List
from collections import defaultdict

class Solution:
  def groupAnagrams(self, strs: List[str]) -> List[List[str]]:
    m = defaultdict(list)
    for w in strs:
      key = tuple(sorted(w)) 
      m[key].append(w)
    return list(m.values())

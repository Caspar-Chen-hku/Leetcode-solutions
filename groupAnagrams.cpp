class Solution:
    def groupAnagrams(self, strs: List[str]) -> List[List[str]]:
        ans = {}
        for s in strs:
            temp = tuple(sorted(s))
            if temp in ans:
                ans[temp].append(s)
            else:
                ans[temp] = [s]
        return list(ans.values())   
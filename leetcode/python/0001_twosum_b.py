class Solution(object):
    def twoSum(self, nums, target):
        """
        :type nums: List[int]
        :type target: int
        :rtype: List[int]
        """
        D = {}
        for i, e in enumerate(nums):
            k = target - e
            if k in D:
                return [D[k], i]
            else:
                D[e] = i


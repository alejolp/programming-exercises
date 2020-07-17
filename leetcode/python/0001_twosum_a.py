class Solution(object):
    def twoSum(self, nums, target):
        """
        :type nums: List[int]
        :type target: int
        :rtype: List[int]
        """
        nums = list(enumerate(nums))
        nums.sort(key=lambda e: e[1])
        
        a = 0
        b = len(nums) - 1
        
        while a < b:
            k = nums[a][1] + nums[b][1]
            if k > target:
                b = b - 1
            elif k < target:
                a = a + 1
            else:
                return [nums[a][0], nums[b][0]]


class Solution(object):
    def twoSum(self, nums, target):
        """
        :type nums: List[int]
        :type target: int
        :rtype: List[int]
        """
        nums = list(enumerate(nums))
        nums.sort(key=lambda e:e[1])
        
        for i in range(len(nums)):
            a = 0
            b = len(nums)
            w = target - nums[i][1]
            while a < b:
                print a, b
                m = a + (b - a) / 2
                if m == i:
                    a = a + 1
                elif nums[m][1] > w:
                    b = m
                elif nums[m][1] < w:
                    a = m + 1
                elif nums[m][1] == w:
                    return [nums[i][0], nums[m][0]]
                else:
                    assert False

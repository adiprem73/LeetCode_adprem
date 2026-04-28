class Solution(object):
    def nextPermutation(self, nums):
        n = len(nums)
        bp = -1

        # Step 1: find breakpoint
        for i in range(n - 2, -1, -1):
            if nums[i] < nums[i + 1]:
                bp = i
                break

        # Step 2: if no breakpoint → reverse whole array
        if bp == -1:
            nums.reverse()
            return

        # Step 3: find just greater element from right
        for i in range(n - 1, bp, -1):
            if nums[i] > nums[bp]:
                nums[i], nums[bp] = nums[bp], nums[i]
                break

        # Step 4: reverse suffix
        nums[bp + 1:] = reversed(nums[bp + 1:])
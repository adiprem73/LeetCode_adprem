class Solution(object):
    def check(self, nums):
        n = len(nums)
        cnt =0
        for i in range(n):
            if(nums[i] > nums[(i+1)%n]):
                print(nums[i]," , ",nums[(i+1)%n])
                cnt+=1
        return cnt<=1
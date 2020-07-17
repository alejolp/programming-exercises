object Solution {
    def singleNumber(nums: Array[Int]): Int = {
        nums.reduce((x, y) => x ^ y)
    }
}
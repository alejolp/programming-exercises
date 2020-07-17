object Solution {
    def singleNumber(nums: Array[Int]): Int = {
        var x: Int = 0
        for (y <- nums) {
            x = x ^ y
        }
        return x
    }
}

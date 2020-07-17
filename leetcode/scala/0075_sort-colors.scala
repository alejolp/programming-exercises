object Solution {
  def sortColors(nums: Array[Int]): Unit = {
    //
    // https://en.wikipedia.org/wiki/Dutch_national_flag_problem
    // 
    
    var i = 0
    var j = 0
    var n = nums.length - 1

    while (j <= n) {
      if (nums(j) < 1) {
        var t = nums(i)
        nums(i) = nums(j)
        nums(j) = t
        i = i + 1
        j = j + 1
      } else if (nums(j) > 1) {
        var t = nums(n)
        nums(n) = nums(j)
        nums(j) = t
        n = n - 1
      } else {
        j = j + 1
      }
    }
  }
}

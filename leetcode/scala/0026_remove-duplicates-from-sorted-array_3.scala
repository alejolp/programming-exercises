object Solution {
  def removeDuplicates(nums: Array[Int]): Int = {
    var p1 = 0
    var p2 = 0
    // 1 2 3 3 3 4

    while (p2 < nums.length) {
        if (p1 != p2) {
      nums(p1) = nums(p2) }
      while (p2 < nums.length && nums(p2) == nums(p1)) {
        p2 = p2 + 1
      }
      p1 = p1 + 1
    }
    
    return p1
  }
}
object Solution {
  def removeElement(nums: Array[Int], x: Int): Int = {
    var p1 = 0
    var p2 = 0

    while (p2 < nums.length) {
      while ((p2 < nums.length) && (nums(p2) == x)) {
        p2 = p2 + 1
      }
      if ((p2 < nums.length)) {
          if ((p1 != p2)) {
        nums(p1) = nums(p2) }

        p1 = p1 + 1
        p2 = p2 + 1
      }
    }

    return p1
  }
}

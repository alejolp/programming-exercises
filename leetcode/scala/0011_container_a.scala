object Solution {
  def maxArea(height: Array[Int]): Int = {
    var maxval: Int = 0
    var l: Int = 0
    var r: Int = height.length - 1
    while (l < r) {
      val area = (r - l) * Math.min(height(l), height(r))
      maxval = Math.max(maxval, area)
      if (height(l) < height(r)) {
        l = l + 1
      } else {
        r = r - 1
      }
    }
    return maxval
  }
}

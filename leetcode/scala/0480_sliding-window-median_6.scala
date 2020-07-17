import scala.util.Sorting

object Solution {
  def medianSlidingWindow(nums: Array[Int], k: Int): Array[Double] = {
    var R = Array.ofDim[Double](nums.length - k + 1)

    for (i <- 0 to R.length - 1) {
      var x = nums.slice(i, i + k)
      Sorting.quickSort(x)
      // 0 1 2 3
      val m : Double = if ((k % 2) == 0) { (1.0 * x(k / 2 - 1) + 1.0 * x(k / 2)) / 2.0 } else { 1.0 *  x(k / 2) }
      R(i) = m
    }

    return R
  }
}


import scala.util.Sorting
import scala.collection.mutable.TreeSet

object Solution {
  def F1(nums: Array[Int], k: Int): Array[Double] = {
    var R = Array.ofDim[Double](nums.length - k + 1)

    for (i <- 0 to R.length - 1) {
      var x = nums.slice(i, i + k)
      Sorting.quickSort(x)
      // 0 1 2 3
      val m: Double = if ((k % 2) == 0) {
        (1.0 * x(k / 2 - 1) + 1.0 * x(k / 2)) / 2.0
      } else {
        1.0 * x(k / 2)
      }
      R(i) = m
    }

    return R
  }

  def F2(nums: Array[Int], k: Int): Array[Double] = {
    var R = Array.ofDim[Double](nums.length - k + 1)
    var A = Array.ofDim[Boolean](nums.length)

    var minT = TreeSet.empty[(Int, Int)]
    var maxT = TreeSet.empty[(Int, Int)]

    for (i <- 0 to nums.length - 1) {
      if (minT.size < maxT.size) {
        minT.add((nums(i), i))
        A(i) = true
      } else {
        maxT.add((nums(i), i))
        A(i) = false
      }

      if (minT.size + maxT.size > k) {
        // 1. Remove nums(i - k) from minT/maxT
        // 2. Rebalance the trees, in a way that abs(size-size) <= 1
        val e = ((nums(i - k), i - k))
        if (A(i - k)) { minT.remove(e) } else { maxT.remove(e) }
      }

      if (minT.size + maxT.size > 1) {
        while (Math.abs(minT.size - maxT.size) > 1 ||
          (if (minT.isEmpty) Int.MinValue else minT.max._1) > (if (minT.isEmpty) Int.MaxValue else maxT.min._1)) {
          if (minT.size < maxT.size) {
            val e = maxT.min
            maxT.remove(e)
            minT.add(e)
            A(e._2) = true
          } else {
            val e = minT.max
            minT.remove(e)
            maxT.add(e)
            A(e._2) = false
          }
        }
      }

      //println(i)
      //println(minT.toList)
      //println(maxT.toList)

      if (minT.size + maxT.size == k) {
        var m = if ((k % 2) == 1) {
          if (minT.size < maxT.size) {
            1.0 * maxT.min._1
          } else {
            1.0 * minT.max._1
          }
        } else {
          (1.0 * maxT.min._1 + 1.0 * minT.max._1) / 2.0
        }

        R(i - k + 1) = m
      }
    }

    return R
  }

  def medianSlidingWindow(nums: Array[Int], k: Int): Array[Double] = {
    if (k < 100) F1(nums, k)
    else F2(nums, k)
  }
}

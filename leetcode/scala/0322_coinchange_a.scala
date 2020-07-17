
import scala.util.Sorting

object Solution {
  def F(coins: Array[Int], amount: Int, count: Int, H: Array[Int]): Int = {
    var R: Int = -1
    if (H(amount) != 0) return H(amount)

    for (c <- coins) {
      if (c < amount) {
        val x = F(coins, amount - c, count + 1, H)
        if (x != -1) {
          if (R == -1 || (x + 1) < R) R = x + 1
        }
      } else if (c == amount) {
        R = 1
      }
    }

    H(amount) = R
    return R
  }

  def coinChange(coins: Array[Int], amount: Int): Int = {
    if (amount == 0) return 0
    var H: Array[Int] = Array.ofDim(amount + 1)
    Sorting.stableSort(coins, (x: Int, y: Int) => y < x)
    
    val x = F(coins, amount, 1, H)
    // println(H)
    return x
  }
}

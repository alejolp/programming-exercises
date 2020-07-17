
import scala.collection.mutable.HashMap
import scala.util.Sorting

object Solution {
  def F(coins: Array[Int], amount: Int, count: Int, H: HashMap[Int, Int]): Int = {
    var R: Int = -1
    var e = H.get(amount)
    if (e.isDefined) return e.get

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

    H.put(amount, R)
    return R
  }

  def coinChange(coins: Array[Int], amount: Int): Int = {
    if (amount == 0) return 0
    var H: HashMap[Int, Int] = HashMap.empty
    Sorting.stableSort(coins, (x: Int, y: Int) => y < x)
    
    val x = F(coins, amount, 1, H)
    println(H)
    x
  }
}

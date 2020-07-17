
import scala.collection.mutable.StringBuilder
import scala.collection.mutable.ListBuffer

object Solution {
  def convert(s: String, numRows: Int): String = {
    var R: StringBuilder = new StringBuilder
    var L: ListBuffer[(Int, Int, Int)] = ListBuffer.empty
    var X = 0
    var Y = 0
    var goingDown = true

    if (numRows == 1) return s
    
    for (i <- 0 to s.length() - 1) {
      L += ((i, X, Y))
      
      if (goingDown) {
        Y += 1
        
        if (Y == numRows) {
          Y = numRows - 2
          X += 1
          goingDown = false
        }
      } else {
        Y -= 1
        X += 1
        if (Y < 0) {
          Y = 1
          X -= 1
          goingDown = true
        }
      }
    }
    
    println(L)
    
    import scala.math.Ordering.Implicits._
    
    L = L.sortWith((a : (Int, Int, Int), b : (Int, Int, Int)) => (a._3, a._2, a._1) < (b._3, b._2, b._1))

    println(L)
    
    for ((i, x, y) <- L) {
      R.append(s.charAt(i))
    }
    
    return R.result()
  }
}


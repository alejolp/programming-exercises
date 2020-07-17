
import scala.collection.mutable.StringBuilder

object Solution {
  def addBinary(a: String, b: String): String = {
    var B: StringBuilder = new StringBuilder
    var L: Int = Math.max(a.size, b.size) - 1
    var r: Int = 0
    
    for (i <- 0 to L) {
      val a1 = if (i < a.length) { a(a.length() - i - 1) - '0' } else { 0 }
      val a2 = if (i < b.length) { b(b.length() - i - 1) - '0' } else { 0 }
      val m = a1 + a2 + r
      B.insert(0, ((m % 2)))
      r = m / 2
    }
    
    if (r > 0) {
      B.insert(0, (r))
    }
    
    return B.toString()
  }
}

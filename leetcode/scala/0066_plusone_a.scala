
import scala.collection.mutable.ArrayBuffer

object Solution {
  def plusOne(digits: Array[Int]): Array[Int] = {
    var r = 1
    var i = digits.length - 1
    var B: ArrayBuffer[Int] = ArrayBuffer.fill(digits.length)(0)
    
    while (i >= 0) {
      val m = digits(i) + r
      B(i) = m % 10
      r = m / 10
      i = i - 1
    }
    
    if (r > 0) {
      B.insert(0, r)
    }
    
    return B.toArray
  }
}

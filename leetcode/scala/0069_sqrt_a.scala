object Solution {
    def mySqrt(x: Int): Int = {
      var i: Long = 0
      while ((i*i) <= x) {
        i = i + 1
      }
      return i.toInt - 1
    }
}

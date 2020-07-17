
object Solution {
    def reverse(x: Int): Int = {
        var a : Long = x
        var R : Long = 0
        
        while (a != 0) {
          var m = a % 10
          a = a / 10
          R = R * 10 + m
          if (R > Int.MaxValue || R < Int.MinValue) {
            return 0
          }
        }
        
        return R.toInt
    }
}

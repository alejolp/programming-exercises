object Solution {
  def trap(height: Array[Int]): Int = {
    var a1 = new Array[Int](height.length)
    var a2 = new Array[Int](height.length)
    var x = 0
    var R = 0
    
    for (i <- 0 to height.length - 1) {
      x = Math.max(x, height(i))
      a1(i) = x
    }

    x = 0
    
    for (i <- height.length - 1 to 0 by -1) {
      x = Math.max(x, height(i))
      a2(i) = x
    }

    for (i <- 0 to height.length - 1) {
      R += Math.min(a1(i), a2(i)) - height(i)
    }
    
    return R
  }
}

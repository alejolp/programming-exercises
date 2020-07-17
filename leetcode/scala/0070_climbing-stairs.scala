
object Solution {
  def F(n: Int, A: Array[Int]): Int = {
    if (A(n) != 0) return A(n)
    if (n == 1) return 1
    if (n == 2) return 2
    return F(n - 1, A) + F(n - 2, A)
  }

  def G(n: Int, A: Array[Int]): Int = {
    A(0) = 1
    A(1) = 1
    A(2) = 2
    for (i <- 3 to n) {
      A(i) = A(i - 1) + A(i - 2)
    }
    return A(n)
  }

  def H(n: Int): Int = {
    if (n == 1) return 1
    if (n == 2) return 2
    var a: Int = 1
    var b: Int = 2
    for (i <- 3 to n) {
      val x = b
      val y = a + b
      a = x
      b = y
    }
    return b
  }

  def climbStairs(n: Int): Int = {
    //var A: Array[Int] = Array.ofDim[Int](n + 2)
    return H(n)
  }
}


object Solution {
    def F(n: Int, A: Array[Int]): Int = {
      if (A(n) != 0) return A(n)
      if (n == 1) return 1
      if (n == 2) return 2
      return F(n - 1, A) + F(n - 2, A)
    }
    
    def climbStairs(n: Int): Int = {
        var A: Array[Int] = Array.ofDim[Int](n + 1)
        return F(n, A)
    }
}

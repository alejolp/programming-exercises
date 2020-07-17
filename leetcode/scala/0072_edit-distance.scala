
object Solution {
  def minDistance(word1: String, word2: String): Int = {
    var matrix = Array.ofDim[Int](word1.length() + 1, word2.length() + 1)
    // m: word1.length()
    // n: word2.length()

    for (y <- 1 to word1.length()) {
      matrix(y)(0) = y
    }

    for (x <- 1 to word2.length()) {
      matrix(0)(x) = x
    }

    for {
      y <- 1 to word1.length()
      x <- 1 to word2.length()
    } {
      val cost = if (word1(y - 1) == word2(x - 1)) { 0 } else { 1 }
      matrix(y)(x) = Math.min(
        Math.min(
          matrix(y - 1)(x) + 1,
          matrix(y)(x - 1) + 1),
        matrix(y - 1)(x - 1) + cost)
    }

    return matrix(word1.length())(word2.length())
  }
}

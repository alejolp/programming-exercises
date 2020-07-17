
import scala.collection.mutable.TreeSet
import scala.collection.mutable.ArrayBuffer

object Solution {
  def networkDelayTime(times: Array[Array[Int]], N: Int, K: Int): Int = {
    var T = Array.ofDim[Int](N + 1)
    var V = Array.ofDim[Boolean](N + 1)
    var H = new TreeSet[(Int, Int)]
    var E = Array.ofDim[ArrayBuffer[(Int, Int)]](N + 1)

    for (i <- 1 to N) {
      T(i) = -1
      V(i) = false
      E(i) = new ArrayBuffer[(Int, Int)]
    }

    for (e <- times) {
      // e: (u, v, w)
      val u = e(0)
      val v = e(1)
      val w = e(2)
      E(u).append((v, w))
    }

    T(K) = 0
    H.add((T(K), K))

    while (H.size > 0) {
      var e = H.min
      H.remove(e)
      V(e._2) = true

      for ((v, w) <- E(e._2)) {
        val j = v
        val newWeight = T(e._2) + w

        if (T(j) == -1) {
          T(j) = newWeight
          if (!V(j)) {
            H.add((T(j), j))
          }
        } else if (T(j) > newWeight) {
          if (!V(j)) {
            H.remove((T(j), j))
            T(j) = newWeight
            H.add((T(j), j))
          } else {
            T(j) = newWeight
          }
        }
      }
    }

    var maxWeight = -1

    for (i <- 1 to N) {
      if (T(i) == -1) return -1
      if (T(i) > maxWeight) maxWeight = T(i)
    }

    return maxWeight
  }
}

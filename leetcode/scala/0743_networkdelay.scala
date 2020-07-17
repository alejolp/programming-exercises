
import scala.collection.mutable.TreeSet
import scala.collection.mutable.ArrayBuffer

object Solution {
  def F1(times: Array[Array[Int]], N: Int, K: Int): Int = {
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

  def F2(times: Array[Array[Int]], N: Int, K: Int): Int = {
    var T = Array.ofDim[Int](N + 1)
    var V = Array.ofDim[Boolean](N + 1)
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
    var go = true

    while (go) {
      var u = -1
      var minu = Int.MaxValue

      for (i <- 1 to N) {
        if (V(i) == false && T(i) != -1 && minu > T(i)) {
          u = i
          minu = T(i)
        }
      }
//println(T.toList)
//println(u)
      if (u == -1) {
        go = false
      } else {
        V(u) = true

        for ((v, w) <- E(u)) {
          val j = v
          val newWeight = T(u) + w

          if (T(j) == -1) {
            T(j) = newWeight
          } else if (T(j) > newWeight) {
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

  def networkDelayTime(times: Array[Array[Int]], N: Int, K: Int): Int = {
    F2(times, N, K)
  }
}

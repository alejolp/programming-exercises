import scala.util.Sorting
import scala.collection.mutable.HashMap
import scala.collection.mutable.ListBuffer
import scala.collection.mutable.HashSet

object Solution {
  def threeSum(numsd: Array[Int]): List[List[Int]] = {
    val S: HashMap[Int, Int] = HashMap.empty
    val R: ListBuffer[List[Int]] = ListBuffer.empty

    Sorting.quickSort(numsd)

    for ((e, i) <- numsd.zipWithIndex) {
      S.put(e, i)
    }

    var i = 0
    while (i < numsd.length) {
      var k = i + 1
      while (k < numsd.length) {
        val e = S.get(-(numsd(i) + numsd(k)))
        if (e.isDefined && e.get > k) {
          R.append((List(numsd(i), numsd(k), numsd(e.get))))
        }
        while ((k + 1) < numsd.length && numsd(k) == numsd(k + 1)) {
          k = k + 1
        }
        k = k + 1
      }

      while ((i + 1) < numsd.length && numsd(i) == numsd(i + 1)) {
        i = i + 1
      }

      i = i + 1
    }

    return R.toList
  }
}


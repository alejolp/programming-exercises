import scala.util.Sorting
import scala.collection.mutable.HashMap
import scala.collection.mutable.ListBuffer
import scala.collection.mutable.HashSet

object Solution {
    def threeSum(nums: Array[Int]): List[List[Int]] = {
        val S: HashMap[Int, Int] = HashMap.empty
        val R: HashSet[List[Int]] = HashSet.empty
        
        Sorting.quickSort(nums)
        
        for ((e, i) <- nums.zipWithIndex) {
          S.put(e, i)
        }
        
        for (i <- 0 to nums.length - 1) {
          for (k <- i + 1 to nums.length - 1) {
            val e = S.get(-(nums(i) + nums(k)))
            if (e.isDefined && e.get > k) {
              R.add((List(nums(i), nums(k), nums(e.get))))
            }
          }
        }
        
        return R.toList
    }
}

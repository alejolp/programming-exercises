
import scala.collection.mutable.HashMap

object Solution {
    def twoSum(nums: Array[Int], target: Int): Array[Int] = {
        val S: HashMap[Int, Int] = HashMap.empty[Int, Int]
        
        for (i <- nums.indices) {
            val x = target - nums(i)
            if (S.contains(x)) {
                val j = S.get(x).get
                return Array(j, i)
            } else {
                S.put(nums(i), i)
            }
        }
        return Array(0, 0)
    }
}


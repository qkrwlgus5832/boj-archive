import java.util.Scanner

class 우체국 {
    class Solution {
        fun solution(list: MutableList<Pair<Int, Int>>): Int {
            var currentSum = 0
            var secondGroup = 0
            var firstGroup = list[0].second

            for (i in 1 until list.size) {
                currentSum += (list[i].first - list[0].first) * list[i].second
                secondGroup += list[i].second
            }

            var minSum = currentSum
            var minIndex = list[0].first

            for (i in 0 until list.size - 1) {
                val gap = list[i + 1].first - list[i].first
                currentSum += firstGroup * gap
                currentSum -= secondGroup * gap
                if (currentSum < minSum) {
                    minSum = currentSum
                    minIndex = list[i + 1].first
                }
                firstGroup += list[i + 1].second
                secondGroup -= list[i + 1].second
            }
            return minIndex
        }
    }
}



fun main() = with(Scanner(System.`in`)) {
    val n = nextInt()

    val list = mutableListOf<Pair<Int, Int>>()

    for (i in 0 until n) {
        val location = nextInt()
        val people = nextInt()
        list.add(Pair(location, people))
    }

    val solution = `우체국`.Solution()
    println(solution.solution(list))
}
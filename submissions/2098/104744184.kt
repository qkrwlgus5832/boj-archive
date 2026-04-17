import java.lang.Math.pow
import java.util.PriorityQueue
import java.util.Scanner
import kotlin.math.min

class `외판원 순회` {
    data class Node(
        val current: Int,
        val checked: Int,
        val cost: Int,
    )

    class Solution {
        private var answer = Int.MAX_VALUE
        private val dp = Array((pow(2.toDouble(), 16.toDouble()) + 1).toInt()) { IntArray(16) { -1 } }
        val queue = PriorityQueue<Node>(compareBy { it.cost })

        private fun setBit(next: Int, checked: Int): Int {
            return checked or (1 shl next)
        }

        private fun isSetted(next: Int, checked: Int): Boolean {
            if (checked and (1 shl next) != 0) {
                return true
            }

            return false
        }

        private fun isEnded(n: Int, checked: Int): Boolean {
            if (checked == (1 shl n) - 1) {
                return true
            }

            return false
        }

        private fun bfs(start: Int, graph: Array<MutableList<Pair<Int, Int>>>) {
            queue.add(Node(start, 0, 0, 0))

            dp[0][start] = 0

            while (queue.isNotEmpty()) {
                val front = queue.poll()
                val current = front.current
                val checked = front.checked
                val cost = front.cost

                if (current == start && checked != 0) {
                    if (isEnded(graph.size, checked)) {
                        answer = min(answer, cost)
                        return
                    }
                    continue
                }

                for (next in graph[current]) {
                    if (isSetted(next.first, checked)) {
                        continue
                    }

                    val nextChecked = setBit(next.first, checked)

                    if (dp[nextChecked][next.first] == -1 || dp[nextChecked][next.first] > cost + next.second) {
                        dp[nextChecked][next.first] = cost + next.second
                        queue.add(Node(next.first, nextChecked, cost + next.second))
                    }

                }
            }
        }

        fun solution(graph: Array<MutableList<Pair<Int, Int>>>): Int {
            bfs(0, graph)
            return answer
        }
    }
}

fun main() = with(Scanner(System.`in`)) {
    val n = nextInt()

    val graph = Array(n) { mutableListOf<Pair<Int, Int>>() }

    for (i in 0 until n) {
        for (j in 0 until n) {
            val cost = nextInt()

            if (cost != 0) {
                graph[i].add(Pair(j, cost))
            }
        }
    }
    val solution = `외판원 순회`.Solution()



    println(solution.solution(graph))
}
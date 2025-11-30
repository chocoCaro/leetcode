class DynamicProgrammingSolution:
    def climbStairs(self, n: int) -> int:
        if n <= 3:
            return n

        ways = [1, 2, 3]

        for _ in range(3, n - 1):
            ways.append(ways[-2] + ways[-1])

        return ways[-2] + ways[-1]


class RecursiveSolution:
    def climbStairs(self, n: int) -> int:
        if n <= 3:
            return n

        return self.climbStairs(n - 2) + self.climbStairs(n - 1)

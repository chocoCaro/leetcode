# 70. Climbing Stairs

## I. Topics

- **Math**
- **Dynamic Programming**
- **Memoization**

## II. Solution Approach

### 1. Recursive

#### 1.1. Statistics

| Complexity | Testcase Failed | Testcases Passed |
| :--------: | :-------------: | :--------------: |
| O($2^{n}$) |     n = 44      |      21/45       |

#### 1.2. Instruction

1. if **n $\le$ 3**, the number of ways is simply **n**, because each step count has that many distinct ways.
2. For any step **n > 3**, compute the result recursively. To reach step **n**, we must come from either step **n - 1** or step **n - 2**, so the total number of ways is the sum of ways to reach those two steps.
3. The function calls itself with **n - 1** and **n - 2**, building the final answer by combining the results of these subproblems.

### 2. Dynamic Programming

#### 2.1. Statistics

| Complexity |   Runtime   |      Memory      |
| :--------: | :---------: | :--------------: |
|    O(n)    | 0 ms (100%) | 17.52 MB (95.6%) |

#### 2.2. Instruction

1. if **n $\le$ 3**, the number of ways is simply **n**, because each step count has that many distinct ways.
2. Initialize a list with the number of ways to reach the first three steps.
3. Starting from step **3** up to **n - 1**, iteratively append the sum of the previous two values, since each step can be reached from the two steps before it.
4. The answer for step **n** is the sum of the last two computed values.

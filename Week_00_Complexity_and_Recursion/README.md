### Data structures and Programming - Seminar
# Week 0 - Recursion and Complexity

## 1. Recursion

*def:* Under a **recursive** function it is understood a function that calls itself, directly or indirectly, during execution. **Recursion** is the process of solving a problem by reducing it to smaller instances of the same problem through repeated application of a recursive function.

**Pros** and **Cons**?

## 2. Complexity

*def:* The **computational complexity** of an algorithm is the amount of resources required to run it, primarily **computation time**(how much steps it takes) and **space**(how much memory it uses). The **complexity** of a problem is defined as the complexity of the most *efficient* algorithm that solves it.

Generally, we talk about **asymptotic** complexity - the use of asymptotic analysis for the estimation of computational complexity, i.e. how the time and memory usage behave as the input size grows.

*def:* Let $f, g: \mathbb{N} \rightarrow \mathbb{R}^+$ be total functions. We say that $f$ is **asymptotically less than or equal to** $g$, written $f \preceq g$, iff $$\exists n_0 \in \mathbb{N},\space \exists c \in \mathbb{R}^+, \space \forall n \in \mathbb{N}: \quad n > n_0 \Rightarrow f(n) \leq c \cdot g(n)$$
Moreover, the asymptotic class of functions is defined: $O(f) = \{g \space | \space g \preceq f\}$.

**Properties:**  
If $f_1 \in O(g_1)$ and $f_2 \in O(g_2)$, then:  
1) $f_1 + f_2 \in O(max\{g_1, g_2\})$;
2) $f_1 \cdot f_2 \in O(g_1 \cdot g_2)$

Not all functions could be compared asymptotically!

## 3. Problems
**P1.** Design a sequence in which the $n^{th}$ element depends on at most three previous(and consecutive) elements. Write a recursive function that calculates the $n^{th}$ element of this series. Think about the time and space complexity of your solution.

**P2.** Write a recursive function that implements the popular **fast exponentiation** algorithm(google it). Think about the time and space complexity of your solution and compare it to the regular exponentiation.  
**Input:**
```
2 7  
```
**Output:**
```
128
```
**P3.** Write a recursive program that, given two naturals $n$ and $k$, prints in lexicographical order all combinations of $n$ elements of class $k$.  
**Input:**
```
5 3
```
**Output:**
```
1 2 3  
1 2 4  
1 2 5  
1 3 4  
1 3 5  
1 4 5  
2 3 4  
2 3 5  
2 4 5  
3 4 5  
```

**P4.** Write a recursive program to find and print all possible ways to represent a given natural number $n$ as an ordered sum of elements taken from a specific set of $k$ denominations.  
**Input:**
```
15 3  
2 3 5
```  
**Output:**  
```
5 + 5 + 5  
5 + 5 + 3 + 2  
5 + 3 + 3 + 2 + 2  
5 + 2 + 2 + 2 + 2 + 2  
3 + 3 + 3 + 3 + 3  
3 + 3 + 3 + 2 + 2 + 2  
3 + 2 + 2 + 2 + 2 + 2 + 2  
```
**P5.** Write a recursive program that takes a natural number $n$, reads $\frac{n(n+1)}{2}$ integers, arranges them into a *triangular* matrix (or **number triangle**), and prints it to the standard output. Starting from the first cell in the matrix (the top vertex), the program is required to construct a path with the maximum sum of the numbers along it. From any given cell, a move is allowed to the cell immediately below it or to the cell "one step down, one step to the right" (i.e., the one below and to the right).  
**Input:**
```
4  
3 7 8 1 0 5 2 3 6 4
```
**Output:**
```
3  
7 8  
1 0 5  
2 3 6 4  
The maximum path sum is 22  
```

**P6.** Implement the popular **Merge Sort** algorithm. Think about its time and space complexity.  
**Input:**
```
5
-3 12 5 0 5
```
**Output:**
```
-3 0 5 5 12
```
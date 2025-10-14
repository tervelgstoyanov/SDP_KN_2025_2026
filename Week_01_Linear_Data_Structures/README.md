### Data structures and Programming - Seminar
# Week 1 - Linear Data Structures

## 1. Dynamic array

Standard operations:
- *access*
- *contains*
- *push_back*, *push_front*
- *pop_back*, *pop_front*
- *insert* - at index
- *erase* - at index

What are the complexities of those operations?

## 2. Stack
```cpp
template <
    class T,
    class Container = std::deque<T>
> class stack;
```
Standard operations:
- *push*
- *pop*
- *top*
- *empty*
- *size*

## 3. Queue
```cpp
template <
    class T,
    class Container = std::deque<T>
> class queue;
```
Standard operations:
- *front*
- *back*
- *empty*
- *size*
- *push*
- *pop*

## 3. Problems
**P1.** Imagine you have two vectors from integers. What is the complexity of finding their union and intersection. Think about the cases where you want to preserve the initial order of the elements and the case where you do not.

**P2.** Write a function that takes a vector of integers(from 0 to 1000) and returns the number of the unique values in it.
**Input:**
```
7
1 1 2 3 4 5 6  
```
**Output:**
```
6
```
**P3.** Check if a parentheses expression $expr$ is valid where each symbol in the expression is one of the following $\{, \}, (, ), [, ]$.  
**Input:**
```
(())()
```
**Output:**
```
True
```
**Input:**
```
()())()
```
**Output:**
```
False
```

**P4.** Reverse a stack.

**P5.** Напишете програма, която приема коректен булев израз, съставен от символите '0', '1', '(', ')', '~', '&' и '|'. Булев израз е коректен в следните случаи:  
- константите 0 и 1 са коректни булеви изрази;  
- ако х е коректен израз, то ~(x) е коректен;  
- ако х и у са коректни, то (х&y) и (x|y) са коректни.

Вашата задача е да прочетете такъв израз и да го изчислите, като символът '~' е логическо отрицание, '&' - конюнкция и '|' - дизюнкция.  
**Input:**
```
(0&~(1))
```
**Output:**
```
False
```
**Input:**
```
(0|(1&~(0)))
```
**Output:**
```
True
```

**P6.** Print all natural numbers from $1$ to $n$ in binary representation.  
**Input:**
```
5
```
**Output:**
```
1
10
11
100
101
```

**P7.** Given a chess board with size $n$, initial positions of the knight $(start_x, start_y)$, and wanted position $(end_x, end_y)$ print the minimal number of moves that the knight needs to go from the start to the end and -1 if this is not possible. The indices start from $0$ to $n - 1$.  
**Input:**
```
5 1 1 3 2
```
**Output:**
```
1
```
**Input:**
```
8 4 1 3 2
```
**Output:**
```
2
```
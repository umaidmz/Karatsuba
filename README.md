# Karatsuba

Karatsuba algorithm for fast multiplication using Divide and Conquer algorithm
Given two binary strings that represent value of two integers, find the product of two strings. For example, if the first bit string is “1100” and second bit string is “1010”, output should be 120.
For simplicity, let the length of two strings be same and be n.

A Naive Approach is to follow the process we study in school. One by one take all bits of second number and multiply it with all bits of first number. Finally add all multiplications. This algorithm takes O(n^2) time.

Using Divide and Conquer, we can multiply two integers in less time complexity O(n^log3).

source for description: https://www.geeksforgeeks.org/karatsuba-algorithm-for-fast-multiplication-using-divide-and-conquer-algorithm/

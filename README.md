# Stack — Template Class (C++)

## Project Description

This project focuses on implementing a template `Stack` class using a dynamic array and applying the stack data structure to check the correct placement of brackets in a string.

## Task 1 — Stack Implementation

Implemented a template class `Stack<T>` based on a dynamic array.

Main features:
- Adding elements (`Push`).
- Removing elements (`Pop`).
- Checking if the stack is empty (`IsEmpty`).
- Checking if the stack is full (`IsFull`).
- Getting the number of elements (`GetCount`).
- Clearing the stack (`Clear`).
- Displaying stack elements (`Show`).
- Automatically increasing the internal array capacity when there is no available space, without losing existing data.

## Task 2 — Bracket Validation

Implemented a bracket validation algorithm for round `()`, square `[]`, and curly `{}` brackets.

Algorithm:
1. Opening brackets are pushed onto the stack.
2. When a closing bracket is encountered, it is checked against the most recently opened bracket.
3. If the bracket types do not match or the stack is empty, an error is detected.
4. The validation stops when the `;` character is encountered.
5. After the loop, the stack is checked for any remaining unmatched opening brackets.

If the string is incorrect, the program displays the part of the string before the first detected error. If all brackets are correctly placed, an appropriate message is displayed.

## Technologies

- C++
- Templates
- Dynamic Memory Allocation
- Stack (LIFO)
- Object-Oriented Programming

## Project Objective

To practice working with class templates, dynamic memory allocation, and the Stack data structure, as well as learn how to use a stack to validate bracket sequences.

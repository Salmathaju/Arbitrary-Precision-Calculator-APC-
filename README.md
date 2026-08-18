# 🚀 Arbitrary Precision Calculator (APC)

## 📌 Overview

The Arbitrary Precision Calculator (APC) is a command-line application developed in C that performs arithmetic operations on integers of unlimited size.

Traditional C data types such as `int`, `long`, and `long long` have storage limitations. When numbers exceed those limits, arithmetic operations may produce incorrect results because of overflow.

This project overcomes that limitation by storing each digit in a doubly linked list and performing calculations digit by digit.

---

## 🎯 Aim

To implement a calculator capable of performing arithmetic operations on very large integers using data structures.

---

## ❓ Problem Statement

Built-in data types cannot handle extremely large integers.

For example:

```
999999999999999999999999999999 + 1
```

Standard data types cannot store such values accurately.

The APC project solves this problem by representing numbers as linked lists.

---

## ✨ Features

- Addition
- Subtraction
- Multiplication
- Division
- Positive number support
- Negative number support
- Input validation
- Error handling
- Large integer calculations

---

## 🛠️ Technologies Used

- C Programming
- Doubly Linked Lists
- Dynamic Memory Allocation
- Modular Programming
- Makefile
- Command-Line Interface

---

## 📂 Project Structure

```
APC/
│
├── main.c
├── add.c
├── sub.c
├── mul.c
├── div.c
├── dll.c
├── validation.c
├── sign.c
│
├── dll.h
├── validation.h
├── sign.h
├── types.h
│
├── Makefile
└── README.md
```

---

## ⚙️ Compilation

```bash
make
```

---

## ▶️ Execution

### Addition

```bash
./APC.exe 123 + 456
```

Output:

```text
RESULT: 579
```

### Subtraction

```bash
./APC.exe 456 - 123
```

Output:

```text
RESULT: 333
```

### Multiplication

```bash
./APC.exe 123 x 456
```

Output:

```text
RESULT: 56088
```

### Division

```bash
./APC.exe 100 / 10
```

Output:

```text
RESULT: 10
```

---

## ⚠️ Challenges Faced During Development

- Implementing carry propagation during addition
- Managing borrow operations during subtraction
- Handling positive and negative numbers
- Removing leading zeros
- Designing multiplication using linked lists
- Implementing division using repeated subtraction
- Debugging infinite loops
- Handling edge cases such as division by zero

---

## 📚 Key Concepts Learned

- Doubly Linked Lists
- Dynamic Memory Allocation
- Data Structures
- Algorithm Design
- Memory Management
- Debugging Techniques
- Modular Programming

---

## 👩‍💻 Author

**Salma**

Electronics and Communication Engineering (ECE)

---

## 🌟 Future Improvements

- Support for decimal numbers
- Support for modulus operations
- Performance optimization for division
- Graphical user interface (GUI)

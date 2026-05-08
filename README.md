# Bank Management System in C++

A Console-Based **Bank Management System** developed in **C++** using **Object-Oriented Programming (OOP)** concepts.

This project allows users to perform banking operations such as:

- Account Creation
- Deposit & Withdrawal
- Fund Transfer
- Balance Inquiry
- Transaction History
- Account Modification
- Account Deletion
- Listing All Accounts

---

# Features

## 1. Account Creation
- Create Savings Account
- Create Current Account
- Auto-generated Account Numbers
- Store Customer Information

---

## 2. Deposit Money
- Deposit cash into account
- Automatic balance update
- Transaction history maintenance

---

## 3. Withdraw Money
- Withdraw funds securely
- Insufficient balance validation
- Automatic balance deduction

---

## 4. Fund Transfer
- Transfer money between accounts
- Sender and receiver validation
- Automatic deduction and credit

---

## 5. Balance Inquiry
- Check current balance
- View transaction history

---

## 6. Account Modification
Update customer details:
- Name
- Phone Number
- Address

---

## 7. Account Deletion
- Delete account only when balance is zero
- Prevent accidental deletion

---

## 8. List All Accounts
Display all accounts in a formatted table including:
- Account Number
- Holder Name
- Account Type
- Balance
- Status

---

# OOP Concepts Used

| Concept | Usage |
|---|---|
| Classes & Objects | Used to model banking entities |
| Encapsulation | Data and functions combined in classes |
| Inheritance | SavingsAccount and CurrentAccount inherit Account |
| Polymorphism | Virtual functions used |
| Constructors | Initialize objects |
| Destructors | Free dynamically allocated memory |
| Abstraction | Complex logic hidden from user |

---

# Technologies Used

- C++
- Object-Oriented Programming
- STL Vector
- Console-Based Interface

---

# Classes Used

## 1. Transaction
Stores:
- Transaction Type
- Transaction Amount

---

## 2. Account (Abstract Base Class)
Stores:
- Account Number
- Holder Name
- Phone
- Address
- Balance
- Transaction History

Functions:
- Deposit
- Withdraw
- Transfer
- Show Balance
- Modify Account

---

## 3. SavingsAccount
Derived from `Account` class.

---

## 4. CurrentAccount
Derived from `Account` class.

---

## 5. Bank
Controls the entire banking system.

Functions:
- Create Account
- Find Account
- Deposit
- Withdraw
- Transfer
- Delete Account
- List Accounts

---

# Project Structure

```text
Bank Management System
│
├── Transaction Class
├── Account Class
│   ├── SavingsAccount
│   └── CurrentAccount
│
└── Bank Class
```
---

# How to Run

## Step 1
Save the file as:

```text
bank_management.cpp
```
---

## Step 2
Compile the program:

```bash
g++ bank_management.cpp -o bank
```

---

## Step 3
Run the program:

```bash
./bank
```

# Learning Outcomes

By building this project, students learn:

- Object-Oriented Programming
- Class Relationships
- Dynamic Memory Allocation
- Pointers
- Vectors
- Menu-Driven Programming
- Problem Solving
- Banking Logic Implementation

---
# License
This project is for educational purposes only.

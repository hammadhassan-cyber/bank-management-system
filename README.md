# Bank Management System in C++

A simple console-based Bank Management System implemented in C++ using Object-Oriented Programming (OOP) principles such as Inheritance, Encapsulation, and Polymorphism.

## Features

- **Account Management**: Support for two types of accounts:
  - **Savings Account**: Features a fixed interest rate.
  - **Current Account**: Features an overdraft limit for flexible withdrawals.
- **Transactions**: Perform deposits and withdrawals with real-time balance updates.
- **Balance Inquiries**: Check the balance and account details using a unique Account Number.
- **Data Display**: List all registered customers and their respective account information.
- **Input Validation**: Basic handling for invalid transaction amounts and non-integer menu selections.

## OOP Concepts Used

- **Inheritance**: `SavingsAccount` and `CurrentAccount` inherit from the base `Account` class.
- **Encapsulation**: Customer and Account data are managed within classes to protect data integrity.
- **Method Overriding**: The `withdraw` method is overridden in the `CurrentAccount` class to handle overdraft logic.
- **Composition**: The `Bank` class uses arrays of objects to manage multiple customers and accounts.

## How to Run

1.  Ensure you have a C++ compiler installed (e.g., `g++`).
2.  Save the source code to a file named `main.cpp`.
3.  Open your terminal or command prompt.
4.  Compile the code:
    ```bash
    g++ main.cpp -o BankSystem
    ```
Run the executable:
    ```bash
    ./BankSystem
    ```

## Usage

Follow the on-screen menu to:
1.  **Open Account**: Choose between Savings or Current and provide initial details.
2.  **Deposit**: Add funds to a specific account using the ID.
3.  **Withdraw**: Remove funds (respecting balance or overdraft limits).
4.  **Check Balance**: View specific holder info.
5.  **Display All**: Overview of all bank records.

---
*Note: This system uses fixed-size arrays (100 accounts) and does not persist data to a database or file; data is cleared when the program exits.*

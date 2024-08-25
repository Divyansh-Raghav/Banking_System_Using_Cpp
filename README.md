# Brainwave_Matrix_Intern

Here's a more detailed description you can use for the `README.md` file on GitHub:

---

# ATM Project

## Overview

This is a simple ATM interface written in C++ as a learning project. The program simulates basic ATM operations, including:

- **Balance Inquiry:** Check the account balance (displayed in Indian Rupees - INR).
- **Deposit:** Add money to the account (in USD).
- **Withdraw:** Withdraw money from the account (in USD).
- **Transaction History:** View a record of all transactions made during the session.

The program uses object-oriented principles, with classes representing accounts and ATM functionality. The balance is maintained in USD but is converted to INR when displayed to the user.

## Features

- **User Authentication:** Requires the user to enter their account number and PIN for security.
- **Currency Conversion:** Converts the balance from USD to INR (using a conversion rate of 1 USD = 83 INR).
- **Transaction Handling:** Supports deposits, withdrawals, and displays transaction history.
- **Simple Interface:** Command-line interface with easy-to-understand menu options.

## How to Run

1. **Compile the code** using any C++ compiler, for example:
   ```bash
   g++ atm.cpp -o atm
   ```
2. **Run the executable**:
   ```bash
   ./atm
   ```
3. **Follow the on-screen instructions** to use the ATM system.

## Future Enhancements

- Add file-based persistence for account data.
- Implement encryption for PINs to enhance security.
- Expand the functionality to support multiple currencies and more advanced transaction types.

## Requirements

- C++ compiler (GCC, Clang, MSVC, etc.)
- Basic knowledge of C++ and object-oriented programming.

---

This README file gives an overview of the project, how to run it, and potential future enhancements. Feel free to modify it according to your needs.

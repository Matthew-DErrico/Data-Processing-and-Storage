# In-Memory Database with Transactions

## **Overview**
This project implements an in-memory key-value database in C++ that supports basic transactions. Transactions allow all-or-nothing updates, ensuring consistency when performing multiple operations.

## **Features**
- Begin a transaction.
- Add or update key-value pairs within a transaction.
- Retrieve values by key at any time.
- Commit changes to make them visible globally.
- Rollback changes to undo all modifications within a transaction.

## **Setup Instructions**
### Prerequisites
- A C++ compiler such as `g++`.

### Build Instructions
1. Clone the repository:
   ```bash
   git clone <repository-url>
   cd <repository-directory>
2. Compile the program
   ```g++ -o InMemoryDB main.cpp InMemoryDB.cpp
3. Run the program
   ```./InMemoryDB

## Example Usage
### Sample Output
```
    Value of A during transaction: 5
    Value of A after commit: 5
    B does not exist after rollback.
```
### Explanation
1. The value of A is added within a transaction and then committed.
2. The value of B is added but rolled back, so it does not exist in the database

## Assignment Feedback
To improve this assignment:
1. Clarify that exceptions should be thrown when attempting to commit or rollback without an active transaction.
2. Add support for nested transactions for advanced use cases.
3. Provide automated test cases for easier grading.
4. Include instructions for handling corner cases (e.g., non-existent keys).

### Acknowledgments
This project is part of the Data Processing and Storage Assignment for CIS4930.

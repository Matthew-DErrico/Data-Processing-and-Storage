#include "InMemoryDB.h"
#include <stdexcept>

void InMemoryDB::begin_transaction() {
    if (isTransactionActive) {
        throw std::runtime_error("A transaction is already in progress.");
    }
    isTransactionActive = true;
    transactionState.clear();
}

void InMemoryDB::put(const std::string &key, int val) {
    if (!isTransactionActive) {
        throw std::runtime_error("No transaction in progress.");
    }
    transactionState[key] = val;
}

int InMemoryDB::get(const std::string &key) {
    if (isTransactionActive && transactionState.count(key)) {
        return transactionState[key];
    }
    if (mainState.count(key)) {
        return mainState[key];
    }
    throw std::runtime_error("Key not found.");
}

void InMemoryDB::commit() {
    if (!isTransactionActive) {
        throw std::runtime_error("No transaction to commit.");
    }
    for (const auto &entry : transactionState) {
        mainState[entry.first] = entry.second;
    }
    transactionState.clear();
    isTransactionActive = false;
}

void InMemoryDB::rollback() {
    if (!isTransactionActive) {
        throw std::runtime_error("No transaction to rollback.");
    }
    transactionState.clear();
    isTransactionActive = false;
}

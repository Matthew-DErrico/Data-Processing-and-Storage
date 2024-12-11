#ifndef IN_MEMORY_DB_H
#define IN_MEMORY_DB_H

#include <unordered_map>
#include <string>

class InMemoryDB {
private:
    std::unordered_map<std::string, int> mainState;
    std::unordered_map<std::string, int> transactionState;
    bool isTransactionActive = false;

public:
    void begin_transaction();
    void put(const std::string &key, int val);
    int get(const std::string &key);
    void commit();
    void rollback();
};

#endif

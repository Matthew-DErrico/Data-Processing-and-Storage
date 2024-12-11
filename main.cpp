#include <iostream>
#include "InMemoryDB.h"

int main() {
    InMemoryDB db;

    try {
        db.begin_transaction();
        db.put("A", 5);
        std::cout << "Value of A during transaction: " << db.get("A") << "\n";
        db.commit();

        std::cout << "Value of A after commit: " << db.get("A") << "\n";

        db.begin_transaction();
        db.put("B", 10);
        db.rollback();
        try {
            std::cout << "Value of B after rollback: " << db.get("B") << "\n";
        } catch (const std::exception &e) {
            std::cout << "B does not exist after rollback.\n";
        }
    } catch (const std::exception &e) {
        std::cerr << "Error: " << e.what() << "\n";
    }

    return 0;
}

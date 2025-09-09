#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <iomanip>

struct Transaction {
    double amount;
    std::string category;
    std::string description;
};

class FinanceTracker {
private:
    std::vector<Transaction> transactions;

public:
    void addTransaction(double amount, const std::string& category, const std::string& description) {
        transactions.push_back({amount, category, description});
    }

    double getBalance() const {
        double balance = 0.0;
        for (const auto& t : transactions) {
            balance += t.amount;
        }
        return balance;
    }

    std::map<std::string, double> getExpensesByCategory() const {
        std::map<std::string, double> expenses;
        for (const auto& t : transactions) {

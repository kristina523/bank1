#include <iostream>
#include<limits>
class BankAccount {
private:
    int accountNumber;
    double balance;
    double interestRate;

public:
    BankAccount(int accNum, double initBalance) : accountNumber(accNum), balance(initBalance), interestRate(0.0) {
    }
    
    void deposit(double amount) {
        if (amount > 0) {
            balance += amount;
            std::cout << "Депозит успешный. Новый баланс: " << balance << std::endl;
        } else {
            std::cout << "Недействительная сумма для депозита." << std::endl;
        }
    }

    bool withdraw(double amount) {
        if (amount > 0 && balance >= amount) {
            balance -= amount;
            std::cout << "Вывод средств успешный. Новый баланс: " << balance << std::endl;
            return true;
        } else {
            std::cout << "Недостаточно средств для вывода или недействительная сумма." << std::endl;
            return false;
        }
    }

    double getBalance() {
        return balance;
    }

    double getInterest() {
        return balance * interestRate * (1 / 12);
    }

    void setInterestRate(double newRate) {
        interestRate = newRate;
    }

    int getAccountNumber() {
        return accountNumber;
    }

    friend bool transfer(BankAccount& sender, BankAccount& receiver, double amount);
};

bool transfer(BankAccount& sender, BankAccount& receiver, double amount) {
    if (amount > 0 && sender.balance >= amount) {
        sender.balance -= amount;
        receiver.balance += amount;
        std::cout << "Перевод прошел успешно. Новый баланс отправителя: " << sender.balance << ", новый баланс приемника: " << receiver.balance << std::endl;
        return true;
    } else {
        std::cout << "Перевод не выполнен. Недостаточно средств или неверная сумма." << std::endl;
        return false;
    }
}

int main() {
    int accNum1, accNum2;
    double initBalance1, initBalance2;
    double depositAmount, withdrawAmount, interestRate, transferAmount;
    int choice;
    
    std::cout << "Введите номер банковского счета и начальный баланс для первого аккаунта: ";
    std::cin >> accNum1 >> initBalance1;
    BankAccount account1(accNum1, initBalance1);
    
    std::cout << "Введите номер банковского счета и начальный баланс для второго аккаунта: ";
    std::cin >> accNum2 >> initBalance2;
    BankAccount account2(accNum2, initBalance2);
    
    do {
        std::cout << "Меню выбора: " << std::endl;
        std::cout << "1. Внести депозит на первый счет" << std::endl;
        std::cout << "2. Вывести средства со второго счета" << std::endl;
        std::cout << "3. Установить процентную ставку для второго счета" << std::endl;
        std::cout << "4. Перевести средства с первого на второй счет" << std::endl;
        std::cout << "5. Выйти из программы" << std::endl;
        std::cout << "Выберите действие: ";
        std::cin >> choice;
        
        switch (choice) {
            case 1:
                std::cout << "Введите сумму для депозита на первый счет: ";
                std::cin >> depositAmount;
                account1.deposit(depositAmount);
                break;
            case 2:
                std::cout << "Введите сумму для вывода средств со второго счета: ";
                std::cin >> withdrawAmount;
                account2.withdraw(withdrawAmount);
                break;
            case 3:
                std::cout << "Введите процентную ставку для второго счета: ";
                std::cin >> interestRate;
                account2.setInterestRate(interestRate);
                break;
            case 4:
                std::cout << "Введите сумму для перевода с первого на второй счет: ";
                std::cin >> transferAmount;
                transfer(account1, account2, transferAmount);
                break;
            case 5:
                std::cout << "Выход из программы..." << std::endl;
                break;
            default:
                std::cout << "Неверный выбор. Пожалуйста, попробуйте снова." << std::endl;
                break;
        }
    } while (choice != 5);
    
        return 0;
    }

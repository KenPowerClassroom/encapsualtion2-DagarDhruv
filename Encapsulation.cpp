#include <iostream>

class BankAccount {
private:
    double balance;

public:
    BankAccount(double initialBalance) : balance(initialBalance) {}

    double getBalance() const {
        return balance;
    }

    void deposit(double amount) {
        balance += amount;
    }

    void withdraw(double amount) {
        if (amount <= balance) {
            balance -= amount;
        }
        else {
            std::cout << "Insufficient funds for withdrawal." << std::endl;
        }
    }
    void checkAndWithdraw(double amount) {
        if (balance > 500) {
            withdraw(amount);
            std::cout << "Withdrawal successful. New balance: $" << balance << std::endl;
        }
        else {
            std::cout << "Insufficient funds for withdrawal." << std::endl;
        }
    }
};
class Boiler {
public:
    void turnOn() {
        std::cout << "Heating system turned on." << std::endl;
    }

    void turnOff() {
        std::cout << "Heating system turned off." << std::endl;
    }
};

class Thermostat {
private:
    double currentTemperature;
    Boiler heating;

public:
    Thermostat(double temperature) : currentTemperature(temperature) {}

    double getCurrentTemperature() const {
        return currentTemperature;
    }

    void regulateHeating() {
        if (currentTemperature < 20.0) {
            heating.turnOn();
        }
        else {
            heating.turnOff();
        }
    }
};
#include <iostream>
#include <string>

class Book {
private:
    std::string title;
    bool isAvailable;

public:
    Book(const std::string& title) : title(title), isAvailable(true) {}

    bool isAvailableToBorrow() const {
        return isAvailable;
    }

    void borrowbook()
    {
        if (isAvailable)
        {
            isAvailable = false;
            std::cout << "book borrowed successfully" << std::endl;
        }
        else
        {
            std::cout << "book not available to borrow" << std::endl;
        }
    }

    void returnBook() {
        isAvailable = true;
    }
};

class Library {
public:
    void processBookBorrowing(Book& book) {
        book.borrowbook();
    }
};

class Player {
private:
    int health;
    int ammo;

public:
    Player() : health(100), ammo(10) {}

    bool canRespondtoAttack() 
    {
        return health>0 && ammo>0;
    }
  
    void takeDamage(int damage) {
        health -= damage;
    }

    void useAmmo() {
        ammo--;
    }
};

class Game {
public:
    void enemyAttack(Player& player) {
        if (player.canRespondtoAttack()) {
            player.takeDamage(10);
            player.useAmmo();
            std::cout << "Player attacked and used ammo." << std::endl;
        }
        else {
            std::cout << "Player can't respond to attack." << std::endl;
        }
    }
};


int main() {
    //////////////////////////////////////////////////////////////////
    // Exercise 1
    //////////////////////////////////////////////////////////////////
 
    BankAccount account(1000.0);
    account.checkAndWithdraw(500);

    //////////////////////////////////////////////////////////////////
    // Exercise 2
    //////////////////////////////////////////////////////////////////

    Thermostat thermostat(18.5);
    thermostat.regulateHeating();
    
    //////////////////////////////////////////////////////////////////
    // Exercise 3
    //////////////////////////////////////////////////////////////////

    Book myBook("1984");
    Library library;

    library.processBookBorrowing(myBook);  // First borrow should succeed
    library.processBookBorrowing(myBook);  // Second attempt should show not available

    //////////////////////////////////////////////////////////////////
    // Exercise 4
    //////////////////////////////////////////////////////////////////
    Player player;
    Game game;

    game.enemyAttack(player); // Player can respond to attack

    return 0;
}

#include <iostream>
#include <string>
using namespace std;

class User {
    string paymentType;

public:
    User(string paymentType) {
        this->paymentType = paymentType;
    }
};

// Interface (Abstraction)
class PaymentMethod {
public:
    virtual void pay() = 0; 
    virtual ~PaymentMethod() = default;
};

// Implementations
class DebitCard : public PaymentMethod {
public:
    void pay() override {
        cout << "💳 Paying using Debit Card\n";
    }
};

class CreditCard : public PaymentMethod {
public:
    void pay() override {
        cout << "💳 Paying using Credit Card\n";
    }
};

// Client Class
class PaymentService {
    PaymentMethod* method;

public:
    PaymentService(PaymentMethod* method) {
        this->method = method;
    }

    void processPayment() {
        method->pay();
    }
};

int main() {
    User user("Debit Card");

    DebitCard debit;
    CreditCard credit;

    PaymentService debitPayment(&debit);
    PaymentService creditPayment(&credit);

    debitPayment.processPayment();
    creditPayment.processPayment();

    return 0;
}

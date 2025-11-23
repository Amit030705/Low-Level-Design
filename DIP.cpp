#include <iostream>
#include <string>
using namespace std;

// Abstraction
class INotifier {
public:
    virtual void notification() = 0;
    virtual ~INotifier() = default;
};

// Concrete implementations
class EmailNotifier : public INotifier {
public:
    void notification() override {
        cout << "📧 Sending Email Notification" << endl;
    }
};

class SMSNotifier : public INotifier {
public:
    void notification() override {
        cout << "📩 Sending SMS Notification" << endl;
    }
};

// High-level module depending on abstraction (DIP)
class OrderService {
    INotifier* notifier;

public:
    OrderService(INotifier* notifier) {
        this->notifier = notifier;
    }

    void placeOrder() {
        cout << "🛒 Order Placed Successfully!" << endl;
        notifier->notification();
    }
};

int main() {
    EmailNotifier email;
    SMSNotifier sms;

    // Inject notification type dynamically
    OrderService service1(&email);
    OrderService service2(&sms);

    service1.placeOrder(); 
    service2.placeOrder();

    return 0;
}

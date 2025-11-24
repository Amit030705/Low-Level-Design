#include <iostream>
using namespace std;

class User {
public:
    string name;
    string email;

    User(string name, string email) {
        this->name = name;
        this->email = email;
    }
};

class EmailValidator {
public:
    bool validate(string email) {
        if (email == "") {
            cout << "❌ Email is invalid\n";
            return false;
        }
        cout << "✔ Email validated\n";
        return true;
    }
};

class Database {
public:
    virtual void save(User user) = 0;
};

class SqlDatabase : public Database {
public:
    void save(User user) override {
        cout << "💾 Saving " << user.name << " to SQL Database\n";
    }
};

class EmailSender {
public:
    void send(User user) {
        cout << "📩 Sending welcome email to " << user.email << "\n";
    }
};

class UserRegistration {
    EmailValidator validator;
    Database* db;
    EmailSender emailSender;

public:
    UserRegistration(Database* db) {
        this->db = db;
    }

    void registerUser(User user) {
        cout << "\n🚀 Starting registration...\n";

        if (!validator.validate(user.email)) {
            cout << "❌ Registration failed\n";
            return;
        }

        db->save(user);
        emailSender.send(user);

        cout << "🎉 Registration complete!\n";
    }
};

int main() {
    User user("Amit", "amit@example.com");

    SqlDatabase sqlDB;
    UserRegistration registration(&sqlDB);

    registration.registerUser(user);

    return 0;
}

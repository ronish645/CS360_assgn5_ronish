#include <iostream>
#include <string>

using namespace std;

// Base class
class Package {
protected:
    string senderName, senderAddress, senderCity, senderState, senderZIP;
    string recipientName, recipientAddress, recipientCity, recipientState, recipientZIP;
    double weight; // in ounces
    double costPerOunce;

public:
    Package(string sName, string sAddress, string sCity, string sState, string sZIP,
            string rName, string rAddress, string rCity, string rState, string rZIP,
            double w, double cpo) : senderName(sName), senderAddress(sAddress), senderCity(sCity), senderState(sState), senderZIP(sZIP),
                                    recipientName(rName), recipientAddress(rAddress), recipientCity(rCity), recipientState(rState), recipientZIP(rZIP),
                                    weight(w > 0 ? w : 0), costPerOunce(cpo > 0 ? cpo : 0) {}

    virtual double calculateCost() const {
        return weight * costPerOunce;
    }

    // Getter functions for sender and recipient information
    string getSenderName() const {
        return senderName;
    }

    string getSenderAddress() const {
        return senderAddress;
    }

    string getRecipientName() const {
        return recipientName;
    }

    string getRecipientAddress() const {
        return recipientAddress;
    }
};

// Derived class for Two-Day Package
class TwoDayPackage : public Package {
private:
    double flatFee;

public:
    TwoDayPackage(string sName, string sAddress, string sCity, string sState, string sZIP,
                  string rName, string rAddress, string rCity, string rState, string rZIP,
                  double w, double cpo, double ff) : Package(sName, sAddress, sCity, sState, sZIP, rName, rAddress, rCity, rState, rZIP, w, cpo),
                                                     flatFee(ff > 0 ? ff : 0) {}

    double calculateCost() const override {
        return Package::calculateCost() + flatFee;
    }
};

// Derived class for Overnight Package
class OvernightPackage : public Package {
private:
    double extraFeePerOunce;

public:
    OvernightPackage(string sName, string sAddress, string sCity, string sState, string sZIP,
                     string rName, string rAddress, string rCity, string rState, string rZIP,
                     double w, double cpo, double efp) : Package(sName, sAddress, sCity, sState, sZIP, rName, rAddress, rCity, rState, rZIP, w, cpo),
                                                         extraFeePerOunce(efp > 0 ? efp : 0) {}

    double calculateCost() const override {
        return (costPerOunce + extraFeePerOunce) * weight;
    }
};

// Main program to test the classes
int main() {
    Package package("John Doe", "123 Main St", "Anytown", "CA", "12345",
                    "Jane Smith", "456 Elm St", "Sometown", "NY", "54321",
                    10, 0.5);
    TwoDayPackage twoDayPackage("Alice Johnson", "789 Oak St", "Othertown", "TX", "67890",
                                "Bob Williams", "987 Pine St", "Anothertown", "FL", "98765",
                                10, 0.5, 5.0);
    OvernightPackage overnightPackage("Eva Martinez", "321 Maple St", "Smalltown", "IL", "13579",
                                      "Mike Brown", "654 Birch St", "Largetown", "OH", "24680",
                                      10, 0.5, 0.25);

    // Output for standard package
    cout << "Sender: " << package.getSenderName() << ", " << package.getSenderAddress() << endl;
    cout << "Recipient: " << package.getRecipientName() << ", " << package.getRecipientAddress() << endl;
    cout << "Standard Package Cost: $" << package.calculateCost() << endl;
    cout << endl;

    // Output for two-day package
    cout << "Sender: " << twoDayPackage.getSenderName() << ", " << twoDayPackage.getSenderAddress() << endl;
    cout << "Recipient: " << twoDayPackage.getRecipientName() << ", " << twoDayPackage.getRecipientAddress() << endl;
    cout << "Two Day Package Cost: $" << twoDayPackage.calculateCost() << endl;
    cout << endl;

    // Output for overnight package
    cout << "Sender: " << overnightPackage.getSenderName() << ", " << overnightPackage.getSenderAddress() << endl;
    cout << "Recipient: " << overnightPackage.getRecipientName() << ", " << overnightPackage.getRecipientAddress() << endl;
    cout << "Overnight Package Cost: $" << overnightPackage.calculateCost() << endl;
    cout << endl;

    return 0;
}

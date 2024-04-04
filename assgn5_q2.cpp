#include <iostream>
#include <string>

class Product {
protected:
    long barcode;
    std::string name;

public:
    // Constructor with default values for barcode and name
    Product(long barcode = 0, const std::string& name = "") : barcode(barcode), name(name) {}

    // Access methods for barcode
    void setCode(long newBarcode) {
        barcode = newBarcode;
    }

    long getCode() const {
        return barcode;
    }

    // Virtual methods for scanner and printer
    virtual void scanner() {
        std::cout << "Enter barcode: ";
        std::cin >> barcode;
        std::cin.ignore(); // To safely handle next line input
        std::cout << "Enter product name: ";
        getline(std::cin, name);
    }

    virtual void printer() const {
        std::cout << "Barcode: " << barcode << ", Name: " << name << std::endl;
    }
};
class PrepackedFood : public Product {
private:
    double unitPrice;

public:
    // Constructor with default values
    PrepackedFood(long barcode = 0, const std::string& name = "", double unitPrice = 0.0)
        : Product(barcode, name), unitPrice(unitPrice) {}

    void setUnitPrice(double newUnitPrice) {
        unitPrice = newUnitPrice;
    }

    double getUnitPrice() const {
        return unitPrice;
    }

    void scanner() override {
        Product::scanner();
        std::cout << "Enter unit price: ";
        std::cin >> unitPrice;
    }

    void printer() const override {
        Product::printer();
        std::cout << "Unit Price: $" << unitPrice << std::endl;
    }
};
class FreshFood : public Product {
private:
    double weight;
    double pricePerKilo;

public:
    // Constructor with default values
    FreshFood(long barcode = 0, const std::string& name = "", double weight = 0.0, double pricePerKilo = 0.0)
        : Product(barcode, name), weight(weight), pricePerKilo(pricePerKilo) {}

    void setWeight(double newWeight) {
        weight = newWeight;
    }

    double getWeight() const {
        return weight;
    }

    void setPricePerKilo(double newPricePerKilo) {
        pricePerKilo = newPricePerKilo;
    }

    double getPricePerKilo() const {
        return pricePerKilo;
    }

    void scanner() override {
        Product::scanner();
        std::cout << "Enter weight (kg): ";
        std::cin >> weight;
        std::cout << "Enter price per kilo: $";
        std::cin >> pricePerKilo;
    }

    void printer() const override {
        Product::printer();
        std::cout << "Weight: " << weight << " kg, Price per Kilo: $" << pricePerKilo << std::endl;
    }
};
int main() {
    // Creating objects
    Product productDefault;
    PrepackedFood prepackedFoodDefault;
    FreshFood freshFoodDefault;

    Product productFull(1001, "Generic Product");
    PrepackedFood prepackedFoodFull(2002, "Packaged Cookies", 4.99);
    FreshFood freshFoodFull(3003, "Organic Tomatoes", 1.5, 2.99);

    // Testing scanner and printer methods
    std::cout << "Please enter details for the default Product:\n";
    productDefault.scanner();
    std::cout << "\nPlease enter details for the default Prepacked Food:\n";
    prepackedFoodDefault.scanner();
    std::cout << "\nPlease enter details for the default Fresh Food:\n";
    freshFoodDefault.scanner();

    // Displaying all products
    std::cout << "\nFully Initialized Product Details:\n";
    productFull.printer();
    prepackedFoodFull.printer();
    freshFoodFull.printer();


    productDefault.printer();
    prepackedFoodDefault.printer();
    freshFoodDefault.printer();

    return 0;
}

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <map>

struct Book {
    std::string title;
    std::string author;
    std::string ISBN;
    double price;
    int quantity;
};

struct Customer {
    std::string name;
    std::string contactDetails;
    std::vector<std::string> purchaseRecords;
};

class BookshopManagementSystem {
private:
    std::map<std::string, Book> bookInventory; 
    std::map<std::string, Customer> customers; 

    const std::string booksFile = "books.txt";
    const std::string customersFile = "customers.txt";

public:
    BookshopManagementSystem() {
        loadBooks();
        loadCustomers();
    }

    ~BookshopManagementSystem() {
        saveBooks();
    }

    void addBook(const Book& book) {
        bookInventory[book.ISBN] = book;
    }

    void removeBook(const std::string& ISBN) {
        bookInventory.erase(ISBN);
    }

    void updateBookQuantity(const std::string& ISBN, int newQuantity) {
        if (bookInventory.find(ISBN) != bookInventory.end()) {
            bookInventory[ISBN].quantity = newQuantity;
        }
    }

    void addCustomer(const Customer& customer) {
        customers[customer.name] = customer;
    }

    void processSale(const std::string& customerName, const std::string& ISBN) {
        if (customers.find(customerName) != customers.end() && bookInventory.find(ISBN) != bookInventory.end()) {
            customers[customerName].purchaseRecords.push_back(ISBN);
            bookInventory[ISBN].quantity--;
        }
    }

    void displayBookInventory() {
        for (const auto& pair : bookInventory) {
            const Book& book = pair.second;
            std::cout << "Title: " << book.title << ", Author: " << book.author << ", ISBN: " << book.ISBN
                      << ", Price: " << book.price << ", Quantity: " << book.quantity << std::endl;
        }
    }

    void displayCustomerPurchases(const std::string& customerName) {
        if (customers.find(customerName) != customers.end()) {
            std::cout << "Purchase records for customer " << customerName << ":" << std::endl;
            for (const auto& purchase : customers[customerName].purchaseRecords) {
                std::cout << purchase << std::endl;
            }
        }
    }

private:
    void loadBooks() {
        std::ifstream inFile(booksFile);
        if (inFile.is_open()) {
            std::string title, author, ISBN;
            double price;
            int quantity;
            while (inFile >> title >> author >> ISBN >> price >> quantity) {
                Book book = {title, author, ISBN, price, quantity};
                bookInventory[ISBN] = book;
            }
            inFile.close();
        }
    }

    void saveBooks() {
        std::ofstream outFile(booksFile);
        if (outFile.is_open()) {
            for (const auto& pair : bookInventory) {
                const Book& book = pair.second;
                outFile << book.title << " " << book.author << " " << book.ISBN << " " << book.price << " " << book.quantity << "\n";
            }
            outFile.close();
        }
    }

    void loadCustomers() {
        std::ifstream inFile(customersFile);
        if (inFile.is_open()) {
            std::string name, contactDetails;
            while (inFile >> name >> contactDetails) {
                Customer customer = {name, contactDetails, {}};
                customers[name] = customer;
            }
            inFile.close();
        }
    }
};

int main() {
    BookshopManagementSystem bookshop;

    Book book1 = {"The Catcher in the Rye", "J.D. Salinger", "9780316769488", 125000, 53};
    bookshop.addBook(book1);
    Book book2 = {"Pride and prejudice", "Jane Austin", "9782319054172", 135000, 112};
   bookshop.addBook(book2);
   Book book3 = {"The Great Gatsby", "F. Scott Fitzerald", "9785646933271", 120000, 78};
   bookshop.addBook(book3);
   Book book4 = {"1984", "George Orwell", "9789016877639", 145000, 183};
   bookshop.addBook(book4);
   Book book5 = {"Lolita", "Vladimir Nabokov", "9784590061436", 115000, 152};
   bookshop.addBook(book5);
   Book book6 = {"Crime and Punishment", "Fyodor Dostoevsky", "9785587899131", 155000, 121};
   bookshop.addBook(book6);
   Book book7 = {"Anna Karenina", "Lev Tolstoy", "9780524827949", 105000, 95};
   bookshop.addBook(book7);
    Book book8 = {"War and Peace", "Lev Tolstoy", "9780750431125", 145000, 287};
   bookshop.addBook(book8);


    Customer customer1 = {"Aziza", "aziza064@gmail.com", {}};
    bookshop.addCustomer(customer1);
   Customer customer2 = {"Karen", "karen0937@gmail.com", {}};
   bookshop.addCustomer(customer2);
   Customer customer3 = {"Parviz", "parviz4436@gmail.com", {}};
   bookshop.addCustomer(customer3);
   Customer customer4 = {"G'anibek", "gani295@gmail.com", {}};
   bookshop.addCustomer(customer4);
   Customer customer5 = {"Anyuta", "anyuta028@gmail.com", {}};
   bookshop.addCustomer(customer5);
   Customer customer6 = {"Mirvosid", "mirvosid843@gmail.com", {}};
   bookshop.addCustomer(customer6);
   Customer customer7 = {"Bogdan", "bogdan883@gmail.com", {}};
   bookshop.addCustomer(customer7);
   Customer customer8 = {"Kamila", "kamila386@gmail.com", {}};
   bookshop.addCustomer(customer8);
   Customer customer9 = {"Davron", "davron7545@gmail.com", {}};
   bookshop.addCustomer(customer9);
   Customer customer10 = {"Vladlen", "vlad984@gmail.com", {}};
   bookshop.addCustomer(customer10);
   Customer customer11 = {"Ilyas", "ilyas532@gmail.com", {}};
   bookshop.addCustomer(customer11);
   Customer customer12 = {"Maya", "maya642@gmail.com", {}};
   bookshop.addCustomer(customer12);
   Customer customer13 = {"Elizaveta", "liza843@gmail.com", {}};
   bookshop.addCustomer(customer13);
   Customer customer14 = {"Karina", "karina931@gmail.com", {}};
   bookshop.addCustomer(customer14);


    bookshop.processSale("Aziza", "9780316769488");
    bookshop.processSale("Elizaveta", "9782319054172");
    bookshop.processSale("Karen", "9785646933271");
   bookshop.processSale("Ilyas", "9780316769488");
   bookshop.processSale("Davron", "9789016877639");
   bookshop.processSale("Maya", "9789016877639");
   bookshop.processSale("Maya", "9780316769488");
   bookshop.processSale("Bogdan", "9789016877639");
   bookshop.processSale("Davron", "9785587899131");
   bookshop.processSale("Mirvosid", "9785646933271");
   bookshop.processSale("G'anibek", "9789016877639");
   bookshop.processSale("Aziza", "9785587899131");
   bookshop.processSale("Vladlen", "9782319054172");
   bookshop.processSale("Karen", "9784590061436");
   bookshop.processSale("G'anibek", "9780316769488");
   bookshop.processSale("Parviz", "9789016877639");
   bookshop.processSale("Anyuta", "9789016877639");
   bookshop.processSale("Anyuta", "9784590061436");
   bookshop.processSale("Anyuta", "9785587899131");
   bookshop.processSale("Anyuta", "9780524827949");
   bookshop.processSale("Anyuta", "9780750431125");
   bookshop.processSale("Anyuta", "9780316769488");
   bookshop.processSale("Ilyas", "9785587899131");
   bookshop.processSale("Kamila", "9784590061436");
   bookshop.processSale("Maya", "9780316769488");
   bookshop.processSale("Elizaveta", "9784590061436");
   bookshop.processSale("Karina", "9789016877639");
   bookshop.processSale("Karina", "9784590061436");
   

    bookshop.displayBookInventory();
    
    bookshop.displayCustomerPurchases("Aziza");
    bookshop.displayCustomerPurchases("Anyuta");
    bookshop.displayCustomerPurchases("Elizaveta");
    bookshop.displayCustomerPurchases("Karen");
    bookshop.displayCustomerPurchases("Ilyas");
    bookshop.displayCustomerPurchases("Davron");
    bookshop.displayCustomerPurchases("Maya");
    bookshop.displayCustomerPurchases("Bogdan");
    bookshop.displayCustomerPurchases("Mirvosid");
    bookshop.displayCustomerPurchases("G'anibek");
    bookshop.displayCustomerPurchases("Vladlen");
    bookshop.displayCustomerPurchases("Parviz");
    bookshop.displayCustomerPurchases("Kamila");
    bookshop.displayCustomerPurchases("Karina");

    return 0;
}
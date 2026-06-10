#include <iostream>
#include <stdexcept>
#include <memory>
#include <string>

using namespace std;

// ═══════════════════════════════════════════════════════════════
//   REAL-WORLD EXAMPLE: Online Shopping Order System
//   We place an order step by step — and handle errors at each step
// ═══════════════════════════════════════════════════════════════


// ─────────────────────────────────────────────────────────────────
// CONCEPT 1: Basic try-throw-catch
//
// STORY: User enters age to verify they are 18+ to buy alcohol.
//        If age is negative → throw invalid_argument
//        If age < 18        → throw logic_error
// ─────────────────────────────────────────────────────────────────
void verifyAge(int age) {
    cout << "\n[STEP 1] Verifying customer age...\n";
    try {
        if (age < 0)
            throw invalid_argument("Age cannot be negative. Got: " + to_string(age));

        if (age < 18)
            throw logic_error("Customer must be 18+ to place this order.");

        cout << "  Age " << age << " verified. Access granted!\n";
    }
    catch (const invalid_argument& e) {
        cout << "  [ERROR - Invalid Input] " << e.what() << "\n";
    }
    catch (const logic_error& e) {
        cout << "  [ERROR - Logic] " << e.what() << "\n";
    }
}


// ─────────────────────────────────────────────────────────────────
// CONCEPT 2: Multiple catch blocks
//
// STORY: User searches for a product by ID.
//        ID = 0   → throw int   (error code)
//        ID = 999 → throw string (not found message)
//        else     → product found successfully
// ─────────────────────────────────────────────────────────────────
void searchProduct(int productId) {
    cout << "\n[STEP 2] Searching for product ID: " << productId << "...\n";
    try {
        if (productId == 0)
            throw 0;                                      // int error code

        if (productId == 999)
            throw string("Product ID 999 not found in catalog.");

        cout << "  Product found! Name: 'Wireless Headphones', Price: $49.99\n";
    }
    catch (int code) {
        cout << "  [ERROR - Code " << code << "] Invalid product ID. IDs must be > 0.\n";
    }
    catch (const string& msg) {
        cout << "  [ERROR - Not Found] " << msg << "\n";
    }
    catch (...) {
        cout << "  [ERROR - Unknown] Something went wrong during product search.\n";
    }
}


// ─────────────────────────────────────────────────────────────────
// CONCEPT 3: Standard Library Exceptions
//
// STORY: Cart has 2 items but we access index 10 → out_of_range
//        Loading a huge product image cache      → bad_alloc
// ─────────────────────────────────────────────────────────────────
void checkCart() {
    cout << "\n[STEP 3] Checking cart...\n";

    // out_of_range
    try {
        string cart[] = {"Book", "Pen"};
        string item = cart->at(10);    // Only index 0 and 1 exist!
    }
    catch (const out_of_range& e) {
        cout << "  [ERROR - Out of Range] Tried to access a cart item that doesn't exist.\n";
        cout << "  Detail: " << e.what() << "\n";
    }

    // bad_alloc
    try {
        int* imageCache = new int[999999999999LL];  // Too much memory!
        delete[] imageCache;
    }
    catch (const bad_alloc& e) {
        cout << "  [ERROR - Memory] Could not load product images. Server out of memory.\n";
        cout << "  Detail: " << e.what() << "\n";
    }
}


// ─────────────────────────────────────────────────────────────────
// CONCEPT 4: User-Defined Exception
//
// STORY: Customer tries to pay. If wallet balance is too low,
//        we throw a custom PaymentFailedException with shortfall amount.
// ─────────────────────────────────────────────────────────────────
class PaymentFailedException : public exception {
    double shortfall;
public:
    PaymentFailedException(double s) : shortfall(s) {}

    const char* what() const noexcept override {
        return "Payment failed! Insufficient wallet balance.";
    }

    double getShortfall() const { return shortfall; }
};

void processPayment(double walletBalance, double orderAmount) {
    cout << "\n[STEP 4] Processing payment of $" << orderAmount << "...\n";
    cout << "  Wallet Balance: $" << walletBalance << "\n";

    try {
        if (orderAmount > walletBalance)
            throw PaymentFailedException(orderAmount - walletBalance);

        cout << "  Payment successful! Remaining balance: $"
             << (walletBalance - orderAmount) << "\n";
    }
    catch (const PaymentFailedException& e) {
        cout << "  [ERROR - Payment] " << e.what() << "\n";
        cout << "  Please add $" << e.getShortfall() << " more to your wallet.\n";
    }
}


// ─────────────────────────────────────────────────────────────────
// CONCEPT 5: Stack Unwinding
//
// STORY: placeOrder() calls assignWarehouse() calls checkStock()
//        checkStock() finds stock = 0 and throws.
//        Error automatically bubbles up all the way to placeOrder().
// ─────────────────────────────────────────────────────────────────
void checkStock() {
    cout << "    checkStock():        Stock is 0. Throwing error...\n";
    throw runtime_error("Item OUT OF STOCK at warehouse.");
}

void assignWarehouse() {
    cout << "   assignWarehouse():    Warehouse assigned. Checking stock...\n";
    checkStock();
    cout << "   assignWarehouse():    (this line never runs)\n";
}

void placeOrder() {
    cout << "\n[STEP 5] Placing order...\n";
    cout << "  placeOrder():         Contacting warehouse...\n";
    try {
        assignWarehouse();
    }
    catch (const runtime_error& e) {
        cout << "  [ERROR - Order Failed] Caught after stack unwind: " << e.what() << "\n";
    }
}


// ─────────────────────────────────────────────────────────────────
// CONCEPT 6: Re-throwing Exceptions
//
// STORY: deliveryModule() catches GPS error, logs it,
//        then re-throws it so scheduleDelivery() can also react.
// ─────────────────────────────────────────────────────────────────
void getGPSLocation() {
    throw runtime_error("GPS signal lost. Cannot locate delivery address.");
}

void deliveryModule() {
    try {
        getGPSLocation();
    }
    catch (const runtime_error& e) {
        cout << "  deliveryModule() LOG: GPS error → " << e.what() << "\n";
        throw;   // re-throw to caller
    }
}

void scheduleDelivery() {
    cout << "\n[STEP 6] Scheduling delivery...\n";
    try {
        deliveryModule();
    }
    catch (const exception& e) {
        cout << "  [ERROR - Delivery] Order system caught re-thrown error: " << e.what() << "\n";
        cout << "  Notifying customer: Delivery delayed due to GPS issue.\n";
    }
}


// ─────────────────────────────────────────────────────────────────
// CONCEPT 7: RAII — Automatic Cleanup on Exception
//
// STORY: We open a DB connection and a log file to save the order.
//        A crash occurs midway. Smart pointers ensure both are
//        automatically closed — no manual cleanup needed!
// ─────────────────────────────────────────────────────────────────
class DatabaseConnection {
public:
    DatabaseConnection()  { cout << "  >> DB Connection opened.\n"; }
    ~DatabaseConnection() { cout << "  >> DB Connection closed (auto).\n"; }
};

class LogFile {
public:
    LogFile()  { cout << "  >> Log file opened.\n"; }
    ~LogFile() { cout << "  >> Log file closed (auto).\n"; }
};

void saveOrderToDB() {
    cout << "\n[STEP 7] Saving order to database...\n";
    try {
        auto db  = make_unique<DatabaseConnection>();
        auto log = make_unique<LogFile>();

        cout << "  Saving order... (crash happens now!)\n";
        throw runtime_error("Database write failed! Disk full.");

        // Even though we crash, destructors run automatically — no leaks!
    }
    catch (const exception& e) {
        cout << "  [ERROR - DB] " << e.what() << "\n";
        cout << "  (DB & Log were closed automatically above — no leaks!)\n";
    }
}


// ─────────────────────────────────────────────────────────────────
// MAIN — Run the full order flow
// ─────────────────────────────────────────────────────────────────
int main() {
    cout << "╔══════════════════════════════════════════╗\n";
    cout << "║    ONLINE SHOPPING — ORDER SIMULATION    ║\n";
    cout << "╚══════════════════════════════════════════╝\n";

    verifyAge(-3);                // bad age     → invalid_argument
    verifyAge(16);                // underage    → logic_error
    verifyAge(25);                // success

    searchProduct(0);             // int error code
    searchProduct(999);           // string error
    searchProduct(42);            // success

    checkCart();                  // out_of_range + bad_alloc

    processPayment(30.0, 49.99);  // not enough  → custom exception
    processPayment(100.0, 49.99); // success

    placeOrder();                 // stack unwinding demo

    scheduleDelivery();           // re-throwing demo

    saveOrderToDB();              // RAII cleanup demo

    cout << "\n╔══════════════════════════════════════════╗\n";
    cout << "║            SIMULATION COMPLETE           ║\n";
    cout << "╚══════════════════════════════════════════╝\n";
    return 0;
}
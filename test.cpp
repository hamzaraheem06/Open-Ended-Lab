#include <iostream>

using namespace std;

// defining all the global variables

const int NUM_ITEMS = 10;

// Parallel arrays to store item attributes
string names[NUM_ITEMS] = { "Laptop", "Phone", "Tablet", "Headphones", "Charger", "Keyboard", "Mouse", "Monitor", "Printer", "USB Cable" };
double prices[NUM_ITEMS] = { 60000, 30000, 15000, 2000, 500, 1500, 700, 10000, 5000, 100 };
int quantities[NUM_ITEMS] = { 10, 15, 5, 20, 50, 30, 40, 8, 12, 100 };
int orderIndexes[NUM_ITEMS], quantityOfProduct[NUM_ITEMS]; // arrays for user order

void displayItems() {
    cout << "Displaying the Products!\n";
    cout << "Index" << "\t\t" << "Name" << "\t\t" << "Price" << "\t\t" << "Quantity" << endl;
    for (int i = 0; i < NUM_ITEMS; i++) {
        cout << i << "\t\t" << names[i] << "\t\t" << prices[i] << "\t\t" << quantities[i] << endl;
    }
    cout << "\n\n";
}

// update prices of items if wanted
void updatePrices() {
    cout << "Updating the price of a pre-existing product!\n";
    int newPrice, indexOfProduct;
    bool productFound = false;
    do {
        cout << "Enter the index of the product whose price has to be changed: ";
        cin >> indexOfProduct;

        if (indexOfProduct >= 0 && indexOfProduct < 10) {
            productFound = true;
            break;
        }
        else {
            cout << "Please enter a valid index.\n";
            continue;
        }
    } while (true);

    if (productFound == true) {
        do {
            cout << "Enter the new price of " << names[indexOfProduct] << ": ";
            cin >> newPrice;

            if (newPrice <= 0) {
                cout << "Please enter a valid price.\n";
                continue;
            }
        } while (newPrice <= 0);

        prices[indexOfProduct] = newPrice;
    }

    // for (int i = 0; i < NUM_ITEMS; i++) {
    //     if (prices[i] != )
    //     {
    //         cout << "enter the new price of " << names[i] << ": ";
    //         cin >> newPrice;
    //         prices[i] = newPrice;
    //         cout << "the new price of " << names[i] << " is " << newPrice << endl;
    //         productFound = true;
    //         break;
    //     }
    // }
    cout << "\n\n";
}

int placeOrder() {
    cout << "Placing an order!";
    int indexOfProduct, quantity, i = 0;
    do {
        // to get the index of the product to be ordered, and also validating it.
        do {
            cout << "\nEnter the index of the product to be ordered: ";
            cin >> indexOfProduct;

            if (indexOfProduct > NUM_ITEMS) {
                cout << "\nEnter a valid index. ";
                continue;
            }
        } while (indexOfProduct > 10);
        orderIndexes[i] = indexOfProduct; // storing the index in an array at the index we created for the orderList i.e. i , so that in case of multiple items, we can store them.

        // to get the quantity of the product to be ordered, and also validating it.
        do {
            cout << "\nEnter the quantity you want to order: ";
            cin >> quantity;

            if (quantity > quantities[indexOfProduct]) {
                cout << "\nSorry, we only have " << quantities[indexOfProduct] << " items at the moment. " << endl;
                continue;
            }
        } while (quantity > quantities[indexOfProduct]);
        quantityOfProduct[i] = quantity; // storing the quantity of the product in the concerning place.

        char moreOrder; // checking if the user wants to order something else.
        do {
            cout << "\nDo you want to order anything else? (y/n): ";
            cin >> moreOrder;
            if (moreOrder == 'y') {
                i++;
                break;
            }
            else {
                break;
            }
        } while (true);

        if (moreOrder == 'y') {
            continue;
        }
        else {
            break;
        }
    } while (true);
    return i; // i represents the number of elements to be order items.
}

void displayOrder(int noOfItems) {
    cout << "Displaying the order!\n";
    cout << "You ordered: \nName\t\tQuatity\t\tPrice Per Item\n";

    for (int i = 0; i <= noOfItems; i++) {
        cout << names[i] << "\t\t" << quantities[i] << "\t\t" << prices[i] << "\n";
    }

    char payment;
    cout << "Proceed to payment (y/n): ";
    cin >> payment;

    // if (payment == 'y')
    //     checkout();
    // else
    //     return;

    cout << "\n\n";
}

int main() {
    cout << "Welcome to XYZ Store!\n";
    displayItems();
    char option;
    do {
        cout << "\n1. View the products\n2. Update prices of pre-exsisting products\n3. Place an order\n4. Exit" << endl;
        cout << "Your choice: ";
        cin >> option;
        switch (option) {
        case '1':
            displayItems();
            break;
        case '2':
            updatePrices();
            break;
        case '3':
            displayOrder(placeOrder());
            break;
        case '4':
            cout << "Exiting........." << endl;
            return 0;
        }
    } while (true);

    return 0;
}

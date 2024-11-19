#include <iostream>
#include<string.h>

using namespace std;

// defining all the global variables

const int MAX_ITEMS = 20; // Maximum number of products the store can have
int NUM_ITEMS = 10; // current number of products the store have.

// Parallel arrays to store item attributes

// empty string refers to an empty slot. 
string names[MAX_ITEMS] = { "Laptop", "Phone", "Tablet", "Headphones", "Charger", "Keyboard", "Mouse", "Monitor", "Printer", "USB Cable" , "", "", "", "", "", "", "", "", "", "" };

// 0 means it is empty or uninitialized
double prices[MAX_ITEMS] = { 60000, 30000, 15000, 2000, 500, 1500, 700, 10000, 5000, 100 , 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };
int quantities[MAX_ITEMS] = { 10, 15, 5, 20, 50, 30, 40, 8, 12, 100 , 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };
int orderedItemsIndex[MAX_ITEMS], quantityOfProduct[MAX_ITEMS]; // arrays for user order

// display all the products the store currently have. 
void displayItems() {
    cout << "Displaying the Products!\n";
    cout << "Index" << "\t\t" << "Name" << "\t\t" << "Price(PKR)" << "\t" << "Quantity(Unit)" << endl;
    for (int i = 0; i < NUM_ITEMS; i++) {
        cout << i << "\t\t" << names[i] << (names[i].length() > 7 ? "\t" : "\t\t") << prices[i] << "\t\t" << quantities[i] << endl;
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

        if (indexOfProduct >= 0 && indexOfProduct < NUM_ITEMS) {
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
    cout << "\n\n";
}

// function to add a new product to store
void addProduct() {
    if (NUM_ITEMS > MAX_ITEMS) { // if there is no capacity we dont move further in the function, and terminate the function 
        cout << "The store has reached its capacity. We cannot add another product.\n";
        return;
        // since the array index starts from 0 we had to make it more than equal to.
    }


    cout << "Enter the details of the new product!\n";
    // taking the name of the product and storing it in the new index, i.e. since there are 10 items initially, NUMS_ITEMS++ will make it 11 for first new item, and 12,13,14 every time the function will be called. 
    string nameOfNewProduct;
    double priceOfNewProduct;
    int quantityOfNewProduct;

    cout << "\nEnter the name of product: ";
    cin >> nameOfNewProduct;
    names[NUM_ITEMS] = nameOfNewProduct;

    // taking the price of the new product
    cout << "\nEnter the price of the product: ";
    cin >> priceOfNewProduct;
    prices[NUM_ITEMS] = priceOfNewProduct;

    // taking the quantity of the new product
    cout << "\nEnter the avaialable quantity of the product: ";
    cin >> quantityOfNewProduct;
    quantities[NUM_ITEMS] = quantityOfNewProduct;

    NUM_ITEMS++; // if there is capacity, we increment the current number of items by 1
    // incrementing the index AFTER the product has been added 


    cout << "The product has been added to the store......\n";
}


void changeOrder() {
    int  indexOfChangedOrder;
    do {
        cout << "Enter the index of the order item you want to change: ";
        cin >> indexOfChangedOrder;
    } while (indexOfChangedOrder >= NUM_ITEMS);

    char changeAttribute;
    cout << "What do you want to change?\n\t1. Quantity\n\t2. Entire product\n";
    cout << "Your choice: ";
    cin >> changeAttribute;

    switch (changeAttribute) {
    case '1':
        int changedQuantity;
        // taking the new quantity 
        do {
            cout << "\nEnter the new quantity of the product: ";
            cin >> changedQuantity;

            if (changedQuantity > quantities[orderedItemsIndex[indexOfChangedOrder]]) {
                cout << "\nSorry, we only have " << quantities[orderedItemsIndex[indexOfChangedOrder]] << " items at the moment. " << endl;
                continue;
            }
        } while (changedQuantity > quantities[orderedItemsIndex[indexOfChangedOrder]]);
        quantityOfProduct[indexOfChangedOrder] = changedQuantity;
        cout << "The quantity has been changed.....\n";
        break;

    case '2':
        int indexOfchangedProduct;
        do {
            cout << "\nEnter the new product you want to order: ";
            cin >> indexOfchangedProduct;
        } while (indexOfchangedProduct > NUM_ITEMS);
        orderedItemsIndex[indexOfChangedOrder] = indexOfchangedProduct;

        int quantityOfchangedProduct;
        do {
            cout << "\nEnter the quantity of the new product: ";
            cin >> quantityOfchangedProduct;

            if (quantityOfchangedProduct > quantities[orderedItemsIndex[indexOfchangedProduct]]) {
                cout << "\nSorry, we only have " << quantities[orderedItemsIndex[indexOfchangedProduct]] << " items at the moment. " << endl;
                continue;
            }
        } while (quantityOfchangedProduct > quantities[indexOfChangedOrder]);
        quantityOfProduct[indexOfChangedOrder] = quantityOfchangedProduct;
        cout << "The product has been changed..........\n";

    default:
        break;
    }
}


// function to place an order
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
        } while (indexOfProduct > NUM_ITEMS);
        orderedItemsIndex[i] = indexOfProduct; // storing the index in an array at the index we created for the orderList i.e. i , so that in case of multiple items, we can store them.

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

// function to calculate the bill
double checkOut(int noOfItems) {
    double total = 0;
    for (int i = 0; i <= noOfItems; i++) {
        total += (quantityOfProduct[i] * prices[orderedItemsIndex[i]]);
    }

    // applying the discount according to given criterai
    double discount = 1;
    if (total >= 5000 && total < 10000)
        discount = total * 0.05;
    else if (total >= 10000)
        discount = total * 0.1;

    total -= discount; // price after applying discount

    // calculating the sales tax according to given value
    double salesTax;
    salesTax = total * 0.15;

    total += salesTax; // price after applying the sales tax

    return total;
}

// function to display the placed order
void displayOrder(int noOfItems) {
    while (true) {
        cout << "Displaying the order!\n";
        cout << "You ordered: \nIndex\t\tName\t\tQuatity\t\tPrice Per Item\n";

        for (int i = 0; i <= noOfItems; i++) {
            cout << i << "\t\t" << names[orderedItemsIndex[i]] << (names[orderedItemsIndex[i]].length() > 7 ? "\t" : "\t\t") << quantityOfProduct[i] << "\t\t" << prices[orderedItemsIndex[i]] << "\n";
        }

        char changeExistingOrder;

        cout << "Do you want to change something in the order? (y/n): ";
        cin >> changeExistingOrder;

        if (changeExistingOrder == 'y') {
            changeOrder();
            continue;
        }

        char payment;
        cout << "Proceed to payment (y/n): ";
        cin >> payment;

        if (payment == 'y') {
            cout << "Your total is: " << checkOut(noOfItems) << "\nPay this at the counter, Thanks for shopping.";
            exit(0); // forcing an exit after the checkout.
        }
        else
            return;

        cout << "\n\n";
    }
}

int main() {
    cout << "Welcome to XYZ Store!\n";
    displayItems();
    char option;
    do {
        cout << "\n1. View the products\n2. Add a new product (Please run the option 1 after adding the new product to display the changes )\n3. Update prices of pre-exsisting products (Please run the option 1 after updating the price to display the changes )\n4. Place an order\n5. Exit" << endl;
        cout << "Your choice: ";
        cin >> option;
        switch (option) {
        case '1':
            displayItems();
            break;
        case '2':
            addProduct();
            break;
        case '3':
            updatePrices();
            break;
        case '4':
            displayOrder(placeOrder());
            break;
        case '5':
            cout << "Exiting........." << endl;
            return 0;
        }
    } while (true);

    return 0;
}

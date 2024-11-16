#include <iostream>

using namespace std;

// defining all the global variables

const int MAX_ITEMS = 20; // Maximum number of products the store can have
int NUM_ITEMS = 10; // current number of products the store have.

// Parallel arrays to store item attributes

// NULL is built in constant that refers that the current location is empty/uninitialized

string names[MAX_ITEMS] = { "Laptop", "Phone", "Tablet", "Headphones", "Charger", "Keyboard", "Mouse", "Monitor", "Printer", "USB Cable" , "", "", "", "", "", "", "", "", "", "" };

// 0 means it is empty or uninitialized
double prices[MAX_ITEMS] = { 60000, 30000, 15000, 2000, 500, 1500, 700, 10000, 5000, 100 , 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };
int quantities[MAX_ITEMS] = { 10, 15, 5, 20, 50, 30, 40, 8, 12, 100 , 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };
int orderedItemsIndex[MAX_ITEMS], quantityOfProduct[MAX_ITEMS]; // arrays for user order

// display all the products the store currently have. 
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

// function to add a new product to store
void addProduct() {
    if (NUM_ITEMS >= MAX_ITEMS) { // if there is no capacity we dont move further in the function, and terminate the function 
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

// function to display the placed order
void displayOrder(int noOfItems) {
    cout << "Displaying the order!\n";
    cout << "You ordered: \nName\t\tQuatity\t\tPrice Per Item\n";

    for (int i = 0; i <= noOfItems; i++) {
        cout << names[orderedItemsIndex[i]] << "\t\t" << quantityOfProduct[i] << "\t\t" << prices[orderedItemsIndex[i]] << "\n";
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

// void calc



int main() {
    cout << "Welcome to XYZ Store!\n";
    displayItems();
    char option;
    do {
        cout << "\n1. View the products\n2. Add a new (Please run the option 1 after adding the new product to display the changes )\n3. Update prices of pre-exsisting products (Please run the option 1 after updating the price to display the changes )\n4. Place an order\n5. Exit" << endl;
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

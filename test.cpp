#include<iostream>
#include<conio.h>

using namespace std;

const int NUM_ITEMS = 10;

// Parallel arrays to store item attributes
string names[NUM_ITEMS] = {"Laptop", "Phone", "Tablet", "Headphones", "Charger","Keyboard", "Mouse", "Monitor", "Printer", "USB Cable"};
double prices[NUM_ITEMS] = {60000, 30000, 15000, 2000, 500, 1500, 700, 10000, 5000, 100};
int quantities[NUM_ITEMS] = {10, 15, 5, 20, 50, 30, 40, 8, 12, 100};
int orderIndexes[NUM_ITEMS], quantityOfProduct[NUM_ITEMS];

int placeOrder() {
    int indexOfProduct, quantity, i = 0;
    do {
        // to get the index of the product to be ordered, and also validating it. 
        do {
            cout<<"Enter the index of the product to be ordered: ";
            cin>>indexOfProduct;

            if(indexOfProduct > NUM_ITEMS) {
                cout<<"Enter a valid index. ";
                continue;
            }
        } while(indexOfProduct > 10);
        orderIndexes[i] = indexOfProduct; // storing the index in an array at the index we created for the orderList i.e. i , so that in case of multiple items, we can store them.

        // to get the quantity of the product to be ordered, and also validating it.
        do {
            cout<<"Enter the quantity you want to order: ";
            cin>>quantity;

            if(quantity > quantities[indexOfProduct]){
                cout<<"Sorry, we only have "<< quantities[indexOfProduct]<<" items at the moment. "<<endl;
                continue;
            }
        } while(quantity > quantities[indexOfProduct]);
        quantityOfProduct[i] = quantity; // storing the quantity of the product in the concerning place.
       
        char moreOrder; // checking if the user wants to order something else.
        do {
            cout<<"Do you want to order anything else? (y/n): ";
            cin>>moreOrder;
            if(moreOrder == 'y'){
                i++;
                break;
            } 
            else {
                break;
            }
        } while(true);


        if(moreOrder == 'y'){
            continue;
        }
        else {
            break;
        }
    } while(true);

    return i; // i represents the number of elements to be order items.
}

int main(){
    cout<<placeOrder();
    return 0;
}

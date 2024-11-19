# Lab No. 09: Open Ended Group Project

### Group Members:

- Hamza Raheem
- Ayesha Mobeen
- Muhammad Uzair

## Problem Statement:

Develop an order management system for a small e-commerce platform. The system should handle product listings, allow users to create and update orders, apply discounts, and calculate total costs with sales tax.

## Our Approach:

In order to keep track and manipulate the user inputs, we will be using the index-based approach. Let’s understand this approach.

```c++
string names[MAX_ITEMS] = { "Laptop", "Phone", "Tablet", "Headphones", "Charger", "Keyboard", "Mouse", "Monitor", "Printer", "USB Cable" , "", "", "", "", "", "", "", "", "", "" };
double prices[MAX_ITEMS] = { 60000, 30000, 15000, 2000, 500, 1500, 700, 10000, 5000, 100 , 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };
int quantities[MAX_ITEMS] = { 10, 15, 5, 20, 50, 30, 40, 8, 12, 100 , 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };

```

In all the parallel 1-dimensional arrays, The item at 0th index

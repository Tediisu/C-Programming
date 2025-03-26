//This problem was created by Cris Militante for CSIT1201 Second Semester AY 2019-2020
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define ARRSIZE 10

typedef struct ProductDetails{
    char prodID[9];
    char prodName[32];
    char shelf[5];
}ProductDetails;

typedef struct Product{
    ProductDetails details;
    float price;
    int stocks;
    int itemsSold;
}Product;

void displayProduct(Product prod)
{
    char buffer[300];
    sprintf(buffer, "ID: %s\nName: %s\nPrice: %.2f\nShelf: %s\nStocks: %d\nItems Sold: %d\n\n", 
    prod.details.prodID, prod.details.prodName, prod.price, prod.details.shelf, 
    prod.stocks, prod.itemsSold);
    puts(buffer);
}

Product* getAllShelfItems(Product P[], char shelf[]);
/*This function receives an array of products and a specific shelf. The function goes 
through the entire array of products and returns to the calling function all the Products 
that can be found on that shelf. Let the last Product have a stock
of -1, to act as a sentinel value.*/

Product* getLowStockItems(Product P[], int threshold);
/* This function receives an array of products and an int threshold. 
The function goes through the entire array of products and returns to the calling function all the 
Products that have stocks equal to or below the threshold. Let the last Product have a stock of -1, 
to act as a sentinel value.*/

int findProd(Product P[], char id[]);
/* This function receives an array of products an a specific id. The function goes 
through the entire array of products and checks if there is a product in the list with the same 
id as the parameter passed. If there is, return the index of that product. Else, return 0 */

void updatePrices(Product P[], int salesThresh, float multiplier);
/* This function receives an array of products, a sales threshold, and a multiplier. 
The function goes through the entire array of products, and updates the prices of ALL products 
who’s sales go BEYOND the sales threshold. New price is calculated as follows: price * multiplier.*/

int main()
{    
    Product prod[ARRSIZE] = {
        {{"11111111", "Pikachu", "Pok"}, 2.99, 5, 7},
        {{"22222222", "Dialga", "Pok"}, 2.99, 5, 2},
        {{"33333333", "Paprika", "Spi"}, 0.53, 10, 3},
        {{"44444444", "Pepper", "Spi"}, 0.50, 7, 3},
        {{"55555555", "Lollipop", "Can"}, 0.10, 5, 10},
        {{"66666666", "Chillies", "Spi"}, 0.45, 10, 15},
        {{"77777777", "Absoulute", "Dri"}, 0.20, 8, 3},
        {{"88888888", "MountDew", "Dri"}, 0.20, 8, 3},
        {{"99999999", "Coke", "Dri"}, 0.15, 9, 5},
        {{"00000000", "Darkrai", "Pok"}, 3.49, 10, 9}
    };
    Product *shelfItems = getAllShelfItems(prod, "Pok");
    Product *gotLow = getLowStockItems(prod, 5);
    int index = findProd(prod, "11111111");
    updatePrices(prod, 1.00, 2);

    printf("Shlef Items\n");
    int i;
    for (i = 0; shelfItems[i].stocks != -1; i++)
    {
        displayProduct(shelfItems[i]);
    }
    printf("Got Low\n");
    for (i = 0; gotLow[i].stocks != -1; i++)
    {
        displayProduct(gotLow[i]);
    }
    printf("Updated prices\n");
    for (i = 0; i < ARRSIZE; i++)
    {
        displayProduct(prod[i]);
    }


    return 0;
}
Product* getAllShelfItems(Product P[], char shelf[])
{
    Product *foundProd = malloc(sizeof(Product) * ARRSIZE);
    int index = 0;

    int i;
    for (i = 0; i < ARRSIZE; i++)
    {
        if (strcmp(P[i].details.shelf, shelf) == 0)
        {
            foundProd[index++] = P[i];
        }
    }

    foundProd[index++].stocks = -1;

    return foundProd;
}
Product* getLowStockItems(Product P[], int threshold)
{
    Product *foundProd = malloc(sizeof(Product) * ARRSIZE);
    int index = 0;

    int i;
    for (i = 0; i < ARRSIZE; i++)
    {
        if (P[i].stocks <= threshold)
        {
            foundProd[index++] = P[i];
        }
    }

    foundProd[index++].stocks = -1;

    return foundProd;
}
int findProd(Product P[], char id[])
{
    int i;
    for (i = 0; i < ARRSIZE && strcmp(P[i].details.prodID, id) != 0; i++){}

    return i;
}
void updatePrices(Product P[], int salesThresh, float multiplier)
{
    int i;
    for (i = 0; i < ARRSIZE; i++)
    {
        if (P[i].price > salesThresh)
        {
            P[i].price *= multiplier;
        }
    }
}
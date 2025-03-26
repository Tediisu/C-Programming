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

Product* getAllShelfItems(Product P[], int count, char shelf[])
{
    int i, j;
    Product temp[count];
    Product *shelfProds;

    for (i = j = 0; i < count; i++)
    {
        if (strcmp(P[i].details.shelf, shelf == 0))
        {
            temp[j++] = P[i];
        }
    }

    shelfProds = malloc(sizeof(Product) * (j + 1));
    if (shelfProds != NULL)
    {
        shelfProds[0].stocks = -1;
        memcpy(shelfProds + 1, temp, sizeof(Product) * j);
    }

    return shelfProds;
}


int main(void)
{
     Product prods[] = {
        {{"PRD00001", "Corned Beef", "SH01"}, 102.00, 1000, 300},
        {{"PRD00002", "Spam", "SH01"}, 208.00, 3000, 273},
        {{"PRD00003", "Sardines in Tomato Sauce", "SH01"}, 26.00, 1235, 200},
        {{"PRD00004", "Purefoods TJ Hotdog 1KG", "FR02"}, 198.00, 1672, 20},
        {{"PRD00005", "Virginia Hotdog 1KG", "FR01"}, 192.00, 2763, 10}
    };




}
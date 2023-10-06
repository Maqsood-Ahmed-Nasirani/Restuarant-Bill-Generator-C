#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Macros
#define PASS 2770

// global variable
char bill[300], name[15];
int TotalBill;

// prototypes
void Customer();
void Manager();

int main(void)
{
    char in;
    int code;
    printf("Are you a customer or Manager?\n\tc for Customer\n\tm for Manager\n");
    scanf("%c", &in);
    switch (in)
    {
    case 'm':
        printf("Enter a password: \n");
        scanf("%i", &code);
        if (code == PASS)
        {
            Manager();
        }
        else
        {
            printf("Try Again!\n");
            scanf("%i", &code);
        }
        break;

    case 'c':

        printf("\nEnter your Good Name Sir? \n");
        scanf("%s", &name);
        Customer();
        break;

    default:
        printf("Enter a valid choice!\n");
        break;
    }

    // reading the content of a text file
    FILE *rfile = fopen("bill.txt", "r");
    printf("_______________________________________________________________\n\n");
    // displaying the generated bill
    if (rfile == NULL)
    {
        printf("Unable to open a file!\n");
    }
    else
    {
        while (fgets(bill, 300, rfile) != NULL)
        {
            printf("%s", bill);
        }
    }

    fclose(rfile);
}

// function for Manager
void Manager()
{
    printf("\n__________________ Welcome Sir! __________________\n");
}

// function for customer
void Customer()
{
    int size, qty, N, inp, bills;

    // getting itmes in text files to generate it
    FILE *file = NULL;
    file = fopen("bill.txt", "w+");
    if (file == NULL)
    {
        printf("Unable to open a file!\n");
    }
    else
    {
        fprintf(file, "Qty  Item_Size    Item_Name\t         Item_Price\n");
    }

    // Pizza prices
    int Rs[] = {350, 850, 1350};
    // Create an array of strings for pizza menu items
    char pizza_menu[6][20] = {"Pepperoni-pizza", "Mushroom-pizza", "Sausage-pizza", "Hawaiian-pizza", "Margherita-pizza", "fajita-pizza"};
    // prices of different sizes of pizza's
    char *pizzaPrice[] = {"Small  Rs.350 ", "Medium Rs.850", "Large  Rs.1350"};
    do
    {

        // Print the pizza menu
        printf("\n\t-------------------- Pizza Menu ----------------------\n");
        for (int i = 0; i < 6; i++)
        {
            printf("\t%i for %s\n", i, pizza_menu[i]);
        }
        printf("\n\tWhich Pizza flavour you want?  ");
        scanf("%i", &N);

        if (N > 5)
        {
            printf("\tEnter a valid choice!  ");
            scanf("%i", &N);
        }

        // asking for size of pizza
        printf("\t------------------------------------------------------\n");
        for (int j = 0; j < 3; j++)
        {
            printf("\t%i  -- for %s\n", j, pizzaPrice[j]);
        }

        printf("\n\tEnter the size of pizza  ");
        scanf("%i", &size);

        if (size > 2)
        {
            printf("\tEnter a valid size!  ");
            scanf("%i", &qty);
        }
        printf("\n\tHow many you want?  ");
        scanf("%i", &qty);
        printf("\n");

        // for small pizzas
        if (size == 0)
        {
            fprintf(file, "%d    | Small   |   %s    |   Rs.%i\n", qty, pizza_menu[N], (qty * Rs[0]));
            TotalBill = TotalBill + (qty * Rs[0]);
        }
        // for medium pizzas
        else if (size == 1)
        {
            fprintf(file, "%d    | Medium  |   %s     |   Rs.%i\n", qty, pizza_menu[N], (qty * Rs[1]));
            TotalBill = TotalBill + (qty * Rs[1]);
        }
        // for large pizzas
        else
        {
            fprintf(file, "%d    | Large   |  %s      |   Rs.%i\n", qty, pizza_menu[N], (qty * Rs[2]));
            TotalBill = TotalBill + (qty * Rs[2]);
        }
        printf("\n(-1 for EXIT): ");
        scanf("%i", &inp);
    } while (inp != -1);

    fprintf(file, "\nTotal bill --------------------------     Rs.%i\n", TotalBill);
    fprintf(file, "\nThank you %s for choosing The pizza Hut,\nCome back soon for Delicious Food\n", name);
    fprintf(file, "\n_______________________________________________________________\n\n");
    fclose(file);
}

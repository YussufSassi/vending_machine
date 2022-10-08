#include <stdio.h>
#include <string>
#include <math.h>
using namespace std;

struct Coins
{
    int twoEuros;
    int oneEuro;
    int fiftyCents;
    int twentyCents;
    int tenCents;
    int fiveCents;
    int twoCents;
    int oneCent;
};

Coins getCoins(float value)
{
    Coins coinsUsed = {};
    float remainder;
    int val = value * 100;
    coinsUsed.twoEuros = floor(val / 200), val %= 200;
    coinsUsed.oneEuro = floor(val / 100), val %= 100;
    coinsUsed.fiftyCents = floor(val / 50), val %= 50;
    coinsUsed.twentyCents = floor(val / 20), val %= 20;
    coinsUsed.tenCents = floor(val / 10), val %= 10;
    coinsUsed.fiveCents = floor(val / 5), val %= 5;
    coinsUsed.twoCents = floor(val / 2), val %= 2;
    coinsUsed.oneCent = floor(val / 1), val %= 1;
    return coinsUsed;
}

int main()
{
    string items[11] = {"Snickers", "Chips", "Mars", "Sprite", "Milk", "Apple", "M&M's", "Coca-Cola", "Iced Tea", "Peanuts", "Pick up"};
    float prices[11] = {0.89, 0.99, 0.89, 1.99, 1.50, 0.79, 2.99, 1.99, 0.99, 0.89, 1.89};
    int choice;
    float money;
    float change;
    float missingMoney;
    printf("|------------------------------|\n");
    for (int i = 0; i < 11; i++)
    {
        printf("| (%i)  %s (%.2f€)\n", i, items[i].c_str(), floorf(prices[i] * 100) / 100);
        printf("|------------------------------|\n");
    }
    printf("🍫🍭 Please enter the number of item you want: ");
    scanf("%i", &choice);
    if (choice > 10)
    {
        printf("This item is does not exist or is out of stock!\n");
        return -1;
    }
    printf("🪙 Please insert your coins (The price is: %.2f€):", prices[choice]);
    scanf("%f", &money);

    while (money < prices[choice])
    {
        printf("You haven't inserted enough money! %.2f€ missing!\nYou can insert another coin here: ", (prices[choice] - money));
        scanf("%f", &missingMoney);
        money += missingMoney;
        if (money >= prices[choice])
        {
            break;
        }
    }

    if (money > prices[choice])
    {
        change = (money - prices[choice]);
        printf("Here's your item: %s\n", items[choice].c_str());
        Coins changeCoins = getCoins(change);
        printf("Returning your change: %.2f€\n", change);
        if (changeCoins.twoEuros)
        {
            printf("🪙 2.00€: %i\n", changeCoins.twoEuros);
        }
        if (changeCoins.oneEuro)
        {
            printf("🪙 1.00€: %i\n", changeCoins.oneEuro);
        }
        if (changeCoins.fiftyCents)
        {
            printf("🪙 0.50€: %i\n", changeCoins.fiftyCents);
        }
        if (changeCoins.twentyCents)
        {
            printf("🪙 0.20€: %i\n", changeCoins.twentyCents);
        }
        if (changeCoins.tenCents)
        {
            printf("🪙 0.10€: %i\n", changeCoins.tenCents);
        }
        if (changeCoins.fiveCents)
        {
            printf("🪙 0.05€: %i\n", changeCoins.fiveCents);
        }
        if (changeCoins.oneCent)
        {
            printf("🪙 0.01€: %i\n", changeCoins.oneCent);
        }
    }
    else
    {
        printf("Here's your item: %s\n", items[choice].c_str());
    }
    return 0;
}
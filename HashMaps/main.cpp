#include <iostream>
#include "HashMap.h"

using namespace std;

int main()
{
    Hashtable <int> price;
    price.insert("Burger",120);
    price.insert("Pepsi",20);
    price.insert("Noodles",90);
    price.insert("Coke",40);
    price.insert("BurgerPizza",120);
    price.insert("Banana",40);
    price.insert("Taco",140);
    price.print();
    int *priceobj = price.search("Noodles");
    if(priceobj==NULL)
    {
        cout<<"Not Found";
    }
    else
        cout<<"Price of Noodles is "<<*priceobj<<endl;
    price.erase("Banana");
    price.print();
    return 0;
}

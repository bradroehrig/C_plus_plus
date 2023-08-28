#include <iostream>
#include "food.h"
using namespace std;

const char* RecommendMeAFood(char firstLetter){
    
    if(firstLetter=='a' || firstLetter=='A')
        return "apple";
    else if(firstLetter=='b' || firstLetter=='B')
        return "banana";
    else if(firstLetter=='C' || firstLetter=='C')
        return "choclate cake";
    else return "pizza";
}

void GetPizzaRecipe(){
    cout<<"To make pizza your need..";
}
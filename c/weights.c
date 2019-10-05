#include "stdlib.h"
#include "stdio.h"
#include "string.h"
#define LIMIT 100

struct IceCream
{
    char flavor[100];
    int weight;
};

// Function to handle weighted random choice
int weigh (int sum, struct IceCream *weights){
    
    // 2. Generate random number between 1 and sum of weights
    int random = rand() % sum + 1;

    // 3. Iterate through items;
    for(int iter = 0; iter != 4; iter++){

        // 4. Subtract weight of each item from random number
        random -= weights[iter].weight;

        // 5. Compare with 0, if <= 0, that item has been chosen
        if(random <= 0){
            return iter;         
        } 
        // 6. Else continue subtracting
    }
    return -1;
}

int main (){
    
    srand(time(NULL));
    // 0. Decide on weights for each item
    // Mapping item to its weight
    struct IceCream *weights = (struct IceCream *)malloc(sizeof(struct IceCream) * 4);
    strcpy(weights[0].flavor, "Vanilla");
    weights[0].weight = 15;
    strcpy(weights[1].flavor, "Strawberry");
    weights[1].weight = 25;
    strcpy(weights[2].flavor, "Chocolate");
    weights[2].weight = 55;
    strcpy(weights[3].flavor, "Cookies and Cream");
    weights[3].weight = 5;
    
    // Example map for storing results
    struct IceCream *results = (struct IceCream *)malloc(sizeof(struct IceCream) * 4);
    strcpy(results[0].flavor, "Vanilla");
    results[0].weight = 0;
    strcpy(results[1].flavor, "Strawberry");
    results[1].weight = 0;
    strcpy(results[2].flavor, "Chocolate");
    results[2].weight = 0;
    strcpy(results[3].flavor, "Cookies and Cream");
    results[3].weight = 0;

    // 1. Get sum of weights 
    int sum = 0;
    for (int iter = 0; iter != 4; iter++ ){
        sum += weights[iter].weight; 
    }

    // Running example LIMIT times 
    for(int i = 0; i < LIMIT; i++){
        results[weigh(sum, weights)].weight += 1;    
    }

    // Display results
    for(int iter = 0; iter != 4; iter++){
        printf("%s: %d\n", results[iter].flavor, results[iter].weight);
    }
    
}

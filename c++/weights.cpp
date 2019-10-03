#include <iostream>
#include <map>
#include <cstdlib>
#define LIMIT 100

// Function to handle weighted random choice
std::string weigh (int sum, std::map<std::string, int> weights, std::map<std::string, int>::iterator iter){
    
    // 2. Generate random number between 1 and sum of weights
    int random = rand() % sum + 1;

    // 3. Iterate through items;
    for(iter = weights.begin(); iter != weights.end(); iter++){

        // 4. Subtract weight of each item from random number
        random -= iter->second;

        // 5. Compare with 0, if <= 0, that item has been chosen
        if(random <= 0){
            return iter->first;         
        } 
        // 6. Else continue subtracting
    }
    return "Should not reach here.";
}

int main (){
    
    srand(time(NULL));
    // 0. Decide on weights for each item
    // Mapping item to its weight
    std::map<std::string, int> weights = {{"Vanilla", 15}, {"Strawberry", 25}, {"Chocolate", 55}, {"Cookies and Cream", 5}};
    
    // Example map for storing results
    std::map<std::string, int> results = {{"Vanilla", 0}, {"Strawberry", 0}, {"Chocolate", 0}, {"Cookies and Cream", 0}};

    // Iterator for map object
    std::map<std::string, int>::iterator iter;
    
    // 1. Get sum of weights 
    int sum = 0;
    for ( iter = weights.begin(); iter != weights.end(); iter++ ){
        sum += iter->second; 
    }

    // Running example LIMIT times 
    for(int i = 0; i < LIMIT; i++){
        results[weigh(sum, weights, iter)] += 1;    
    }

    // Display results
    for(iter = results.begin(); iter != results.end(); iter++){
        std::cout << iter->first << ":" << iter->second << std::endl; 
    }
    
}

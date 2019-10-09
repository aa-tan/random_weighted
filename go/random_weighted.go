package main

import (
	"fmt"
	"math/rand"
	"time"
)

const LIMIT = 100

// randomWeighted returns an element of weights chosen randomly. The probability of an element
// being chosen depends on its weight
func randomWeighted(weights map[string]int) string {
	// Get a random number between 1 and the sum of weights
	weightSum := 0
	for _, weight := range weights {
		weightSum += weight
	}

	randSource := rand.NewSource(time.Now().UnixNano())
	random := rand.New(randSource)

	randomValue := random.Intn(weightSum) + 1

	// Iterate through items
	for k, weight := range weights {
		// Substract item's weight from the generated random value
		randomValue -= weight

		// If randomValue is <= 0, the item has been chosen
		if randomValue <= 0 {
			return k
		}

		// Else, continue iterating
	}

	return "Shouldn't reach here"
}

func main() {
	// Weights map
	weights := map[string]int{
		"Vanilla":           15,
		"Strawberry":        25,
		"Chocolate":         55,
		"Cookies and Cream": 5,
	}

	// Results map. In go, maps will yield the zero value of the corresponding
	// type for keys not in the map, so there is no need to initialize the map
	// with the necessary keys
	results := make(map[string]int)

	// Run the function LIMIT times
	for i := 0; i < LIMIT; i++ {
		randomKey := randomWeighted(weights)
		results[randomKey]++
	}

	// Show results
	for k, v := range results {
		fmt.Printf("%s: %v (w = %v)\n", k, v, weights[k])
	}
}

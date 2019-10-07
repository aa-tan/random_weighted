package random_weighted;

import java.util.HashMap;

/**
 *
 * @author Juan Manuel Gutierrez
 */
public class Random_weighted {

    /**
     * *
     * Constants
     */
    public static int LIMIT = 100;

    /**
     * Constructor
     */
    public Random_weighted() {

    }

    /**
     * Method to handle weighted random choice
     *
     * @param sum
     * @param weights
     * @return
     */
    public static String weight(int sum, HashMap<String, Integer> weights) {
        // 2. Generate random number between 1 and sum of weights
        int random = (int) Math.floor(Math.random() * sum) + 1;
        
        // 3. Iterate through items;
        for (String flavor : weights.keySet()) {
            // 4. Subtract weight of each item from random number
            random -= weights.get(flavor);
            
            // 5. Compare with 0, if <= 0, that item has been chosen
            if (random <= 0) {
                return flavor;
            }
            
            // 6. Else continue subtracting
        }
        
        return "Should not reach here.";
    }

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) {
        // 0. Decide on weights for each item
        // Mapping item to its weigh
        HashMap<String, Integer> weights = new HashMap<>();;
        weights.put("Vanilla", 15);
        weights.put("Strawberry", 25);
        weights.put("Chocolate", 55);
        weights.put("Cookies and Cream", 5);

        HashMap<String, Integer> results = new HashMap<>();

        // 1. Get sum of weights 
        int sum = 0;
        for (String flavor : weights.keySet()) {
            sum += weights.get(flavor);
            results.put(flavor, 0);
        }

        // Running example LIMIT times 
        for (int i = 0; i < Random_weighted.LIMIT; i++) {
            String actual_flavor = Random_weighted.weight(sum, weights);
            results.put(actual_flavor, results.get(actual_flavor) + 1);
        }

        // Display results
        System.out.println(results);
    }

}

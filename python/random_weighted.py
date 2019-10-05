"""
Implements a random weighted choice function

Functions: weight(collection)
"""
import random


def weight(collection):
    """Choose an element from a dict based on its weight and return its key.

       Parameters:
       - collection (dict): dict of elements with weights as values.

       Returns:
       string: key of the chosen element.
    """

    # 1. Get sum of weights
    weight_sum = sum([value for value in collection.values()])

    # 2. Generate random number between 1 and sum of weights
    random_value = random.randint(1, weight_sum)

    # 3. Iterate through items
    for key, value in collection.items():

        # 4. Subtract weight of each item from random number
        random_value -= value

        # 5. Compare with 0, if <= 0, that item has been chosen
        if random_value <= 0:
            return key
        # 6. Else continue subtracting

    # Should not reach here.
    raise ValueError("Invalid argument value.")


if __name__ == '__main__':

    LIMIT = 100

    # 0. Decide on weights for each item
    # Mapping item to its weight
    WEIGHTS = {
        'Vanilla': 15,
        'Strawberry': 25,
        'Chocolate': 55,
        'Cookies and Cream': 5
    }

    # Initializing the counter for storing results
    counter = {
        'Vanilla': 0,
        'Strawberry': 0,
        'Chocolate': 0,
        'Cookies and Cream': 0
    }

    # Running example LIMIT times
    for i in range(LIMIT):
        counter[weight(WEIGHTS)] += 1

    # Display results
    print(counter)

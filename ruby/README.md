## Run
```
$ ruby ./weights.rb
```

## Notes

chocolate almond, mint chocolate, mocha, raspberry almond, and triple chocolate

This example has a weighted selection of M&M's flavors. After a flavor is chosen and dispense, another bag with the same weighted contents is prepared. Each bag gives a weight for 5 different M&M's flavors. 

|Flavor|Weight|
|:----:|:----:|
|Chocolate Almond|60|
|Mint Chocolate|15|
|Mocha|5|
|Raspberry Almond|10|
|Triple Choclate|10|
|Sum| 100

Based on the weights, a random flavor is chosen. The process is repeated 100 times by default to demonstrate the weighted distribution. This can be changed by modifying the `NUMBER_OF_RUNS` constant defined at the top of the code. The final output is how many times each flavor was chosen. It will be found that the results closely resemble the distribution of the weights provided.

### Example Output

|Flavor| # of times chosen|
|:-:|:-:|
|Chocolate Almond|62|
|Mint Chocolate|10|
|Mocha|6|
|Raspberry Almond|13|
|Triple Choclate|9|

Comments can be found in the sourcecode that explain the process.

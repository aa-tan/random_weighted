## Run
```
$ python3 random_weighted.py
```

## Notes

This example gives a weight for 4 different ice cream flavors.

|Flavor|Weight|
|:----:|:----:|
|Vanilla|15|
|Strawberry|25|
|Chocolate|55|
|Cookies and Cream|5|
|Sum| 100

Based on the weights, a random flavor is chosen. The process is repeated 100 times by default to demonstrate the weighted distribution. This can be changed by modifying the LIMIT defined at the top of the code. The final output is how many times each flavor was chosen. It will be found that the results closely resemble the distribution of the weights provided.

### Example Output

|Flavor| # of times chosen|
|:-:|:-:|
|Vanilla|15|
|Strawberry|26|
|Chocolate|53|
|Cookies and Cream|6|

Comments can be found in the sourcecode that explain the process.

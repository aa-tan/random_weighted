# Random Weighted Choice
An example of how to implement a random generator with weighted distribution.

## Build
Clone the repo.
```console
$ git clone https://github.com/aa-tan/random_weighted
```
Enter the directory.
```console
$ cd random_weighted
```
Make.
```console
$ make
```

## Run
```
$ ./weights
```

## Notes

This program gives a weight for 4 different ice cream flavors. Based on the weights, a random flavor is chosen. The process is repeated 100 times by default to demonstrate the weighted distribution. This can be changed by modifying the LIMIT defined at the top of the code. The final output is how many times each flavor was chosen. It will be found that the results closely resemble the distribution of the weights provided. Comments can be found in the sourcecode that explain the process.
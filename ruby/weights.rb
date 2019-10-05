NUMBER_OF_RUNS = 100

# chooses one of the items from the array randomly
def weighted_selection(hash)
  create_array_of_weighted_items(hash).sample
end

# create an array of the total amount of weights
# items based on the weight
def create_array_of_weighted_items(hash)
  array_of_items = []
  hash.each do |item, weight|
    weight.times { array_of_items << item }
  end
  array_of_items
end


# weighted items and values
weighted_hash = {
  'Chocolate Almond': 60,
  'Mint Chocolate': 15,
  'Mocha': 5,
  'Raspberry Almond': 10,
  'Triple Chocolate': 10
}

# script that is ran. Empty hash is built to store the results
# As the selection is chosen, it increments that item by one in the hash
random_selections = Hash.new(0)
NUMBER_OF_RUNS.times do
  random_selections[weighted_selection(weighted_hash)] += 1
end

puts random_selections

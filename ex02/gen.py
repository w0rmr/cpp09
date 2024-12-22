import random

# Generate 10,000 unique random numbers between 1 and 10,000
numbers = random.sample(range(1, 10001), 10000)

# Convert the list of numbers to a space-separated string
input_string = ' '.join(map(str, numbers))

print(input_string)

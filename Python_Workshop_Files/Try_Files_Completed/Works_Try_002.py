# Python 2.7.X
# Try_003.py
# Logical and Conditional statement practice

# Objective: Write a script that will generate random number,
# and check if user guesses right input
# We will use variable as user input for this script
# Print out that user guessed right number
# If user's guess was lower than random number,
# print out that user's guess was lower than random number
# If user's guess was higher than random number,
# print out that user's guess was higher than random number
# Make sure to print the random number after

import random
input = 10 # User input
# This sets random number between 0 through 10
number = random.randrange(0, 10, 1) + 1

# Write your code here
if input == number:
    print "Your guess was right:", number
elif input > number:
    print "Your guess was higher:", number
elif input < number:
    print "Your guess was lower:", number

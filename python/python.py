
import random  #first function

def generate_user_bank_number():
    user_bank_number = 0
    for i in range(10):
        user_bank_number *= 10
        user_bank_number += random.randint(0, 9)
    
    return abs(user_bank_number)

def generate_user_money():
    user_money = 0
    for i in range(10):
        user_money *= 10
        user_money += random.randint(0, 9)
    
    return abs(user_money)


import random   #second function

def generate_user_money():
    user_money = 0
    rd = random.Random()
    range_generator = random.randint(0, 9)

    for i in range(range_generator):
        user_money *= 10
        user_money += random.randint(0, 9)

    return abs(user_money)
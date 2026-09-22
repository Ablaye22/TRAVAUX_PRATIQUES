import random
names = input("Enter all the names separated by common: ")
names = names.split(",")
choix = random.choice(names)
print(f"{choix} will pay the bill")
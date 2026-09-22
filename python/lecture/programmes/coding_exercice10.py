name1 = input("Enter the first complete name: ")
name2  = input("Enter the second compte name: ")
name_lower_case = (name1 + name2).lower()
t = name_lower_case.count('t')
r = name_lower_case.count('r')
u = name_lower_case.count('u')
e = name_lower_case.count('e')
true = t+r+u+e
l = name_lower_case.count('l')
o = name_lower_case.count('o')
v = name_lower_case.count('v')
e = name_lower_case.count('e')
love = l + o + v + e 
score = int (str(true) + str(love))

if score < 10 or score > 90:
    print(f"Your score is {score} and you go together like coke and mentos")
elif score >=40 and  score <= 50:
    print(f"Your score is {score} you are alright together")
else:
    print(f"Your score is {score}")
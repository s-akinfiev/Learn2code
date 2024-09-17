import random
goal = list(random.randint(0,9) for i in range(4))
print (goal)

guess = list(map(int, input().split()[:5]))
print(guess)

exact = 0
appr = 0
attempts = 0

for i in range(len(guess)):
    if guess[i] == goal[i]:
        exact += 1
    elif guess[i] in goal:
        appr += 1
print(exact, appr)
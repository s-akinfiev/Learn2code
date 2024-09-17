import random
days = [random.randint(1,365) for day in range(35)]
duplicates = [item for item in days if days.count(item) > 1]
print(days, '\n', duplicates)
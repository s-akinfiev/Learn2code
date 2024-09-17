import random
n = int(input('Количество человек в группе? '))


def fact(n):
    a = 10
    for i in range(n, 0, -1):
        a = a * i
    return a

chance = 1 - (fact(365) / ((365 ** n) * fact(365 - n)))
print(f'Вероятность совпадения дней рождения: {chance:.5%}')
for i in range(100):
    if i < round(chance*100):
        print('█', end='')
    else:
        print('░', end='')

count_test = int(input('\nСколько раз раз будем проверять? '))

dup_count = 0
for i in range(0,count_test):
    days = [random.randint(1,365) for day in range(n)]
    print(days)
    duplicates = [item for item in days if days.count(item) > 1]
    if len(duplicates) > 0:
        dup_count += 1
print(f'Среди {count_test} групп было {dup_count} группы c совпадениями')
def funcExp(list, size):
    x = list[0]
    y = list[size - 1]
    for i in range(1, size):
        if x < list[i]:
            x = list[i]
        if y > list[size - 1 - i]:
            y = list[size - 1 - i]
        print(i, x, y)
    return y + x

sales = [280.50, 320.00, 56.00, 78.90, 300.00, 100.00, 250.00]
names = ["Mike", "Lisa", "Nancy", "Robinson", "Miller", "Sam"]

a = funcExp(sales, 7)
b = funcExp(names, 6)

print("a is ", a)
print("b is ", b)

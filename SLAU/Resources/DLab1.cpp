import numpy as np
 
a = np.array([
    [3.25, 1.54, 4.91, 2.43, 0.14],
    [-3.34, 1.17, 3.2, 5.13, 1.15],
    [-9.52, 2.73, 3.37, -5.89, 0.92],
    [1.13, 2.21, 4.47, 5.11, 5.65]], 
    dtype=np.float64)
a1 = a.copy()
a2 = np.array([
    [3.25, 1.54, 4.91, 2.43],
    [-3.34, 1.17, 3.2, 5.13],
    [-9.52, 2.73, 3.37, -5.89],
    [1.13, 2.21, 4.47, 5.11]], 
    dtype=np.float64)
x = np.zeros((4, 1))
x1 = x.copy()

podstanovki = np.array([1, 2, 3, 4])
t = 0

rows = 4
cols = 5
podstanovki_count = 0

#def bubble_max_row(n, m):
#    max_element = a1[n][0]
#    q = 0
#    for i in range(1, m - 1):
#        if abs(a1[n][i]) > abs(max_element):
#            max_element = a1[n][i]
#            q = i
#    return q
    
def bubble_max_row(n, m):
    for j in range(cols):
        mx = a1[0][j]
        q = 0
        for i in range(rows):
            if a1[i][j] > mx:
                mx = a1[i][j]
                q = i
    return q    
    
def print_matrix(a):
    for i in range(len(a)):
        for j in range(len(a[i])):
            print("%8.4f" % (a[i][j]), end=' ')
        print()

print("исходная матрица")
print_matrix(a)        

# прямой ход
while (t != rows - 1):
    y = bubble_max_row(t, cols)
    if (y != t):
        for i in range(0, rows):
            a1[i][t], a1[i][y] = a1[i][y], a1[i][t]
        podstanovki[t], podstanovki[y] = podstanovki[y], podstanovki[t]  # запоминаем перестановки
        podstanovki_count += 1
    coefficient = 0
    for i in range(t + 1, rows):
        coefficient = a1[t][t] / a1[i][t]
        for j in range(t, a.shape[1]):
            a1[i][j] = a1[i][j] - a1[t][j]/coefficient
    t += 1
 
# oбратный ход
for i in range(rows - 1, -1, -1):
    x[i] = (a1[i][-1] - sum([a1[i][j] * x[j] for j in range(i + 1, cols - 1)])) / a1[i][i]
   
# вост порядок х
for i in range(0, 4):
    x1[podstanovki[i] - 1] = x[i]
print("решение")
for i in range(0, 4):
    print("x[", i + 1, "]=", "%2.4f" % (x1[i]))
 
# невязка
diff = np.zeros((4, 1))
for i in range(rows):
    diff[i] = a[i][-1] - sum([a[i][j] * x1[j] for j in range(0, cols - 1)])

print("вектор невязки")
for i in range(0, 4):
    print("d[", i + 1, "]=", "%.16f" % (diff[i]))

# определитель
det = 1
for i in range(0, 4):
    det *= a1[i][i]
print("det=", "%2.4f" % (pow((-1),podstanovki_count)*det))
print("проверка: ", np.linalg.det(a2))

# обратная матрица
inv = np.zeros((4, 4))
for k in range(0, 4):
    a3 = a.copy()
    for j in range(0, 4):
        if (k == j):
            a3[j][4] = 1
        else:
            a3[j][4] = 0
    t = 0
    podstanovki = np.array([1, 2, 3, 4])
 
    # прямой ход
    while (t != rows - 1):
        y = bubble_max_row(t, cols)
        if (y != t):
            for i in range(0, rows):
                a3[i][t], a3[i][y] = a3[i][y], a3[i][t]
            podstanovki[t], podstanovki[y] = podstanovki[y], podstanovki[t]  # запоминаем перестановки
        coefficient = 0
        for i in range(t + 1, rows):
            coefficient = a3[t][t] / a3[i][t]
            for j in range(t, a.shape[1]):
                a3[i][j] = a3[i][j] - a3[t][j]/coefficient
        t += 1
 
    # обратный ход
    for i in range(rows - 1, -1, -1):
        x[i] = (a3[i][-1] - sum([a3[i][j] * x[j] for j in range(i + 1, cols - 1)])) / a3[i][i]
 
    # восстанавливаем порядок
    for i in range(0, 4):
        x1[podstanovki[i] - 1] = x[i]
    for i in range(0, 4):
        inv[i][k] = x1[i]
print("обратная матрица")
print_matrix(inv)
print("проверка")
c = a2.dot(inv)
print_matrix(c)
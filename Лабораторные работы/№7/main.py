print("MAIN STARTED")

import zeroArray
import time

print("MODULE IMPORTED")

def slow_zero_array(size):
    arr = []
    for _ in range(size):
        arr.append(0)
    return arr


SIZE = 50000000

print("Создание нулевого массива")
print("-" * 40)

print("Запуск C++")
t1 = time.time()
arr_c = zeroArray.create(SIZE)
t2 = time.time()
print(f"C++ time: {t2 - t1:.6f} s")

print("-" * 40)

print("Запуск Python")
t3 = time.time()
arr_py = slow_zero_array(SIZE)
t4 = time.time()
print(f"Python time: {t4 - t3:.6f} s")

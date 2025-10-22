def calculate_sum(arr):
    total = 0
    for x in arr:
        total += x
    return total


def filter_array(arr):
    result = []
    for x in arr:
        if x % 3 == 0:
            result.append(x)
    return result

def symmetric_difference(setA, setB):
    result = set()
    for elem in setA:
        if elem not in setB:
            result.add(elem)
    for elem in setB:
        if elem not in setA:
            result.add(elem)
    return result


def main():
    print("Введите 10 элементов массива A:")
    A = [int(input()) for _ in range(10)]

    B = filter_array(A)

    sumA = calculate_sum(A)
    sumB = calculate_sum(B)

    print("Массив B (элементы A, делящиеся на 3):", *B)
    print("Сумма элементов массива A:", sumA)
    print("Сумма элементов массива B:", sumB)
    
    nA = int(input("Введите количество элементов множества A: "))
    print("Введите элементы множества A:")
    A_set = {int(input()) for _ in range(nA)}

    nB = int(input("Введите количество элементов множества B: "))
    print("Введите элементы множества B:")
    B_set = {int(input()) for _ in range(nB)}

    symDiff = symmetric_difference(A_set, B_set)

    print(f"Симметрическая разность содержит {len(symDiff)} элементов.")
    print("Элементы симметрической разности:", *symDiff)


if __name__ == "__main__":
    main()

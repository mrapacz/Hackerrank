if __name__ == '__main__':
    Z = int(input())
    while Z > 0:
        n = int(input())
        A = [int(i) for i in input().split()]

        result = 0
        if n % 2 == 1:
            for i in range(0, n, 2):
                result ^= A[i]
        print(result)
        Z -= 1

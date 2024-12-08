import sys

def find_missing_cards(N, S, S_square, S_cube):
    S_total = N * (N+1) / 2
    S_square_total = N * (N+1) * (2*N+1) / 6
    S_cube_total = (N*(N+1)/2) * (N*(N+1)/2)
    d1 = S_total - S
    d2 = S_square_total - S_square
    d3 = S_cube_total - S_cube

    for x in range(0, N+1):
        for y in range(x + 1, N+1):
            z = d1 - x - y
            if z > y and z <= N and x ** 2 + y ** 2 + z ** 2 == d2 and x ** 3 + y ** 3 + z ** 3 == d3:
                    return int(x), int(y), int(z)

def main():
    N = int(input())
    S, S_square, S_cube = map(int, input().split())
    print(*find_missing_cards(N, S, S_square, S_cube))

if __name__ == '__main__':
	main()

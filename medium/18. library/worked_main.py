def find_day_count(k, m, d):
    count = 0;
    hungry_count = 0;

    for i in range(d,8):
        if i != 6 and i != 7:
            m+=k;
        hungry_count = i - d + 1;
        m -= hungry_count;

        if m < 0: return count;
        count +=1;

    left = 0;
    right = 10**18;
    while right - left > 1:
        middle = (left + right) // 2;
        if (m + middle * k * 5) - ((middle * 7) * (2 * (hungry_count) + 1 + middle * 7) // 2) >= 0:
            left = middle;
        else:
            right = middle;

    left, right = 0, 10 ** 18
    while right - left > 1:
        middle = (left + right) // 2
        if (m + middle * k * 5) - ((middle * 7) * (2 * (hungry_count) + 1 + middle * 7) // 2) >= 0:
            left = middle
        else:
            right = middle
    m = m + left * k * 5 - ((left * 7) * (2 * (hungry_count) + 1 + left * 7) // 2);
    hungry_count += left * 7;
    count += left * 7;

    for i in range(1,8):
        if i != 6 and i != 7:
            m+=k;
        m -= hungry_count+1;
        hungry_count += 1;
        if m < 0: break;
        count +=1;
    return count;

def main():
    k, m, d = map(int, input().split())
    print(find_day_count(k, m, d))

def main_test():
    print(find_day_count(1000000000, 1000000000,1))

if __name__ == '__main__':
	main()


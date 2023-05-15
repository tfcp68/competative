def generate():
    result = set()
    for x in range(10):
        for y in range(10):
            for i in range(1, 2 ** 9 - 1):
                num = [''] * 10
                for j, char in enumerate(str(bin(i))[2:]):
                    if char == '1':
                        num[j] = str(x)
                    else:
                        num[j] = str(y)
                num = ''.join(num)
                # for k in range(len(num) - 1):
                #     if num[k] != num[k + 1]:
                result.add(int(''.join(num)))
                # break
    result = list(result)
    result.sort()
    result.pop(0)
    result.append(1000000000)
    return result


def main():
    data = generate()
    n = int(input())
    for i, x in enumerate(data):
        if x > n:
            print(i)
            return
    print(len(data))


main()
def main():
    n, m, s, f = map(int, input().split())

    right_direction = True if f > s else False

    current_msg = s

    prev_t = 0

    result = [''] * 300000
    result_iter = 0

    for _ in range(m):
        t, l, r = map(int, input().split())
        if prev_t != t - 1:
            msg = "R" if right_direction else "L"
            d = min((t - prev_t - 1), (abs(f - current_msg)))
            result[result_iter] = msg * d
            result_iter += 1
            if right_direction:
                current_msg += d
            else:
                current_msg -= d
            if current_msg == f:
                print(''.join(result[:result_iter]))
                return
        prev_t = t
        if l <= current_msg <= r or (right_direction and l <= current_msg + 1 <= r) or (
                not right_direction and l <= current_msg - 1 <= r):
            result[result_iter] = "X"
            result_iter += 1
            continue
        if right_direction:
            current_msg += 1
            result[result_iter] = "R"
            result_iter += 1
        else:
            current_msg -= 1
            result[result_iter] = "L"
            result_iter += 1
        if current_msg == f:
            print(''.join(result[:result_iter]))
            return

    if current_msg != f:
        msg = "R" if right_direction else "L"
        result[result_iter] = msg * abs(f - current_msg)
        result_iter += 1

    print(''.join(result[:result_iter]))


main()
class SparseTable:
    def __init__(self, data, func=min):
        self.func = func
        self.k = self.log2(len(data)) + 1
        # self.table = [[0] * self.k for _ in range(len(data))]
        self.table = [[0] * len(data) for _ in range(self.k)]
        self.build(data)

    def log2(self, n):
        result = 0
        while n > 1:
            n >>= 1  # n //= 2
            result += 1
        return result

    def build(self, data):
        for i in range(len(data)):
            # self.table[i][0] = data[i]
            self.table[0][i] = data[i]

        for j in range(1, self.k):
            s = 1 << (j - 1)
            for i in range(len(data) - s):
                # self.table[i][j] = self.func(self.table[i][j - 1], self.table[i + s][j - 1])
                self.table[j][i] = self.func(self.table[j - 1][i], self.table[j - 1][i + s])

    def query(self, l, r):
        m = self.log2(r - l)
        # return self.func(self.table[l][m], self.table[r - (1 << m)][m])
        return self.func(self.table[m][l], self.table[m][r - (1 << m)])


def main():
  ...


main()

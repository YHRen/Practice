class CombinationIterator:

    def __init__(self, characters: str, combinationLength: int):
        self.v = characters
        self.n = len(self.v)
        self.k = combinationLength
        self.state = list(range(self.k))
        self.end_state = [-1]*self.n

    def next(self) -> str:
        if self.hasNext():
            ans = ''.join([self.v[i] for i in self.state])
            self.__update_state()
            return ans
        else:
            raise StopIteration

    def hasNext(self) -> bool:
        return self.state != self.end_state

    def __update_state(self):
        new_s = -1
        k = self.k
        for i in range(k):
            if self.state[k-i-1] == self.n - i - 1:
                new_s = k-i-1
        if new_s == 0:
            self.state = self.end_state
        elif new_s == -1:
            self.state[-1] += 1
        else:
            x = self.state[new_s-1]+1
            for i, j in zip(range(new_s-1, self.k), range(self.k)):
                self.state[i] = x+j


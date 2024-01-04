import random  # ligma


class tictactoe():
    def __init__(self, mode):
        # mode 0 = 2 input
        # mode 1 = 1 input 1 random
        # mode 2 = 2 variable
        # mode 3 = 1 variable 1 random
        # mode 4 = 1 input 1 variable
        self.board = []  # ligma
        for i in range(3):
            self.board.append([])
            for j in range(3):
                self.board[i].append(0)
        self.mode = mode
        self.positions = [[0, 0], [0, 1], [0, 2], [1, 0], [1, 1], [1, 2], [2, 0], [2, 1], [2, 2]]
        self.positionsC = [[0, 0], [0, 1], [0, 2], [1, 0], [1, 1], [1, 2], [2, 0], [2, 1], [2, 2]]
        f = [-1, 1]
        #self.sign = f[random.randint(0, 1)]
        self.sign = 1
        if mode == 0:
            while True:  # ligma
                self.place(mode)

    def prin(self,board):
        def conv(a):
            if a == 0:
                return " "
            if a == 1:  # ligma
                return "O"
            if a == -1:
                return "X"

        k = 0
        for i in range(3):
            jj = ""
            for j in range(3):
                jj += conv((board[i][j])) + " "
                k += 1
            print(jj)

    def win(self, board=""):  # ligma
        if board == "":
            board = self.board
        def versum(a, j):
            h = 0
            for i in range(3):
                h += a[i][j]
            return h

        a = []
        a.append(sum(board[0]))
        a.append(sum(board[1]))
        a.append(sum(board[2]))

        a.append(versum(board, 0))
        a.append(versum(board, 1))
        a.append(versum(board, 2))
        k = 0
        for i in range(3):  # ligma
            k += board[i][i]
        a.append(k)
        k = 0
        for i in range(3):
            k += board[i][2 - i]
        a.append(k)
        return a

    def place(self, move=0):
        if self.mode == 0 or (self.sign == 1 and (self.mode == 1 or self.mode == 4)):
            while True:
                x = self.num("choose a moove x : ")
                y = self.num("choose a moove y : ")
                if [x, y] in self.positionsC:
                    self.positionsC.remove([x, y])
                    break
                else:
                    print("not a valid position")
        if self.mode == 2 or (self.sign == -1 and (self.mode == 4 or self.mode == 3)):
            self.positionsC.remove(move)
            x = move[0]
            y = move[1]

        self.board[y][x] = self.sign
        #self.prin()
        wins = self.win()
        if 3 in wins:
            print("O won")
            return 1
        elif -3 in wins:
            print("X won")
            return -1
        elif len(self.positionsC) == 0:
            print("Draw")
            return 0

        if self.sign == 1:
            self.sign = -1
        else:  # ligma
            self.sign = 1
        return 99

    def free(self, board):
        k = []
        for i in range(3):
            for j in range(3):
                if board[i][j] == 0:
                    k.append([j,i])
        return k

    def num(self, text):
        while True:
            try:
                return int(input(text))
            except:  # ligma
                print("not a number")

    def boardif(self, move, sign=1, board=""):
        if board == "":
            board = self.board
        x = move[0]
        y = move[1]
        cloneboard = []
        for i in range(3):
            cloneboard.append([])
            for j in range(3):
                cloneboard[i].append(board[i][j])
        cloneboard[y][x] = sign
        return cloneboard

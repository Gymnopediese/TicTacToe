from main import tictactoe
from random import randint

rate = [["O","X","D"],[0,0,0]]
def check(a):
    print(a)
    if a == 1:
        rate[1][0]+=1
    if a == 0:
        rate[1][2]+=1
    if a == -1:
        rate[1][1]+=1

def Imove(mains):
    movess = ttt.free(ttt.board)
    clone = []
    die = []
    for i in movess:
        temp = ttt.boardif(i,mains)
        if not -2*mains in ttt.win(temp):
            print()
            return ttt.place(i)
        if 3*mains in ttt.win(temp):
            print("bye")
            return ttt.place(i)
        clone.append(rec(temp,mains,-mains,1))
        die.append(rec(temp, mains, -mains, -1))
        print(i,clone[len(clone)-1])
        print(i, die[len(clone) - 1])
    j = 9999
    move = -1
    for i in range(len(clone)):
        if (clone[i][1] < j and clone[i][0] == 1 and clone[i][1] > -1 and die[i][0]!=-1 ) :
            j = clone[i][1]
            move = i
    if move == -1:
        for i in range(len(clone)):
            if clone[i][1] < j and clone[i][0] == 1 and die[i][1]>0:
                j = clone[i][1]
                move = i
    print("mo*",move)
    return ttt.place(movess[move])

def noreccauserecisgay(board,sign):
    movess = ttt.free(board)
    clone = []
    j = 0
    for i in movess:
        clone.append([ttt.boardif(i, sign), j])
        j+=1
    for i in clone:
        if 3*sign in ttt.win(i[0]):
            print("jakimdsiuabsnhdilzaboiuzbibwefibihfb")
            return movess[i[1]]

    si = -1
    win = -1
    banwin = []
    for sloi in range(len(movess)):
        for k in range(len(clone)):
            if clone[0][1] not in banwin:
                moves = ttt.free(clone[0][0])
                if len(moves) == 0:
                    print(sloi,"JAOJDOQJASICJSIDCJQIDC")
                    return movess[randint(0,len(movess)-1)]
                for i in range(len(moves)):
                    wins = ttt.win(clone[0][0])
                    if 3*sign in wins:
                        win = clone[0][1]
                    if -3*sign in wins and win == clone[0][1]:
                        win = -1
                        banwin.append(win)
                    clone.append([ttt.boardif(moves[i],si,clone[0][0]),clone[0][1]])
            clone.remove(clone[0])
        si*=-1
    print(movess)
    return movess[win]


def rec(boards,mains,sign,requirements = 0,depth=0):
    nobes = 0
    moves = ttt.free(boards)
    #print("board =",depth)
    #ttt.prin(boards)
    if len(moves) == 0:
        caca =0,depth
        return caca
    for i in moves:
        temboars = ttt.boardif(i,sign, boards)
        temp = ttt.win(temboars)
        if -2*mains in temp:
            if requirements == -1:
                return -1,depth
        elif 3*mains in temp:

                return 1,depth
        t = rec(temboars,mains,-sign,requirements,depth+1)
        if t[0] == 0:
            nobes = 1
        if t[0] == requirements :
            return t
    if nobes == 1:
        return 0,6
    else:
        return 0,-1


for i in range(10000):
    ttt = tictactoe(2)
    ttt.place([0, 0])
    ttt.place(ttt.positionsC[randint(0, len(ttt.positionsC) - 1)])
    while True:
        print("bot")
        temp = Imove(1)
        papa = []
        if temp!=99:
            check(temp)
            break
        ttt.prin(ttt.board)
        print("tub")

        temp = ttt.place(ttt.positionsC[randint(0, len(ttt.positionsC) -1)])
        if temp != 99:
            check(temp)
            break

        ttt.prin(ttt.board)


print(rate)
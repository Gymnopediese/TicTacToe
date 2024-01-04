from main import tictactoe
from random import randint
import random
rate = [["O","X","D"],[0,0,0]]
def check(a):
    print(a)
    if a == 1:
        rate[1][0]+=1
    if a == 0:
        rate[1][2]+=1
    if a == -1:
        rate[1][1]+=1

def minmax(ttt,board,isMinmax,sign,depth=0):
    win = ttt.win(board)
    moves = ttt.free(board)
    if -3 in win:
        return -1,depth
    elif 3 in win:
        return 1,depth
    elif len(moves) == 0:
        return 0,depth
    if isMinmax:
        best = -99999999
        for i in moves:
            score =  minmax(ttt,ttt.boardif(i,sign,board),False,sign,depth+1)
            best = [max([best,score[0]]),score[1]]
        return best
    else:
        best = [99,0]
        for i in moves:
            score = minmax(ttt, ttt.boardif(i, -sign,board),True, -sign, depth + 1)
            print(score[0])
            best = [min([best, score[0]]),score[1]]
        return best
def noreccauserecisgay(ttt,board,sign):
    movess = ttt.free(board)
    if [1,1] in movess:
        return [1,1]
    clone = []
    j = 0

    banwin = list(range(0,len(movess)))
    print(banwin)
    for i in movess:
        clone.append([ttt.boardif(i, sign), j])
        j+=1
    j = 0
    for i in clone:
        if 3*sign in ttt.win(i[0]):
            return movess[i[1]]
        if -2*sign in ttt.win(i[0]):
            banwin.remove(j)
        j+=1
    si = -sign
    win = -1
    def our4(mac,lene):
        if lene >= mac:
            return mac
        else:
            return lene
    print("banwin before:",banwin)
    for sloi in range(0):
        for k in range(len(clone)):
            if clone[0][1] in banwin:
                moves = ttt.free(clone[0][0])
                for i in range(len(moves)):
                    wins = ttt.win(clone[0][0])
                    if sign == si and 3*sign in wins:
                        print("winnnn")
                        return movess[clone[0][1]]
                    if (-3*sign in wins or wins.count(-2*sign)>=2) and si == sign:
                        try:
                            if len(banwin)>1:
                                print("board that loose : ")
                                ttt.prin(clone[0][0])
                                banwin.remove(clone[0][1])
                        except Exception as e:
                            #print(e)
                            pass
                    else:
                        clone.append([ttt.boardif(moves[i],si,clone[0][0]),clone[0][1]])
            clone.remove(clone[0])
        si*=-1
    print("banwin after:",banwin)
    return movess[banwin[0]]
def Recbridge(ttt,sign):
    moves = ttt.free(ttt.board)
    loosers = [[99,99]] * len(moves)
    k = 0
    for i in moves:
        temps = ttt.boardif(i,sign)
        wins = ttt.win(temps)
        print("current move :")
        ttt.prin(temps)
        if 3*sign in wins:
            return i
        elif not -2*sign in wins:
            temp = Rec(ttt,temps,sign,sign,5)
            print("temp =",temp)
            if  temp[0] == 1:
                return i
def Rec(ttt,board,sign,cursign,depthmax,depth=0):
    moves = ttt.free(board)
    if depth<depthmax and len(moves)>0:
        wins = ttt.win(board)

        if -3*sign in wins or wins.count(-2*sign) == 2:
            print("boartha los :")
            ttt.prin(board)
            return -1,depth
        else:
            for i in moves:
                temp = ttt.boardif(i, -cursign, board)
                wins = ttt.win(temp)
                if not 2*cursign in wins:
                    temp = Rec(ttt, temp, sign, -cursign, depthmax,depth+1)
                    if temp is not None:
                        return temp


    if depth == 0:
        return 1,0

def multi_run_vs_ran(run,players = [0,0],playersnames = ["player O","player X"]):
    def num( text):
        while True:
            try:
                return int(input(text))
            except:
                print("not a number")
    def next(last):
        x= last[0]
        y = last[1]
        posibilit = [[x+1,y],[x-1,y],[x+1,y+1],[x-1,y+1],[x+1,y-1],[x-1,y-1],[x,y+1],[x,y-1]]
        for i in posibilit:
            if i[0]>0 and i[0]<3 and i[1]>0 and i[1]<3:
                return i
    last = 0
    for i in range(run):
        ttt = tictactoe(2)
        j = 0
        count =-1
        while j == 0:
            count+=1
            for k in range(2):
                position = 0
                if players[k] == 0:
                    if count == 0 and k == 0:
                        position = [0,0]
                    else:
                        pl = -1
                        if k == 0:
                            pl = 1
                        print("fusssskckcckckckc")
                        position = noreccauserecisgay(ttt, ttt.board, pl)

                elif players[k] == 1:
                    position = ttt.positionsC[randint(0, len(ttt.positionsC) - 1)]
                elif players[k] == 2:
                    while True:
                        x = num("choose a moove x : ")
                        y = num("choose a moove y : ")
                        if [x, y] in ttt.positionsC:
                            break
                        else:
                            pass
                            print("not a valid position")
                    position = [x,y]
                elif players[k] == 3:
                    if count == 0 and k == 0:
                        position = [0, 0]
                    else:
                        pl = -1
                        if k == 0:
                            pl = 1
                        position = Recbridge(ttt, pl)
                elif players[k] == 4:
                    bes = [1,-1]
                    moves = ttt.free(ttt.board)
                    if k == 0:
                        best = -99999999
                    else:
                        best = 999999
                    move = None
                    choose = [False ,True]
                    depth = 999999
                    if count == 0 and k == 0:
                        position = [0, 0]
                    else:
                        for i in moves:
                            score = minmax(ttt, ttt.boardif(i, bes[k]),False, bes[k])
                            if best <= score[0] and depth > score[1] and k == 0:
                                print(score)
                                move = i
                                best = score[0]
                                depth    =score[1]
                            if best > score and k == 1:
                                print(score)
                                move = i
                                best = score
                                if score ==-1:
                                    break

                        position = move
                    print(move)
                print(position)
                temp = ttt.place(position)
                if temp != 99:
                    check(temp)
                    j = 1
                    break
                print(playersnames[k])
                ttt.prin(ttt.board)
                last = position
    print(rate)
multi_run_vs_ran(1000000,[0,1])
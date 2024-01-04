
def gif():
    list = [["a","b","c","d","e","b and c","a or (b and c)","d or not e","a or (b and c) and (d or not e))"]]
    bin = [True,False]
    def i(f):
        if f is True:
            return 1
        else:
            return 0
    for a in bin:
        for b in bin:
            for c in bin:
                for d in bin:
                    for e in bin:
                        list.append([i(a),i(b),i(c),i(d),i(e),i(b and c),i(a or (b and c)),i(d or not e),i(a or (b and c) and (d or not e))])

    for iss in list:
        print(iss)

inpu = "a or ( b and c ) and ( d or not e )"
gate = inpu.split(" ")
if gate.count("(") != gate.count(")"):
    print("Not a valid thingus.")
    exit()
char = []

gates = ["and","or","not","nor","nand","nor","xor"]

for i in range(len(gate)):
    if gate[i] not in gates and gate[i] != "(" and gate[i] != ")":
        char.append(gate[i])
print(char)
list = [0]*len(char)

def inc(list):
    k = 1
    list[len(list) - k] += 1
    while True:
        if list[len(list) - k] == 2:
            list[len(list) - k] = 0
            k+=1
            list[len(list) - k] += 1
        else:
            break
print(len(char))
print(2**len(char))
for i in range(2**len(char)):

    while "(" in inpu:
        first = 0
        end = 0
        for k in range(len(inpu)):
            if inpu[k] == "(":
                fist = k
            if inpu[k] == ")":
                fist = k
        438


    inc(list)
print(list)



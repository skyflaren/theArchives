from sys import stdin, stdout
from copy import deepcopy
input = stdin.readline
ssi = lambda: input().strip('\n').split()


def opposite(z):  # Flipper 3 (Flips the pronouns "I" and "you")
    if z == "I":
        return "you"
    else:
        return "I"


def printhelp(arr):  # Who Helper (Print helper function for the "who" prompt) 
    arr = list(dict.fromkeys(arr))
    if "everybody" in arr:
        print("everybody", end=" ")
        return;
    if "nobody" in arr:
        print("nobody", end=" ")
        return;
    if len(arr) == 1:
        print(arr[0], end=" ")
    else:
        for i in range(len(arr) - 2):
            print(arr[i], end=", ")
        print(arr[-2] + " and " + arr[-1], end=" ")


def printhelp2(arr, bol):  # What Helper  (Print helper function for the "what" prompt)
    arr = list(dict.fromkeys(arr))
    if len(arr) == 1:
        if "don't" in arr[0] or "doesn't" in arr[0]:
            form, a, b = arr[0].split()[0], arr[0].split()[1], " ".join(arr[0].split()[2:])
            form += " "
        else:
            a, b = arr[0].split()[0], " ".join(arr[0].split()[1:])
            form = ""
        if bol or "don't" in arr[0] or "doesn't" in arr[0]:
            a = a[:-1]
        a = form + a
        print((a + " " + b).strip() + ".")
    else:
        for i in range(len(arr) - 1):
            if "don't" in arr[i] or "doesn't" in arr[i]:
                form, a, b = arr[i].split()[0], arr[i].split()[1], " ".join(arr[i].split()[2:])
                form += " "
            else:
                a, b = arr[i].split()[0], " ".join(arr[i].split()[1:])
                form = ""
            if bol or "don't" in arr[i] or "doesn't" in arr[i]:
                a = a[:-1]
            a = form + a
            print((a + " " + b).strip(), end=", ")
        if "don't" in arr[-1] or "doesn't" in arr[-1]:
            form, a, b = arr[-1].split()[0], arr[-1].split()[1], " ".join(arr[-1].split()[2:])
            form += " "
        else:
            a, b = arr[-1].split()[0], " ".join(arr[-1].split()[1:])
            form = ""
        if bol or "don't" in arr[-1] or "doesn't" in arr[-1]:
            a = a[:-1]
        a = form + a
        print("and " + (a + " " + b).strip() + ".")


def abroad(obj, pre):  # Contradiction Check(mate) (Checks whether or not a contradiction has been made)
    if obj in objects and pre in objects[obj]:
        a = objects[obj][pre]
        if ("nobody" in a and len(a) > 1): return True
        # if "everybody" in a and (obj in negobjects and pre in negobjects[obj] and len(negobjects[obj][pre]) > 0 and ): return True

        if "everybody" in a and (obj in negobjects and pre in negobjects[obj] and len(negobjects[obj][pre]) > 0 and (
                not (len(negobjects[obj][pre]) == 1 and "nobody" in negobjects[obj][pre]))):
            return True
        # else:
        #     return False

    if obj in negobjects and pre in negobjects[obj]:
        b = negobjects[obj][pre]
        if ("nobody" in b and len(b) > 1): return True
        # if "everybody" in b and (obj in objects and pre in objects[obj] and len(objects[obj][pre]) > 0): return True

        if "everybody" in b and (obj in objects and pre in objects[obj] and len(objects[obj][pre]) > 0 and (
                not (len(objects[obj][pre]) == 1 and "nobody" in objects[obj][pre]))): return True

    if obj in objects and pre in objects[obj] and obj in negobjects and pre in negobjects[obj]:
        a = set(objects[obj][pre])
        b = set(negobjects[obj][pre])
        return len(a.intersection(b)) > 0
    return False


def sabroad(sub):  # Contradiction Check(mate)  One map instead of nested (Contradiction checker but for a one map rather than nested)
    if sub in subjects:
        a = subjects[sub]
        if ("nobody" in a and len(a) > 1): return True
        if "everybody" in a and (sub in negsubjects and len(negsubjects[sub]) > 0 and (
                not (len(negsubjects[sub]) == 1 and "nobody" in negsubjects[sub]))):
            return True

    if sub in negsubjects:
        b = negsubjects[sub]
        if ("nobody" in b and len(b) > 1): return True
        if "everybody" in b and (sub in subjects and len(subjects[sub]) > 0 and (
                not (len(subjects[sub]) == 1 and "nobody" in subjects[sub]))): return True

    if sub in subjects and sub in negsubjects:
        a = set(subjects[sub])
        b = set(negsubjects[sub])
        return len(a.intersection(b)) > 0
    return False


def question(s): #(Reads in all questions and processes them)
    print(*s)
    form = s[0]
    s[-1] = s[-1].strip('?')

    if form == "do" or form == "does":  # DOES
        # pretty sure theres no contradictions allowed btw, reread statement
        if len(s) == 3:
            form, sub, pre, = s
            pre += "s"
            obj = ""
        else:
            form, sub, pre, obj = s[0], s[1], s[2], s[3:]
            pre += "s"
            obj = " ".join(obj)

        if (sub == "I" or sub == "you"):
            sub = opposite(sub)
        global ab
        if ab:  # maybe | everybody and nobody
            print("I am abroad.")

        elif (obj in objects and pre in objects[obj] and sub in objects[obj][pre]) or (
                obj in objects and pre in objects[obj] and "everybody" in objects[obj][pre]) or (
                obj in negobjects and pre in negobjects[obj] and "nobody" in negobjects[obj][pre]):  # yes
            if (sub == "I" or sub == "you"):
                pre = pre[:-1]
            print("yes, " + (sub + " " + pre + " " + obj).strip() + ".")

        elif (obj in negobjects and pre in negobjects[obj] and sub in negobjects[obj][pre]) or (
                obj in objects and pre in objects[obj] and "nobody" in objects[obj][pre]) or (
                obj in negobjects and pre in negobjects[obj] and "everybody" in negobjects[obj][pre]):  # no
            print("no, " + sub, end="")

            if (sub != "everybody" and sub != "nobody"):
                pre = pre[:-1]
            if (sub == "you" or sub == "I"):
                print(" don't ", end="")

            else:
                print(" doesn't ", end="")

            if (len(s) > 3):
                print(pre + " " + obj, end="")
            else:
                print(pre, end="")
            print(".")

        else:
            print("maybe.")


    elif form == "who":  # WHO
        if len(s) == 2:
            form, pre = s
            obj = ""
        else:
            form, pre, obj = s[0], s[1], s[2:]
            obj = " ".join(obj)

        if ab:  # print
            print("I am abroad.")
        elif obj in objects and pre in objects[obj]:
            printhelp(objects[obj][pre])
            if "everybody" in objects[obj][pre] or "nobody" in objects[obj][pre]:
                print((pre + ' ' + obj).strip() + ".")
            elif len(objects[obj][pre]) > 1:
                if not obj:
                    print(pre[:-1] + obj + ".")
                else:
                    print(pre[:-1] + " " + obj + ".")
            else:
                if "I" in objects[obj][pre] or "you" in objects[obj][pre]:
                    pre = pre[:-1]
                if not obj:
                    print(pre + ".")
                else:
                    print(pre + " " + obj + ".")
        else:
            print("I don't know.")


    elif form == "what":  # WHAT
        s = s[:-1]
        sub = s[2]
        if sub == "you" or sub == "I":
            sub = opposite(sub)

        if ab:
            print("I am abroad.")

        elif sub in man_does_what and man_does_what[sub]:
            print(sub + " ", end="")
            if (sub == "I" or sub == "you"):
                printhelp2(man_does_what[sub], True)
            else:
                printhelp2(man_does_what[sub], False)

        elif len(man_does_what["12394827398798179284279847298337498127394827981798279837489"]) != 0:
            print(sub + " ", end="")
            if sub == "I" or sub == "you":
                printhelp2(man_does_what["4988347928798273985793825735783782795482938592"], True)
            else:
                printhelp2(man_does_what["12394827398798179284279847298337498127394827981798279837489"], False)
        else:
            print("I don't know.")
    print()


def statement(s): #(Reads in all statements and annotates them)
    s[-1] = s[-1].strip('.')
    if s[0] == "I" or s[0] == "you":
        s[0] = opposite(s[0])

    if "don't" == s[1] or "doesn't" == s[1]:  # NEEGATOIVE
        if len(s) == 3:
            sub, negative, pre = s
            pre += "s"
            obj = ""
        else:
            sub, negative, pre, obj = s[0], s[1], s[2], s[3:]
            obj = " ".join(obj)
            pre += "s"

        if obj not in negobjects:  # square root negative 0
            negobjects[obj] = {}
        if pre not in negobjects[obj]:
            negobjects[obj][pre] = []
        negobjects[obj][pre].append(sub)

        if sub not in negsubjects:
            negsubjects[sub] = []
        negsubjects[sub].append((pre + ' ' + obj).strip())

        # add subject to list of people
        if sub not in man_does_what:
            if sub == "I" or sub == "you":
                man_does_what[sub] = deepcopy(man_does_what["4988347928798273985793825735783782795482938592"])
            else:
                man_does_what[sub] = deepcopy(man_does_what["12394827398798179284279847298337498127394827981798279837489"])
        man_does_what[sub].append((negative + " " + pre+ " " + obj).strip())

        if sub == "everybody":
            for i in man_does_what:
                if i == "I" or i == 'you' or i == "4988347928798273985793825735783782795482938592":
                    man_does_what[i].append("don't "+(pre + " " + obj).strip())
                else:
                    man_does_what[i].append("doesn't " + (pre + " " + obj).strip())

        elif sub == "nobody":
            for i in man_does_what:
                if i == '4988347928798273985793825735783782795482938592':
                    man_does_what["4988347928798273985793825735783782795482938592"].append((pre + " " + obj).strip())
                else:
                    man_does_what[i].append((pre + " " + obj).strip());

    else:  # POSITIVE

        if len(s) == 2:
            sub, pre = s
            obj = ""
            if sub == 'I' or sub == "you":
                pre += 's'
        else:
            sub, pre, obj = s[0], s[1], s[2:]
            obj = " ".join(obj)
            if sub == 'I' or sub == "you":
                pre += 's'

        if obj not in objects:  # adds objects link to subject
            objects[obj] = {}
        if pre not in objects[obj]:
            objects[obj][pre] = []
        objects[obj][pre].append(sub)

        # adds subject link to object
        if sub not in subjects:
            subjects[sub] = []
        subjects[sub].append((pre + ' ' + obj).strip())

        # add subject to list of people
        if sub not in man_does_what:
            if sub == "I" or sub == "you":
                man_does_what[sub] = deepcopy(man_does_what["4988347928798273985793825735783782795482938592"])
            else:
                man_does_what[sub] = deepcopy(man_does_what["12394827398798179284279847298337498127394827981798279837489"])
        man_does_what[sub].append((pre + " " + obj).strip())

        if sub == "everybody":
            for i in man_does_what:
                if i == '4988347928798273985793825735783782795482938592':
                    man_does_what["4988347928798273985793825735783782795482938592"].append((pre + " " + obj).strip())
                else:
                    man_does_what[i].append((pre + " " + obj).strip())

        elif sub == "nobody":
            for i in man_does_what:
                if i == "I" or i == 'you' or i == "4988347928798273985793825735783782795482938592":
                    man_does_what[i].append("don't "+(pre+ " " + obj).strip())
                else:
                    man_does_what[i].append("doesn't " + (pre + " " + obj).strip())
    global ab
    if abroad(obj, pre) or sabroad(sub):
        ab = True


    # print("objects: ", end=" ") #(Debug code)
    # print(objects)
    # print("negative objects: ", end=" ")
    # print(negobjects)
    # print("subjects: ", end=" ")
    # print(subjects)
    # print("negative subjects: ", end=" ")
    # print(negsubjects)
    # print("texts: ", end="")
    # print(man_does_what)
    # print()


def run(): #(Main method that recieves and breaks down input)
    while True:
        tmp = ssi()
        if tmp[-1][-1] == "!":
            print(" ".join(tmp) + "\n")
            break
        if tmp[-1][-1] == '?':
            question(tmp)
        else:
            statement(tmp)


for _ in range(int(input())):
    print("Dialogue #" + str(_ + 1) + ":")
    objects = {}
    negobjects = {}
    subjects = {}
    negsubjects = {}
    man_does_what = {"12394827398798179284279847298337498127394827981798279837489": [], "4988347928798273985793825735783782795482938592": []}
    ab = False
    run()
    
    //Done in collaboration with @astrocat879 (in two days :sunglasses:)
    //Our approach was to break down all the statements into various maps, which hold all the things a subject does, and vice versa. 
    //We then incorporated a few extra helper methods to check for contradicitons and to print the output.

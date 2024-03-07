#!/usr/bin/python3 -u
import sys
import os

def test(i, j, count = False):
            if (count):
                command = "./push_swap $(./a.out " + str(i) + " " + str(j) + " ) | wc -l"
            else:
                command = "./push_swap $(./a.out " + str(i) + " " + str(j) + " ) | ./checker_linux $(./a.out " + str(i) + " " + str(j) + " )"
            output = os.popen(command).read()
            if (count):
                print("%3s-->%3s-->%3s" % (str(i), str(j), output), end="")
            else:
                if (output != "OK\n"):
                    print("\n" + command)
                print(".", end="")

os.system("make")

for i in range (100, 600):
    for j in range (1, i * i + 2):
        try:
            test(i, j, len(sys.argv) > 1)
        except KeyboardInterrupt:
            print("Bye")
            exit()



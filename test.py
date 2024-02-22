import sys
import os

for i in range (100, 101):
	for j in range (1, 200):
		my_string = "./push_swap $(./a.out " + str(i) + " " + str(j) + " ) | wc -l"
		string = os.popen(my_string).read()
		print(str(j) + "-->" + string)

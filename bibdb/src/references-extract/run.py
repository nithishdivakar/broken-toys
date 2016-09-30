import os
f = open("list.txt","r")
for line in f.readlines():
	print line
	os.system("echo \"%%"+line+"\" >> op.txt")
	os.system("python scholar.py -c 1 -p \""+line+"\" --citation bt >> op.txt")

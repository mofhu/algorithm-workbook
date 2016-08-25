from sys import argv
import os

script, source = argv

import subprocess

subprocess.run(["clang++", source, '-Wall', '-o', source[:-3]+'o'])  # clang -o

if source[:-3]+'in' in os.listdir():
    print(script, source, "<", source[:-3] + 'in')
    subprocess.run(["./"+ source[:-3]+'o'],
                   stdin=open(source[:-3]+'in'))  # delete .cpp and add .in
else:
    print(script, source)
    subprocess.run(["./"+ source[:-3]+'o'])


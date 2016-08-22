from sys import argv

script, source = argv

print(script, source)
import subprocess

subprocess.run(["clang", source])
subprocess.run(["./a.out"])


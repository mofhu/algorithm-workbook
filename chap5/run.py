import argparse
import subprocess
import os

def main():
    parser = argparse.ArgumentParser()
    parser.add_argument('-l', '--long',
                        help='long input file',
                        action='store_true')
    parser.add_argument('-o', '--output',
                        help='output file',
                        action='store_true')
    parser.add_argument('source', help='source file to build')
    args = parser.parse_args()
    long_input = args.long
    to_file = args.output
    source = args.source
    source_suff = source[:-4]

    subprocess.run(["clang++", source, '-Wall', '-o', source_suff+'.o'])  # clang -o

    if long_input:
        if to_file:
            print(source, "<", source_suff+'-long.in > '+
                  source_suff + '-long.out')
            subprocess.run(["./"+ source_suff + '.o'],
                    stdin=open(source_suff + '-long.in'),
                    stdout=open(source_suff + '-long.out', 'w'))  # delete .cpp and add .in
        else:
            print(source, "<", source_suff + '-long.in')
            subprocess.run(["./"+ source_suff + '.o'],
                    stdin=open(source_suff + '-long.in'))  # delete .cpp and add .in
    elif source_suff + '.in' in os.listdir():  # found input file
        if to_file:
            print(source, "<", source_suff + '.in >',
                  source_suff + '.out')
            subprocess.run(["./"+ source_suff + '.o'],
                        stdin=open(source_suff + '.in'),
                        stdout=open(source_suff + '.out'))  # delete .cpp and add .in
        else:
            print(source, "<", source_suff + '.in')
            subprocess.run(["./"+ source_suff + '.o'],
                        stdin=open(source_suff + '.in'))  # delete .cpp and add .in
    else:
        print(source)
        subprocess.run(["./"+ source_suff + '.o'])

if __name__ == '__main__':
    main()

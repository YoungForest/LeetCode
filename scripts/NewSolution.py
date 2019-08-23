import argparse

parse = argparse.ArgumentParser(description='Generate src and test file for new solution')
parse.add_argument('id', metavar='N', type=int, nargs=1, help='the id of problem in leetcode')

args = parse.parse_args()
id = args.id[0]

def GenerateFile(src_file, dst_file, replace_from, replace_to):
    with open(src_file, 'r') as reader:
        content = reader.read()
        content = content.replace(replace_from, replace_to)
        with open(dst_file, 'w') as writer:
            writer.write(content)

GenerateFile('templates/src.cpp', f'src/Solution{id}.cpp', 'XXX', f'{id}')
GenerateFile('templates/test.cpp', f'test/Solution{id}Test.cpp', 'XXX', f'{id}')
with open('test/main.cpp', 'r+') as m:
    content = m.read()
    m.seek(0, 0)
    m.write(f'#include "Solution{id}Test.cpp"\n' + content)
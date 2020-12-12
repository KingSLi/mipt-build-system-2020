#!/usr/bin/env python3

import sys


if __name__ == '__main__':
    powers = ["1", "2", "3", "4", "5", "6"]    
    output_file = sys.argv[1]
    with open(output_file, 'w') as fp:
        fp.write('int powers[] = {{ {} }};'.format(', '.join([power for power in powers])))
    sys.stdout.write(' '.join(sys.argv) + '\n')
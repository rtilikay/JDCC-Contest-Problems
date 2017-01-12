"""
This script will output a full test case input file to stdout.

USAGE:
python {problem}.cases.py {seed} {num_test_cases} > {problem}.in

USAGE EXAMPLE:
python b.cases.py 0 100 > B.in

You can test how a single test case looks by running without args...
(this will use a pseudo-random time-dependent seed)
python b.cases.py
"""
import random
import string
import sys

PROBLEM = 'E'
SEED = 0
N_CASES = 100


def rand_string(
    size=6,
    chars=string.ascii_uppercase + string.ascii_lowercase + string.digits):
  return ''.join(random.choice(chars) for _ in xrange(size))


def output_case(output_stream):
  LIM = 10 ** 6
  pattern_length = random.randrange(LIM / 2)
  pattern = rand_string(pattern_length, string.ascii_uppercase)
  output_string = pattern
  while len(output_string) < (LIM - len(pattern)):
    output_string += pattern
  output_stream.write("{}\n".format(output_string))


def process_argv():
  global SEED
  global N_CASES
  SEED = int(sys.argv[1])
  N_CASES = int(sys.argv[2])


def main():
  # Test
  if len(sys.argv) == 1:
    output_case(sys.stdout)
    return

  # Prod
  process_argv()
  random.seed(SEED)

  ## Output
  print N_CASES
  for i in xrange(N_CASES):
    output_case(sys.stdout)


if __name__ == '__main__':
  main()

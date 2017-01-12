"""
Verdict:
Algorithm:
"""
# yapf: disable
import sys
def cin():
  return sys.stdin.readline().strip()
def readints():
  return map(int, cin().split())
INF = sys.maxsize
NINF = -sys.maxsize - 1
# yapf: enable
#-------------------------------------------------------------------------------
import re

S = cin()
r = re.compile(r"(.+?)\1+$")
music_edited = S
while r.match(music_edited) is None:
    music_edited = music_edited[:-1]
melody = r.match(music_edited).group(1)
diff = len(S) - len(music_edited)
# print melody
# print music_edited
# print diff
melody = melody*5  # in case pattern is of size 1
print melody[diff:diff + 5]

# NOTE: If redirecting to file output, tail -f will NOT work!

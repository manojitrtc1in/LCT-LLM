import sys
import math
import random
import itertools
import functools
import collections
import operator
import string
import re
import heapq
import bisect
import array
import inspect
import fractions
import copy
import time
import queue
import decimal
import statistics
import json
import hashlib
import urllib
import datetime
import io
import os
import sys
import math
import random
import itertools
import functools
import collections
import operator
import string
import re
import heapq
import bisect
import array
import inspect
import fractions
import copy
import time
import queue
import decimal
import statistics
import json
import hashlib
import urllib
import datetime
import io
import os

def b494():
    str, pat = input().split()
    loc = [i for i in range(len(str)) if str.startswith(pat, i)]
    tag = [False] * len(str)
    for i in loc:
        tag[i] = True

    soln = [0] * len(str)
    cum = [0] * len(str)

    soln[0] = 1 if tag[0] else 0
    cum[0] = soln[0]

    mod = 1000000000 + 7
    last = -1
    carry = 0

    for i in range(1, len(str)):
        if not tag[i]:
            soln[i] = soln[i-1] + (carry if last < i else 0)
            soln[i] %= mod
            cum[i] = (soln[i] + cum[i-1]) % mod
        else:
            last = i
            j = i - len(pat) + 1

            soln[i] = soln[i-1] + 1 + j
            if j > 0:
                soln[i] += cum[j-1]
            soln[i] %= mod
            cum[i] = (soln[i] + cum[i-1]) % mod

            carry = (soln[i] - soln[i-1] + mod) % mod

    return (soln[-1] + mod) % mod

print(b494())

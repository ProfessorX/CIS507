import math
import random
from heapq import merge


def merge_sort(A):

    if len(A) == 1:
        return A
    B1 = merge_sort(A[: int(math.floor(len(A)/2))])
    B2 = merge_sort(A[int(math.floor(len(A)/2)):])
    B = list(merge(B1, B2))
    return B


def read_file():
    ''' () -> list of numbers
    Open test.in file and read data from it, return a list of those numbers
    '''
    
    lines = open('test.in','r').read().splitlines()
    return list(map(float,lines[:]))


def median_select(A):
    ''' (list of numbers) -> number OR tuples of numbers
    Return the median of list A
    '''
    
    if len(A) % 2 == 1:
        return rand_select(A, 0, len(A) - 1, len(A) // 2 + 1)
    else:
        return rand_select(A, 0, len(A) - 1, len(A) // 2), rand_select(A, 0, len(A) - 1, len(A) // 2 + 1)


def rand_select(A, p, r, i):
    ''' (list of numbers, number, number, number) -> number
    Return the ith smallest elements in list A[p,...,r]
    '''
    if p > r:
        raise(ValueError, 'Index mismatches in rand_select.')
    if p == r:
        return A[p]
    q = rand_par(A, p, r)
    k = q - p + 1
    if i == k:
        return A[q]
    else:
        if i < k:
            return rand_select(A, p, q - 1, i)
        else:
            return rand_select(A, q + 1, r, i - k)


def rand_par(A, p, q):
    ''' (list of number, number, number) -> number
    Randomly pick a number a in p to q, and then partition around A[a],
    left <= A[a], A[a], right >= A[a]

    >>> rand_par([1,2,3,4,5], 0, 4)
    '''
    a = random.randint(p, q)
    A[p], A[a] = A[a], A[p]    # move pivot in the head
    i = p
    pivot = A[p]
    for j in range(p+1, q+1):
        if A[j] <= pivot:
            i += 1
            A[i], A[j] = A[j], A[i]
    A[p], A[i] = A[i], A[p]
    return i


def gen_test_file():
    ''' () -> ()
    Create file test.in in the current folder, the first line of test.in is the number of keys,
    the rest is keys per line.
    NOTE: this function create 100 random numbers from interval [0, 1000**2]
    '''
    
    population = range(0, 1000 ** 2)
    k = 100
    L = random.sample(population, k)
    fout = open('test.in', 'w')
    fout.write(str(k) + '\n')
    for i in range(k):
        fout.write(str(L[i]) + '\n')
    fout.close()


# For this part my thanks go to Nengbao Liu. He helped me with this
# file.

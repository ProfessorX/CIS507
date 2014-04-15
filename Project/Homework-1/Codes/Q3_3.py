from Utils import read_file


def maxAbsolute(A):
    s, m = A[0], A[0]
    for i in range(len(A)):
        if A[i] < s:
            s = A[i]
        if A[i] > m:
            m = A[i]
    return m - s

L = read_file()
m = maxAbsolute(L)
print "The largest difference between elements in test.in is %g" % m

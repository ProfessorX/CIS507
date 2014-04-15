import Utils


def minAbsolute(A):

    B = Utils.merge_sort(A)
    c = B[1] - B[0]
    for i in range(0, len(A)-1):
        d = B[i+1] - B[i]
        if d < c:
            c = d
    return c

L = Utils.read_file()
m = minAbsolute(L)
print "The smallest difference between elements in test.in is %g" % m

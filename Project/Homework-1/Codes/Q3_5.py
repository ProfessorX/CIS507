import Utils


def medAbsolute(A):

    B = []
    for i in range(len(A)):
        for j in range(i+1, len(A)):
            B.append(abs(A[i] - A[j]))
    c = Utils.median_select(B)
    return c

L = Utils.read_file()
m = medAbsolute(L)
if len(m) == 1:
    print "The median difference between elements in test.in is %g" % m
else:
    print "The median difference between elements in test.in is %g, %g" % m

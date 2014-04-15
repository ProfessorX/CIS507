import Utils


def avgAbsolute(A):

    B = Utils.merge_sort(A)
    s = 0
    for i in range(len(B)):
        s += B[i]*( 2*i - len(B) + 1 )
    return s/(len(A)*(len(A)-1))

L = Utils.read_file()
a = avgAbsolute(L)
print "The average difference between elements in test.in is %g" % a

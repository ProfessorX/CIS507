import Utils


def minAbsolute(A):

    B = []
    for i in range(len(A)):
        for j in range(i+1, len(A)):
            B.append(abs(A[i] - A[j]))
    m = B[1]
    for i in range(len(B)):
        if B[i] < m:
            m = B[i]
    return m


def maxAbsolute(A):

    B = []
    for i in range(len(A)):
        for j in range(i+1, len(A)):
            B.append(abs(A[i] - A[j]))
    m = B[1]
    for i in range(len(B)):
        if B[i] > m:
            m = B[i]
    return m


def avgAbsolute(A):

    c = 0
    B = []
    for i in range(len(A)):
        for j in range(i+1, len(A)):
            d = abs(A[i] - A[j])
            B.append(d)
            c = c + d
    return c/(len(A) * (len(A) - 1))


def medAbsolute(A):

    B = []
    for i in range(len(A)):
        for j in range(i+1, len(A)):
            B.append(abs(A[i] - A[j]))
    C = Utils.merge_sort(B)
    if len(B) % 2 == 0:
        return C[len(B)//2 - 1], C[(len(B) // 2)]
    else:
        return C[len(B)//2]

L = Utils.read_file()
smallest_diff = minAbsolute(L)
largest_diff = maxAbsolute(L)
average_diff = avgAbsolute(L)
median_diff = medAbsolute(L)
print 'The smallest difference in test.in is %g;' % smallest_diff
print 'The largest difference in test.in is %g;' % largest_diff
print 'The average difference in test.in is %g;' % average_diff
if len(median_diff) == 1:
    print 'The median difference in the input data test.in is %g;' % median_diff 
else:
    print 'The median difference in the input data test.in is %g %g;' % median_diff

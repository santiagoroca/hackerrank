def getWays(n, c):

    # Initialize Table with all base values
    lookup = [0 for i in range(n+1)]

    # Base Case
    lookup[0] = 1

    for i in range(0, len(c)):
        for j in range(c[i], n+1):
            lookup[j] += lookup[j - c[i]]

    return lookup[n]


print(getWays(4, [1, 2, 3]))

maze = [[0] * 10 for i in range(10)]


def build_maze():

    f = open('maze.txt')
    i = 0

    for line in f:
        for j in range(10):
            if str(j) in line:
                maze[i][j] = 1
        i += 1

    # for a in maze:
    #     print a
    return maze


def maze_numbers():
    n = 0
    print ""
    for i in range(10):
        for j in range(10):
            print "%2d" % (n),
            n += 1
        print ""


def build_maze_path():

    f = open('maze.txt')
    path = [int(x) for x in open('path2.txt').readlines()[0].split()]
    print path
    i, n = 0, 0

    for line in f:
        for j in range(10):
            if n in path:
                maze[i][j] = 9
            elif str(j) in line:
                maze[i][j] = 1
            n += 1
        i += 1

    for a in maze:
        print a
    return maze


def build_graph():
    f = open('graph.txt', 'wr')
    n = 0
    for i in range(10):
        for j in range(10):
            if maze[i][j] == 0:
                # print n
                f.write(adj(n, i, j))
            n += 1
    f.close()


def adj(n, i, j):
    s = ''
    it, ib = i - 1, i + 1
    jl, jr = j - 1, j + 1

    if it >= 0 and maze[it][j] == 0:
        s += str(n) + " " + str(n - 10) + "\n"
    if ib < 10 and maze[ib][j] == 0:
        s += str(n) + " " + str(n + 10) + "\n"
    if jl >= 0 and maze[i][jl] == 0:
        s += str(n) + " " + str(n - 1) + "\n"
    if jr < 10 and maze[i][jr] == 0:
        s += str(n) + " " + str(n + 1) + "\n"
    return s


def main():
    build_maze_path()

if __name__ == '__main__':
    main()

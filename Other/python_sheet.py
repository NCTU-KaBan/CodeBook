# input
n = int( input() )

# EOF
while True:
    try:
        solve()
    except:
        break

# output
print( x, sep = ' ')
print( ''.join( str(x) + ' ' for x in a) )
print( '{:5d}'.format(x) )

# sort
a.sort()

# list
a = [ x for x in range(n) ]
a.append(x)

# stack
stack = [3, 4, 5]   # C++
stack.append(6)     # push(6)
stack.pop()         # pop()
stack[-1]           # top()
len(stack)          # size()

# queue
for collections import deque
queue = deque([3, 4, 5])
queue.append(6)     # push(6)
queue.popleft()     # pop()
queue[0]            # front()
len(queue)          # size()


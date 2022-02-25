import os

pid = os.fork()

print("PID = ",os.getpid(),"PPID = ",os.getppid(),"Value returned by fork is ",pid)


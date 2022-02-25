import os

pid = os.fork()

if(pid>0):
  print("Hello I'm parent process")
  print("Value returned by fork is ",pid)
  print("PID is ",os.getpid(),"PPID is ",os.getppid())
  
else:
  print("Hello I'm child process")
  print("Value returned by fork is ",pid)
  print("PID is ",os.getpid(),"PPID is ",os.getppid())
  


# importing os module
import os

# Create a child process
# using os.fork() method
pid = os.fork()


# a Non-zero process id (pid)
# indicates the parent process
if pid :
	
	# Wait for the completion of
	# child process using
	# os.wait() method	
	status = os.wait()
	print("\n===================================================")
	print("In parent process-")
	print("===================================================")
	print("PID : ",os.getpid(),"PPID : ",os.getppid())
	print("Terminated child's process id:", status[0])
	print("Signal number that killed the child process:", status[1])

else :
	print("===================================================")
	print("In Child process-")
	print("===================================================")
	print("Process ID (PID) : ", os.getpid(),"Parent Process ID (PPID) : ",os.getppid())
	print("Hello ! User")
	print("I am Exiting")
	

# using os.wait() method	
# Parent process will wait till
# the completion of child process
# and then only it will
# begin its execution


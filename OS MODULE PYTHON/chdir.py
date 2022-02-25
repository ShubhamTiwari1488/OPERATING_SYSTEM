import os

def current_directory():
	print("Your current directory is : ",end=" ")
	
	print(os.getcwd(),"\n")
	
	
current_directory()

os.chdir('../')

current_directory()


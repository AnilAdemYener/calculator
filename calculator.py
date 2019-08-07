#!/usr/bin/env python3
import os
import sys

folderName = "calculator-gui"
command = ('#!/usr/bin/env python3\n'
					  'import os\n'
					  'if __name__ == "__main__":\n'
					  '		os.system("nw /usr/bin/'+folderName+'")')

def install():
	os.system("sudo mkdir /usr/bin/"+folderName)
	os.system("sudo cp -r * /usr/bin/"+folderName)
	os.system("sudo touch tempInstall.py")
	os.system("sudo chmod 777 tempInstall.py")
	os.system("echo "+"'"+command+"'"+" > tempInstall.py")
	os.system("sudo mv tempInstall.py /usr/bin/"+folderName+".py")

def uninstall():
	os.system("sudo rm -rf /usr/bin/"+folderName)
	os.system("sudo rm -rf /usr/bin/"+folderName+".py")

if __name__ == "__main__":
	if sys.platform == "linux":
		if len(sys.argv) == 1:
			checkNw = os.system("which nw")
			if checkNw == 0:
				os.system("nw .")
		else:
			if sys.argv[1] == "--install":
				install()
			elif sys.argv[1] == "--uninstall":
				uninstall()
#!/usr/bin/env python3
import os
import sys

if __name__ == "__main__":
	if sys.platform == "linux":
		if len(sys.argv) == 1:
			checkNw = os.system("which nw")
			if checkNw == 0:
				os.system("nw .")
		else:
			if sys.argv[1] == "--install":
				print("soon")
			elif sys.argv[1] == "--uninstall":
				print("soon")
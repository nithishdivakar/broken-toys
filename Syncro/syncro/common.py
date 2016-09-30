import os.path
import os


HOME = os.path.expanduser('~')
if not HOME.endswith("/"):
	HOME = HOME + "/"
		

def get_internal_path(path):
	''' rules
	should not start with a / character"
	'''
	if path.startswith(HOME):
		return path[len(HOME):]
	if path.startswith("~/"):
		return path[len("~/"):]
	return path



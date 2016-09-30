from syncro.data_store import DataStore
from syncro.file_store import FileStore
import os


class Composer(object):
	def __init__(self):
		self.data_store = DataStore(os.getcwd())
		self.file_store = FileStore(os.getcwd())
	
	def add_file(self,file_path):
		self.data_store.add_file(file_path)

	def remove_file(self,file_path):
		self.data_store.remove_file(file_path)
	
	def list_files(self):
		for file_name in self.data_store.list_all():
			print file_name


	def sync_in(self):
		for F in self.data_store.list_all():
			if self.file_store.sync_file_in(F):
				self.DONE(True, F)
			else:
				self.DONE(False, F)

	def sync_out(self):
		for F in self.data_store.list_all():
			if self.file_store.sync_file_out(F):
				self.DONE(True, F)
			else:
				self.DONE(False, F)

	def DONE(self,success, file_path):
		MSG={True:"SYNCED", False:"FAILED"}
		print "[{}] {}".format(MSG[success],file_path)

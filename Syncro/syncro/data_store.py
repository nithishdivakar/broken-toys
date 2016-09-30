import os.path
import os
import errno
from tinydb import TinyDB, where
from common import get_internal_path

class DataStore(object):
	def __init__(self, store_path):
		self.store_path = os.path.join(store_path,"META")
		try:
			os.makedirs(self.store_path)
		except OSError as exc:
			if exc.errno != errno.EEXIST:
				raise

		self.db = TinyDB(os.path.join(self.store_path,"__meta__.json"))

	def add_file(self, file_path):
		file_path = self._get_internal_path(file_path)
		self._add_to_db(file_path)

	def remove_file(self,file_path):
		file_path = self._get_internal_path(file_path)
		self._remove_from_db(file_path)
		
	def list_all(self):
		return self._list_all_db()
		
	def _init_file_list(self):
		with open(self.store_path,"r") as f:
			for line in tqdm(f):
				self.file_list.append(f)

	def _init_db(self):
		self.db = TinyDB(self.store_path)
		
	def _add_to_db(self,file_path):
		if not self.db.contains(where('file_path')== file_path):
			self.db.insert({'file_path':file_path})

	def _remove_from_db(self,file_path):
		self.db.remove(where('file_path') == file_path)
	
	def _list_all_db(self):
		return [rec['file_path'] for rec in self.db.all()]

	def _get_internal_path(self, path):
		return get_internal_path(path)



import librsync
import os
import os.path
import errno

from common import get_internal_path

HOME = os.path.expanduser('~')

class FileStore(object):
	def __init__(self,store_path):
		self.store_path = os.path.join(store_path,"DATA")
		try:
			os.makedirs(self.store_path)
		except OSError as exc:
			if exc.errno != errno.EEXIST:
				raise
	
	def sync_file_in(self,file_path):
		src_path  = os.path.join(HOME,file_path)
		dst_path  = os.path.join(self.store_path,file_path)
		
		try:
			src = open(src_path,'rb')
		except IOError:
			print "{} does not exist".format(src_path)
			return False
		try:
			dst = open(dst_path,'rb')
		except IOError:
			try:
				os.makedirs(os.path.dirname(dst_path))
			except OSError as exc:
				if exc.errno != errno.EEXIST:
					raise
			dst = open(dst_path,'w+')
			dst.close()
			dst = open(dst_path,'rb')
		return self._sync(src,dst,dst_path)

	def sync_file_out(self,file_path):
		dst_path  = os.path.join(HOME,file_path)
		src_path  = os.path.join(self.store_path,file_path)
		
		try:
			src = open(src_path,'rb')
		except IOError:
			print "{} does not exist".format(src_path)
			return False
		try:
			dst = open(dst_path,'rb')
		except IOError:
			try:
				os.makedirs(os.path.dirname(dst_path))
			except OSError as exc:
				if exc.errno != errno.EEXIST:
					raise
			dst = open(dst_path,'w+')
			dst.close()
			dst = open(dst_path,'rb')
		return self._sync(src,dst,dst_path)
	

	def _sync(self,src,dst,dst_path):
		syn = open(dst_path,'wb')
		signature = librsync.signature(dst)
		delta = librsync.delta(src, signature)
		librsync.patch(dst,delta,syn)
		return True
	

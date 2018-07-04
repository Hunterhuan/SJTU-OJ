import os
import shutil
pathdir = os.listdir()
print(pathdir)
for i in pathdir:
	if i<='9' and i>='1':
		filedir = os.listdir(i)
		for filename in filedir:
			if 'cpp' in filename:
				os.rename(os.getcwd()+'\\'+i+'\\'+filename,os.getcwd()+'\\'+i+'\\'+i+'.cpp')
				shutil.copy(os.getcwd()+'\\'+i+'\\'+i+'.cpp',os.getcwd())

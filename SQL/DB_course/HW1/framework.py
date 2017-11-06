import os
import sqlite3

# get dir
homedir = os.getcwd()

conn = sqlite3.connect('{dir}\\test.db'.format(dir=homedir))


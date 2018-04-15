
from simple import *

crt = crypto() 

txt = "abc"
enc = crt.encrypt("key.key", "_0", txt)
dec = crt.decrypt("key.key", "_0", enc)
print(enc + " : " + dec)

conf = config()
print(conf.source())



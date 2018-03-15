BASEINCLUDE	?= ../../
kmemleak-objs	:= kmemleak_test.o


obj-m	:= kmemleak.o

all :
	$(MAKE) -C $(BASEINCLUDE) SUBDIRS=$(PWD) modules;

clean :
	$(MAKE) -C $(BASEINCLUDE) SUBDIRS=$(PWD) clean;
	rm -rf *.ko

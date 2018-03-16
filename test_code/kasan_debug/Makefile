BASEINCLUDE	?= ../../
kasan-objs	:= test_kasan.o


obj-m	:= kasan.o

all :
	$(MAKE) -C $(BASEINCLUDE) SUBDIRS=$(PWD) modules;

clean :
	$(MAKE) -C $(BASEINCLUDE) SUBDIRS=$(PWD) clean;
	rm -rf *.ko

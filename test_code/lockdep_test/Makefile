BASEINCLUDE	?= ../../
lock-objs	:= lockdep_test.o
mutexlock-objs	:= mutexlock_test.o

ccflags-y	+= -o0 -g

obj-m	:= lock.o mutexlock.o

all :
	$(MAKE) -C $(BASEINCLUDE) SUBDIRS=$(PWD) modules;

clean :
	$(MAKE) -C $(BASEINCLUDE) SUBDIRS=$(PWD) clean;
	rm -rf *.ko

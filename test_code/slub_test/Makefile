BASEINCLUDE ?= /home/al/running_kernel/linux-v4.4

slub-objs	:= slub_test.o
slub2-objs	:= slub_test2.o
slub3-objs	:= slub_test3.o

obj-m	:= slub.o slub2.o slub3.o

all	:
	$(MAKE) -C $(BASEINCLUDE) SUBDIRS=$(PWD) modules;

clean	:
	$(MAKE) -C $(BASEINCLUDE) SUBDIRS=$(PWD) clean;
	rm -rf *.ko;

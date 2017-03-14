#/*
# *  Copyright (C) 2016.
# *  All Rights Reserved.
# *
# */
#
#
.PHONY: clean

ROOTFS ?= $(SDKTARGETSYSROOT)

ROOTFS_USR :=$(ROOTFS)/usr

OBJS := x-hello.o

CFLAGS += -I $(ROOTFS)/usr/include --sysroot=$(ROOTFS)

LFLAGS += -Wl,-rpath-link,$(ROOTFS)/usr/lib -Wl,-rpath-link,$(ROOTFS)/usr/lib/arm-linux-gnueabi -lGLESv2 -lEGL -lX11 -lm --sysroot=$(ROOTFS)


TARGET := x-hello
all:$(TARGET)

%.o: %.c
	$(CC) $(CFLAGS) -o $@ -c $<

# build as shared library
x-hello: x-hello.o
	$(CC) $^ -o x-hello $(LFLAGS)

clean:
	-@rm $(TARGET) $(OBJS)


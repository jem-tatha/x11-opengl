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

OBJS := glxinfo.o glinfo_common.o

CFLAGS += -I $(ROOTFS)/usr/include --sysroot=$(ROOTFS)

LFLAGS += -Wl,-rpath-link,$(ROOTFS)/usr/lib -Wl,-rpath-link,$(ROOTFS)/usr/lib/arm-linux-gnueabi -lGL -lEGL -lX11 -lm --sysroot=$(ROOTFS)


TARGET := glxinfo
all:$(TARGET)

%.o: %.c
	$(CC) $(CFLAGS) -o $@ -c $<

# build as shared library
glxinfo: glxinfo.o glinfo_common.o
	$(CC) $^ -o glxinfo $(LFLAGS)

clean:
	-@rm $(TARGET) $(OBJS)


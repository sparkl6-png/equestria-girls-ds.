# Standard devkitPro/libnds Makefile
TARGET := equestria-girls-ds
BUILD := build
SOURCES := source
DATA :=
INCLUDES :=

ARCH := -mthumb -mthumb-interwork
CFLAGS := -g -Wall -O2 -ffunction-sections -fdata-sections $(ARCH) $(INCLUDES)
CXXFLAGS := $(CFLAGS) -fno-rtti -fno-exceptions
ASFLAGS := $(ARCH)
LDFLAGS := -specs=ds_arm9.specs -g $(ARCH) -Wl,--gc-sections
LIBS := -lnds9

ifeq ($(strip $(DEVKITPRO)),)
$(error "Please set DEVKITPRO in your environment. devkitPro is required.")
endif

include $(DEVKITPRO)/libnds/Makefile
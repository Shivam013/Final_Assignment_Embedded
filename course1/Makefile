# Makefile

# Include the sources.mk
include sources.mk

# General Compiler Flags
CFLAGS = -Wall -Werror -g -O0 -std=c99 $(INCLUDES)

# Compiler Selection
ifeq ($(PLATFORM),HOST)
    CC = gcc
    CFLAGS += -DHOST
else ifeq ($(PLATFORM),MSP432)
    CC = arm-none-eabi-gcc
    CFLAGS += -DMSP432 -mcpu=cortex-m4 -mthumb -march=armv7e-m -mfloat-abi=hard -mfpu=fpv4-sp-d16 --specs=nosys.specs
    LDFLAGS += -T msp432p401r.lds
endif

# Default target
.PHONY: all build clean compile-all

all: build

# Compile object files
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# Compile all objects but do not link
.PHONY: compile-all
compile-all: $(SOURCES:.c=.o)

# Build the final executable
build: compile-all
	$(CC) $(CFLAGS) $(LDFLAGS) -o c1m2.out $(SOURCES:.c=.o)
	size c1m2.out

# Clean all generated files
.PHONY: clean
clean:
	rm -f *.o *.i *.asm c1m2.out *.map

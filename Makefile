CC = gcc
CFLAGS = -ffreestanding -mno-red-zone -m64 -fPIC -c

# List of apps to compile into .bloe binaries
APPS = apps/discord.bloe apps/youtube.bloe apps/x.bloe

all: $(APPS)

# Compile the .c source code into a position-independent .bloe executable object
apps/%.bloe: apps/%.c
	$(CC) $(CFLAGS) $< -o $@

clean:
	rm -f apps/*.bloe

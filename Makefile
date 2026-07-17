CXX = g++
CXXFLAGS = -ffreestanding -fno-stack-protector -fpic -fpie -mno-red-zone -m64 -c -fno-exceptions -fno-rtti
LDFLAGS = -nostdlib -shared -Bsymbolic

# List of apps to compile into ELF binaries
APPS = apps/discord.elf apps/youtube.elf apps/x.elf apps/settings.elf apps/blankdrop.elf apps/blankbrowser.elf

all: $(APPS)

# Compile the .cpp source code into a position-independent ELF executable
apps/%.elf: apps/%.cpp
	$(CXX) $(CXXFLAGS) $< -o apps/$*.o
	ld $(LDFLAGS) apps/$*.o -o $@

clean:
	rm -f apps/*.o apps/*.elf

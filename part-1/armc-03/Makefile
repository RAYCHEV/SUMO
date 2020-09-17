COMPILER_BAREMETAL := arm-none-eabi-
CFLAGS := -g -nostartfiles -mfloat-abi=hard -O0 -DRPI3 -mfpu=crypto-neon-fp-armv8 -march=armv8-a+crc -mcpu=cortex-a53

all:
	${COMPILER_BAREMETAL}gcc ${CFLAGS} *.c -o kernel7.elf
	${COMPILER_BAREMETAL}objcopy kernel7.elf -O binary kernel7.img
	${RM} kernel7.elf
clean:
	${RM} kernel7.elf kernel7.img

install:
#	cp /media/${USER}/boot/kernel7.img /media/${USER}/boot/kernel7.img.bak
	cp /media/${USER}/BOOT/kernel7.img /media/${USER}/BOOT/kernel7.img.bak
#	cp kernel7.img /media/${USER}/boot/kernel7.img
	cp kernel7.img /media/${USER}/BOOT/kernel7.img
	eject /media/${USER}/BOOT/
	umount /media/${USER}/BOOT/

get_compiler:
# Link: https://developer.arm.com/tools-and-software/open-source-software/developer-tools/gnu-toolchain/gnu-a/downloads
	wget https://developer.arm.com/-/media/Files/downloads/gnu-a/9.2-2019.12/binrel/gcc-arm-9.2-2019.12-x86_64-arm-none-eabi.tar.xz -O ~/Downloads/gcc-arm-9.2-2019.12-x86_64-arm-none-eabi.tar.xz
	sudo mkdir -p /opt/arm_compilers
	sudo tar -xJf ~/Downloads/gcc-arm-9.2-2019.12-x86_64-arm-none-eabi.tar.xz -C /opt/arm_compilers
	echo "export PATH=/opt/arm_compilers/gcc-arm-9.2-2019.12-x86_64-arm-none-eabi/bin/:\$PATH" >> ~/.bashrc
	source ~/.bashrc

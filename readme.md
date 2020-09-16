Download:
http://downloads.raspberrypi.org/raspios_full_armhf/images/raspios_full_armhf-2020-08-24/2020-08-20-raspios-buster-armhf-full.zip
http://downloads.raspberrypi.org/raspios_full_armhf/images/raspios_full_armhf-2020-08-24/2020-08-20-raspios-buster-armhf-full.zip.torrent

Files:
- 2020-08-20-raspios-buster-armhf-full.zip.torrent                               - Torrent file of Raspbian GNU/Linux 10 (buster) + Kernel Linux raspberrypi 5.4.51-v7+
- 2020-08-20-raspios-kernel-5.4.64-sdcard-recovery-content-files.tar.gz          - Upgrade / Recovery Kernel Linux raspberrypi version 5.4.64-v7+ sdcard files content
- 2020-08-20-raspios-kernel-5-4-64-split.aa                                      - Upgrade / Recovery Kernel Linux raspberrypi version 5.4.64-v7+ sdcard part aa of kernel image
- 2020-08-20-raspios-kernel-5-4-64-split.ab                                      - Upgrade / Recovery Kernel Linux raspberrypi version 5.4.64-v7+ sdcard part ab of kernel image
- 2020-08-20-raspios-rootfs-lib-drivers-for-kernel-5.4.64-sdcard-recovery.tar.gz - Upgrade for all kernel drivers version 5.4.64-v7+
- readme.md                                                                      - The file is content of the directory

Description:
1. Download the full operating system from the web link or by torrent client. Extract the image and expand it to sdcard storage device.
lsblk
ls -la /dev/sd*
sudo dd if=2020-08-20-raspios-buster-armhf-full.img of=/dev/sdX

2. Upgrade or recovery kernel v5.4.64
Extract lib modules of kernel v5.4.64 into /rootfs/lib/modules partition on sdcard
tar -xzf 2020-08-20-raspios-rootfs-lib-drivers-for-kernel-5.4.64-sdcard-recovery.tar.gz
sudo mv rootfs/lib/modules/5.4.64-v7+/ /media/rootfs/lib/modules/5.4.64-v7+/

2.1.1 Recovery kernel only this is /boot partition on sdcard
Where "X" is you place for sdcard use commands: "lsblk" and "ls -la /dev"

Concatenate / join all parts archives to one 2020-08-20-raspios-kernel-5.4.64-sdcard-recovery.img.tar.gz
cat 2020-08-20-raspios-kernel-5-4-64-split.* 2020-08-20-raspios-kernel-5.4.64-sdcard-recovery.img.tar.gz
tar -xzf 2020-08-20-raspios-kernel-5.4.64-sdcard-recovery.img.tar.gz
lsblk
ls -la /dev/sd*
sudo dd if=2020-08-20-raspios-kernel-5.4.64-sdcard-recovery.img of=/dev/sdX1

2.1.2 Set /boot partition with lba flag by gparted tool:
sudo gparted
# Select correct disk - sdcard storage and boot parition.
# Use mouse right click "Manage flags" and click tick only on "lba".

2.2 Or use alternative way only with extractung files on sd card in /boot partition

2.2.1 Extract files and replace all into /boot on sdcard storage device.
tar -xzf 2020-08-20-raspios-kernel-5.4.64-sdcard-recovery-content-files.tar.gz
sudo cp -r /boot/* /media/boot

2.2.2 Set /boot partition with lba flag by gparted tool:
sudo gparted
# Select correct disk - sdcard storage and boot parition.
# Use mouse right click "Manage flags" and click tick only on "lba".

Help split and join/combine files:
split -b 99M 2020-08-20-raspios-kernel-5.4.64-sdcard-recovery.img.tar.gz 2020-08-20-raspios-kernel-5-4-64-split.
cat 2020-08-20-raspios-kernel-5-4-64-split.* 2020-08-20-raspios-kernel-5.4.64-sdcard-recovery.img.tar.gz
This needs if you want to push bigger files than 99MB because github has limit for filesize.

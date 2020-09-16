Download:
http://downloads.raspberrypi.org/raspios_full_armhf/images/raspios_full_armhf-2020-08-24/2020-08-20-raspios-buster-armhf-full.zip
http://downloads.raspberrypi.org/raspios_full_armhf/images/raspios_full_armhf-2020-08-24/2020-08-20-raspios-buster-armhf-full.zip.torrent

Files:
- 2020-08-20-raspios-buster-armhf-full.zip.torrent                      - Torrent file of Raspbian GNU/Linux 10 (buster) + Kernel Linux raspberrypi 5.4.51-v7+
- 2020-08-20-raspios-kernel-5.4.51-sdcard-recovery.img.tar.gz           - Recovery Kernel Linux raspberrypi 5.4.51-v7+ sdcard image file
- 2020-08-20-raspios-kernel-5.4.51-sdcard-recovery-content-files.tar.gz - Recovery Kernel Linux raspberrypi 5.4.51-v7+ sdcard files content
- readme.md                                                             - The file is content of the directory

Description:
1. Download the full operating system from the web link or by torrent client. Extract the image and expand it to sdcard storage device.
tar -xzf 2020-08-20-raspios-kernel-5.4.51-sdcard-recovery.img.tar.gz
lsblk
ls -la /dev/sd*
sudo dd if=2020-08-20-raspios-buster-armhf-full.img of=/dev/sdX

2. Recovery kernel only this is /boot partition on sdcard
Where "X" is you place for sdcard use commands: "lsblk" and "ls -la /dev"

tar -xzf 2020-08-20-raspios-kernel-5.4.51-sdcard-recovery.img.tar.gz
sudo dd if=2020-08-20-raspios-kernel-5.4.51-sdcard-recovery.img of=/dev/sdX1

3. Set /boot partition with lba flag by gparted tool:
sudo gparted
# Select correct disk - sdcard storage and boot parition.
# Use mouse right click "Manage flags" and click tick only on "lba".

Help split and join/combine files:
split -b 99M file.img.zip file.img.zip.split.
cat file.img.zip.split.* > file.img.zip
This needs if you want to push bigger files than 99MB because github has limit for filesize.

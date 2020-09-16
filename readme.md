Download:
http://downloads.raspberrypi.org/raspios_full_armhf/images/raspios_full_armhf-2020-08-24/2020-08-20-raspios-buster-armhf-full.zip
http://downloads.raspberrypi.org/raspios_full_armhf/images/raspios_full_armhf-2020-08-24/2020-08-20-raspios-buster-armhf-full.zip.torrent

Files:
- 2020-08-20-raspios-buster-armhf-full.zip.torrent                               - Torrent file of Raspbian GNU/Linux 10 (buster) + Kernel Linux raspberrypi 5.4.51-v7+
- 2020-08-20-raspios-kernel-5.4.64-sdcard-recovery-content-files.tar.gz          - Upgrade / Recovery Kernel Linux raspberrypi version 5.4.64-v7+ sdcard files content
- 2020-08-20-raspios-rootfs-lib-drivers-for-kernel-5.4.64-sdcard-recovery.tar.gz - Upgrade for all kernel drivers version 5.4.64-v7+
- readme.md                                                                      - The file is content of the directory

Description:
1. Download the full operating system from the web link or by torrent client. Extract files and replace all into /boot on sdcard storage device.
tar -xzf 2020-08-20-raspios-kernel-5.4.64-sdcard-recovery-content-files.tar.gz
sudo cp -r /boot/* /media/boot

2. Extract and replace all kernel modlules /rootfs/lib/modules
tar -xzf 2020-08-20-raspios-rootfs-lib-drivers-for-kernel-5.4.64-sdcard-recovery.tar.gz
sudo mv rootfs/lib/modules/5.4.64-v7+/ /media/rootfs/lib/modules/5.4.64-v7+/


Help split and join/combine files:
split -b 99M file.img.zip file.img.zip.split.
cat file.img.zip.split.* > file.img.zip
This needs if you want to push bigger files than 99MB because github has limit for filesize.

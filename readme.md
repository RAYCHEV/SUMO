Download:
http://downloads.raspberrypi.org/raspios_full_armhf/images/raspios_full_armhf-2020-05-28/2020-05-27-raspios-buster-full-armhf.zip

Files:
- 2020-05-27-raspios-split.aa to 2020-05-27-raspios-split.az   - Raspbian GNU/Linux 10 (buster) + Kernel Linux raspberrypi 4.19.118-v7+
- 2020-05-27-raspios-buster-full-armhf.zip.torrent.tar.gz      - Torrent file of Raspbian GNU/Linux 10 (buster) + Kernel Linux raspberrypi 4.19.118-v7+
- 2020-05-27-raspi-kernel-v4.19.118-sdcard-recovery.img.tar.gz - Recovery Kernel Linux raspberrypi 4.19.118-v7+
- readme.md                                                    - This file, info about content of the current branch


Description:
1. Concatenate / join all parts archives to one 2020-05-27-raspios-buster-full-armhf.img.tar.gz
Extract archive and create full raspbian OS on sdcard with 2020-05-27-raspios-buster-full-armhf.img
Where "X" is you place for sdcard use commands: "lsblk" and "ls -la /dev"

mv .git ../
rm -rf * && rm -rf .*
mv ../.git .
git reset --hard
cat 2020-05-27-raspios-split.* > 2020-05-27-raspios-buster-full-armhf.img.tar.gz
tar -xzf 2020-05-27-raspios-buster-full-armhf.img.tar.gz
lsblk
ls -la /dev/sd*
sudo dd if=2020-05-27-raspios-buster-full-armhf.img of=/dev/sdX

2. Recovery kernel only this is /boot partition on sdcard
Where "X" is you place for sdcard use commands: "lsblk" and "ls -la /dev"

tar -xzf 2020-05-27-raspi-kernel-v4.19.118-sdcard-recovery.img.tar.gz
sudo dd if=2020-05-27-raspi-kernel-v4.19.118-sdcard-recovery.img of=/dev/sdX1

Help split and join/combine files:
split -b 99M 2020-05-27-raspios-buster-full-armhf.img.tar.gz 2020-05-27-raspios-split.
cat 2020-05-27-raspios-split.* > 2020-05-27-raspios-buster-full-armhf.img.tar.gz
You need to have 10GB free space to combine files to archive image and extract the image.

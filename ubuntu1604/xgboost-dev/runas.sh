#!/bin/bash
# env-vars
#  . UID  - uid of the user
#  . USER - user name

# if these vars are not set
if [ "$UID" = "" ] || [ "$USER" = "" ]; then
    $*
    exit
fi

adduser --disabled-password --gecos "" --uid $UID $USER
mkdir -p /etc/sudoers.d
echo "$USER ALL=(root) NOPASSWD:ALL" > /etc/sudoers.d/$USER
chmod 0440 /etc/sudoers.d/$USER
echo >> /home/$USER/.bashrc
env | grep -v LS_COLORS >> /home/$USER/.bashrc
ldconfig
su - $USER -c $*

#!/bin/bash
# env-vars
#  . UID  - uid of the user
#  . USER - user name

# if both these vars are not set, run as root, as usual
if [ "$UID" = "" ] || [ "$USER" = "" ]; then
    $*
    exit
fi

# create a new user and setup his/her env
HOME=/home/$USER
adduser --disabled-password --gecos "" --uid $UID --home $HOME $USER
mkdir -p /etc/sudoers.d
echo "$USER ALL=(root) NOPASSWD:ALL" > /etc/sudoers.d/$USER
chmod 0440 /etc/sudoers.d/$USER
echo >> $HOME/.bashrc
env | grep -v LS_COLORS >> $HOME/.bashrc
ldconfig
mkdir $HOME/.vnc
touch $HOME/.Xauthority $HOME/.Xresources
cp /.xinitrc $HOME/.xinitrc
cp /.xsession $HOME/.xsession
chown $USER $HOME/.vnc $HOME/.Xauthority $HOME/.Xresources $HOME/.xsession
chown $HOME/.xinitrc

# run as that user
su - $USER -c $*

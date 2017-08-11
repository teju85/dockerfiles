#!/bin/bash
# env-vars
#  . UID  - uid of the user. Eg: $(id -u $USER)

USER=myuser

# if both these vars are set
# create a new user and setup his/her env
if [ "$UID" != "" ]; then
    echo "Creating env for the user uid=$UID"
    HOME=/home/$USER
    adduser --disabled-password --gecos "" --uid $UID --home $HOME $USER
    mkdir -p /etc/sudoers.d
    echo "$USER ALL=(root) NOPASSWD:ALL" > /etc/sudoers.d/$USER
    chmod 0440 /etc/sudoers.d/$USER
    echo > $HOME/.bashrc
    env | grep -v -e LS_COLORS -e UID >> $HOME/.bashrc
    ldconfig
else
    USER=root
    HOME=/$USER
fi

# vnc server related files
# NOTE: NOTE: NOTE:
# this assumes that the docker image would have been built using
# the reusables/vnc docker commands!!
if [ "$VNC_SETUP" = "1" ]; then
    mkdir $HOME/.vnc
    touch $HOME/.Xauthority $HOME/.Xresources
    cp /.xinitrc $HOME/.xinitrc
    cp /.xsession $HOME/.xsession
    chown $USER $HOME/.vnc $HOME/.Xauthority $HOME/.Xresources $HOME/.xsession
    chown $HOME/.xinitrc
fi

echo "Cmd to run: $*"
# run as that user
if [ "$USER" != "root" ]; then
    exec su - $USER -c "cd `pwd`; $*"
else
    exec $*
fi

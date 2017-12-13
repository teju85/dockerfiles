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

echo "Cmd to run: $*"
# run as that user (or root)
if [ "$USER" != "root" ]; then
    # compile the exec-as binary and execute it to switch user
    cc -o /exec-as /exec-as.c
    exec /exec-as `id -u $USER` `id -g $USER` `pwd` $*
else
    exec $*
fi

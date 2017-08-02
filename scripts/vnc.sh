#!/bin/bash

SCRIPT=$0

function showHelp() {
    cat <<EOF
Script to run container on the images built with vnc capability
USAGE:
 $SCRIPT [-h, -u, -v <port>] <xgpath>
  -h                     Print this help
  -i                     Image to be used. [xgb-dev:8.0]
  -p <host>:<container>  Start vncserver on this port. [5900:5900]
  -u                     Run as current user. [runs as root]
  -v                     Start vncserver. [starts bash terminal]
  <xgpath>    Path to the root of xgboost repo. Mandatory!
EOF
    exit 0
}


image=xgb-dev:8.0
xgpath=
needUser=0
vncPort=5900:5900
startVnc=0
while [ "$1" != "" ]; do
    case "$1" in
        "-h")
            shift
            showHelp;;
        "-i")
            shift
            image=$1
            shift;;
        "-p")
            shift
            vncPort=$1
            shift;;
        "-u")
            needUser=1
            shift;;
        "-v")
            startVnc=1
            shift;;
        *)
            xgpath=$1
            shift;;
    esac
done
if [ "$xgpath" = "" ]; then
    echo "USAGE: xgb-dev.sh <xgboostRepoPath>"
    exit 1
fi
if [ ! -d "$xgpath" ]; then
    echo "Directory '$xgpath' does not exist!"
    exit 1
fi

userOpts=
if [ "$needUser" = "1" ]; then
    userOpts="-e USER=$USER -e UID=`id -u $USER`"
fi

startCmd=
portsOpt=
if [ "$startVnc" = "0" ]; then
    startCmd="/bin/bash"
else
    portsOpt="-p $vncPort"
fi

cmd="nvidia-docker run --rm -it -v $xgpath:/xgboost:rw $userOpts $portsOpt $image $startCmd"
echo $cmd
exec $cmd

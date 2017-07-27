#!/bin/bash

IMAGE=xgb-dev:8.0
SCRIPT=$0

function showHelp() {
    echo <<EOF
Script to run container on the image: $IMAGE
USAGE:
 $SCRIPT [-h, -u, -v <port>] <xgpath>
  -h          Print this help
  -u          Run as the current user. Default is to run as root.
  -v <port>   Start vncserver on this port. Default is to start a bash terminal.
  <xgpath>    Path to the root of xgboost repo. Mandatory!
EOF
}


xgpath=
needUser=0
startVnc=
while [ "$1" != "" ]; do
    case "$1" in
        "-h")
            showHelp;;
        "-u")
            needUser=1
            shift;;
        "-v")
            shift
            startVnc=$1
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
if [ "$startVnc" = "" ]; then
    startCmd="/bin/bash"
else
    portsOpt="-p $startVnc:$startVnc"
fi

cmd="nvidia-docker run --rm -it -v $xgpath:/xgboost:rw $userOpts $portsOpt $IMAGE $startCmd"
echo $cmd
exec $cmd

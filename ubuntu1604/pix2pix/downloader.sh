#!/bin/bash
# USAGE:
#  cd pytorch-CycleGAN-and-pix2pix && \\
#    downloader.sh <type1> <dataset1> [<type2> <dataset2> [...]]
#      <type>     cycle-gan or pix2pix
#      <dataset>  name of the dataset as in the github repo:
#                 https://github.com/junyanz/pytorch-CycleGAN-and-pix2pix
#
# shamelessly copied from the above repo!
#

function download() {
    local TYPE=$1
    local FILE=$2
    if [ "$TYPE" = "pix2pix" ]; then
        URL=https://people.eecs.berkeley.edu/~tinghuiz/projects/pix2pix/datasets/$FILE.tar.gz
        TAR_FILE=./datasets/$FILE.tar.gz
        TARGET_DIR=./datasets/$TYPE/$FILE/
        if [ ! -e "$TARGET_DIR" ]; then
            wget -N $URL -O $TAR_FILE
            mkdir -p $TARGET_DIR
            tar -zxvf $TAR_FILE -C ./datasets/
            rm $TAR_FILE
        fi
    elif [ "$TYPE" = "cycle-gan" ]; then
        URL=https://people.eecs.berkeley.edu/~taesung_park/CycleGAN/datasets/$FILE.zip
        ZIP_FILE=./datasets/$FILE.zip
        TARGET_DIR=./datasets/$TYPE/$FILE/
        if [ ! -e "$TARGET_DIR" ]; then
            wget -N $URL -O $ZIP_FILE
            mkdir -p $TARGET_DIR
            unzip $ZIP_FILE -d ./datasets/
            rm $ZIP_FILE
        fi
    else
        echo "Bad <type> passed! $TYPE"
        exit 1
    fi
}

while [ "$1" != "" ]; do
    TYPE=$1
    shift
    FILE=$1
    shift
    if [ "$TYPE" = "" ] || [ "$FILE" = "" ]; then
        echo "Incorrect usage!"
        exit 1
    fi
    download $TYPE $FILE
done

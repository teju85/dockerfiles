#!/bin/bash
# script to setup visdom env and start sever in the background
# Usage: visdom.sh <visdomPort>
port=${VISPORT:-8097}
pid=`ps aux | grep visdom.server | grep -v 'grep visdom.server'`
if [ "$pid" != "" ]; then
    echo "visdom server already running..."
    echo "  $pid"
else
    echo "Starting visdom server..."
    python -m visdom.server &
fi

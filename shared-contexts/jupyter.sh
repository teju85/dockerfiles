#!/bin/bash
# script to setup jupyter env and start a session
jpdir=$HOME/.jupyter
jpcfg=$jpdir/jupyter_notebook_config.py
mkdir -p -m 0700 $jpdir
jupyter notebook --generate-config --allow-root
echo >> $jpcfg
echo "c.NotebookApp.ip = '*'" >> $jpcfg
echo "c.NotebookApp.port = $NB_PORT" >> $jpcfg
exec jupyter notebook --allow-root --no-browser

#!/bin/bash
resolution=${1:-1600x1200}
exec x11vnc -display :0 -create -shared -forever -scale $resolution

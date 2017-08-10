#!/bin/bash
exec x11vnc -display :0 -create -shared -forever

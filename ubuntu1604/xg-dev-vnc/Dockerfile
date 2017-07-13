FROM xgboost-dev:latest

ARG port=5900
ARG userid=9001

ENV DEBIAN_FRONTEND noninteractive

RUN apt-get update && \
    apt-get install -y --no-install-recommends \
        dbus \
        dbus-x11 \
        lxde \
        cuda-visual-tools-$CUDA_PKG_VERSION \
        x11vnc \
        xorg \
        xrdp \
        xterm \
        xvfb && \
    rm -rf /var/lib/apt/lists/*

EXPOSE $port

COPY .xinitrc /.xinitrc
COPY vncserver.sh /vncserver.sh
COPY .xsession /.xsession

RUN sed -i "0,/port=-1/{s/port=-1/port=$port/}" /etc/xrdp/xrdp.ini && \
    chmod +x /.xinitrc /.xsession /vncserver.sh

# create the new user
# and setup the environment for the new user
RUN useradd -d /home/app -m -u $userid app
ENV USER app
ENV HOME /home/$USER
RUN mkdir $HOME/.vnc && \
    touch $HOME/.Xauthority $HOME/.Xresources && \
    cp /.xinitrc $HOME/.xinitrc && \
    cp /.xsession $HOME/.xsession && \
    chown $USER $HOME/.vnc $HOME/.Xauthority $HOME/.Xresources \
        $HOME/.xsession $HOME/.xinitrc

ENTRYPOINT ["/vncserver.sh"]

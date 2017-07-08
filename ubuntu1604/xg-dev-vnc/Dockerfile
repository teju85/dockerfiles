FROM xgboost-dev:latest

ENV DEBIAN_FRONTEND noninteractive
ENV USER root

RUN apt-get update && \
    apt-get install -y --no-install-recommends \
        lxde \
        nvidia-visual-profiler \
        x11vnc \
        xorg \
        xrdp \
        xterm \
        xvfb && \
    mkdir /root/.vnc

EXPOSE 5900

COPY .xinitrc /root/.xinitrc
COPY vncserver.sh /vncserver.sh

RUN sed -i '0,/port=-1/{s/port=-1/port=5900/}' /etc/xrdp/xrdp.ini && \
    chmod +x /root/.xinitrc /vncserver.sh && \
    touch /root/.Xauthority && \
    touch /root/.Xresources

ENTRYPOINT ["/vncserver.sh"]

FROM cuda:9.0-dev
RUN apt-get update && \
    apt-get install -y --no-install-recommends \
        apt-utils \
        build-essential \
        cpio \
        curl \
        dirmngr \
        git \
        iputils-ping \
        libbz2-dev \
        libncursesw5-dev \
        libncurses5-dev \
        libopenblas-dev \
        libreadline-dev \
        libsqlite3-dev \
        libssl-dev \
        llvm \
        make \
        net-tools \
        pbzip2 \
        python3 \
        python3-dev \
        python3-software-properties \
        python3-dateutil \
        python3-magic \
        python3-pip \
        software-properties-common \
        swig \
        tk-dev \
        virtualenv \
        wget \
        xz-utils \
        zip \
        zlib1g-dev && \
    rm -rf /var/lib/apt/lists && \
    mkdir /var/lib/apt/lists && \
    wget "http://launchpadlibrarian.net/326935544/s3cmd_2.0.0-1_all.deb" && \
    dpkg -i s3cmd_2.0.0-1_all.deb && \
    curl -sL "https://deb.nodesource.com/setup_7.x" | bash -
RUN virtualenv --python=python3.5 /opt/.venv && \
    chmod 0777 -R /opt/.venv && \
    . /opt/.venv/bin/activate && \
    pip install --no-cache-dir setuptools
RUN apt-get update && \
    apt-get install -y --no-install-recommends \
        python3 \
        python3-dev \
        python3-pip \
        python3-setuptools && \
    pip3 install --upgrade pip && \
    rm -rf /var/lib/apt/lists && \
    mkdir /var/lib/apt/lists
RUN apt-get update && \
    apt-get install -y --no-install-recommends \
        build-essential \
        libblas-dev \
        libbz2-dev \
        liblapack-dev && \
    rm -rf /var/lib/apt/lists && \
    mkdir /var/lib/apt/lists
RUN pip3 install --no-cache-dir \
        h5py \
        ipython[all] \
        jupyter \
        keras \
        keras-resnet \
        matplotlib \
        nose \
        numpy \
        pandas \
        Pillow \
        Pillow-PIL \
        scikit-learn \
        scipy \
        sklearn \
        tensorflow \
        tqdm
ARG port=8888
EXPOSE $port
COPY contexts/jupyter /opt/jupyter
ENV NBPORT $port
CMD /opt/jupyter/jupyter.sh
RUN apt-get update && \
    apt-get install -y --no-install-recommends \
        build-essential \
        git \
        make \
        tar \
        wget && \
    rm -rf /var/lib/apt/lists && \
    mkdir /var/lib/apt/lists
COPY contexts/runas /opt/runas
RUN cc -o /opt/runas/exec-as /opt/runas/exec-as.c
ENTRYPOINT ["/opt/runas/runas.sh"]
ENV DEBIAN_FRONTEND noninteractive
EXPOSE 22
EXPOSE 45555
RUN apt-get update && \
    apt-get install -y --no-install-recommends \
        openssh-server && \
    rm -rf /var/lib/apt/lists && \
    mkdir /var/lib/apt/lists
COPY "contexts/ssh" "/opt/ssh/"
ENV RUNAS_PRE_SWITCH_CMD "/opt/ssh/start.sh"
RUN mkdir /var/run/sshd && \
    sed -i 's/PermitRootLogin prohibit-password/PermitRootLogin yes/' /etc/ssh/sshd_config && \
    sed -i 's/#PasswordAuthentication yes/PasswordAuthentication yes/' /etc/ssh/sshd_config && \
    sed 's@session\s*required\s*pam_loginuid.so@session optional pam_loginuid.so@g' -i /etc/pam.d/sshd && \
    echo "root:root" | chpasswd

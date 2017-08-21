FROM pytorch:0.1.12


RUN git clone "https://github.com/pytorch/vision" && \\
    cd vision && \\
    python setup.py install

RUN pip install --upgrade pip && \\
    pip install --no-cache-dir \\
        dominate \\
        visdom

RUN apt-get update && \\
    apt-get install -y --no-install-recommends \\
        unzip && \\
    rm -rf /var/lib/apt/lists && \\
    mkdir /var/lib/apt/lists

// TODO: dataset downloader scripts currently download everything inside
// the 'datasets' directory. Thus, the idea is to have custom scripts to
// download the datasets into a volume mount!
//RUN git clone "https://github.com/junyanz/pytorch-CycleGAN-and-pix2pix"
//WORKDIR pytorch-CycleGAN-and-pix2pix
COPY downloader.sh /downloader.sh

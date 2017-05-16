FROM python:2.7

RUN apt-get update && \
    apt-get install -y --no-install-recommends \
        postgresql \
        postgresql-contrib && \
    rm -rf /var/lib/apt/lists/*

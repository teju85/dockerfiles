FROM cudnn:5.1
FROM python:2.7

# tensorflow installation
RUN pip install --no-cache-dir \
    tensorflow-gpu

# validate the tensor flow installation
COPY validate.py .
CMD python validate.py

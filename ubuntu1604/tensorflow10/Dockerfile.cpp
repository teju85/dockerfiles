FROM cudnn:5.1

#include "../../reusables/pyml-env-2.7"

// tensorflow installation
RUN pip install --no-cache-dir tensorflow-gpu

// validate the tensor flow installation
COPY validate.py .
CMD python validate.py

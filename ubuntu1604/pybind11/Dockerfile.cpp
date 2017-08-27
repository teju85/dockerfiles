FROM cudnn:6.0

#include "../../reusables/pyml-env-2.7"

RUN apt-get update && \\
    apt-get install -y --no-install-recommends \\
        build-essential \\
        git

ENV PYBIND11 /pybind11
RUN git clone "https://github.com/pybind/pybind11" $PYBIND11

COPY examples $PYBIND11/examples
RUN chmod a+w -R $PYBIND11/examples
CMD $PYBIND11/examples/run.sh

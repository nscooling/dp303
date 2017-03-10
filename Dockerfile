FROM gcc:4.9

RUN apt-get update; \
    apt-get -y upgrade

RUN apt-get -y install cmake git

COPY . /usr/dp303/

RUN ls -la /usr/dp303/; \
    cd /usr/dp303; \
    mkdir build; \
    cd build; \
    cmake ..; \
    make
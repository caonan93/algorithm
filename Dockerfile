FROM hub.c.163.com/public/ubuntu:14.04
COPY . /data
WORKDIR /data
RUN apt-get -y update && apt-get install -y gcc g++ gtest cmake vim
RUN mv /usr/sbin/tcpdump /usr/bin/tcpdump
ENTRYPOINT /usr/sbin/sshd -D

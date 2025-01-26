FROM rockylinux:9

RUN dnf install epel-release -y && crb enable && dnf update -y && dnf install -y xz fzf which libcurl-devel lua-devel clang lld cmake ninja-build git-all

WORKDIR /build

COPY . /build/

CMD [ "bash" ]
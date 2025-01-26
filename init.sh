su -
cd /usr
mkdir boof
cd boof
mkdir store
touch Packages
touch Metadata
curl https://archive.archlinux.org/packages/.all/index.0.xz | unxz > Packages
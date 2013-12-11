# pdbq

The ultimate game modification playground.

## Dependencies

```sh
# Install required development files
sudo apt-get install xorg-dev libglu1-mesa-dev

# Download, extract, compile, and install GLFW 3.0.3
wget https://github.com/glfw/glfw/archive/3.0.3.zip && \
  unzip 3.0.3.zip && cd glfw-3.0.3 && mkdir build && cd build && \
  cmake .. && make && sudo make install

# Download, extract, compile, and install GLEW 1.10.0
wget \
  http://downloads.sourceforge.net/project/glew/glew/1.10.0/glew-1.10.0.tgz && \
  tar -xf glew-1.10.0.tgz && cd glew-1.10.0 && make && sudo make install
```

## Building & Running

```sh
cd src && make && ./main
```

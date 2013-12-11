# pdbq

The ultimate game modification playground.

## Dependencies

```sh
# Install required development files
sudo apt-get install xorg-dev libglu1-mesa-dev

# Download, extract, and compile GLFW
wget https://github.com/glfw/glfw/archive/3.0.3.zip && \
  unzip 3.0.3.zip && cd glfw-3.0.3 && mkdir build && cd build && \
  cmake .. && make
  
# Install GLFW
sudo make install
```

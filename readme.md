# lcm learning

## depend

- [lcm](https://github.com/lcm-proj/lcm)

## run

```
cd tools
./lcm_gen.sh
cd ..

mkdir build
cd build
cmake ..
make -j`nproc`

./publisher/publisher
./subscriber/subscriber
```
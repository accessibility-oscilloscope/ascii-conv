### expected behavior:

converts whitespace-separated ascii representations of integers into raw
integers (C's `int` type, signed, 4 bytes)

### testing:

run
```
make
./ascii_conv /tmp/testingfifo /dev/stdout | hexdump -C
```
in another terminal run
```
echo -ne "20000\n40000\n127\n127\n128\n0\n0\n100\n30\n25\n" > /tmp/testingfifo
echo -ne "20000\n40000\n127\n127\n128\n0\n0\n100\n30\n25\n" > /tmp/testingfifo
```
you should see the following
```
00000000  20 4e 00 00 40 9c 00 00  7f 00 00 00 7f 00 00 00  | N..@...........|
00000010  80 00 00 00 00 00 00 00  00 00 00 00 64 00 00 00  |............d...|
00000020  1e 00 00 00 19 00 00 00  20 4e 00 00 40 9c 00 00  |........ N..@...|
00000030  7f 00 00 00 7f 00 00 00  80 00 00 00 00 00 00 00  |................|
00000040  00 00 00 00 64 00 00 00  1e 00 00 00 19 00 00 00  |....d...........|
```

the same should work for any combination of whitespace, e.g.
```
echo -ne "20000 40000 127 127 128 0 0 100 30 25 " > /tmp/testingfifo
echo -ne "20000 40000   \n\n  127 127 128 0 0 100 30 25 " > /tmp/testingfifo
```

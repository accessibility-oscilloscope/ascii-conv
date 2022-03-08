# ASCII to Byte Converter

## Expected Behavior:
This program converts the ASCII representation of integers, seperated by newlines, into the raw integers. For the pruposes of gathering coordinate data, the program reads in the ASCII string into a buffer, and depending on if the character is a newline or not, stores the character in one of two arrays. The arrays are then converted into integers and the output, which is a 2-byte (u_int8_t) is assigned to these integers values. The 2-byte output containing the coordinate data is then written to the output FIFO. Right now the data being converted into the 2-byte struct is the first two ASCII values, so the output will be one coordinate point in the 2-byte structure.

### Instructions

In one terminal run the following commands:

```
make
mkfifo test-fifo
./convert test-fifo /dev/stdout | hd
```

Open another terminal and run the following commands to input coordinate data:

```
echo -ne "12222\n33222\n23111\n" > test-fifo
```

The expected output will be one coordinate area in this case pertaining to the first two values in the ASCII string (12222 and 33222).

```
00000000  be c6                                             |..|
00000002
```

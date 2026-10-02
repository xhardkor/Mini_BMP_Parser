# Mini BMP Parser

> [!NOTE]
> That "parser" is just mini project to get a bit of experience. \
> It only works with BITMAPINFOHEADER and BITMAPV4HEADER.

In `inp/` directory put .bmp file. \
Then use this command:
```bash
# You can also add at the end `-d` to dump hex of the new file you created.
./START.sh inp/<YOUR BMP FILE> <NAME OF NEW FILE>
# or
make test
# Just to do it faster / BUT YOUR BMP FILE HAS TO BE "test.bmp"
```
It will create an `out/` directory where there will be your new file and executable. \
To delete that directory with content use:
```bash
make clean
```

## Functionality:
> Inverting Pixel Colors;

## Bash's arguments:
> -d = Debug / Dumps hex of the new file \
> -t = Testing purpose / prints full image path and name of new file \
> -- = If there are other arguments/no arguments, you will only get `out/` directory without hex dump

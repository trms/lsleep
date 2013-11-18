# lsleep: Lua Sleep
Because sometimes, you just want sleep.


## Introduction

**lsleep** is an uber-simple library that just adds `sleep` and `usleep` to Lua.

## Installation

### Luarocks and LuaDist

TODO!

### Mac and *nix

```
make
make install
```
### Windows

I might include a VS2010 project, once I can figure out how to make an offshoot of one that is automatically generalized (and figure out what that means in Windows :)).

For now, just know that all that you need to do is make a standard DLL project that includes the Lua library in your path (usually lua52.lib or lua.52.lib, or whatever).

Also, _WINDLL must be `#define`-ed but that happens automatically in VS.
##Usage

```lua

local lsleep = require'lsleep'

lsleep(3) --wait three seconds.

local sleep, usleep = lsleep.sleep, lsleep.usleep

sleep(1) --wait one second.
usleep(2.5 * 10000000) --wait 2.5 seconds

```

## Motivation

It seems odd to me that the sleep command only comes bundled inside of the TCP/IP library for Lua. So, here is `sleep`, and as a bonus, `usleep`, all by themselves. :)

## Contact

If you have questions or come across any issues, please email me at andrew.starks@trms.com.

## The MIT License (MIT)

Copyright (c) 2013 Andrew Starks

Permission is hereby granted, free of charge, to any person obtaining a copy of
this software and associated documentation files (the "Software"), to deal in
the Software without restriction, including without limitation the rights to
use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies of
the Software, and to permit persons to whom the Software is furnished to do so,
subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS
FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR
COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER
IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN
CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
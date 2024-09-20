# node-system-time
Get timestamp of current system time in nanoseconds.

## Dependency
You need to install [Python3](https://www.python.org/downloads/) first to use [node-addon-api](https://www.npmjs.com/package/node-addon-api).

## Installation
```bash
npm install node-system-time
```
## Features
* Support Linux and Windows. (Testing in progress)
* Get timestamp in nanoseconds.
* Return timestamp as [`BigInt`](https://developer.mozilla.org/ko/docs/Web/JavaScript/Reference/Global_Objects/BigInt) type.

## Quick Start
Install package use below command.
```bash
npm install node-system-time
```

Copy and paste below example code to file like `main.js`
```javascript
const systemTime = require("node-system-time");
console.log(systemTime.getTimestamp());
```

Execute `main.js` and get current system timestamp.
```bash
user@server:~$ node main.js 
1726826333990371143n
```

## Mechanism
Call [`uv_clock_gettime`](https://docs.libuv.org/en/v1.x/misc.html#c.uv_clock_gettime) function of [libuv](https://docs.libuv.org/) multi-platform C library using [node-addon-api](https://www.npmjs.com/package/node-addon-api).

## Licence
[MIT](LICENSE)
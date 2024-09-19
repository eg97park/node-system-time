const binding = require("./build/Release/node-system-time");

module.exports = {
    getTimestamp: () => {
        return binding.getCurrentTime();
    }
}

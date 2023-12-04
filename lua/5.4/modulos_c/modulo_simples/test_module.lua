-- Run with Lua 5.4
package.cpath="./build/default/?.so"
local test = require'test'
-- Output should be:
--	2.5	5.0
print(test.soma(2, 5))
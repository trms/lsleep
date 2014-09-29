local lsleep = require'lsleep'
local ticks = lsleep.getticks()

print('ticks', ticks)

print("time", lsleep.time())
local nt = 10 * 1000 * 1000
print("time", lsleep.time())
print("nt to ticks?", nt == ticks, nt - ticks, ticks//nt)

--FINISHING LSLEEP, which we should rename to lclock and make crossplatform again. THen need to test timeout.


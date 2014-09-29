local lsleep = require'lsleep'

local nt = 10 * 1000 * 1000
local ticks = lsleep.getticks()

print('ticks', ticks)

print("time", lsleep.time())
local time =lsleep.time
local t = {}
for i = 1, 10 do
	t[i] = time()
end

for i = 1, 10 do
	print(t[i])
end

print("time", lsleep.time())
print("nt to ticks?",  nt - ticks, nt, ticks, ticks / nt)

-- print('sleep' 1)

print("\nslept", lsleep.sleep(nt))

--FINISHING LSLEEP, which we should rename to lclock and make crossplatform again. THen need to test timeout.


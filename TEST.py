
import re

with open("input.txt") as fin:
    line = fin.read().strip()


matches = re.findall(r"(?:mul\((\d+),(\d+)\))|(do\(\)|don't\(\))", line)

enabled = True

ans = 0
for match in matches:
    if match[2] == "" and enabled:
        print(match)
        ans += int(match[0]) * int(match[1])
    else:
        if match[2] == "do()":
            enabled = True
        else:
            enabled = False

print(ans)
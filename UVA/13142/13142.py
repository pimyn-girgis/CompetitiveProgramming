##############################################################
# Author  : Bemen Girgis
# Contact : bemen@girgis.org
# Problem : 13142 UVA
# Link    : https://onlinejudge.org/external/131/p13142.pdf
##############################################################
# Approach:
##############################################################

factor = 60 * 60 * 24
tc = int(input())

for _ in range(tc):
    t, s, d = map(int, input().split())
    add = (d <= 0)
    d = abs(d) * 1_000_000
    ans = d // (t * factor)
    if (add or ans == 0):
        print("Add {} tons".format(ans))
    else:
        print("Remove {} tons".format(ans))

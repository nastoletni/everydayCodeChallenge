import re
class WTFException: pass
cykablyat = (
    ("M", 1000),
    ("CM", 900),
    ("D", 500),
    ("CD", 400),
    ("C", 100),
    ("XC", 90),
    ("L", 50),
    ("XL", 40),
    ("X", 10),
    ("IX", 9),
    ("V", 5),
    ("IV", 4),
    ("I", 1)
)
chuj = raw_input("Liczba: ")
if len(chuj) <= 0: raise WTFException
try: i = int(chuj)
except: i = 0
if 1 <= i <= 4999:
    r = ""
    for z in cykablyat:
        while z[1] <= i:
            r += z[0]
            i -= z[1]
    print r
elif re.search(re.compile(ur'^[IVXLCDM]+$'), chuj):
    cykablyatv2 = {}
    for raz, dwa in cykablyat: cykablyatv2[raz] = dwa
    pozdrawiamrodzicow = re.findall(re.compile(ur'(M|CM|D|CD|C|XC|L|XL|X|IX|V|IV|I)'), chuj)
    for j in pozdrawiamrodzicow:
        i += cykablyatv2[j]
    print i
else:
    raise WTFException
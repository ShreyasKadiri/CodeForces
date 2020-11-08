for s in[*open(0)][2::2]:
    print(len(s)//2-s.count(s[0]+'01'[s[0]<'1']))

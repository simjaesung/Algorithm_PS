cr_alpha = ['c=', 'c-', 'dz=', 'd-', 'lj', 'nj', 's=', 'z=']
word = str(input())
for cr in cr_alpha :
    if cr in word :
        word = word.replace(cr,' ')
print(len(word))
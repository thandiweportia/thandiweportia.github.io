# program that writes to a file MyCovidNotes

f=open('MyCovidNotes.txt','w')
facts = 10
print("Data Collection:: Ask ten people to write about how Covid-19 affected their lives")
for i in range(facts):
    fact=input("fact" + str(i+1) + ": \n")
    f.write(str(fact)+' \n')
f.close

f=open('MyCovidNotes.txt','r')
lines=f.readlines()

print ("Data Collection for Covid-19 effects: ")
for line in lines:
    print(line)

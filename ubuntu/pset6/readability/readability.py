# deal w/ comma n shit wen u do dis
import cs50
s = input("Text: ")
x = len(s)
words = sent = let = 0
for i in range(x):
    # if (s[i] >= 'a' and s[i] <= 'z') or (s[i] >= 'A' and s[i] <= 'Z'):
    #   let += 1
    if s[i].isalpha() == True:
        let += 1
    elif ((s[i]) == " " and s[i-1].isalpha() == True):
        words += 1
    elif (((s[i]) == " ") and not s[i-1].isalpha() == True):
        let += 1
        continue
    elif (s[i] == "?" or s[i] == "." or s[i] == "!"):
        sent += 1
        words += 1
    elif (s[i] == "," or s[i] == ":" or s[i] == ";"):
        words += 1
    elif (s[i] == "'"):
        continue

let = int((let+1)/words*100)
sent = int(sent/words*100)
index = int(0.0588 * (let) - 0.296 * sent - 15.8)
if index <= 16 and index >= 1:
    print("Grade ", index)
elif index < 1:
    print("Before Grade 1")
else:
    print("Grade 16+")

def isPalindrome(s):
    a = reversed(s)
    b = ""
    for i in a:
        b += i

    return b == s

n = int(input())
s = input()

se = set()

for i in s:
    for j in s:
        for k in s:
            if (isPalindrome(i + j + k) and len(i + k + j) == 3):
                se.add(i + j + k)

print(len(se))

for i in sorted(se):
    print(i)

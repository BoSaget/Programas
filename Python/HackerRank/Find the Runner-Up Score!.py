scores = int(input(""))
scores = input().split()

scores.sort()
scores.reverse()
max_score = int(scores[0])
runner = -101
for i in range (0, len(scores)):
    if int(scores[i]) > runner and int(scores[i]) < max_score:
        runner = int(scores[i])

if runner != -101:
    print(runner)
else:
    print(max_score)
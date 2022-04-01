def number_of_vowels (letter):
    vowels = 0
    for i in range(0, len(letter)):
        if letter[i] == "a" or letter[i] == "e" or letter[i] == "i" or letter[i] == "o" or letter[i] == "u" or letter[i] == "y":
            vowels = vowels + 1

    if vowels % 2 == 0:
        return 2
    else:
        return 1

def score_words(word):
    score = 0
    for i in word:
        score = number_of_vowels(i) + score
    
    return score



#words = int(input(""))
#word = input().split()
#score = score_words(word)

#print(score)
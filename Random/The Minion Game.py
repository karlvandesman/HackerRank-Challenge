#https://www.hackerrank.com/challenges/the-minion-game/problem

def minion_game(string):
    KPoints = SPoints = 0   #starting with 0 points
    vowels = 'AEIOU'        #assigning all whe vowels to be compared

    for index, letter in enumerate(string):     #getting the index and the respective letter from the string
        if letter in vowels:                    #if this letter is a vowel (is in the string vowel), Kevin gets the points
            KPoints += len(string) - index      #the quantity of points will be the length of the substring
        else:                                   #in the other case (consonant), Stuart gets the points
            SPoints += len(string) - index

    if SPoints > KPoints:
        print("Stuart", SPoints)
    elif KPoints > SPoints:
        print("Kevin", KPoints)
    else:
        print("Draw")

if __name__ == '__main__':
    s = input()
    minion_game(s)S
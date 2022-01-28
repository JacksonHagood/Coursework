from random import *


def instructions():
    """Prints the instructions of Yahtzee to the user."""

    # page of instructions
    print("\n   -----------Yahtzee Instructions-----------\n"
          "   There are five dice that will be rolled\n"
          "   (numbered 1-5 left to right). Each turn the\n"
          "   dice will be rolled, then the user can\n"
          "   select certain dice to be rolled again.\n"
          "   After 3 total rolls the turn is over, and\n"
          "   the user chooses to score them out of 7\n"
          "   categories:\n"
          "   3 of a kind        (three)     sum of dice.\n"
          "   4 of a kind        (four)      sum of dice.\n"
          "   2 and 3 of a kind  (full)      25.\n"
          "   4 sequential       (small)     30.\n"
          "   5 sequential       (large)     40.\n"
          "   5 of a kind        (yahtzee)   50.\n"
          "   Any                (chance)    sum of dice.\n"
          "   There are 13 total turns, and no category\n"
          "   can be used twice. Additionally, there is\n"
          "   an upper score that is the sum of the dice,\n"
          "   which is counted every turn. Call dice in\n"
          "   the format 1-5 and the way to be graded\n"
          "   the list above.\n"
          "   -----------Yahtzee Instructions-----------\n")


def turn():
    """Goes through a single turn of the game."""

    # dice stores values of dice and to_roll keeps track of dice to roll again
    dice, to_roll = [], []

    # dice can be rolled 3 times
    for i in range(3):
        # on the first roll, roll all dice.
        if i == 0:
            dice += roll(5)

        # on subsequent rolls, allow specific rolling of dice.
        else:
            # reset vars
            die, to_roll = "temp", []

            # output current dice
            print("   Dice:", dice)

            # get dice to roll
            while True:
                # prompt
                die = input("   Enter a dice number (1 - 5) to roll again (0 to stop): ")

                if die in "012345":
                    die = int(die)

                    if die == 0:
                        # 0 terminates loop
                        break
                    else:
                        to_roll.append(die - 1)

            print("")

            # roll dice
            for j in to_roll:
                dice[j] = roll(1)[0]

    # output and return dice
    print("   Dice:", dice)
    return dice


def roll(n):
    """Rolls n dice."""

    dice = []

    # roll dice
    for i in range(n):
        dice.append(randint(1, 6))

    return dice


def score(dice, method):
    """Returns the score of given dice using a method."""

    # tallies points
    points = 0

    # three of a kind
    if method == "three":
        # if there exists three of a kind, add the dice summed
        for i in range(1, 7):
            if dice.count(i) >= 3:
                points += sum(dice)

    # four of a kind
    elif method == "four":
        # if there exists four of a kind, add the dice summed
        for i in range(1, 7):
            if dice.count(i) >= 4:
                points += sum(dice)

    # full house
    elif method == "full":
        # if there exists both a two and three of a kind add 25
        a, b = False, False
        for i in range(1, 7):
            if dice.count(i) == 3:
                a = True
            if dice.count(i) == 2:
                b = True
        if a and b:
            points += 25

    # small sequence
    elif method == "small":
        # if there exists a sequence of 4 numbers add 30
        for i in range(1, 7):
            if dice.count(i) == 2:
                dice.remove(i)
        dice = "".join(str(i) for i in sorted(dice))
        if "1234" in dice or "2345" in dice or "3456" in dice:
            points += 30

    # large sequence
    elif method == "large":
        # if there exists a sequence of 5 numbers add 40
        dice = "".join(str(i) for i in sorted(dice))
        if "12345" in dice or "23456" in dice:
            points += 40

    # five of a kind
    elif method == "yahtzee":
        # if there exists five of a kind, add 50
        for i in range(1, 7):
            if dice.count(i) == 5:
                points += 50

    # chance
    elif method == "chance":
        # add the dice summed
        points += sum(dice)

    return points


# main Program

# output an initial message and the instructions
print("Welcome to Yahtzee!")
instructions()

# vars
score1, score2, way, previous, q = 0, 0, "", [], False

# repeat allows scoring methods to be repeated
repeat = input("Enter 'y' to allow repeated scoring methods: ")
print("-" * 100)

# iterate through thirteen turns
for t in range(13):
    print("TURN:", t + 1)

    # allow the user to view one of several items
    option = input("   (i: instructions, q: quit, or s: score): ")

    # output the indicated item
    if option == "q":
        # terminate
        q = True
        break

    elif option == "i":
        instructions()

    elif option == "s":
        print("   Current score:", score1 + score2)

    # run through a turn
    final = turn()
    score1 += sum(final)

    # score
    way = input("   Enter the way to score (n for none): ")

    if way not in previous or repeat == "y":
        # add the method to the list of methods used
        previous.append(way)

        # increment score 2 by the dice scored with the method
        score2 += score(final, way)

    print("-" * 100)

# ensure the user has not quit
if not q:
    # add an additional 35 points if score 1 exceeded 63
    if score1 >= 63:
        score1 += 35

    # final scores
    print("DONE!")
    print("   Upper score:", score1)
    print("   Lower score:", score2)
    print("   Final score:", score1 + score2)

    # file output
    File = open("Board.txt", "a")
    name = input("   Enter a name: ")
    File.write(name + " | " + str(score1 + score2) + '\n')
    File.close()

# output a final message to the user
print("-" * 100)
print("Thanks for playing!")

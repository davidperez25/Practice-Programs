import csv
import math

ROUND = 5

with open("favorites.csv", "r") as file:
    reader = csv.DictReader(file)
    langs = {}

    for row in reader:
        favorite = row["language"]

        if favorite in langs:
            langs[favorite] += 1
        else:
            langs[favorite] = 1

    sortedLangs = sorted(langs.items(), key=lambda item: item[1], reverse=True)
    counts = [count for _, count in sortedLangs]

    stats = {
        "Languages": len(langs),
        "Entries": sum(counts),
        "Mean": round(sum(counts) / len(langs), ROUND),
        "Median": round((counts[(len(counts) - 1) // 2] + counts[len(counts) // 2]) / 2, ROUND),
        "Standard Deviation": math.sqrt(sum((x - (sum(counts) / len(langs))) ** 2 for x in counts) / len(counts))
    }

    for lang, count in sortedLangs:
        print(f"{lang} : {count}")

    print("\033[92m") # green
    for stat, value in stats.items():
        print(f"{stat} : {value}")
    print("\033[0m") # reset

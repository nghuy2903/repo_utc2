def translate(phara):
    tra = ""
    for leter in phara:
        if leter in "ô i à n ê":
            tra = tra + "g"
        else:
            tra = tra + leter
    return tra

print(translate(input()))


import os

with open("input.txt", "r") as input:
    data = input.read()
    floor = 0
    instruction = 0
    basement_instruction = 0

    for c in data:
        if c == "(":
            floor += 1
        elif c == ")":
            floor -= 1
        
        instruction += 1
        
        if basement_instruction == 0 and floor == -1:
            basement_instruction = instruction
    
    print("Final Floor:", floor)
    print("Basement Level:", basement_instruction)
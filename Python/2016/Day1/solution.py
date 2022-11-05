
def switch_vector(vector, direction):
    a, b = vector
    if direction == "R":
        c, d = (0, -1)
    elif direction == "L":
        c, d = (0, 1)
        
    return (a * c - b * d, a * d + b * c)

def add_vector(vector1, vector2):
    a, b = vector1
    c, d = vector2
    return (a + c, b + d)

def scalar_vector(vector, scalar):
    a, b = vector
    return (a * scalar, b * scalar)

with open("input.txt", "r") as input:
    data = input.read()
    instructions = data.split(", ")

    locations = set()
    step_count = 0
    visited_distance = -1

    vector = (0, 0)
    direction = (0, 1)
    for instruction in instructions:
        direction = switch_vector(direction, instruction[0])
        for n in range(int(instruction[1:])):
            vector = add_vector(vector, direction)
            step_count += 1
            locations.add(vector)

            if len(locations) < step_count and visited_distance == -1:
                visited_distance = abs(vector[0]) + abs(vector[1])
        

    print("Final Vector:", vector)
    print("Grid Distance:", abs(vector[0]) + abs(vector[1]))
    print("Visited Distance:", visited_distance)


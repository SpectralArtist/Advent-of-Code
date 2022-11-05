from collections import Counter

def is_real(string, checksum):
    count = Counter(list(string))

    count_list = count.most_common()
    count_list = sorted(count_list, key = lambda x: x[0], reverse=False)
    count_list = sorted(count_list, key = lambda x: x[1], reverse=True)
    
    if len(count_list) >= 5:
        test_checksum = "".join([x[0] for x in count_list[0:5]])

        if test_checksum == checksum:
            return True
        
    return False

def shift_cipher(string, id):
    shifted_string = ""

    for c in string:
        asc = ord(c)
        letter = (asc - 97 + id) % 26
        shifted_string += chr(letter + 97)

    return shifted_string


with open("input.txt", "r") as input:
    data = input.readlines()

    total = 0
    total_shifted = 0
    for line in data:
        string, checksum = line.split("[")
        checksum = checksum[0:5]
        string_pieces = string.split("-")
        id = int(string_pieces[-1])
        string_pieces.pop()

        string = "".join(string_pieces)

        if is_real(string, checksum):
            total += id

            shifted_string = shift_cipher(string, id)
            if "northpole" in shifted_string:
                print("Shifted String:", shifted_string, id)

    print("Total:", total)

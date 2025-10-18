output_1 = list()
with open("1.txt", "r") as f:
    output_1 = f.readlines()

    output_1 = [t.strip() for t in output_1]

output_2 = list()
with open("2.txt", "r") as f:
    output_2 = f.readlines()

    output_2 = [t.strip() for t in output_2]

print(len(output_1), len(output_2))

n = len(output_1)
for i in range(n):
    if output_1[i] != output_2[i]:
        print("ERROR")
        print(i + 1)
        print(output_1[i])
        print(output_2[i])
        exit()

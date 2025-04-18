MAX = 10**9


all_numbers = list()
def gen(l: list) -> None:
  number = int(''.join(map(str, l)))
  if number > MAX:
    return 
  all_numbers.append(number)
  for i in range(l[-1] + 1, 10):
    gen(l + [i])

def main() -> None:
  for i in range(1, 10):
    gen([i])
  all_numbers.sort()
  print(len(all_numbers))
  with open("generated.txt", "w") as f:
    f.write("{")
    f.write(", ".join(map(str, all_numbers)))
    f.write("}\n")

if __name__ == "__main__":
  main()
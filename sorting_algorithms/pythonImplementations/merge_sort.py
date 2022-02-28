#array = [3, 2, 1, 6, 5]
array = [4, 15, 16, 50, 8, 23, 42, 108]
#array = [2, 5, 3, 1, 9, 10, 6]

def merge_sort(arr):
    if len(arr) == 1:
        return arr

    first_half = []
    second_half = []

    #Separates the array in halves
    for i in range(0, len(arr)):
        if i+1 <= (len(arr)/2):
            first_half.append(arr[i])
        else:
            second_half.append(arr[i])

    #This recursion is done in order to
    #divide in half the created arrays
    first_half = merge_sort(first_half)
    second_half = merge_sort(second_half)

    #This is used to sort and merge the halves
    arr = merge(first_half, second_half)

    return arr


def merge(first, second):
    sorted_half = []
    cont_f = 0
    cont_s = 0
    while True:
        if first[cont_f] <= second[cont_s]:
            sorted_half.append(first[cont_f])
            cont_f = cont_f + 1
            if cont_f == len(first):
                for i in range(cont_s, len(second)):
                    sorted_half.append(second[i])
                break
        else:
            sorted_half.append(second[cont_s])
            cont_s = cont_s + 1
            if cont_s == len(second):
                for i in range(cont_f, len(first)):
                    sorted_half.append(first[i])
                break
    return sorted_half


print(array)
array = merge_sort(array)
print(array)


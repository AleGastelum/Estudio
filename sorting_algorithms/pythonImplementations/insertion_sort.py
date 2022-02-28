array = [2, 8, 5, 3, 5, 9, 4]

def insertion_sort(arr):
    temp = 0
    for i in range(1, len(arr)):
        for j in range(i, 0, -1):
            if arr[j-1] > arr[j]:
                temp = arr[j-1]
                arr[j-1] = arr[j]
                arr[j] = temp
            else:
                break
    return arr

sort_array = insertion_sort(array)
print(sort_array)

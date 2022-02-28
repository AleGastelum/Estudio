def quick_sort(start, pivot):
    temp = 0
    i = start-1
    for j in range(start, pivot):
        if array[j] < array[pivot]:
            i = i+1
            temp = array[j]
            array[j] = array[i]
            array[i] = temp
    temp = array[pivot]
    array[pivot] = array[i+1]
    array[i+1] = temp
    if i+2 < pivot:
        quick_sort(i+2, pivot)
    if i > start:
        quick_sort(start, i)


#array = [7, 2, 1, 8, 6, 3, 5, 4]
array = [1, 15, 2, 3, 17, 5, 6, 3, 9]

print(array)
quick_sort(0, len(array)-1)
print(array)

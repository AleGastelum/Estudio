#def swap(left, right):
    #temp = 0

def bubble_sort(array):
    for i in range(len(array)-1, 0, -1):
        for j in range(0, i):
            if array[j] > array[j+1]:
                #swap()
                temp = array[j+1]
                array[j+1] = array[j]
                array[j] = temp
    return array


result = bubble_sort([2, 5, 1, 7, 5, 8, 9])
print(result)

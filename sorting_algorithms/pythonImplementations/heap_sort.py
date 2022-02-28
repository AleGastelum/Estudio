def heap_sort(array):
    last = len(array)-1
    i = int(len(array)/2)-1
    
    while last > 0:
        while i >= 0:
            heapify(array, i, last)
            i = i-1

        swap(array, 0, last)

        last = last - 1
        i = int((last+1)/2)-1

    #swap(array, 0, last)

    print(array)

def heapify(array, i, last):

    while i < last:
        father = i
        left = (2*i)+1
        right = (2*i)+2

        if left <= last and array[left] > array[father]:
            father = left

        if right <= last and array[right] > array[father]:
            father = right

        if father == i:
            return

        swap(array, father, i)

        print(array)

        i = father


def swap(array, child, father):
    temp = array[child]
    array[child] = array[father]
    array[father] = temp


#array = [10, 5, 3, 8, 1]
array = [15, 20, 13, 4, 1, 6]
#array = [4, 15, 16, 50, 8, 23, 42, 108]

heap_sort(array)

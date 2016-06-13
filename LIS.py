def find(tuple_list, element, start, end):
    while start < end and start + 1 != end:
        middle = (start + end) // 2
        if tuple_list[middle][1] == element:
            return -1

        if tuple_list[middle][1] < element:
            start = middle
        else:
            end = middle
    return start


def replace_or_append(tuple_list, index, element):
    if index + 1 >= len(tuple_list):
        tuple_list.append((tuple_list[index][0] + 1, element))
    else:
        tuple_list[index + 1] = (tuple_list[index][0] + 1, element)


def add_element(active_lists, element):
    if active_lists:
        if active_lists[0][1] < element:
            index = find(active_lists, element, 0, len(active_lists))
            if index == -1:
                return
            replace_or_append(active_lists, index, element)
        else:
            active_lists[0] = (1, element)
    else:
        active_lists.append((1, element))


if __name__ == '__main__':
    n = int(input())

    A = []
    for i in range(n):
        A.append(int(input()))

    active_lists = []
    for i in range(n):
        add_element(active_lists, A[i])

    print(active_lists[-1][0])
